/*
 * Race simulation program - Car interface
 * This is a part of examples to illustrate functional programming style
 * Author: Sooraj Raveendran <soorajmr@slingmedia.com>
 */

/* opaque handle for the callers to keep track of a CAR object */
typedef struct CAR_ CAR;

/*
 * Creates a CAR object.
 * Params: Car name, maximum speed in Kmph, acceleration in m/sec^2 
 * Return: CAR object
 */
CAR *car_create(char *name, double speed_kmph,
                double accelaration_mps2);

/*
 * Gets the position of the car after a given time interval from start
 * Params: Car object
 *         Time offset from start in sec
 * Return: Distance travelled from start in Km
 */
double car_get_position_km(CAR *car, double time_from_start_sec);

/* 
 * Time taken to cover the given distance from the starting point 
 * Params: Car object
 *         Distance from start in Km
 *
 * Return: time taken to cover the distnace (in sec)
 * */
double car_get_travel_time_sec(CAR *car, double distance_km);

/* 
 * Getter for car name
 * */
char *car_get_name(CAR *car);

/*
 * Destroys a CAR object.
 * Param: CAR object
 * Return: Nothing
 */
void car_destroy(CAR *car);

