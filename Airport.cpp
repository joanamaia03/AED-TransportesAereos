#include "Airport.h"

Airport::Airport(string code, string name, string city, string country, double latitude, double longitude) {
    this->code=code;
    this->name=name;
    this->city=city;
    this->country=country;
    this->latitude=latitude;
    this->longitude=longitude;
}

Airport::Airport() {

}

string Airport::getName() {
    return name;
}

string Airport::getCode() {
    return code;
}

string Airport::getCity() {
    return  city;
}

string Airport::getCountry() {
    return country;
}

double Airport::getLatitude() {
    return latitude;
}

double Airport::getLongitude() {
    return longitude;
}
