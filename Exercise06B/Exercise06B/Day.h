//Exercise 06B

#pragma once
#ifndef DAY_H_INCLUDED
#define DAY_H_INCLUDED
#include <iostream>
#include <vector>
#include "Time.h"

using namespace std;

class Day {
public:
    Day();
    bool from_str(const string& s);
    string to_str();
    void dst(int offset);
private:
    int day;
    string month;
    vector<Time> list;
};

#endif

