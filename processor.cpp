#include<iostream>
#include<string>
#include<fstream>
#include "processor.h"
#include "stack.h"
using namespace std;

void readFile(char* fileName[], startStack& autos, startStack& vans){

  ifstream vehicleInput;
  ifstream checkoutInput;
  int y;


    if((fileName[ARG_ONE] != NULL) && (fileName[ARG_TWO] != NULL)) {



       vehicleInput.open(fileName[ARG_ONE]);
       checkoutInput.open(fileName[ARG_TWO]);
       if((vehicleInput.is_open()) && (checkoutInput.is_open()) ){


        loadVehicle(vehicleInput,  autos,  vans);

            do {

                 checkoutInput >> y;
                 cout << y << endl;




           }while(!checkoutInput.eof());
           checkoutInput.close();



       }// end of vehicleinput

       else{

          cout << " Error no file to open! " << endl;
          vehicleInput.close();


       }//end of else

    } // end null condition

    else {


        cout << endl << "Error one or both file does not exits" << endl;

    } // end of else statment


} // end of function

void loadVehicle(ifstream& vehicleFile, startStack& autos, startStack& vans){


createEmptyStack(autos);
createEmptyStack(vans);
vehicleTemp temp;


do{
    vehicleFile >> temp.vehicleType >> temp.license >> temp.capacity;

    if(temp.vehicleType == "A"){

        cout << endl << "Placing " << temp.license << " into automobile area. " << endl;
        push(autos, temp.vehicleType, temp.license, temp.capacity);

        }


    else{


        cout << endl << "Placing " << temp.license << " into van area. " << endl;
        push(vans, temp.vehicleType, temp.license, temp.capacity);

    }

    }while(!vehicleFile.eof());

vehicleFile.close();

}
