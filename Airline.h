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

};


#endif //PROJETO_AIRLINE_H
