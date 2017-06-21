#include "paddle.h"
/**
 * Instantiates paddle in bottom-middle of window.
 */
GRect initPaddle(GWindow window)
{   
    GRect paddle = newGRect ( WIDTH/2-(PADDLE_SH/2), HEIGHT - 20, PADDLE_SH, PADDLE_V);
    setFilled(paddle, true);
    setColor(paddle, "BLACK");
    add(window, paddle);
    return paddle;
}
