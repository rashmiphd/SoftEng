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
    std::string humidRecord1;
    std::string humidRecord2;
    std::string tempRecord1;
    std::string tempRecord2;
    //Humidity h= new Humidity();

    Humidity h1,h2;
    Temperature t1,t2;


    h1.add_data(25,"Moist");
    h2.add_data(8,"Dry");

    humidRecord1=h1.retrieve_data();
    humidRecord2=h2.retrieve_data();

    cout<<"The first Humidity Recording is "<<humidRecord1<<endl;
    cout<<"The second Humidity Recording is "<<humidRecord2<<endl;

    t1.add_data(32,"High");
    t2.add_data(15,"Low");

    tempRecord1=t1.retrieve_data();
    tempRecord2=t2.retrieve_data();

    cout<<"The first temperature recording is " << tempRecord1<<endl;
    cout<<"The second temperature recording is " << tempRecord2<<endl;

    cout<<"The total number of recordings in the queue are "<<iotDataQueue::c<<endl;

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
