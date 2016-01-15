//*********************************************************************
// CODE FILENAME: stack.h
// DESCRIPTION: A stack header file that specify the data structure and the function
//  prototypes
// CLASS/TERM: CS 372/ 16SP 8 Week 1
// DESIGNER:       Christopher R. Francisco
// FUNCTIONS:   createEmptyStack - initialize stack to empty state
//                             push - push the data to the stack
//                             pop -  pop the data on the top of stack
//                             isEmptyStack - check of stack is empty
//                             isFullStack - check of the stack is full
//**********************************************************************



#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
#include <string>
#include <iostream>
using namespace std;

const int COUNTERNONE = 0;        //counter to initialize to zero


struct vehicle {                        //struct data of vehicle

	string vehicleType;                  //Type of vehicle (Auto or Van)
	string vehicleLicencse;            // Six character license plate
	int vechicleCapacity;              //Number of PAX in the vehicle
	vehicle *nextVehicle;	          //Pointer to the next vehicle
};



struct startStack {                  // struct data for stack

           vehicle *topNode;           //Pointer to the top of vehicle in the stack
            int counter;                     //Counter of how many vehicle in the stack

};



//*********************************************************************
// FUNCTION: createEmptyStack
// DESCRIPTION: Description of what the function does
// INPUT:
// Parameters: Name and description of each input parameter
// File: Description of data read from file
// OUTPUT:
// Return Val: Name (if it has one) and description of data
// returned by a function
// Parameters: Name and description of the output parameters
// File: Description of data written to file
// CALLS TO: List of user-defined functions called (names only)
//**********************************************************************

void createEmptyStack(startStack& topOfStack);

//*********************************************************************
// FUNCTION: push
// DESCRIPTION: Description of what the function does
// INPUT:
// Parameters: Name and description of each input parameter
// File: Description of data read from file
// OUTPUT:
// Return Val: Name (if it has one) and description of data
// returned by a function
// Parameters: Name and description of the output parameters
// File: Description of data written to file
// CALLS TO: List of user-defined functions called (names only)
//**********************************************************************

void push(startStack& topOfStack, string vehicleType,  string vehicleLicense, int numberPax);

//*********************************************************************
// FUNCTION: pop
// DESCRIPTION: Description of what the function does
// INPUT:
// Parameters: Name and description of each input parameter
// File: Description of data read from file
// OUTPUT:
// Return Val: Name (if it has one) and description of data
// returned by a function
// Parameters: Name and description of the output parameters
// File: Description of data written to file
// CALLS TO: List of user-defined functions called (names only)
//**********************************************************************

void pop(startStack& topOfStack);

//*********************************************************************
// FUNCTION: isEmptyStack
// DESCRIPTION: Description of what the function does
// INPUT:
// Parameters: Name and description of each input parameter
// File: Description of data read from file
// OUTPUT:
// Return Val: Name (if it has one) and description of data
// returned by a function
// Parameters: Name and description of the output parameters
// File: Description of data written to file
// CALLS TO: List of user-defined functions called (names only)
//**********************************************************************

bool isEmptyStack(startStack topOfStack);

//*********************************************************************
// FUNCTION: isFullStack
// DESCRIPTION: Description of what the function does
// INPUT:
// Parameters: Name and description of each input parameter
// File: Description of data read from file
// OUTPUT:
// Return Val: Name (if it has one) and description of data
// returned by a function
// Parameters: Name and description of the output parameters
// File: Description of data written to file
// CALLS TO: List of user-defined functions called (names only)
//**********************************************************************

bool isFullStack();

//*********************************************************************
// FUNCTION: getStackCount
// DESCRIPTION: Description of what the function does
// INPUT:
// Parameters: Name and description of each input parameter
// File: Description of data read from file
// OUTPUT:
// Return Val: Name (if it has one) and description of data
// returned by a function
// Parameters: Name and description of the output parameters
// File: Description of data written to file
// CALLS TO: List of user-defined functions called (names only)
//**********************************************************************

int getsStackCount(startStack topOfStack);


//*********************************************************************
// FUNCTION: toString
// DESCRIPTION: Description of what the function does
// INPUT:
// Parameters: Name and description of each input parameter
// File: Description of data read from file
// OUTPUT:
// Return Val: Name (if it has one) and description of data
// returned by a function
// Parameters: Name and description of the output parameters
// File: Description of data written to file
// CALLS TO: List of user-defined functions called (names only)
//**********************************************************************

void toString (startStack topOfStack);





#endif // STACK_H_INCLUDED
