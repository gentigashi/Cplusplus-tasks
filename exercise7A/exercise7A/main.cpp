//
//  main.cpp
//  exercise7A
//
//  Created by Genti Gashi on 17.11.2020.
//  Copyright © 2020 Genti Gashi. All rights reserved.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <iterator>
#include <set>

using namespace std;
//Ordinary function
int randGen_1(int numbers) {
    return rand() % numbers + 1;
}
//Function object
class RandGen_2 {
public:
    RandGen_2(int range = 0, int num = 0);
    RandGen_2() : numbers() { srand(time(NULL)); }
    int operator()();
private:
    vector<int> numbers;
    int range;
    int num;
};

 int main() {
     
    char c ='n';
    do {

    
    srand(time(NULL));
    ostream_iterator<int> out_it(cout, " ");
    vector<int> s;
    vector<int> s2;
    //1.
    vector<int> numbers_lotto(7);
    RandGen_2 randGen_1(40, 7);
    
    generate(numbers_lotto.begin(), numbers_lotto.end(), randGen_1);
    cout << "Lotto: ";
    copy(numbers_lotto.begin(), numbers_lotto.end(), out_it);

    //2.
    vector<int> numbers_viking(7);
    RandGen_2 randGen_2(48, 6);
   
    generate(numbers_viking.begin(), numbers_viking.end(), randGen_2);
    cout << "\nViking Lotto: ";
    copy(numbers_viking.begin(), numbers_viking.end(), out_it);

    cout << "\nMatching numbers: " << endl;
    sort(numbers_lotto.begin(), numbers_lotto.end());
    sort(numbers_viking.begin(), numbers_viking.end());
    set_intersection(numbers_lotto.begin(), numbers_lotto.end(), numbers_viking.begin(), numbers_viking.end(), back_inserter(s));
    int count = 0;
    for_each(s.begin(), s.end(), [&count](int x) {
        count = count + 1;
        cout << "#" << count << ":" << x << endl;
        });




    //3. Eurojackpot
    vector<int> numbers_eurojackpot(5);
    RandGen_2 randGen_3(50, 5);
    
    generate(numbers_eurojackpot.begin(), numbers_eurojackpot.end(), randGen_3);
    cout << "Euro JackPot:  ";
    copy(numbers_eurojackpot.begin(), numbers_eurojackpot.end(), out_it);

    cout << "\nMatching numbers in three sets: " << endl;
    count = 0;
    sort(s.begin(), s.end());
    sort(numbers_eurojackpot.begin(), numbers_eurojackpot.end());
    set_intersection(s.begin(), s.end(),
        numbers_eurojackpot.begin(), numbers_eurojackpot.end(),
        back_inserter(s2));
    for_each(s2.begin(), s2.end(), [&count](int x) {
        count = count + 1;
        cout << "#" << count << ":" << x << endl;
        });


    // repeating process
    do
    {
        cout << "\ndo Do you want to continue [Y/N]? ";
        cin >> c;
        if (toupper(c) != 'Y' && toupper(c) != 'N') {
            cout << "\nInvalid answer! Try gain!" << endl;
        }
    } while (toupper(c) != 'Y' && toupper(c) != 'N');
    
    
    } while (toupper(c) == 'Y');
     
return 0;
}

RandGen_2::RandGen_2(int r, int n) { // Initialization
    range = r;
    num = n;
    
}

int RandGen_2::operator()() {
    int number;
    do {
        number = rand() % range + 1;
        num--;
    } while (find(numbers.begin(), numbers.end(), number) != numbers.end());
    numbers.push_back(number);
    return number;
}





