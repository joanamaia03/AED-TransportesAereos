#include <fstream>
#include <sstream>
#include <iostream>
#include <utility>
#include <valarray>
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
        double latitude;
        double longitude;


        stringstream inputString(line1);

        getline(inputString, code, ',');
        getline(inputString, name, ',');
        getline(inputString, city, ',');
        getline(inputString, country, ',');
        getline(inputString, temp, ',');
        latitude= atof(temp.c_str());
        getline(inputString, temp, ',');
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


void Control_Tower::shortestPath(int code1, int code2, string start, string destinie, vector<string> user_airlines){
    vector<string> start_vec;
    vector<string> destinie_vec;
    switch (code1){
        case 1:
            start_vec.push_back(start);
            break;
        case 2:
            start_vec= getAirportsByCity(start);
            break;
        case 3:
            start_vec= getAirportsByCountry(start);
            break;
        case 4:
            start_vec= getAirportsByLocation(start);
            break;
        default:
            cout<<"Invalid input\n";
            return;
    }

    switch (code2){
        case 1:
            destinie_vec.push_back(destinie);
            break;
        case 2:
            destinie_vec= getAirportsByCity(destinie);
            break;
        case 3:
            destinie_vec= getAirportsByCountry(destinie);
            break;
        case 4:
            destinie_vec= getAirportsByLocation(destinie);
            break;
        default:
            cout<<"Invalid input\n";
            return;
    }
    if(start_vec.empty()) {
        cout<<"Invalid starting point";
        return;
    }
    if(destinie_vec.empty()) {
        cout<<"Invalid destination\n";
        return;
    }
    vector<string> vec = flights.shortesPath(start_vec, destinie_vec,user_airlines);

    int i = vec.size() - 1;
    if (i==-1) {
        cout<<"Start point not found\n";
        return;
    }
    if (i==0 && start!=destinie){
        cout<<"Path not found\n";
        return;
    }
    if (i==1) {
        cout<<"Destine not found\n";
        return;
    }
    cout<<"<----------------------->\n";
    while(i > 0){
        cout<<"Aeroporto:"<<airports[vec[i]].getName()<<'\n';
        cout<<"Pais:"<<airports[vec[i]].getCountry()<<'\n';
        cout<<"Cidade:"<<airports[vec[i]].getCity()<<'\n';
        i--;
        cout<<"  |  \n";
        cout<<"  |  \n";
        cout<<"Airline:"<<airlines[vec[i]].getName()<<'\n';
        i--;
        cout<<"  |  \n";
        cout<<"  V  \n";
    }
    cout<<"Aeroporto:"<<airports[vec[i]].getName()<<'\n';
    cout<<"Pais:"<<airports[vec[i]].getCountry()<<'\n';
    cout<<"Cidade:"<<airports[vec[i]].getCity()<<'\n';
    cout<<"<----------------------->\n";
}

vector<string> Control_Tower::getAirportsByCity(const string& city){
    vector<string> airports_by_city;
    auto it = airports.begin();
    while (it!=airports.end()){
        if(it->second.getCity()==city) airports_by_city.push_back(it->second.getCode());
        it++;
    }
    return airports_by_city;
}

vector<string> Control_Tower::getAirportsByCountry(const string& country){
    vector<string> airports_by_country;
    auto it = airports.begin();
    while (it!=airports.end()){
        if(it->second.getCountry()==country) airports_by_country.push_back(it->second.getCode());
        it++;
    }
    return airports_by_country;
}

vector<string> Control_Tower::getAirportsByLocation(const string& location){
    vector<string> airports_by_location;

    string temp;
    double latitude;
    double longitude;

    stringstream inputString(location);

    getline(inputString, temp, ',');
    latitude= atof(temp.c_str());
    getline(inputString, temp, ',');
    longitude = atof(temp.c_str());

    auto it = airports.begin();
    while (it!=airports.end()){
        if(haversine(it->second.getLatitude(),it->second.getLongitude(),latitude,longitude)<100) airports_by_location.push_back(it->second.getCode());
        it++;
    }
    return airports_by_location;
}



//Function taken from https://www.geeksforgeeks.org/haversine-formula-to-find-distance-between-two-points-on-a-sphere/
double Control_Tower::haversine(double lat1, double lon1,double lat2, double lon2){
    // distance between latitudes
    // and longitudes
    double dLat = (lat2 - lat1) *
                  M_PI / 180.0;
    double dLon = (lon2 - lon1) *
                  M_PI / 180.0;

    // convert to radians
    lat1 = (lat1) * M_PI / 180.0;
    lat2 = (lat2) * M_PI / 180.0;

    // apply formulae
    double a = pow(sin(dLat / 2), 2) +
               pow(sin(dLon / 2), 2) *
               cos(lat1) * cos(lat2);
    double rad = 6371;
    double c = 2 * asin(sqrt(a));
    return rad * c;
}

void Control_Tower::FlightsPerAirport(string airport_code) {
    int i = flights.FlightsPerAirport(airport_code);
    cout<<"Numero de voos a partir do aeroporto "<<airports[airport_code].getName()<<":"<<i<<'\n';
    cout<<"<----------------------->\n";
}

void Control_Tower::TargetsPerAirport(string airport_code) {
    int res = flights.TargetsPerAirport(airport_code);
    cout<<"Numero de voos com destinos diferentes: "<<res<<'\n';
    cout<<"<----------------------->\n";
}

void Control_Tower::AirlinesPerAirport(string airport_code) {
    int res = flights.AirlinesPerAirport(airport_code);
    cout<<"Numero de voos de companhias areas diferentes: "<<res<<'\n';
    cout<<"<----------------------->\n";
}

void Control_Tower::CountriesPerAirport(string airport_code) {
    vector<string> vec = flights.CountriesPerAirport(airport_code);
    unordered_set<string> countries;
    for(string s : vec){
        countries.insert(airports[s].getCountry());
    }
    cout<<"Numero de de voos para paises diferentes: "<<countries.size()<<'\n';
    cout<<"<----------------------->\n";
}
