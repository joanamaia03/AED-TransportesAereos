#include "Airport.h"

Airport::Airport(string code, string name, string city, string country, float latitude, float longitude) {
    this->code=code;
    this->name=name;
    this->city=city;
    this->country=country;
    this->latitude=latitude;
    this->longitude=longitude;
}