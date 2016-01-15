#ifndef PROCESSOR_H_INCLUDED
#define PROCESSOR_H_INCLUDED
#include<iostream>
#include<string>
#include<fstream>
#include "stack.h"
using namespace std;

const int ARG_ONE = 1;
const int ARG_TWO = 2;

struct vehicleTemp {

        string vehicleType;
        string license;
        int capacity;

};



void readFile(char* fileName[], startStack& autos, startStack& vans);
void loadVehicle(ifstream& vehicleFile, startStack& autos, startStack& vans);

#endif // PROCESSOR_H_INCLUDED
