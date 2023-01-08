#ifndef PROJETO_AIRLINE_H
#define PROJETO_AIRLINE_H

#include <string>

using namespace std;
///Esta classe tem como função guardar o codigo, o nome, o indicativo e o pais de uma companhia aérea;
///
///A classe Airline contém a string code, a string name, a  string callsign e a string country, que podem ser acedidos através dos getters string getCode(), string getName(), string getCallsign() e string getCountry(). Nos parâmetros públicos da classe são apresentados dois constructors para inicialização do objeto, Airline() e Airline(string code, string name, string callsign, string country), com os parâmetros code do tipo string, name do tipo string, callsign do tipo string e country do tipo string,

class Airline {
    string code;
    string name;
    string callsign;
    string country;
public:
    ///Default constructor.
    ///
    ///Complexidade de nível 1.
    Airline();
    ///Constructor com parâmetros.
    ///
    ///Complexidade de nível 1.
    /// \param code Este parâmetro contém o codigo da companhia aérea.
    /// \param name Este parâmetro contém o nome da companhia aérea.
    /// \param callsign Este parâmetro contém o indicativo da companhia aérea.
    /// \param country Este parâmetro contém o país da companhia aérea.
    Airline(string code, string name, string callsign, string country);
    ///Getter que retorna o codigo da companhia aérea, do tipo string, quando utilizado.
    ///
    ///Complexidade de nível 1.
    string getCode();
    ///Getter que retorna o nome da companhia aérea, do tipo string, quando utilizado.
    ///
    ///Complexidade de nível 1.
    string getName();
    ///Getter que retorna o indicativo da companhia aérea, do tipo string, quando utilizado.
    ///
    ///Complexidade de nível 1.
    string getCallsign();
    ///Getter que retorna o país da companhia aérea, do tipo string, quando utilizado.
    ///
    ///Complexidade de nível 1.
    string getCountry();
};


#endif //PROJETO_AIRLINE_H
