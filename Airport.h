#ifndef PROJETO_AIRPORT_H
#define PROJETO_AIRPORT_H

#include <string>

using namespace std;

///Esta classe tem como função guardar o codigo, o nome, a cidade, o pais e as coordenadas de um aeroporto;
///
///A classe Airport contém a string code, a string name, a  string city, a string country, o double latitude e o double longitude que podem ser acedidos através dos getters string getCode(), string getName(), string getCity(), string getCountry(), double getLatitude() e double getLongitude(). Nos parâmetros públicos da classe são apresentados dois constructors para inicialização do objeto, Airport() e Airport(string code, string name, string city, string country, double latitude, double longitude), com os parâmetros code do tipo string, name do tipo string, callsign do tipo string, country do tipo string, latitude do tipo double e longitude do tipo double.


class Airport {
    string code;
    string name;
    string city;
    string country;
    double latitude;
    double longitude;
public:
    ///Default constructor.
    ///
    ///Complexidade de nível 1.
    Airport();
    ///Constructor com parâmetros.
    ///
    ///Complexidade de nível 1.
    /// \param code Este parâmetro contém o codigo do aeroporto.
    /// \param name Este parâmetro contém o nome do aeroporto.
    /// \param city Este parâmetro contém a cidade do aeroporto.
    /// \param country Este parâmetro contém o país do aeroporto.
    Airport(string code, string name, string city, string country, double latitude, double longitude);
    ///Getter que retorna o codigo do aeroporto, do tipo string, quando utilizado.
    ///
    ///Complexidade de nível 1.
    string getCode();
    ///Getter que retorna o nome do aeroporto, do tipo string, quando utilizado.
    ///
    ///Complexidade de nível 1.
    string getName();
    ///Getter que retorna a cidade do aeroporto, do tipo string, quando utilizado.
    ///
    ///Complexidade de nível 1.
    string getCity();
    ///Getter que retorna o país do aeroporto, do tipo string, quando utilizado.
    ///
    ///Complexidade de nível 1.
    string getCountry();
    ///Getter que retorna a latitude do aeroporto, do tipo double, quando utilizado.
    ///
    ///Complexidade de nível 1.
    double getLatitude();
    ///Getter que retorna a longitude do aeroporto, do tipo double, quando utilizado.
    ///
    ///Complexidade de nível 1.
    double getLongitude();
};


#endif //PROJETO_AIRPORT_H
