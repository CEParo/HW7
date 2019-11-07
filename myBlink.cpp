#include"derek_LED.h"
#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<unistd.h>
#include<cstring>

using namespace std;

int main(int argc, char* argv[])
{
  if (argc!=2)
   {
     cout << "Usage is makeLEDs <command>" << endl;
     cout << "    command is one of: on, off, flash, or status" << endl;
     cout << " e.g. makeLEDs flash" << endl;
   }

  cout << "Starting the makeLEDs program" << endl;
  string cmd(argv[1]);
  LED leds;
   if (cmd == "on") 
    leds.turnOn();
   else if (cmd == "off")leds.turnOff();
   else if (cmd == "flash")leds.flash("100");
   else if (cmd == "status")leds.outputState();
   else if (cmd == "blink")leds.Blink();
   else 
     cout << "Invalid command!" << endl;
   
  cout << "Finished the makeLEDs program" << endl;
  return 0;
}
