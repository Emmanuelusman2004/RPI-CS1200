#include "time.h"		// library created by me for time
#include <iostream> 	// library for input and output

Time::Time()
{
	second = 0;
	minute = 0;
	hour = 0;
}

Time::Time(int aHour, int aMinute, int aSecond)
{
	hour = aHour;
	minute = aMinute;
	second = aSecond;
}

Time::Time(const Time &t1)
{
	hour = t1.getHour();
	minute = t1.getMinute();
	second = t1.getSecond();
}

int Time::getHour() const
{
	return hour;   // these return the specified values
}

int Time::getMinute() const
{
	return minute;
}

int Time::getSecond() const
{
	return second;
}

void Time::setHour(int h)
{
	hour = h; //all these are pass by reference i think
}

void Time::setMinute(int m)
{
	minute = m;
}

void Time::setSecond(int s)
{
	second = s;
}

void Time::PrintAMPM()
{
	int printHour = hour;
	int printMinute = minute;
	int printSecond = second;
	if (hour > 12)
	{
		printHour = printHour % 12;
	}
	if (printHour == 0)
	{
		printHour = 12;
	}
//std::cout<<hour<<std::endl;
	std::cout << printHour << (printMinute < 10 ? ":0" : ":") << printMinute << (printSecond < 10 ? ":0" : ":") << printSecond << " " << (hour >= 12 ? "pm" : "am") << std::endl;
}

//if t1 earlier, return true
bool isEarlierThan(const Time &t1, const Time &t2)
{
	return((t1.getHour() < t2.getHour()) ||
     ((t1.getHour() == t2.getHour()) && (t1.getMinute() < t2.getMinute())) ||
      ((t1.getHour() == t2.getHour()) && (t1.getMinute() == t2.getMinute()) && (t1.getSecond() < t2.getSecond())));
	
	}

