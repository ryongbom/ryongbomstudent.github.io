#ifndef DATA_H
#define DATA_H

#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>

using namespace std;

struct Data {
    string code;
    string name;
    double price;
    double weight;
    
    Data();
    
    Data(string c, string n, double p, double w);
    
    void display() const;
    string toFileString() const;
};

#endif 
