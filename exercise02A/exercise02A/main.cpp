//
//  main.cpp
//  exercise02A
//
//  Created by Genti Gashi on 29.10.2020.
//  Copyright © 2020 Genti Gashi. All rights reserved.
//


#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string find_field(const string &xml, string tag_name);  // find function


int main(void)
{

    string page, line, location, temperature, input, output;
    ifstream inputFile("weather.xml");

    while (getline(inputFile, line))
    {
        page.append(line);
        line.erase();
    }
    // Now page is a string that contains the whole xml page
    // Here you need to write something that finds and
    // extracts location and temperature from the XML
    // data in the string page and stores them in
    // the strings location and temperature respectively
    
    
    location = find_field(page, "Location");
    temperature = find_field(page, "temp_c");

    cout << "Location: " << location << endl;
    cout << "Temperature: " << temperature << endl;
    do
    {
        cout << "Type another string to search for. OR press x on keyboard to end program: " << endl; //Search
        cin >> input;
        if (input != "x")
        {
            output = find_field(page, input);
            cout << input << " = " << output << endl;
        }
        else
        {
            cout << "Program terminated." << endl;
            break;
            
        }
    } while (input != "x");
}


string find_field(const string &xml, string tag_name)
{
    // construct start and end tags from from the tag name
    // add angle brackets to both tags and also slash to end tag
    // then search for tags
    // if both are found then return the substring between the tags
    
    
    auto x = xml.find("<" + tag_name + ">") + tag_name.length() + 2;
    // auto: a way to declare a variable that has a complicated type
       
    auto y = xml.find("</" + tag_name + ">");
    
        if ((x - 2 - tag_name.length()) != y)
        {
            return xml.substr(x, y - x); //substr:= substring
        }
        else
        {
            return "not found";
        }
    }

