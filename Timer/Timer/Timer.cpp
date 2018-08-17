// Timer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <ctime>
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::string;
using std::to_string;

void DisplayUsage(); // UI and display explaining the desired input from the user
void outputReadableTime(int num);  // converting secs to mins to hours for the user
int getTargetTime(); // how long it will run
void targetHit();  // close out

void main()
{
	int targetTime = getTargetTime();
	time_t curTime = time(0);
	int i = 0;
	while (i < targetTime) {
		if (time(0) > curTime) {
			curTime = time(0);
			i++;
			DisplayUsage();
			outputReadableTime(i);
		}
	}
	targetHit();
	system("pause");
}

int getTargetTime() {
	int targetTime = 0;
	int holding;
	cout << "Enter your desired alarm time hours, minutes, and seconds\n";
	cout << "\tHours : ";
	cin >> holding;
	targetTime += holding * 3600;
	cout << "\tMinutes : ";
	cin >> holding;
	targetTime += holding * 60;
	cout << "\tSeconds : ";
	cin >> holding;
	targetTime += holding;
	return targetTime;
}

void DisplayUsage() {   //  UI display only
	system("cls");
	cout << "Usage: \n";
	cout << "\tCounts the passage of time... \n\tpress ctrl + C to break execution\n";  
}

void outputReadableTime(int num) {
	string output = "\n";
	if (num >= 3600) {
		output += to_string((int)floor(num / 3600)) + " Hours\n";   // converting to hours
		num %= 3600;
	}
	if (num >= 60) {
		output += to_string((int)floor(num / 60)) + " Minutes\n";   // converting to minutes
		num %= 60;
	}
	if (num > 0) {
		output += to_string(num) + " Seconds\n";   // displaying to seconds
	}
	cout << output;
}

void targetHit() {
	system("cls");
	cout << "TIMER HAS RUNG!!!\n\n\t";
}