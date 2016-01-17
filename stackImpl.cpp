//*********************************************************************
// CODE FILENAME: stackImpl.cpp
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


#include <iostream>
#include "stack.h"
#include <string>
using namespace std;


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

void createEmptyStack(startStack& topOfStack){

     vehicle *temps;              //temporary pointer variable to delete node in the stack

    //If the stack is not empty, loop to
   //delete node in the stack
     while (topOfStack.topNode != NULL) {

         temps = topOfStack.topNode;          			  //assigned the node on the top of stuck to temporary
         topOfStack.topNode = topOfStack.topNode->nextVehicle;	 //go to the next node of the stack and assigned it to the top of stack
         delete temps;				                  //delete the temporary node

     } //end of loops

    topOfStack.counter = 0;

} //end of functions

//*********************************************************************
// FUNCTION: push
// DESCRIPTION: Description of what the function does
// INPUT:
// Parameters: Name and description of each input parameter
// File: Description of data read from file
// OUTPUT:
// Return Val:  Void - It does nto return any thing
// Parameters: N/A
// File:  N/A
// CALLS TO: N/A
//**********************************************************************

void push(startStack& topOfStack, string vehicleType,  string vehicleLicense, int numberPax) {

            vehicle *vehicles;             			 //Create a pointer vehicles to create new node

            vehicles = new  vehicle;       		//Allocate a new vehicle for stack

            vehicles->vehicleType =   vehicleType;            	 //add the vechileType of data to rec
            vehicles->vehicleLicencse = vehicleLicense;      	//add the License to rec
            vehicles->vechicleCapacity = numberPax;        	//add the capcity the the vechile hold
            vehicles->nextVehicle = topOfStack.topNode;  	//point the vechile pointer to the top of the node pointer

            topOfStack.topNode = vehicles;              	//assigne the newly create node to the top of the stuck
            topOfStack.counter++;                            	//increment the counters


}

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


void pop(startStack& topOfStack, string& tempLicense, int& numAvail) {


  	 vehicle *temp;            //pointer to deallocate a pop node in stack


 	 //call the function isEmptyStack() to find if the stack is empty
	 // of not
   	if(isEmptyStack(topOfStack)){

   		cout << "Stack is empty! Nothing to remove" << endl;

  	 } // end of if

 	 else {


               		 temp = topOfStack.topNode;           		          // assigned the top of the node to the temp pointer
               		 topOfStack.topNode = topOfStack.topNode->nextVehicle;          //advance or assigned the next pointer to the top of the stack
                   tempLicense = temp->vehicleLicencse;
                   numAvail = temp->vechicleCapacity;
              		 delete temp;                                                                                  //deallocate memory
                   topOfStack.counter--;                                                                   //decrement the counter


       	 } //end of else statment

   }  //end of pop



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

bool isEmptyStack(startStack topOfStack){

    if (topOfStack.topNode == NULL)

        return true;

    else

        return false;


}


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

bool isFullStack(){

    return false;
}


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



int getsStackCount(startStack topOfStack){

      return topOfStack.counter;
}


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


void toString (startStack topOfStack){

      startStack temp;
      string myCapcity;
      string code;

      temp = topOfStack;

   while(temp.topNode != NULL) {

       myCapcity = temp.topNode->vehicleLicencse;
       code = temp.topNode->vehicleType;
       cout << "vehicle type is " << myCapcity <<  "  code is " << code << endl;
       temp.topNode = temp.topNode->nextVehicle;


   }




}
