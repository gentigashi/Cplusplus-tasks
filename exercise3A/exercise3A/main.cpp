//
//  main.cpp
//  exercise3A
//
//  Created by Genti Gashi on 2.11.2020.
//  Copyright © 2020 Genti Gashi. All rights reserved.
//


#include <iostream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
    
    vector <double>x_1;
    float storing;
    
    do {
        
        cout << "Welcome to Exercise 3A!\n";
        cout << "Please enter a  number :";
        cin >> storing;
        
        if (storing < 0) {
            break;
        }
        x_1.push_back(storing);
        
        sort(x_1.begin(), x_1.end());
        
    } while (storing > 0);

    
    cout << "Your chosen numbers sorted in an acsending order \n:" << endl;

    for (auto x = x_1.begin(); x != x_1.end();) {
        
        cout << fixed<<setprecision(3) << *x << endl; //cplusplus.com //program prints the numbers on separate lines with 3 decimal precision.
        x++;
    }
}


