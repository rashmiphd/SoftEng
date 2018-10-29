#ifndef HUMIDITY_H
#define HUMIDITY_H
#include "iotDataQueue.h"
#include<string>

class Humidity: public iotDataQueue{
public:
    //Humidity();
    void add_data(int s,std::string name);
    std::string retrieve_data();
private:
    int data;
    std::string type;
    //int cn=iotDataQueue::c;
};

#endif // HUMIDITY_H
