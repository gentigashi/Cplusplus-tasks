//
//  main.cpp
//  ex01
//
//  Created by Genti Gashi on 25.10.2020.
//  Copyright © 2020 Genti Gashi. All rights reserved.
//

#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>


using namespace std;

float mean(int* array, int n);

int main() {
    int size;
    
    cout << "Welcome to Exercise 01! \n";
    cout << "Enter size of the array: ";
    cin >> size;
    
    int* array = new int[size];
    srand(time(NULL));

    if (size == NULL)
        printf("\n Please use real number numbers :)!");

    for (int x = 0; x < size; x++) {
        array[x] = rand() % 100; //generating random numbers with rand. limiting to 0-99 with rand()%100.
    }
    for (int x = 0; x < size; x++) {
        printf("\n%d", array[x]);
    }

    cout << "\n\n The average of "<<  size  <<" numbers is: \n" << mean(array, size);
    
    delete[] array;
}
float mean(int* array, int n) //separate function. calculates average
{
    float  sum = 0;

    for (int x = 0; x < n; x++)
    {
        sum += array[x];
    }
    sum = sum / n;

    return sum;
}

