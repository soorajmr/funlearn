/*
 * Race simulation program - Race implementation
 * This is a part of examples to illustrate functional programming style
 * Author: Sooraj Raveendran <soorajmr@slingmedia.com>
 */

#include <stdlib.h>
#include <stdio.h>
#include <float.h>
#include "car.h"
#include "race.h"

struct RACE_
{
  char *name;
  CAR  **car_list;
  unsigned int car_count;
  double track_length_km;
};

/* get the mininum time taken by all the cars in the 
 * list of cars to cover the given distance. */
static double get_min_time_sec(RACE *race)
{
  double min_time = DBL_MAX;
  double next_time = 0.0;
  int i = 0;

  if(NULL == race)
  {
    return 0.0;
  }

  for(i = 0; i < race->car_count; i++)
  {
    next_time = car_get_travel_time_sec(race->car_list[i],
                                        race->track_length_km);
    if(next_time < min_time)
    {
      min_time = next_time;
    }
  }

  return min_time;
}

/* Create and intialize a RACE object */
RACE *race_create(char *name, CAR **car_list, 
                  unsigned int car_count, 
                  double track_length_km)
{
  RACE *race = NULL;

  race = malloc(sizeof(RACE));
  if(race != NULL)
  {
    race->name = name;
    race->car_list = car_list;
    race->car_count = car_count;
    race->track_length_km = track_length_km;
  }
}

/* 
 * Start and run the race 
 * Param: race object
 * Return: 0 on succcessful completion. -1 on any error.
 */
int race_run(RACE *race)
{
  double winner_time = 0.0;
  double pos = 0.0;
  CAR *car = NULL;
  int i = 0;

  if(NULL == race)
  {
    return -1;
  }

  winner_time = get_min_time_sec(race);

  for(i = 0; i < race->car_count; i++)
  {
    car = race->car_list[i];
    pos = car_get_position_km(car, winner_time);

    printf("\t%s: %f Km\n", car_get_name(car), pos);
  }

  return 0;
}

/* Delete a race object */
void race_destroy(RACE *race)
{
  free(race);
  // Do not free up the CARs in the list of CARs. Assume the caller will
  // take care of freeing the CARs.
}


