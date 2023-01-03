//
// Created by Pedro on 03/01/2023.
//

#include <fstream>
#include <sstream>
#include "Control_Tower.h"

Control_Tower::Control_Tower() {

}

void Control_Tower::Read_Files() {
    Read_Flights();
    Read_Airports();
    Read_Airlines();
}

void Control_Tower::Read_Flights(){
    ifstream inputFile1;
    inputFile1.open(R"(..\csvfiles\flights.csv)");
    string line1;

    getline(inputFile1, line1);
    line1 = "";

    while (getline(inputFile1, line1)) {
        string src;
        string dest;
        string airline;

        stringstream inputString(line1);

        getline(inputString, src, ',');
        getline(inputString, dest, ',');
        getline(inputString, airline, ',');


        flights.addEdge(src,dest,airline);

        line1 = "";
    }
}

void Control_Tower::Read_Airports(){
    ifstream inputFile1;
    inputFile1.open(R"(..\csvfiles\airports.csv)");
    string line1;

    getline(inputFile1, line1);
    line1 = "";

    while (getline(inputFile1, line1)) {
        string code;
        string name;
        string city;
        string country;

        string temp;
        float latitude;
        float longitude;


        stringstream inputString(line1);

        getline(inputString, code, ',');
        getline(inputString, name, ',');
        getline(inputString, city, ',');
        getline(inputString, country, ',');
        getline(inputString, temp, ',');
        latitude= atof(temp.c_str());
        longitude = atof(temp.c_str());



        Airport airport(code,name,city,country,latitude,longitude);
        airports[code]=airport;

        line1 = "";
    }
}

void Control_Tower::Read_Airlines(){
    ifstream inputFile1;
    inputFile1.open(R"(..\csvfiles\airlines.csv)");
    string line1;

    getline(inputFile1, line1);
    line1 = "";

    while (getline(inputFile1, line1)) {
        string code;
        string name;
        string callsign;
        string country;


        stringstream inputString(line1);

        getline(inputString, code, ',');
        getline(inputString, name, ',');
        getline(inputString, callsign, ',');
        getline(inputString, country, ',');



        Airline airline(code,name,callsign,country);
        airlines[code]=airline;

        line1 = "";
    }
}


