//
//  main.cpp
//  exercise02B
//
//  Created by Genti Gashi on 29.10.2020.
//  Copyright © 2020 Genti Gashi. All rights reserved.
//
// Exercise 2B

// Investigate minor issue @line47 - Genti

#include <iostream>
#include <string>
#include <vector>
#include <ctime>

using namespace std;

int main()
{
    vector<string> vos;
    string i;
    string length_str_b;
    int x = 0;
    int y = 0;
    
    cout << "Exercise 2B!\n";
    cout << "Enter a string. Type 'stop' to stop the program : " ;

    while (cin >> i)
    {
        if (i == "stop")
        {
            cout << "\n\n";
            break;
        }
        
        vos.push_back(i);
        x++;

        cout << "Enter a string. Type 'stop' to stop the program: " ;
    }

    for (auto z : vos)
    {
        cout << z << endl;
        if (z.length() > y)
        {
            y = z.length();
            length_str_b = z;
        }
    }

    cout << "Amount of strings entered : " << x << endl;
    cout << "Longest string : " << length_str_b << endl;
    cout << "String length : " << y << endl;
    
    cout << "Vector size: " << vos.size() << endl;
    cout << "Vector capacity: " << vos.capacity() << endl;
}

