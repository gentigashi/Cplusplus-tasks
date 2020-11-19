//Exercise 06A


#pragma once
#ifndef TIME_H_INCLUDED
#define TIME_H_INCLUDED
#include <iostream>

using namespace std;

class Time

{
    
    friend istream &operator>>(istream &in, Time &t);
    friend ostream &operator<<(ostream &out, const Time &t);
    
    
public: // access specifier (accessible from outside class)
    
    void read(const char* number);
    bool lessThan(Time less_than);
    Time subtract(Time lss);
    //Time add(Time ups);
    void display();

    
private: // cannot be accessed nor viewed
    
    int hour;
    int minute;
    
    
    public:
Time () : hour(0),minute(00){}
Time operator + (const Time&);
Time operator - (const Time&);
bool operator < (const Time&);
bool operator>(const Time&);
bool operator==(const Time&);
Time operator++(int); //Postposition++, next second
Time & operator +(); // pre + +, next second
    
};

#endif
