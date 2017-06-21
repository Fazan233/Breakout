#include "scoreboard.h"
/**
 * Instantiates, configures, and returns label for scoreboard.
 */
GLabel initScoreboard(GWindow window)
{
    GLabel label = newGLabel("");
    setFont(label, "Sanserif-36");
    add(window, label);
    return label;
}
