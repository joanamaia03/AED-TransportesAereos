#include "Airline.h"

Airline::Airline(string code, string name, string callsign, string country) {
    this->code=code;
    this->name=name;
    this->callsign=callsign;
    this->country=country;
}

Airline::Airline() {

}

string Airline::getName() {
    return name;
}

string Airline::getCode() {
    return code;
}

string Airline::getCallsign() {
    return  callsign;
}

string Airline::getCountry() {
    return country;
}