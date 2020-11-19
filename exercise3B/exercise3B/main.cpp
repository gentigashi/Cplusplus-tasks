//
//  main.cpp
//  exercise3B
//
//  Created by Genti Gashi on 2.11.2020.
//  Copyright © 2020 Genti Gashi. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <algorithm>


using namespace std;


void backwards(vector<string>& str);


void backwards(vector<string>& str)
{
    for (auto && result : str)
    {
        reverse(result.begin(), result.end());
    }

    sort(str.begin(), str.end(), greater<>());
}


int main() {
    
    vector<string> S1;
    string sanoja;
   
    do {  //same as 3A basically

        cout << "Welcome to exercise 3B!:\n";
        cout <<"Enter a string: OR type 'stop' to stop the program.\n";
        cin >> sanoja;
        if (sanoja == "stop")
        {
            break;
        }
        S1.push_back(sanoja);
    } while (getline(cin, sanoja));
    
    cout << "The stored strings : " << endl;
    
    for (auto x = S1.begin(); x != S1.end();) {
        
        cout << *x << endl;
        x++;
    }
    
    backwards(S1);
    cout << " Strings in reverse: Descending order : " << endl;
    for (auto x = S1.begin(); x != S1.end();) {
        cout << *x << endl;
        x++;
    }

}
