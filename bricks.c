#include <bricks.h>
/**
 * Initializes window with a grid of bricks.
 */
void initBricks(GWindow window)
{
    for (int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            double a = WIDTH/COLS;
            double xn = a/20;
            double shir = a - a/10;  // 40 - 4 = 36
            double yn = xn, visota = a/2 - a/10; // 20 - 4 = 16
            int x = xn + j * a;
            int y = yn + i * a/2;
            GRect block = newGRect(x, 50 + y, shir, visota);
            int q = i%5;
            if (q == 0)
            {
                setFilled(block, true);
                setColor(block, "RED");
            }
            else if (q == 1)
            {
                setFilled(block, true);
                setColor(block, "ORANGE");
            }
            else if (q == 2)
            {
                setFilled(block, true);
                setColor(block, "YELLOW");
            }
            else if (q == 3)
            {
                setFilled(block, true);
                setColor(block, "GREEN");
            }
            else if (q == 4)
            {
                setFilled(block, true);
                setColor(block, "BLUE");
            }
            else
            {
                setFilled(block, true);
                setColor(block, "BLACK");
            }
            
            add(window, block);
        }
    }
}
