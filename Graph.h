#ifndef PROJETO_GRAPH_H
#define PROJETO_GRAPH_H

#include <string>
#include <list>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

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
    void addEdge(string src , string dest, string airline);

    vector<string> shortesPath(const vector<string>& start, const vector<string>& destinie, const vector<string>& user_airlines);
    bool isIn(string n, vector<string> vec);

    int FlightsPerAirport(string airport_code);
    int TargetsPerAirport(string airport_code);
    int AirlinesPerAirport(string airport_code);
    vector<string> CountriesPerAirport(string basicString);
};


#endif //PROJETO_GRAPH_H
