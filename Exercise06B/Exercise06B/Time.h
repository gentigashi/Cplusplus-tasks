//exercise 6B

#pragma once
#ifndef TIME_H_INCLUDED
#define TIME_H_INCLUDED
#include <iostream>

using namespace std;

class Time
{
    friend istream& operator>>(istream& is, Time& output);
public:
    Time(int hh = 0, int mm = 0); 
    Time& dst();
    string to_str();
private:
    int hour;
    int min;
};

#endif

