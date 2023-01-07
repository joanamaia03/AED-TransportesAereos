#ifndef PROJETO_CONTROL_TOWER_H
#define PROJETO_CONTROL_TOWER_H

#include "Graph.h"
#include "HashTable.h"
#include "Airport.h"
#include "Airline.h"

class Control_Tower {
    Graph flights;
    unordered_map<string,Airport> airports;
    unordered_map<string,Airline> airlines;
public:
    Control_Tower();
    void Read_Files();
    void Read_Flights();
    void Read_Airlines();
    void Read_Airports();

    void shortestPath(int code1, int code2, string start, string destiny, vector<string> user_airlines);

    vector<string> getAirportsByCity(const string& city);
    vector<string> getAirportsByCountry(const string& country);
    vector<string> getAirportsByLocation(const string& country);

    static double haversine(double lat1, double lon1, double lat2, double lon2);

    void flightsPerAirport(string airport_code);
    void targetsPerAirport(string airport_code);
    void airlinesPerAirport(string airport_code);
    void countriesPerAirport(string airport_code);

    void targetsAfterN(string airport_code, int n);
    void citiesAfterN(string airport_code, int n);
    void countriesAfterN(string airport_code, int n);

};


#endif //PROJETO_CONTROL_TOWER_H
