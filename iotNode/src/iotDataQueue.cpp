#include <iostream>
#include<string>
#include "iotDataQueue.h"

using namespace std;
//public int counter=0;
//public char type;

/*iotDataQueue::iotDataQueue(int s, char type)
{
    //this.data=s;
    //this.type=type
}
*/
//iotDataQueue::~iotDataQueue()
//{
    //dtor
//}


//void iotDataQueue::init()
//{
    //Datacount= 0;
//}

//initialise the queue


int iotDataQueue::c =0;

void iotDataQueue::qput(int i)
{
    if(sloc==100){
        cout << "queue is full. \n";
        return;
    }
    sloc++;
    q[sloc] = i;
}

//get an integer from the queue
int iotDataQueue::qget()
{
    if(rloc == sloc){
        cout << "queue underflow. \n";
        return 0;
    }
    rloc++;
    return q[rloc];
}


