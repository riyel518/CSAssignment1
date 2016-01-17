#ifndef PROCESSOR_H_INCLUDED
#define PROCESSOR_H_INCLUDED
#include<iostream>
#include<string>
#include<fstream>
#include "stack.h"
#include "queue.h"
using namespace std;

const int ARG_ONE = 1;
const int ARG_TWO = 2;
const string AUTO_CODE = "A";

struct vehicleTemp {

        string vehicleType;
        string license;
        int capacity;

};



void readFile(char* fileName[], startStack& autos, startStack& vans, startQueue& employees);
void loadVehicle(ifstream& vehicleFile, startStack& autos, startStack& vans);
void checkOutVehicle(ifstream& checkOutFile, startStack& autos, startStack& vans, startQueue& numPaxWaiting);
void autoCheckOut(int& numPax, startStack& autos, startQueue& numPaxWaiting);
void vanCheckOut(int& numPax, startStack& vans, startQueue& numPaxWaiting);


#endif // PROCESSOR_H_INCLUDED
