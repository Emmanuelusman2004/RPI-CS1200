// =======================================================================
//
// IMPORTANT NOTE: You should edit this file
//
// =======================================================================

#include <iostream>
#include <iomanip>
#include <string>
#include <cassert>
#include <cmath>
#include <cstdlib>
#include <vector>

#include "traincar.h"

// =======================================================================
// =======================================================================
//
//  HERE'S WHERE YOU SHOULD IMPLEMENT THE FUNCTIONS YOU PROTOTYPED IN
//  THE "traincar_prototypes.h" FILE.
//

TrainCar* PopFront(TrainCar* &head) {
    if (head == NULL) {
        return NULL;
    }
    TrainCar * ReturnEngine = head;
    head = head->next;
    if (head != NULL) {
        head->prev = NULL;
    }
    ReturnEngine->next = NULL;
    return ReturnEngine;    
}

TrainCar* PopBack(TrainCar* &head) {
    if (head == NULL) {
        return NULL;
    }
    TrainCar* p = head;
    while (p->next != NULL) {
        p = p->next;
    }
    TrainCar* k = p->prev;
    if (k != NULL) {
        k->next = NULL;
    } else {
        head = NULL;
    }
    p->prev = NULL;
    return p;
}



void PushFront(TrainCar* &head, TrainCar* car) {
    if (head == NULL) {
        head = car;
    }
    else {
        TrainCar* front = head;
        head->prev = car;
        car->next = head;
        head = front;
    }
}

void PushBack(TrainCar* &head, TrainCar* car) {
    if (head == NULL) {
        head = car;
    } 
    else {
        TrainCar* last = head;
        while (last->next != NULL) {
            last = last->next;
        }

        last->next = car;
        car->prev = last;
    }
}


void DeleteAllCars(TrainCar* &head) {
    TrainCar* p = head;
    while (p != NULL) { 
        TrainCar* temp = p;
        p = p->next;
        delete temp;
    }
    head = NULL;
    delete p;
}


float CalculateSpeed(TrainCar* head) {
    float speed;
    int num_engines = 0;
    int total_weight = 0;
    TrainCar* p = head;
    while (p != NULL) { //get the total weight
        if (p->isEngine()) {
            num_engines+=1;
            total_weight+=150;
        }
        else if (p->isFreightCar()) {
            total_weight+=p->getWeight();
        }
        else {
            total_weight+=50;
        }
        p = p->next;
    }
    //calculate speed
    speed = ((float(num_engines) * 3000) * 550 * 3600) / (20 * 2 * 5280 * float(total_weight));
    return speed;
}

int ClosestEngineToSleeperCar(TrainCar* train) {
    TrainCar* p = train;  //iterate to engine
    while (p->isEngine()) {
        p = p->next;
    }
    int closest = 1;
    while (p != NULL) { //find sleeper car
        if (p->isSleepingCar()) {
            break;
        }
        else {
            closest+=1;
        }
        p = p->next;
    }
    return closest;
}

void TotalWeightAndCountCars(TrainCar* train, int &total_weight, int &num_engines, int &num_freight_cars, int &num_passenger_cars, int &num_dining_cars, int &num_sleeping_cars) {
    TrainCar* p = train;
    total_weight = 0;
    num_engines = 0;
    num_freight_cars = 0;
    num_passenger_cars = 0;
    num_dining_cars = 0;
    num_sleeping_cars = 0;
    while (p != NULL) { //initialize all values
        if (p->isEngine()) {
            num_engines+=1;
        }
        else if (p->isFreightCar()) {
            num_freight_cars+=1;

        }
        else if(p->isDiningCar()){
            num_dining_cars+=1;
        }
        else if (p->isPassengerCar()) {
            num_passenger_cars+=1;
        }
        else if (p->isSleepingCar()) {
            num_sleeping_cars+=1;
        }
        total_weight += p->getWeight();
        p = p->next;
    }
    



}

float AverageDistanceToDiningCar(TrainCar* train) {
    TrainCar* p = train;
    TrainCar* j = train;
    int counter = 0;
    int total_dist = 0;
    int total_passenger_cars = 0;
    //find the distances in the front of train to dining car
    while (p != NULL) { 
        if (p->isPassengerCar()) { //if its a passenger car we set out looking for dining car
            while (j->isDiningCar() == false) {
                if (j->isEngine() || j->isFreightCar()) {
                    return -1; //this makes sure that we set to inf if you cant pass through to dining car
                }
                counter+=1;
                j = j->next;
            }
            total_dist+=counter;
            counter = 0;
            total_passenger_cars+=1;
            j = p;
        }
        if (p->isDiningCar()) { //break if we run into the dining car in the first half
            break;
        }
        p = p->next;
        j = j->next;

    }
    p = train;
    j = train;
    while (p->next != NULL) {
        p = p->next;
        j = j->next;
    }
    //find the distances to the dining car from the back half of the train
    while (p != NULL) {
        if (p->isPassengerCar()) {
            while (j->isDiningCar() == false) {
                if (j->isEngine() || j->isFreightCar()) {
                return -1;
                }
                counter+=1;
                j = j->prev;
            }
            total_dist+=counter;
            counter = 0;
            total_passenger_cars+=1;
            j = p;
        }
        if  (p->isDiningCar()) {
            break;
        }
        p = p->prev;
        j = j->prev;
    }
    float averageDist = float(total_dist) / float(total_passenger_cars); //divide distances by passenger cars.
    return averageDist;
}

void Separate(TrainCar* &train1, TrainCar* &train2, TrainCar* &train3) {
    //this was  my attempt at making it full proof

    // int countEng = 0;
    // int countCars = 0;
    // train2 = NULL;
    // train3 = NULL;
    // TrainCar* p = train1;
    // while (p!=NULL){
    //     if (p->isEngine()) {
    //         countEng+=1;
    //     } 
    //     else {
    //         countCars+=1;
    //     }
    //     p = p->next;
    // }
    // int countEngReq = countEng / 2;
    // int countCarsReq = countCars / 2;
    // countEng = 0;
    // countCars = 0;
    // p = train1;
    // while (countCarsReq < countCars && countEngReq < countEng) {
    //     if (p->getWeight() == 150) {
    //         countEng +=1;
    //         PushBack(train2,PopFront(train1));
    //     }
    //     else {
    //         countCars +=1;
    //         PushBack(train2,PopFront(train1));
    //     }
    // }

    // if (countCars >= countCarsReq && countEng >=countEngReq) {
    //     while (p!=NULL) {
    //         PushBack(train3,PopFront(train1));
    //     }
    // }
    // else if (countCars >= countCarsReq && countEng < countEngReq) {
    //     while (countEngReq > countEng) {
    //         if (p->isEngine()) {
    //             PushBack(train2,Pop(train1,p)); //check if this works
    //             countEng+=1;
    //         } 
    //         p = p->next;
    //     }
    //     //pushback rest of train1
    //     while (train1!=NULL) {
    //         PushBack(train3, PopFront(train1));
    //     }
    // }
    // else if (countCars < countCarsReq && countEng < countEngReq) {
    //     while (countCars < countCarsReq && (p!=NULL)) {
    //         if (p->isEngine() == false) {
    //             PushBack(train2,Pop(train1,p)); //check if this works
    //             countCars+=1;
    //         } 
    //         p = p->next;
    //     }
    //     while (train1!=NULL) {
    //         PushBack(train3, PopFront(train1));
    //     }
    // }

    //this was the code I used to just splitting it in half for points to try and get a late day
    
    
    
    int count = 0;  
    TrainCar* p = train1; 
    while (p != NULL) { //iterate to back of list to count all cars
        count++;
        p = p->next;
    }
    //split car into two to separate
    int half = count / 2; //here we cast to int and leftover will be pushed back to train3
    p = train1;
    for (int i = 0; i < half; i++) {
        p = p->next;    
    }
    train2 = train1; //we set the pointer to where the halfway point would be
    train1 = train1->prev;  
    p->prev->next = NULL;
    p->prev = NULL;
    train3 = p; //makes the head the second half of train 1;
    }

 std::vector<TrainCar*> ShipFreight(TrainCar* &all_engines, TrainCar* &all_Freight, int speed, int max_cars) {
    std::vector<TrainCar*>v;
    int countcars = 0;
    TrainCar* newtrain = NULL;
    TrainCar* p = NULL;

    while (all_Freight != NULL) { //makes sure we reach the end of freight
        //add engine
        if (all_engines == NULL) { //if no more engines just exit function
            break;
        }
        PushBack(newtrain, PopFront(all_engines)); //PopFront returns the node popped at the front of engines
        countcars+=1;
        while ((CalculateSpeed(newtrain) >= speed) && (countcars < max_cars) ) {
            PushBack(newtrain, PopFront(all_Freight));
            countcars+=1;
        }
        if (countcars >= max_cars) { //this was the condition i spoke about in the read me but it does not work...
             if (CalculateSpeed(newtrain)<speed){
                //get the extra car that was pushed back it front of freight trains
                PushFront(all_Freight,PopBack(newtrain));

                p = newtrain;
                v.push_back(p); //pushback into vector
                newtrain = NULL;
                p= NULL;
                countcars=0;
             }
            else {
            p = newtrain;
            v.push_back(p); //pushback into vector
            newtrain = NULL;
            p = NULL;
            countcars=0;
            }
        }
        

    }
    if (newtrain != NULL) {  //pushback rest of last train intto vector
         v.push_back(newtrain);
     }
    return v;
}




