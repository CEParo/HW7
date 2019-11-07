#include<iostream>
#include<string>
#include<fstream>
#include<cstring>

using namespace std;
using std::string;

#define LED_PATH "/sys/class/leds/beaglebone:green:usr0"

class LED
{
	private:
	  string path;
	  int number;
	  virtual void writeLED(string filename, string value);
	  virtual void removeTrigger();
	public:
	  LED();
	  virtual void turnOn();
	  virtual void turnOff();
	  virtual void flash(string delayms);
	  virtual void Blink();
	  virtual void outputState();
	  virtual ~LED();
};
