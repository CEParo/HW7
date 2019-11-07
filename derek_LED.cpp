#include "derek_LED.h"
#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<unistd.h>
#include<cstring>

using namespace std;


LED::LED()
{
  ostringstream s;
  s << LED_PATH;
  path = string(s.str());
}

void LED::writeLED(string filename, string value)
{
  ofstream fs;
  fs.open((path+filename).c_str());
  fs << value;
  fs.close();
}

void LED::removeTrigger()
{
  writeLED("/trigger", "none");
}

void LED::turnOn()
{
  cout << "Turning LED on." << endl;
  removeTrigger();
  writeLED("/brightness", "1");
}

void LED::turnOff()
{
  cout << "Turning LED off." << endl;
  removeTrigger();
  writeLED("/brightness", "0");
}

void LED::flash(string delayms = "50")
{
  cout << "Making LED flash." << endl;
  writeLED("/trigger", "timer");
  writeLED("/delay_on", delayms);
  writeLED("/delay_off", delayms);
}

void  LED::Blink()
{
  cout << "Amount of Blinks:" << endl;
  scanf("%i", &number);
  cout << "Blinking the LED " << number << "  times" << endl;
  int y;
  for (y = 0; y < number; y++)
  {
    writeLED("/brightness", "1");
    sleep(1);
    writeLED("/brightness", "0");
    sleep(1);
  }
}

void LED::outputState()
{
  ifstream fs;
  fs.open((path + "/trigger").c_str());
  string line;
  while(getline(fs,line)) 
     cout << line << endl;
  fs.close();
}

LED::~LED()
{
  cout << "destroying the LED with path: " << path << endl;
}
