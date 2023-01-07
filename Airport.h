#ifndef PROJETO_AIRPORT_H
#define PROJETO_AIRPORT_H

using namespace std;

#include <string>

class Airport {
    string code;
    string name;
    string city;
    string country;
    double latitude;
    double longitude;
public:
    Airport();
    Airport(string code, string name, string city, string country, double latitude, double longitude);
    string getCode();
    string getName();
    string getCity();
    string getCountry();
    float getLatitude();
    float getLongitude();
};


#endif //PROJETO_AIRPORT_H
