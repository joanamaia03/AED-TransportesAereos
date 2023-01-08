#ifndef PROJETO_GRAPH_H
#define PROJETO_GRAPH_H

#include <string>
#include <list>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

///Esta classe tem como função armazenar a todas os voos entre aeroportos em um grafo, permitindo o otimização na procura de trajetos entre aeroportos.
///
///A classe Graph contém um unordered_map nodes, que tem como key os codigos de todos os aeroports, e retorna o Node correspondente, a struct Edge, que representa um voo, com os campos string dest (aeroporto de destino) e strin airline, e a struct Node(que representa um aeroporto), que contem os campos list<Edge> destinies(contem todos os voos que partem deste aeroporto), bool visited (indica se este node já foi visitado na instancia atual do algoritmo BSF), int distance (distância ao Node inicial), string parent(quando este node é visitado, este campo indica que aeroporto foi visitando antes deste), string parent_airline(quando este node é visitado, este campo indica que companhia aerea foi utilizada para alcançar este node). Esta classe contem um constructor, Graph(). Também contém os métodos void addEdge(string src , string dest, string airline), vector<string> shortesPath(const vector<string>& start, const vector<string>& destinie, const vector<string>& user_airlines), bool isIn(string n, vector<string> vec), int flightsPerAirport(string airport_code), int targetsPerAirport(string airport_code), int airlinesPerAirport(string airport_code), vector<string> countriesPerAirport(string basicString); vector<string> howManyAirports(string code, int n).

class Graph {
    struct Edge {
        string dest;
        string airline;
    };

    struct Node {
        list<Edge> destinies;
        bool visited;
        int distance;
        string parent;
        string parent_airline;
    };

    unordered_map<string,Node> nodes;
public:
    Graph();

    ///Tem como função adicionar uma Edge(voo) de um aeroporto para outro.
    ///
    ///Complexidade 1.
    /// \param src string que contem o codigo do aeroporto de partida.
    /// \param dest string que contem o codigo do aeroporto de chegada.
    /// \param airline string que contem o codigo da companhia aerea responsavel pelo voo.
    void addEdge(string src , string dest, string airline);

    ///Algoritmo BSF que tem como função retornar o caminho mais curto entre dois locais, usando apenas as companhias aereas especificadas(podendo-se usar qualquer uma caso não sejam especificadas).
    ///
    ///Complexidade (V * E) * n.
    /// \param start Vetor que contem todos os codigos dos aeroportos considerados como ponto de partida.
    /// \param destiny Vetor que contem todos os codigos dos aeroportos considerados como ponto de chegada.
    /// \param user_airlines Vetor que contem as companhias aereas especificadas pelo utilizador.
    vector<string> shortesPath(const vector<string>& start, const vector<string>& destiny, const vector<string>& user_airlines);

    ///Tem como função indicar se a string n está contida no vetor vec.
    ///
    ///Complexidade n.
    bool isIn(string n, vector<string> vec);

    ///Tem como função indicar o numero de voos a partir de um aeroporto.
    ///
    ///Complexidade 1.
    /// \param airport_code string que contem o codigo do aeroporto.
    int flightsPerAirport(string airport_code);
    ///Tem como função indicar o numero de destinos diferentes a partir de um aeroporto.
    ///
    ///Complexidade n.
    /// \param airport_code string que contem o codigo do aeroporto.
    int targetsPerAirport(string airport_code);
    ///Tem como função indicar o numero de voos com companhias aereas diferentes a partir de um aeroporto.
    ///
    ///Complexidade n.
    /// \param airport_code string que contem o codigo do aeroporto.
    int airlinesPerAirport(string airport_code);
    ///Tem como função retornar um vetor com todos os destinos a partir de um aeroporto.
    ///
    ///Complexidade n.
    /// \param airport_code string que contem o codigo do aeroporto.
    vector<string> countriesPerAirport(string airport_code);

    ///Tem como função retornar um vetor com todos os aeroportos acessiveis utilizando no maximo N voos.
    ///
    ///Complexidade (V * E).
    /// \param code string que contem o codigo do aeroporto.
    vector<string> howManyAirports(string code, int n);
};


#endif //PROJETO_GRAPH_H
