#include <iostream>
#include<string>
#include "iotDataQueue.h"
#include"Humidity.h"
#include"Temperature.h"


using namespace std;

int main()
{
   // iotDataQueue temperature, humidity; //create two queue objects
    //iotDataQueue obj1=iotDataQueue(10,'Temp')
    std::string name;
    std::string name2;
    //Humidity h= new Humidity();

    Humidity hh,h2;
    Temperature t;


    hh.add_data(34,"hello");
    h2.add_data(23,"world");

    name=hh.retrieve_data();
    cout<<"The Humidity Recording is "<<name<<endl;

    t.add_data(23,"temp");
    name2=t.retrieve_data();
    cout<<"The temp recording is " << name2<<endl;

    cout<<"The total number of recordings are"<<iotDataQueue::c<<endl;

    //temperature.init();
    //humidity.init();

    //temperature.qput(10);
    //humidity.qput(19);

    //temperature.qput(20);
    //humidity.qput(1);
    //this is a comment

    //cout << "Contents of Temperature queue: ";

    //cout << temperature.qget() << " ";
   // cout << temperature.qget() << "\n";

   // cout << "Contents of Humidity queue: ";
   // cout << humidity.qget() << " ";
   // cout << humidity.qget() << "\n";

    return 0;
}
