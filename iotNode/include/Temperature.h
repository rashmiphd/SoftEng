#ifndef TEMPERATURE_H
#define TEMPERATURE_H
#include "iotDataQueue.h"

class Temperature: public iotDataQueue
{
    public:
        void add_data(int s,std::string name);
        std::string retrieve_data();
private:
    int data;
    std::string type;
    //int ct=iotDataQueue::c;

    protected:


};

#endif // TEMPERATURE_H
