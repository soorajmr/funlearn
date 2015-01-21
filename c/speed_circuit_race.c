/*
 * Speed Circuit Race simulation
 * This is a part of examples to illustrate functional programming style
 * Author: Sooraj Raveendran <soorajmr@slingmedia.com>
 */

#include <stdlib.h>
#include <stdio.h>
#include "car.h"
#include "race.h"

static const double MAX_SPEED_JAGUAR_MPS  = 120;
static const double MAX_SPEED_AUDI_MPS    = 126;
static const double MAX_SPEED_PORCHE_MPS  = 99;
static const double ACCEL_JAGUAR_MPS2      = 8;
static const double ACCEL_AUDI_MPS2        = 6;
static const double ACCEL_PORCHE_MPS2      = 9;

#define CAR_COUNT (3)

int main(int argc, char **argv)
{
  CAR *cars[CAR_COUNT] = {};
  CAR *jaguar = NULL;
  CAR *porche = NULL;
  CAR *audi = NULL;
  RACE *sp_circuit_race = NULL;
  unsigned int i = 0;
  int status = -1;
  double track_len = 0;

  if(2 != argc)
  {
    return -1;
  }

  track_len = strtod(argv[1], NULL);

  /* create the "CAR" objects */
  jaguar = car_create("Jaguar", MAX_SPEED_JAGUAR_MPS, ACCEL_JAGUAR_MPS2);
  porche = car_create("Porche", MAX_SPEED_PORCHE_MPS, ACCEL_PORCHE_MPS2);
  audi = car_create("Audi", MAX_SPEED_AUDI_MPS, ACCEL_AUDI_MPS2);
  
  if((jaguar != NULL) && (porche != NULL) && (audi != NULL))
  {
    cars[0] = jaguar;
    cars[1] = porche;
    cars[2] = audi;

    /* create a "RACE" object with appropriate parameters */
    sp_circuit_race = race_create("Speed Circuit", cars, CAR_COUNT, 
                                  track_len);
  
    if(sp_circuit_race != NULL)
    {
      /* run the race! */
      status = race_run(sp_circuit_race);
    }
  }

  /* destroy functions safely ignore NULL parameters */
  race_destroy(sp_circuit_race);
  for(i = 0; i < CAR_COUNT; i++)
  {
    car_destroy(cars[i]);
  }

  return status;
}

