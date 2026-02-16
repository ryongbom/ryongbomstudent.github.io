#include "Data.h"
    
Data::Data() : code(""), name(""), price(0.0), weight(0.0) { }
    
Data::Data(string c, string n, double p, double w) 
		: code(c), name(n), price(p), weight(w) { }
    
void Data::display() const {
    cout << left << setw(10) << code 
         << setw(20) << name
         << setw(10) << fixed << setprecision(2) << price
         << setw(10) << fixed << setprecision(2) << weight << endl;
}
    
string Data::toFileString() const {
	stringstream ss;
   	ss << code << "," << name << "," 
	   << fixed << setprecision(2) << price << ","
	   << fixed << setprecision(2) << weight;
	   
	return ss.str();
}
