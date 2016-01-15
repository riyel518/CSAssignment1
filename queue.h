#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

struct customerQueue {

    int numWaiting;
    customerQueue *nextNode;

};

struct startQueue {

     customerQueue *front;
     customerQueue *back;
     int queueCounter;


};


bool isEmptyQueue(startQueue& queueList);
bool isFullQueue(startQueue& queueList);
void createEmptyQueue(startQueue& queueList);
void enQueue(startQueue& queueList, int numWaitingCustomer);
int deQueue(startQueue& queueList);
void toStrings(startQueue& queueList);


#endif // QUEUE_H_INCLUDED
