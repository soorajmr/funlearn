/*
 * Race simulation program - Car implementation
 * This is a part of examples to illustrate functional programming style
 * Author: Sooraj Raveendran <soorajmr@slingmedia.com>
 */

#include <stdlib.h>
#include <math.h>
#include "car.h"

/* struct to keep the data for each CAR instance */
struct CAR_
{
  char *name;
  double speed_mps;
  double accel_mps2;
};

/*
 * Creates a CAR object.
 * Params: Car name, maximum speed in Kmph, acceleration in m/sec^2 
 * Return: CAR object
 */
CAR *car_create(char *name, double speed_mps,
                double accel_mps2)
{
  CAR *car = NULL;

  car = malloc(sizeof(CAR));
  if(car != NULL)
  {
    car->name = name;
    car->speed_mps = speed_mps;
    car->accel_mps2 = accel_mps2;
  }
  return car;
}

/*
 * Gets the position of the car after a given time interval from start
 * Params: Car object
 *         Time offset from start in sec
 * Return: Distance travelled from start in Km
 */
double car_get_position_km(CAR *car, double time_from_start_sec)
{
  double distance = 0;
  double accel_time_sec = 0;

  if(NULL == car)
  {
    return 0;
  }

  accel_time_sec = car->speed_mps / car->accel_mps2;

  if(time_from_start_sec > accel_time_sec)
  {
    distance 
      = (car->accel_mps2 * accel_time_sec * accel_time_sec) / 2
                   + car->speed_mps * (time_from_start_sec - accel_time_sec);
  }
  else
  {
    distance = (car->accel_mps2 
                     * time_from_start_sec * time_from_start_sec) / 2;
  }

  /* m => Km  */
  return (distance / 1000);
}

/* 
 * Time taken to cover the given distance from the starting point 
 * Params: Car object
 *         Distance from start in Km
 *
 * Return: time taken to cover the distnace (in sec)
 * */
double car_get_travel_time_sec(CAR *car, double distance_km)
{
  double accel_time_sec = 0;
  double accel_dist_m = 0;
  double distance_m = distance_km * 1000;
  double time_sec = 0;

  if(NULL == car)
  {
    return 0;
  }

  accel_time_sec = car->speed_mps / car->accel_mps2;
  accel_dist_m = (car->accel_mps2 
                     * accel_time_sec * accel_time_sec) / 2;

  if(distance_m < accel_dist_m)
  {
    /* all travel is in uniform acceleration */
    time_sec = sqrt(2 * distance_m / car->accel_mps2);
  }
  else
  {
    /* acceleration stops after accel_dist_m; constant speed then on */
    time_sec = accel_time_sec + (distance_m - accel_dist_m) / car->speed_mps;
  }

  return time_sec;
}

/* 
 * Getter for car name
 * */
char *car_get_name(CAR *car)
{
  if(car != NULL)
  {
    return car->name;
  }
  return NULL;
}

/*
 * Destroys a CAR object.
 * Param: CAR object
 * Return: Nothing
 */
void car_destroy(CAR *car)
{
  free(car);
}

