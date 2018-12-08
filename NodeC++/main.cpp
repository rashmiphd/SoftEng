#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
//using namespace system;
//using namespace System::IO::Ports;
//using namespace System::Threading;


int main()
{
    HANDLE serialHandle;
    string data = "\n Hello \n";
    DWORD dwBytesWritten;
    DWORD  dwBytesRead;
    serialHandle = CreateFile("\\\\.\\COM1", GENERIC_READ | GENERIC_WRITE, 0, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
    //WriteFile()

    /*DCB serialParams = { 0 };
serialParams.DCBlength = sizeof(serialParams);

GetCommState(serialHandle, &serialParams);
serialParams.BaudRate = baudrate;
serialParams.ByteSize = byteSize;
serialParams.StopBits = stopBits;
serialParams.Parity = parity;
SetCommState(serialHandle, &serialParams);

// Set timeouts
COMMTIMEOUTS timeout = { 0 };
timeout.ReadIntervalTimeout = 50;
timeout.ReadTotalTimeoutConstant = 50;
timeout.ReadTotalTimeoutMultiplier = 50;
timeout.WriteTotalTimeoutConstant = 50;
timeout.WriteTotalTimeoutMultiplier = 10;

SetCommTimeouts(serialHandle, &timeout);
*/

    int isWritten = WriteFile(serialHandle, &data,(DWORD) sizeof(data), &dwBytesWritten, NULL);

    string temperature,humidity,wind,time,location;
    cout << "Enter sensor value(numeric) for: temperature" << endl;
    cin>>temperature;
    cout<<"Enter humidity value"<<endl;
    cin>>humidity;
    cout<<"Enter wind speed"<<endl;
    cin>>wind;
    cout<<"Enter time (hh:mm)"<<endl;
    cin>>time;
    cout<<"Enter location"<<endl;
    cin>>location;
    cout<<"Thank you! The information is successfully stored in a text document.You can access it via web.js file"<<endl;


    //ofstream myfile;
    fstream myfile("sensorlog.txt", fstream::out);

  myfile<< temperature<<","<<humidity<<","<<wind<<","<<time<<","<<location<<","<<"\n"<<endl;
  myfile.close();
    //system("pause");
    //system.IO.Ports;
    //findPorts();
    return 0;
}
