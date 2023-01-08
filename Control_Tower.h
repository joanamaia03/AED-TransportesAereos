#ifndef PROJETO_CONTROL_TOWER_H
#define PROJETO_CONTROL_TOWER_H

#include "Graph.h"
#include "HashTable.h"
#include "Airport.h"
#include "Airline.h"

///Esta classe armazena a informação que se encontra nos ficheiros, contendo todos os métodos que trabalham com esses dados.
///
///A classe ontrol_Tower contém o Graph flights, o unordered_map<string,Airport> airportse o unordered_map<string,Airline> airlines. Nos parâmetros públicos da classe é apresentado um constructor para inicialização do objeto, Control_Tower(). Também contém as funções void void Read_Files(), void Read_Flights(), void Read_Airlines(), void Read_Airports(), void shortestPath(int code1, int code2, string start, string destiny, vector<string> user_airlines), vector<string> getAirportsByCity(const string& city), vector<string> getAirportsByCountry(const string& country), vector<string> getAirportsByLocation(const string& country), static double haversine(double lat1, double lon1, double lat2, double lon2), void flightsPerAirport(string airport_code), void targetsPerAirport(string airport_code), void airlinesPerAirport(string airport_code), void countriesPerAirport(string airport_code), void targetsAfterN(string airport_code, int n), void citiesAfterN(string airport_code, int n), void countriesAfterN(string airport_code, int n)."
class Control_Tower {
    Graph flights;
    unordered_map<string,Airport> airports;
    unordered_map<string,Airline> airlines;
public:
    ///Default constructor.
    ///
    ///Complexidade de nível 1.
    Control_Tower();
    ///Tem como função ler todos os ficheiros.
    ///
    ///Complexidade n.
    void Read_Files();
    ///Tem como função ler o ficheiro flights.csv.
    ///
    ///Complexidade n.
    void Read_Flights();
    ///Tem como função ler o ficheiro airlines.csv.
    ///
    ///Complexidade n.
    void Read_Airlines();
    ///Tem como função ler o ficheiro airports.csv.
    ///
    ///Complexidade n.
    void Read_Airports();

    ///Algoritmo BSF que tem como função retornar o caminho mais curto entre dois locais, usando apenas as companhias aereas especificadas(podendo-se usar qualquer uma caso não sejam especificadas).
    ///
    ///Complexidade (V * E) * n.
    /// \param code1 Valor, do tipo int, que indica se a string start é um aeroporto, cidade, país ou localização.
    /// \param code2 Valor, do tipo int, que indica se a destiny start é um aeroporto, cidade, país ou localização.
    /// \param start String que indica o local de partida.
    /// \param destiny String que indica o local de chegada.
    /// \param user_airlines Vetor que contem as companhias aereas especificadas pelo utilizador.
    void shortestPath(int code1, int code2, string start, string destiny, vector<string> user_airlines);

    ///Tem como função receber uma string city e retornar todos os codigos dos aeroportos presentes nessa cidade.
    ///
    ///Complexidade n.
    /// \param city String que indica a cidade.
    vector<string> getAirportsByCity(const string& city);
    ///Tem como função receber uma string country e retornar todos os codigos dos aeroportos presentes nesse país.
    ///
    ///Complexidade n.
    /// \param country String que indica o país.
    vector<string> getAirportsByCountry(const string& country);
    ///Tem como função receber uma string location e retornar todos os codigos dos aeroportos presentes a 100Km da localização indicada.
    ///
    ///Complexidade n*log(n).
    /// \param location String que indica a lcalização, construida da seguinte maneira: "latitude,longitude".
    vector<string> getAirportsByLocation(const string& location);

    ///Algoritmo que retona a distância, em kilometros, entre duas localizações.
    ///
    ///Complexidade log(n).
    /// \param lat1 Valor, do tipo int, que contem a latitude do local 1.
    /// \param lon1 Valor, do tipo int, que contem a longitude do local 1.
    /// \param lat2 Valor, do tipo int, que contem a latitude do local 2.
    /// \param lon2 Valor, do tipo int, que contem a longitude do local 2.
    static double haversine(double lat1, double lon1, double lat2, double lon2);

    void flightsPerAirport(string airport_code);
    void targetsPerAirport(string airport_code);
    void airlinesPerAirport(string airport_code);
    void countriesPerAirport(string airport_code);

    ///Tem como função receber uma airport_code e retornar o numero de aeroportos disponiveis em utilizando, no máximo, N voos.
    ///
    ///Complexidade n.
    /// \param airport_code String que indica o codigo do aeroporto.
    /// \param n Valor, do tipo int, que contem o numero de voos N.
    void targetsAfterN(string airport_code, int n);
    ///Tem como função receber uma airport_code e retornar o numero de cidades disponiveis em utilizando, no máximo, N voos.
    ///
    ///Complexidade n.
    /// \param airport_code String que indica o codigo do aeroporto.
    /// \param n Valor, do tipo int, que contem o numero de voos N.
    void citiesAfterN(string airport_code, int n);
    ///Tem como função receber uma airport_code e retornar o numero de países disponiveis em utilizando, no máximo, N voos.
    ///
    ///Complexidade n.
    /// \param airport_code String que indica o codigo do aeroporto.
    /// \param n Valor, do tipo int, que contem o numero de voos N.
    void countriesAfterN(string airport_code, int n);
};


#endif //PROJETO_CONTROL_TOWER_H
