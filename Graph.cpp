#include "Graph.h"

Graph::Graph() {}

void Graph::addEdge(string src, string dest, string airline) {
    nodes[src].destinies.push_back({dest,airline});
}
