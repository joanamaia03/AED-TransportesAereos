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

    int flightsPerAirport(string airport_code);
    int targetsPerAirport(string airport_code);
    int airlinesPerAirport(string airport_code);
    vector<string> countriesPerAirport(string basicString);

    vector<string> howManyAirports(string code, int n);
};


#endif //PROJETO_GRAPH_H
