//
//  main.cpp
//  exercise05
//
//  Created by Genti Gashi on 9.11.2020.
//  Copyright © 2020 Genti Gashi. All rights reserved.
//

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <vector>
#include <algorithm>



using namespace std;

class Time

{
    
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
Time operator++(int); //Postposition++, next second
Time & operator +(); // pre + +, next second
    
};




int main() { //Exercise4 preset main function
    Time time1, time2, duration;

    time1.read("Enter Time 1:");
    time2.read("Enter Time 2:");
    if (time1<time2)
    {
    cout<<"Time1 is Smaller than < Time2."<<endl;
    }
    else
    {
    cout<<"Time1 > is Bigger  than Time2."<<endl;
    }
   
    cout<<"Time Pre Increment:"<<endl;
    duration= +time1;
    duration.display();
    time1.display();

    cout<<"Time Post Increment:"<<endl;
    duration= time1++;
    duration.display();
    time1.display();
    
    
    
    
    
    /*cout<<"duration=time1++"<<endl;
    duration=time1++;
    cout<<"duration= "<< duration <<"  t1= "<<time1<<endl;
    cout<<"t=++t1"<< duration<<endl;
    duration= +time1;
    cout<<"t= "<< duration << "  t1= "<<time1<<endl;
    cout<<"*****************************"<<endl;*/
    
    duration=time1 + time2;
    cout <<"Adding times is ";
    duration.display();
    
    
    duration=time1 - time2;
    cout <<"Subtracting times";
    duration.display();
    
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
    cout << input;
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
 Time Time::operator+(const Time& plus)    //operator function
{
    Time calc_a;
    int calc_b;
    calc_b = (hour * 60 + minute) + (plus.hour * 60 + plus.minute);
    calc_a.hour = (calc_b / 60)%24;
    calc_a.minute = (calc_b) % 60;
    return calc_a;
    /*Time t;
    int a,b;
    //a = s+t1.s;
    //t.s = a%60;
    b = (a/60)+minute+t1.minute;
    t.minute = b%60;
    t.hour = (b/60)+hour+t1.hour;
    t.hour = t.hour%24;
    return t;*/
    
}

 Time Time::operator-(const Time& sub)    //operator function
{
    Time calc_a;
    int calc_b;
    calc_b = (hour * 60 + minute) - (sub.hour * 60 + sub.minute);
    calc_a.hour = (calc_b / 60)%24;
    calc_a.minute = (calc_b) % 60;
    return calc_a;
    /*Time t;
    int a,b;
    //a = s+t1.s;
    //t.s = a%60;
    b = (a/60)+minute+t1.minute;
    t.minute = b%60;
    t.hour = (b/60)+hour+t1.hour;
    t.hour = t.hour%24;
    return t;*/
    
}
bool Time::operator<(const Time& sub)    //operator function
{
    /*Time calc_a;
    int calc_b;
    calc_b = (hour * 60 + minute) - (sub.hour * 60 + sub.minute);
    calc_a.hour = (calc_b / 60)%24;
    calc_a.minute = (calc_b) % 60;
    return calc_a;*/
    //return ( hour < sub.hour && minute < sub.minute  );
  if (hour<sub.hour) return true;
  if (hour>sub.hour) return false;
  if (minute<sub.minute) return true;
  if (minute>sub.minute) return false;
  
  return false;
    
}
/*Time Time:: operator + (int)//postposition+++, next second
{
  Time duration=*this;
  *this=*this+1;
  return t;
}
Time & Time:: operator ++()// prefix ++, next second
{
  *this=*this+1;
  return *this;
}*/

Time Time::operator++(int) //post-incremented operator

     {

         minute = hour * 60 + minute;
         minute++;
         hour = minute / 60;
         hour = hour % 24;
         minute = minute % 60;
         return *this;

     }

     

     Time& Time::operator +() // pre-incremented operator

     {

         //Time rev = *this;
         minute = hour * 60 + minute;
         minute++;
         hour = minute / 60;
         hour = hour % 24;
         minute = minute % 60;
         return *this;// alternative version to return rev;

     }
void Time::display() //4. display that is used to display time in the format hh:mm
{
    cout << setiosflags(ios::right); cout << setfill('0') << setw(2) << hour;
    cout << ":" << setfill('0') << setw(2) << minute << endl;
}
