#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <stack>
using namespace std;

class Graph{
    int vertex;
    list<int> *connections;
public:
    Graph(int vertex);
    void addEdge(int v1, int v2);
    void printGraph();
    void BFS(int start);
    void DFS(int start);
};

Graph::Graph(int vertex){
    this->vertex = vertex;
    connections = new list<int>[vertex];
}

void Graph::addEdge(int v1, int v2){
    connections[v1].push_back(v2);
    connections[v2].push_back(v1);
}

void Graph::printGraph(){
    for(int i = 0; i < vertex; i++){
        cout << i << ": ";
        for(auto it = connections[i].begin(); it != connections[i].end(); it++){
            cout << *it << " ";
        }
        cout << endl;
    }
}

void Graph::BFS(int start){
    vector<bool> visited(vertex, false);
    for(int i = 0; i < vertex; i++){
        visited[i] = false;
    }
    queue<int> q;
    q.push(start);
    while(!q.empty()){
        int current = q.front();
        q.pop();
        cout << current << " ➡ ";
        visited[current] = true;
        for(auto it = connections[current].begin(); it != connections[current].end(); it++){
            if(!visited[*it]){
                visited[*it] = true;
                q.push(*it);
            }
        }
    }
}

void Graph::DFS(int start){
    vector<bool> visited(vertex, false);
    for(int i = 0; i < vertex; i++){
        visited[i] = false;
    }
    stack<int> s;
    s.push(start);
    while(!s.empty()){
        int current = s.top();
        s.pop();
        cout << current << " ➡ ";
        visited[current] = true;
        for(auto it = connections[current].begin(); it != connections[current].end(); it++){
            if(!visited[*it]){
                visited[*it] = true;
                s.push(*it);
            }
        }
    }
}

int main(){
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 4);

    g.printGraph();

    g.BFS(2);
    cout << endl;
    g.DFS(2);
    return 0;
}
