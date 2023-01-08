#include <queue>
#include <iostream>
#include <unordered_set>
#include "Graph.h"

Graph::Graph() {}

void Graph::addEdge(string src, string dest, string airline) {
    nodes[src].destinies.push_back({dest,airline});
}

bool Graph::isIn(string n, vector<string> vec){
    if(vec.empty()) return true;
    for(string s : vec){
        if (s==n) return true;
    }
    return false;
}



vector<string> Graph::shortesPath(const vector<string>& start_vec, const vector<string>& destinies_vec, const vector<string>& user_airlines){
    vector<string> path;
    auto it = nodes.begin();
    while (it!=nodes.end()){
        it->second.visited=false;
        it->second.parent="###";
        it++;
    }

    queue<string> q;
    for(string s : start_vec){
        if(nodes[s].parent!="###") return path;
        q.push(s);
        nodes[s].visited= true;
    }


    while (!q.empty()){
        string u = q.front();
        q.pop();
        bool flag = false;
        for(string s : destinies_vec){
            if(u == s) {
                path.push_back(s);
                flag = true;
                break;
            }
        }
        if (flag) break;
        else {
            for (Edge edge: nodes[u].destinies) {
                if (!nodes[edge.dest].visited && isIn(edge.airline, user_airlines)) {
                    nodes[edge.dest].visited = true;
                    q.push(edge.dest);
                    nodes[edge.dest].parent = u;
                    nodes[edge.dest].parent_airline = edge.airline;
                }
            }
        }
    }
    if(path.empty()) {
        path.push_back("Error message");
        return path;
    }
    string u = path[0];

    while (nodes[u].parent!="###"){
        path.push_back(nodes[u].parent_airline);
        path.push_back((nodes[u].parent));
        u=nodes[u].parent;
    }
    return path;
}

int Graph::flightsPerAirport(string airport_code) {
    return nodes[airport_code].destinies.size();
}

int Graph::targetsPerAirport(string airport_code) {
    unordered_set<string> sett;
    for(Edge edge : nodes[airport_code].destinies){
        sett.insert(edge.dest);
    }
    return sett.size();
}

int Graph::airlinesPerAirport(string airport_code) {
    unordered_set<string> sett;
    for(Edge edge : nodes[airport_code].destinies){
        sett.insert(edge.airline);
    }
    return sett.size();
}

vector<string> Graph::countriesPerAirport(string airport_code) {
    vector<string> vec;
    for(Edge edge : nodes[airport_code].destinies){
        vec.push_back(edge.dest);
    }
    return vec;
}

vector<string> Graph::howManyAirports(string code, int n){
    vector<string> vec;
    auto it = nodes.begin();
    while (it!=nodes.end()){
        it->second.visited=false;
        it->second.distance=0;
        it++;
    }

    queue<string> q;
    q.push(code);
    nodes[code].visited= true;
    while (!q.empty()){
        string u = q.front();
        q.pop();
        vec.push_back(u);
        if(nodes[u].distance<n) {
            for (Edge edge: nodes[u].destinies) {
                if (!nodes[edge.dest].visited) {
                    nodes[edge.dest].visited = true;
                    q.push(edge.dest);
                    nodes[edge.dest].distance=nodes[u].distance + 1;
                }
            }
        }
    }
    return vec;
}