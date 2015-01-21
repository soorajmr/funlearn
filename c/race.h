/*
 * Race simulation - Race interface
 * This is a part of examples to illustrate functional programming style
 * Author: Sooraj Raveendran <soorajmr@slingmedia.com>
 */

/* struct to keep the data for each RACE instance */ 
typedef struct RACE_ RACE;

/* Create and intialize a RACE object */
RACE *race_create(char *name, CAR **car_list, unsigned int car_count,
                  double circuit_length_km);

/* start the race, print the final positions of CARs */
int race_run(RACE *race);

/* Delete a race object */
void race_destroy(RACE *race);

