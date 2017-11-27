#ifndef DEFINES_H
#define DEFINES_H

/* ---------------------
 * Name: DEBUG
 * Description: Setting to TRUE execute debugging tasks during execution. This can
 *              considerably slow down the execution
 *              These tasks are:
 *              1) Death Screenshots: when the player dies, a screenshots is taken and
 *              and saved to DEATH_DEBUG_IMAGE (defined belove, png image), and all the
 *              required data to raw calculations (Positions, radiuses, ecc.) are
 *              saved to DEATH_DEBUG_REPORT (defined belove, txt file)
 *              2) To be defined...
 * Default: FALSE
 * --------------------- */
#define DEBUG false

/* ---------------------
 * Name: DEATH_DEBUG_IMAGE
 * Description: The name of the image file where a death screenshot is saved if
 *              DEBUG is set to TRUE.
 * Default: N/A
 * --------------------- */
#define DEATH_DEBUG_IMAGE "DeathDebug.png"

/* ---------------------
 * Name: DEATH_DEBUG_REPORT
 * Description: The name of the text file where debug data are stored in case of
 *              player's death if DEBUG is set to TRUE.
 * Default: N/A
 * --------------------- */
#define DEATH_DEBUG_REPORT "DeathDebug.txt"

#endif // DEFINES_H
