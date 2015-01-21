//
// breakout.c
//
// Computer Science 50
// Problem Set 4
//

// standard libraries
#define _XOPEN_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Stanford Portable Library
#include "gevents.h"
#include "gobjects.h"
#include "gwindow.h"

// height and width of game's window in pixels
#define HEIGHT 600
#define WIDTH 400

// number of rows of bricks
#define ROWS 5

// number of columns of bricks
#define COLS 10

// radius of ball in pixels
#define RADIUS 10

// lives
#define LIVES 3

// paddle dimensions
#define PADHEIGHT 10
#define PADWIDTH 80

// prototypes
void initBricks(GWindow window);
GOval initBall(GWindow window);
GRect initPaddle(GWindow window);
GLabel initScoreboard(GWindow window);
void updateScoreboard(GWindow window, GLabel label, int points);
GObject detectCollision(GWindow window, GOval ball);

int main(void)
{
    // seed pseudorandom number generator
    srand48(time(NULL));

    // instantiate window
    GWindow window = newGWindow(WIDTH, HEIGHT);

    // instantiate bricks
    initBricks(window);

    // instantiate ball, centered in middle of window
    GOval ball = initBall(window);

    // instantiate paddle, centered at bottom of window
    GRect paddle = initPaddle(window);

    // instantiate scoreboard, centered in middle of window, just above ball
    GLabel label = initScoreboard(window);

    // number of bricks initially
    int bricks = COLS * ROWS;

    // number of lives initially
    int lives = LIVES;

    // number of points initially
    int points = 0;
    
    // ball speed
    double horizvelocity = drand48() + 0.35;
    double vertvelocity = drand48() + 0.35;
    
    // keep playing until game over
    while (lives > 0 && bricks > 0)
    {
        GEvent event = getNextEvent(MOUSE_EVENT);
        
        if (event != NULL)
        {
            if (getEventType(event) == MOUSE_MOVED)
            {
                double x = getX(event) - getWidth(paddle) / 2;
                double y = HEIGHT - 50;
                setLocation(paddle, x, y);
            }
        }
        
        move(ball, horizvelocity, vertvelocity);
        
        if (getX(ball) + getHeight(ball) >= getWidth(window))
        {
            horizvelocity = -horizvelocity;
        }
        
        else if (getX(ball) <= 0)
        {
            horizvelocity = -horizvelocity;
        }
        
        else if (getY(ball) <= 0)
        {
            vertvelocity = -vertvelocity;
        }
        
        else if (getY(ball) + getHeight(ball) >= getHeight(window))
        {
            lives--;
            setLocation(ball, (getWidth(window) - getHeight(ball)) / 2, getHeight(window) / 3);
            setLocation(paddle, (getWidth(window) - getWidth(paddle)) / 2, getHeight(window) - 50);
            waitForClick();
        }
        
        GObject object = detectCollision(window, ball);
        
        if (object != NULL)
        {
            if (object == paddle)
            {
                if (vertvelocity >=0)
                {
                    vertvelocity = -vertvelocity;
                }      
            }
        
            else if (strcmp(getType(object), "GRect") == 0)
            {
                removeGWindow(window, object);
                vertvelocity = -vertvelocity;
                points++;
                bricks--;
                updateScoreboard(window, label, points);
                
            }   
        }
        pause (1);
    }

    // wait for click before exiting
    waitForClick();

    // game over
    closeGWindow(window);
    return 0;
}

/**
 * Initializes window with a grid of bricks.
 */
void initBricks(GWindow window)
{
    int x = 0;
    int y = 40;
    char *a[5];
    a[0] = "RED";
    a[1] = "YELLOW";
    a[2] = "BLUE";
    a[3] = "GREEN";
    a[4] = "ORANGE";
    for (int i=0; i < ROWS; i++)
    {
        for (int j=0; j < COLS; j++)
        {       
            GRect brick = newGRect(x, y, 37, 12);
            setColor(brick, a[i]);
            setFilled(brick, true);
            add(window, brick);
            x += 40;
        }
        x = 0;
        y += 15;      
    }     
}

/**
 * Instantiates ball in center of window.  Returns ball.
 */
GOval initBall(GWindow window)
{
    double x = WIDTH / 2 - RADIUS / 2;
    double y = HEIGHT / 2 - RADIUS / 2;
    GOval ball = newGOval(x, y, RADIUS*2, RADIUS*2);
    setFilled(ball, true);
    add(window, ball);
    return ball;
}

/**
 * Instantiates paddle in bottom-middle of window.
 */
GRect initPaddle(GWindow window)
{
    double x = WIDTH / 2 - PADWIDTH / 2;
    double y = HEIGHT - 50;
    GRect paddle = newGRect(x, y, PADWIDTH, PADHEIGHT);
    setFilled(paddle, true);
    add(window, paddle);
    return paddle;
}

/**
 * Instantiates, configures, and returns label for scoreboard.
 */
GLabel initScoreboard(GWindow window)
{
    GLabel label = newGLabel("0");
    setFont(label,  "SansSerif-18");
    double x = (getWidth(window) - getWidth(label)) / 2;
    double y = (getHeight(window) - getHeight(label)) / 2;
    setLocation(label, x, y);
    add(window, label);
    return label;
}

/**
 * Updates scoreboard's label, keeping it centered in window.
 */
void updateScoreboard(GWindow window, GLabel label, int points)
{
    // update label
    char s[12];
    sprintf(s, "%i", points);
    setLabel(label, s);

    // center label in window
    double x = (getWidth(window) - getWidth(label)) / 2;
    double y = (getHeight(window) - getHeight(label)) / 2;
    setLocation(label, x, y);
}

/**
 * Detects whether ball has collided with some object in window
 * by checking the four corners of its bounding box (which are
 * outside the ball's GOval, and so the ball can't collide with
 * itself).  Returns object if so, else NULL.
 */
GObject detectCollision(GWindow window, GOval ball)
{
    // ball's location
    double x = getX(ball);
    double y = getY(ball);

    // for checking for collisions
    GObject object;

    // check for collision at ball's top-left corner
    object = getGObjectAt(window, x, y);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's top-right corner
    object = getGObjectAt(window, x + 2 * RADIUS, y);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's bottom-left corner
    object = getGObjectAt(window, x, y + 2 * RADIUS);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's bottom-right corner
    object = getGObjectAt(window, x + 2 * RADIUS, y + 2 * RADIUS);
    if (object != NULL)
    {
        return object;
    }

    // no collision
    return NULL;
}
