#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

class Graph{
    int vertex;
    vector<vector<int>> connections;
public:
    Graph(int vertex);
    void addEdge(int v1, int v2);
    void printGraph();
    void BFS(int start);
    void DFS(int start);
};

Graph::Graph(int vertex){
    this->vertex = vertex;
    for(int i =0; i< vertex; i++){
        vector<int> temp;
        for(int j =0; j< vertex; j++){
            temp.push_back(0);
        }
        connections.push_back(temp);
    }
}

void Graph::addEdge(int v1, int v2){
    connections[v1][v2] = 1;
    connections[v2][v1] = 1;
}

void Graph::printGraph(){
    cout << "  ";
    for(int i =0; i< vertex; i++){
        cout << i << " ";
    }
    cout << endl;
    for(int i =0; i< vertex; i++){
        cout << i << " ";
        for(int j =0; j< vertex; j++){
            cout << connections[i][j] << " ";
        }
        cout << endl;
    }
}

void Graph::BFS(int start){
    vector<bool> visited(vertex, false);
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while(!q.empty()){
        int current = q.front();
        q.pop();
        cout << current << " ➡ ";
        for(int i =0; i< vertex; i++){
            if(connections[current][i] == 1 && !visited[i]){
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

void Graph::DFS(int start){
    vector<bool> visited(vertex, false);
    stack<int> s;
    s.push(start);
    visited[start] = true;
    while(!s.empty()){
        int current = s.top();
        s.pop();
        cout << current << " ➡ ";
        for(int i =0; i< vertex; i++){
            if(connections[current][i] == 1 && !visited[i]){
                s.push(i);
                visited[i] = true;
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

