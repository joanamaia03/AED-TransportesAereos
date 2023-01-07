#include <queue>
#include <iostream>
#include "Graph.h"

Graph::Graph() {}

void Graph::addEdge(string src, string dest, string airline) {
    nodes[src].destinies.push_back({dest,airline});
}

vector<string> Graph::shortesPath(string start, string destinie){
    vector<string> path;
    auto it = nodes.begin();
    while (it!=nodes.end()){
        it->second.visited=false;
        it->second.parent="###";
        it++;
    }
    if(nodes[start].parent!="###") return path;
    queue<string> q;
    q.push(start);
    nodes[start].visited= true;
    while (!q.empty()){
        string u = q.front();
        q.pop();
        if(u == destinie) break;
        for(Edge edge : nodes[u].destinies){
            if (!nodes[edge.dest].visited){
                nodes[edge.dest].visited= true;
                q.push(edge.dest);
                nodes[edge.dest].parent=u;
                nodes[edge.dest].parent_airline=edge.airline;
            }
        }
    }

    string u = destinie;
    path.push_back(u);
    if(nodes[u].parent=="") return path;
    while (nodes[u].parent!="###"){
        path.push_back(nodes[u].parent_airline);
        path.push_back((nodes[u].parent));
        u=nodes[u].parent;
    }
    return path;
}