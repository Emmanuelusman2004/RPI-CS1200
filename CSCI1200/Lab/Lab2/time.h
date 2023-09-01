#include <iostream>

class Time {
private: 
/*
these are variables that we do not want users changing
*/
int hour;
int minute;
int second;

public:
/*
what the users will manipulate
*/
	//Constructors
	Time();
	Time(int hour, int minute, int second);
	Time(const Time &t1); //we use const so that the user cant cange it

	//Accessors
	int getHour() const;
	int getMinute() const;
	int getSecond() const;
	void setHour(int h);
	void setMinute(int m);
	void setSecond(int s);
	void PrintAMPM();
};

	bool isEarlierThan(const Time &t1, const Time &t2);