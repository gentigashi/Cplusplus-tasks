//
//  main.cpp
//  Exercise06B
//
//  Created by Genti Gashi on 15.11.2020.
//  Copyright © 2020 Genti Gashi. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <iomanip>  // std::setiosflags
#include "Day.h"
#include "Time.h"

using namespace std;

int main()
{
    ifstream inputFile("calendar.txt");

    if (!inputFile.is_open()) {
        cout << "Unable to open file" << endl;
        return 1;
    }

    string line;
    vector<Day> cal;
    Day day;

    while (getline(inputFile, line)) {
        if (day.from_str(line)) {
            cal.push_back(day);
        }
    }
    cout << "Calendar" << endl;

    for (auto& e : cal) {
        cout << e.to_str() << endl;
    }

    // DST shift
    for (auto& e : cal) {
        e.dst(1);
    }
    cout << "DST" << endl;

    for (auto& e : cal) {
        cout << e.to_str() << endl;
    }

    cout << "End" << endl;

    return 0;
}

Day::Day() {
    day = 1;
    month = "January";
    list.clear();
}

bool Day::from_str(const string& line) {
    int ret =0;
    string temp;
    istringstream sin(line);
    bool loop = false;
    *this = Day();
    
    Time t;
    
    while (ret <= 1 && sin >> temp) {
        if (ret == 0) {
            day = stoi(temp);
            ret++;
        }
        else if (ret == 1) {
            month = temp;
            ret++;
            loop = true;
        }
    }

    while (sin >> t)
    {
        list.push_back(t);
    }
    return loop;
}

string Day::to_str() {
    ostringstream out;
    out << day << " " << month;
    for (auto t : list)
    {
        out << " " << t.to_str();
    }
    return out.str();
}

void Day::dst(int offset) {
    for (auto& s : list) {
        s.dst();
    }
}


Time::Time(int hh, int mm)
    :hour(hh), min(mm) { //
}

Time& Time::dst() {
    hour++;
    hour = hour % 24;
    return *this;
}

string Time::to_str() {
    ostringstream out;
    out << setiosflags(ios::right) << setfill('0') << setw(2) << hour << ":" << setfill('0') << setw(2) << min; // 00:00
    return out.str();
}

istream& operator>>(istream& in, Time& output)
{
    char s = ':';
    in >> output.hour >> s >>output.min;
    return in;
}



