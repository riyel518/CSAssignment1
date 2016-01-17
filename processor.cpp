#include<iostream>
#include<string>
#include<fstream>
#include "processor.h"
#include "stack.h"
#include "queue.h"
using namespace std;

void readFile(char* fileName[], startStack& autos, startStack& vans, startQueue& employees){

  ifstream vehicleInput;
  ifstream checkoutInput;



    if((fileName[ARG_ONE] != NULL) && (fileName[ARG_TWO] != NULL)) {



       vehicleInput.open(fileName[ARG_ONE]);
       checkoutInput.open(fileName[ARG_TWO]);
       if((vehicleInput.is_open()) && (checkoutInput.is_open()) ){


        loadVehicle(vehicleInput,  autos,  vans);

        checkOutVehicle(checkoutInput,  autos,  vans, employees);



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

    if(temp.vehicleType == AUTO_CODE){

        cout << endl << "Placing " << temp.license << " into automobile area. " << endl;
        push(autos, temp.vehicleType, temp.license, temp.capacity);

        }


    else{


        cout << endl << "Placing " << temp.license << " into van area. " << endl;
        push(vans, temp.vehicleType, temp.license, temp.capacity);

    }

    }while(!vehicleFile.eof());

cout << endl <<"---------------------------------------------- ";
cout << endl << "Parking lot status: " << endl;
cout << "   " <<  getsStackCount(autos) << " automobile available" << endl;
cout << "   " << getsStackCount(vans) << " vans available " << endl;
cout << "----------------------------------------------" << endl;

vehicleFile.close();

}


void checkOutVehicle(ifstream& checkOutFile, startStack& autos, startStack& vans, startQueue& numPaxWaiting) {

int numEmployee;
string checkOut;
vehicleTemp vehicleReturn;
int employeeWaiting;
int stillWaiting;

createEmptyQueue(numPaxWaiting);

  do{

      checkOutFile >> checkOut;

      if (checkOut == "C"){

      checkOutFile >> numEmployee;
      cout << endl <<  "For " << numEmployee << " employees in group, vehicles check out are: " << endl;

      while(numEmployee > 0){

            if((numEmployee > 0) && (numEmployee < 5)){

                autoCheckOut(numEmployee, autos, numPaxWaiting);
            } // end of if

            else {

                  vanCheckOut(numEmployee, vans, numPaxWaiting);

             }// end of else

        } //end of while loop

    }// end of if checkout


  else {

    checkOutFile >> vehicleReturn.vehicleType >> vehicleReturn.license >> vehicleReturn.capacity;

    if(vehicleReturn.vehicleType == AUTO_CODE){
      cout << endl << "Returning " << vehicleReturn.license << " to automobile area";

        if(!isEmptyQueue(numPaxWaiting)){
          employeeWaiting = deQueue(numPaxWaiting);
          cout << endl << endl << "For " << employeeWaiting << " employees waiting, vehicles checked out are: ";
          cout << endl << "Automobile " << vehicleReturn.license << " hold " << vehicleReturn.capacity << endl;
          stillWaiting = employeeWaiting - vehicleReturn.capacity;
            if(stillWaiting > 0){
            cout << endl << stillWaiting << " employees still waiting for a vehicle" << endl;
            enQueue(numPaxWaiting, stillWaiting);
          } // if there are still left waiting
      }// end if there is waiting

      else {

           push(autos, vehicleReturn.vehicleType, vehicleReturn.license, vehicleReturn.capacity);
      }

    }//end of auto return

  else{

    cout << endl << "Returning " << vehicleReturn.license << " to van area";

      if(!isEmptyQueue(numPaxWaiting)){
        employeeWaiting = deQueue(numPaxWaiting);
        cout << endl << endl << "For " << employeeWaiting << " employees waiting, vehicles checked out are: ";
        cout << endl << "Van " << vehicleReturn.license << " hold " << vehicleReturn.capacity << endl;
        stillWaiting = employeeWaiting - vehicleReturn.capacity;
          if(stillWaiting > 0){
          cout << endl << stillWaiting << " employees still waiting for a vehicle" << endl;
          enQueue(numPaxWaiting, stillWaiting);
        } // if there are still left waiting
    }// end if there is waiting

    else {

         push(vans, vehicleReturn.vehicleType, vehicleReturn.license, vehicleReturn.capacity);
    } // end of else

   } // end of else
  }
}while(!checkOutFile.eof());

    checkOutFile.close();

}


void autoCheckOut(int& numPax, startStack& autos, startQueue& numPaxWaiting){

int groupPaxNum;
string tempLicense;


      if(isEmptyStack(autos)) {

          enQueue(numPaxWaiting, numPax);
          cout << endl << "No available vehicle for this group: ";
          cout << endl << numPax << " employees waiting for a vehicle" << endl;
          numPax = 0;
      }

     else {

        pop(autos, tempLicense, groupPaxNum);

         cout << "Auto " << tempLicense  << " holds " << groupPaxNum << endl;
         numPax = numPax - 4;

     }


}// end autoCheck function




void vanCheckOut(int& numPax, startStack& vans, startQueue& numPaxWaiting){



  int groupPaxNums;
  string tempLicense;


        if(isEmptyStack(vans)) {

            enQueue(numPaxWaiting, numPax);
            cout << endl << "No available vehicle for this group: ";
            cout << endl << numPax << " employees waiting for a vehicle" << endl;
            numPax = 0;

        } // end of if stack is empty

       else {

          pop(vans,  tempLicense, groupPaxNums);

           cout << "Van " << tempLicense << " holds " << groupPaxNums << endl;
           numPax = numPax - 8;

       } // end of else


  }// end vanCheck function
