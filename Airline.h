#ifndef PROJETO_AIRLINE_H
#define PROJETO_AIRLINE_H

#include <string>

using namespace std;

class Airline {
    string code;
    string name;
    string callsign;
    string country;
public:
    Airline();
    Airline(string code, string name, string callsign, string country);
    string getCode();
    string getName();
    string getCallsign();
    string getCountry();

};


#endif //PROJETO_AIRLINE_H
