#include <iostream>
#include "Temperature.h"
using namespace std;

/*Temperature::Temperature()
{
    //ctor
}

Temperature::~Temperature()
{
    //dtor
}
*/
void Temperature::add_data(int s,string name)
{

   if (iotDataQueue::c<10)
   {
      data=s;
      type=name;
      iotDataQueue::c+=1;
      //cout<<"Temperature counter"<<c;

   }
   else
    {
      cout<<" the queue is full";
    }

}

std::string Temperature::retrieve_data()
{
    return type ;

}
