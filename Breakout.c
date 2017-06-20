//
// breakout.c
//
// Computer Science 50
// Problem Set 3
//

// standard libraries
#define _XOPEN_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "bricks.h"
#include "ball.h"
#include "scoreboard"
#include "paddle"
#include "detectCollision"

// Stanford Portable Library
#include <spl/gevents.h>
#include <spl/gobjects.h>
#include <spl/gwindow.h>

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

#define PADDLE_SH 50
#define PADDLE_V 5

#define BALL 20

// prototypes




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
    
    double velocityX = 2.0, velocityY = drand48()*2+1;
    // keep playing until game over
    
    char s[3];
    sprintf(s, "%i", bricks);
    setLabel(label, s);
    
    double xx = (getWidth(window) - getWidth(label))/2;
    double yy = (getHeight(window) - getHeight(label))/2;
    
    setLocation(label, xx, yy);
    
    waitForClick();
    
    while (lives > 0 && bricks > 0)
    {   
        GEvent event = getNextEvent(MOUSE_EVENT);
        
        if (event != NULL)
        {
            if(getEventType(event) == MOUSE_MOVED)
            {
                double x = getX(event) - getWidth(paddle) / 2;
                double y = getY(event) - getHeight(paddle) / 2;
                setLocation(paddle, x, HEIGHT - 20);
            }
        }
        
        
        
        GObject object = detectCollision(window, ball);
        
        if(object != NULL)
        {
            if(object == paddle)
            {
                velocityY = -velocityY;
            }
            else if(strcmp(getType(object), "GRect") == 0)
            {
                velocityY = -velocityY;
                removeGWindow(window, object);
                bricks--;
                sprintf(s, "%i", bricks);
                setLabel(label, s);
                setLocation(label, xx, yy);
                if (bricks == 0)
                {
                    setLabel(label, "You win!!!");
                    double xx = (getWidth(window) - getWidth(label))/2;
                    double yy = (getHeight(window) - getHeight(label))/2;
                    setLocation(label, xx, yy);
                    break;
                }
            }
        }
        
        
        move(ball, velocityX, velocityY);
        
        if(getY(ball) + getHeight(ball) >= getHeight(window))
        {
            velocityX = (getWidth(window)/2 - BALL / 2);
            velocityY = (getHeight(window)/2 - BALL / 2);  
            
            lives--;          
            if(lives == 0)
            {
                    setLabel(label, "You lose!!!");
                    double xx = (getWidth(window) - getWidth(label))/2;
                    double yy = (getHeight(window) - getHeight(label))/2;
                    setLocation(label, xx, yy);
                    break;
            }
            setLocation(ball, velocityX, velocityY);
            waitForClick();
            velocityX = 2.0;
            velocityY = drand48()*2+1;
            
            
        }
        else if (getY(ball) <= 0)
        {
            velocityY = -velocityY;
        }
        
        if(getX(ball) + getWidth(ball) >= getWidth(window))
        {
            velocityX = -velocityX;
        }
        else if (getX(ball) <= 0)
        {
            velocityX = -velocityX;
        }
        
        
        pause(10);
        
        
    }

    // wait for click before exiting
    waitForClick();

    // game over
    closeGWindow(window);
    return 0;
}



