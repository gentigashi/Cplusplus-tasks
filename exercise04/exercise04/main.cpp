//
//  main.cpp
//  exercise04
//
//  Created by Genti Gashi on 5.11.2020.
//  Copyright © 2020 Genti Gashi. All rights reserved.
//

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>



using namespace std;

class Time

{
    
public: // access specifier (accessible from outside class)
    
    void read(const char* number);
    bool lessThan(Time less_than);
    Time subtract(Time lss);
    void display();

    
private: // cannot be accessed nor viewed
    
    int hour;
    int minute;
    
};

int main() { //Exercise4 preset main function
    Time time1, time2, duration;

    time1.read("Enter time 1");
    time2.read("Enter time 2");
    if (time1.lessThan(time2)) {
        duration = time2.subtract(time1);
        cout << "Starting time was ";
        time1.display();
    }
    else {
        duration = time1.subtract(time2);
        cout << "Starting time was ";
        time2.display();
    }
    cout << "Duration was ";
    duration.display();

    return 0;
}

void Time::read(const char* input) //1. read that is used to read time (minutes and hours) from the keyboard.
{
    char x;
    int f = 0;
    cout << input << endl;
    while (f == 0)
    {
        cin >> hour >> x >> minute;
        
        if (hour >= 0 && hour <= 23 && minute >= 0 && minute <= 60)
        {
            f = 1;
        }
        else
        {
            printf("\nUnfortunately, there has been an error with user input.\n Please select the appropriate time ");
        }
    }
}

bool Time::lessThan(Time less_than) //2. lessThan that is used to compare two times
{
    if (hour < less_than.hour || (hour == less_than.hour && minute < less_than.minute))
    {
        return true;
    }
    else
        
        return false;
}

Time Time::subtract(Time lss) //3. subtract that is used to calculate time difference between two times.
{
    Time calc_a;
    int calc_b;
    calc_b = (hour * 60 + minute) - (lss.hour * 60 + lss.minute);
    calc_a.hour = calc_b / 60;
    calc_a.minute = calc_b % 60;
    return calc_a;
}

void Time::display() //4. display that is used to display time in the format hh:mm
{
    cout << setiosflags(ios::right); cout << setfill('0') << setw(2) << hour;
    cout << ":" << setfill('0') << setw(2) << minute << endl;
}
