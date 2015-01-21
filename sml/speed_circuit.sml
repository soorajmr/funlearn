(*
   This is part of a set of examples to demonstrate features of functional programming.
   
   This file implements a tiny car race simulation in Standart ML. All cars are assumed
   to have uniform accelerations until they reach their maximum speed. Then on, they travel
   at constant speeds.

   Author: Sooraj Raveendran <soorajmr@slingmedia.com>
*)

(* 
   Types of cars. 
   Each car has acceleration and max speed associated with it 
 *)
datatype car = Jaguar of (real * real)
	     | Porche of (real * real)
	     | Audi of (real * real)

(* 
   min number in a list of real numbers 
 *)
val min_of_reals = foldl (fn(i, min) => Real.min(i, min)) Real.maxFinite

(* 
   position finder 
 *)
fun car_position_at_time car time_sec =
    let
	fun position_helper(a_mps2, sp_mps) =
	    let
		val accel_time_sec = sp_mps / a_mps2
	    in
		if time_sec > accel_time_sec
		then (a_mps2 * accel_time_sec * accel_time_sec) 
                         / 2.0 + sp_mps * (time_sec - accel_time_sec)
		else (a_mps2 * time_sec * time_sec) / 2.0
	    end
    in
	case car of
	    Jaguar(a, s) => ("Jaguar", position_helper(a, s) / 1000.0)
	  | Porche(a, s) => ("Porche", position_helper(a, s) / 1000.0)
	  | Audi(a, s) => ("Audi", position_helper(a, s) / 1000.0)
    end

(* 
   Time (in sec) taken to cover the given distance 
 *)
fun car_time_taken car distance_km =
    let
	fun time_helper(a_mps2, sp_mps) =
	    let
		val accel_time_sec = sp_mps / a_mps2
		val accel_dist_m = (a_mps2 * accel_time_sec * accel_time_sec) / 2.0
		val distance_m = distance_km * 1000.0
	    in
		if distance_m < accel_dist_m
		then Math.sqrt(2.0 * distance_m / a_mps2)
		else accel_time_sec + (distance_m - accel_dist_m) / sp_mps 
	    end
    in
	case car of
	    Jaguar(a, s) => time_helper(a, s)
	  | Porche(a, s) => time_helper(a, s)
	  | Audi(a, s) => time_helper(a, s)
    end


(* 
   find the position of all cars when the winner has just reached the 
   finishing point 
 *)
fun get_final_positions cars track_length_km =
 let
   val position_generators = map car_position_at_time cars
   val time_generators = map car_time_taken cars
   val winner_time_sec = (min_of_reals o map (fn f => f track_length_km)) time_generators
 in
   map (fn f => f winner_time_sec) position_generators
 end

(* ******************************** *)

(* List of cars and their properties *)
val cars = [Jaguar (8.0, 120.0),
	    Porche (9.0, 99.0),
	    Audi (6.0, 126.0)]

(* Run cars, run! *)
fun do_race track_length_km =
 let
     val final_positions = get_final_positions cars track_length_km
     fun format_position_string((car_name, position), str) =
	 String.concatWith " " [str, car_name, ": ", Real.toString(position), "Km\n"]
 in
     (* For now, we are interested only in the final positions of the cars.
        So, get the positions of the cars at the end of the race and print them *)
     print(foldl format_position_string "" final_positions)
 end
