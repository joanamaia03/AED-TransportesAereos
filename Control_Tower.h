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
};


#endif //PROJETO_CONTROL_TOWER_H
