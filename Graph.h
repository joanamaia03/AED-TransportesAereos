#ifndef PROJETO_GRAPH_H
#define PROJETO_GRAPH_H

#include <string>
#include <list>
#include <vector>
#include <unordered_map>

using namespace std;

class Graph {
    struct Edge {
        string dest;
        string airline;
    };

    struct Node {
        list<Edge> destinies;
    };

    unordered_map<string,Node> nodes;
public:
    Graph();
    void addEdge(string src , string dest, string airline);
};


#endif //PROJETO_GRAPH_H
