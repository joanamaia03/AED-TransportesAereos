#include "Control_Tower.h"

#include <fstream>
#include <sstream>
#include "Control_Tower.h"

Control_Tower::Control_Tower() {

}

void Control_Tower::Read_Files() {
    Read_Flights();

}

void Control_Tower::Read_Flights(){
    ifstream inputFile1;
    inputFile1.open(R"(..\flights.csv)");
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
    inputFile1.open(R"(..\airports.csv)");
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
        //airports[code]=; incompleto

        line1 = "";
    }
}