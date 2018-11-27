#include <iostream>
#include "Humidity.h"
using namespace std;
#include<string>

void Humidity::add_data(int s,string name)
{

   if (iotDataQueue::c<10)
   {
      data=s;
      type=name;
      iotDataQueue::c+=1;
      //cout<<"humidity counter"<<c;

   }
   else
    {
      cout<<" the queue is full";
    }

}

std::string Humidity::retrieve_data()
{
    return type ;

}


