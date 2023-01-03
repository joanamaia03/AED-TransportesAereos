#ifndef PROJETO_AIRPORT_H
#define PROJETO_AIRPORT_H

using namespace std;

class Airport {
    string code;
    string name;
    string city;
    string country;
    float latitude;
    float longitude;
public:
    Airport(string code, string name, string city, string country, float latitude, float longitude);

};


#endif //PROJETO_AIRPORT_H
