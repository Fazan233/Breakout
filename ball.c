#include "ball.h"
/**
 * Instantiates ball in center of window.  Returns ball.
 */
GOval initBall(GWindow window)
{
    double x = (getWidth(window)/2 - BALL / 2);
    double y = (getHeight(window)/2 - BALL / 2);
    GOval circle = newGOval(x, y, BALL, BALL);
    setColor(circle, "BLACK");
    setFilled(circle, true);
    add (window, circle);
    return circle;
}
