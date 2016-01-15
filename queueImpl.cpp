#include <iostream>
#include "queue.h"
#include <string>
using namespace std;


bool isEmptyQueue(startQueue& queueList){

     if (queueList.front == NULL) {

         return true;

     }

     else {

         return false;
     }
}




bool isFullQueue(startQueue& queueList){

  return false;

}


void createEmptyQueue(startQueue& queueList){

    customerQueue *temps;

    while (queueList.front != NULL){

        temps = queueList.front;
        queueList.front = queueList.front->nextNode;
        delete temps;

    }

    queueList.back = NULL;

}
void enQueue(startQueue& queueList, int numWaitingCustomer){

      customerQueue *customerData;

      customerData = new customerQueue;

      customerData->numWaiting = numWaitingCustomer;

      customerData->nextNode = NULL;

      if (queueList.front == NULL){

          queueList.front = customerData;
          queueList.back = customerData;
          queueList.queueCounter++;


      }

      else {

          queueList.back->nextNode = customerData;
          queueList.back = queueList.back->nextNode;
          queueList.queueCounter++;



      }



}
int deQueue(startQueue& queueList){

       int numCustomer;

       customerQueue *temps;


        if (!isEmptyQueue(queueList))    {


            numCustomer = queueList.front->numWaiting;
            temps = queueList.front;
            queueList.front = queueList.front->nextNode;
            queueList.queueCounter--;
            delete temps;

            return numCustomer;

            if (queueList.front == NULL){

                queueList.back = NULL;
            }


        }

        else {

            cout << "Error: Cannot Remove from empty queues!";

        }

         return 0;

}

void toStrings(startQueue& queueList){


int testNumber;
startQueue temp;

temp = queueList;

while(temp.front != NULL){

testNumber = temp.front->numWaiting;
cout << "My Number is " << testNumber << endl;
temp.front = temp.front->nextNode;

}


}
