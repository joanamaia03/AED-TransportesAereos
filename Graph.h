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
        bool visited;
        int distance;
        string parent;
        string parent_airline;
    };

    unordered_map<string,Node> nodes;
public:
    Graph();
    void addEdge(string src , string dest, string airline);

    vector<string> shortesPath(string start, string destinie);
};


#endif //PROJETO_GRAPH_H
