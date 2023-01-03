#ifndef PROJETO_AIRPORT_H
#define PROJETO_AIRPORT_H

using namespace std;

#include <string>

class Airport {
    string code;
    string name;
    string city;
    string country;
    float latitude;
    float longitude;
public:
    Airport();
    Airport(string code, string name, string city, string country, float latitude, float longitude);

};


#endif //PROJETO_AIRPORT_H
