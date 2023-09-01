// =======================================================================
//
// IMPORTANT NOTE: You should edit this file
//                 This file is #include'd from traincar.h and main.cpp
//
// =======================================================================
//
// There are a number of additional functions used in main.cpp that
// you need to declare and implement.  Study main.cpp and the provided
// output to determine the arguments, return type, and overall
// behavior.
//
// Add all required additional function prototypes here
// (you may also add your own helper function prototypes here too)
//
// Implement these functions in "traincar.cpp"
//
#ifndef __traincar_prototypes_h_
#define __traincar_prototypes_h_

TrainCar* PopFront(TrainCar* &head);

TrainCar* PopBack(TrainCar* &head);

void PushFront(TrainCar* &head, TrainCar* car);

void PushBack(TrainCar* &head, TrainCar* car);

void DeleteAllCars(TrainCar* &head);

void TotalWeightAndCountCars(TrainCar* train, int &total_weight, int &num_engines, int &num_freight_cars, int &num_passenger_cars, int &num_dining_cars, int &num_sleeping_cars);

float CalculateSpeed(TrainCar* head);

float AverageDistanceToDiningCar(TrainCar* train);

int ClosestEngineToSleeperCar(TrainCar* train);

void Separate(TrainCar* &train1,TrainCar* &train2,TrainCar* &train3);

std::vector<TrainCar*> ShipFreight(TrainCar* &all_engines, TrainCar* &all_Freight, int speed, int max_cars);



#endif