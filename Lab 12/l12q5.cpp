#include <iostream>
#include <queue>
using namespace std;

class Graph {
private:
    int vertices;
    int** adjMatrix;
    
public:
    Graph(int v) {
        vertices = v;
        adjMatrix = new int*[v];
        for (int i = 0; i < v; i++) {
            adjMatrix[i] = new int[v];
            for (int j = 0; j < v; j++) {
                adjMatrix[i][j] = 0; } }
    }
    
    void addEdge(int u, int v) {
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;
    }
    
    void displayAdjacencyMatrix() {
        cout << "Adjacency Matrix:" << endl;
        cout << "  ";
        for (int i = 0; i < vertices; i++) {
            cout << i + 1 << " "; }
        cout << endl;
        for (int i = 0; i < vertices; i++) {
            cout << i + 1 << " ";
            for (int j = 0; j < vertices; j++) {
                cout << adjMatrix[i][j] << " "; }
            cout << endl; }
    }
    
    void displayAdjacencyList() {
        cout << "Adjacency list:" << endl;
        for (int i = 0; i < vertices; i++) {
            cout << i + 1 << ": ";
            bool first = true;
            for (int j = 0; j < vertices; j++) {
                if (adjMatrix[i][j] == 1) {
                    if (!first) cout << ", ";
                    cout << j + 1;
                    first = false; }  }
            cout << endl; }
    }
    
    void BFS(int start) {
        bool* visited = new bool[vertices];
        for (int i = 0; i < vertices; i++) {
            visited[i] = false; }
        queue<int> q;
        visited[start] = true;
        q.push(start);
        cout << "BFS Traversal: ";
        while (!q.empty()) {
            int current = q.front();
            q.pop();
            cout << current + 1 << " ";
            for (int i = 0; i < vertices; i++) {
                if (adjMatrix[current][i] == 1 && !visited[i]) {
                    visited[i] = true;
                    q.push(i); } } }
        cout << endl;
        delete[] visited;
    }
    
    void DFSUtil(int v, bool visited[]) {
        visited[v] = true;
        cout << v + 1 << " ";
        for (int i = 0; i < vertices; i++) {
            if (adjMatrix[v][i] == 1 && !visited[i]) {
                DFSUtil(i, visited); } }
    }
    
    void DFS(int start) {
        bool* visited = new bool[vertices];
        for (int i = 0; i < vertices; i++) {
            visited[i] = false; }
        cout << "DFS Traversal: ";
        DFSUtil(start, visited);
        cout << endl;
        delete[] visited;
    }
    
    ~Graph() {
        for (int i = 0; i < vertices; i++) {
            delete[] adjMatrix[i];
        }
        delete[] adjMatrix;
    }
};

int main() {
    Graph g(5);    
    g.addEdge(0, 3); 
    g.addEdge(1, 3); 
    g.addEdge(1, 2); 
    g.addEdge(2, 4); 
    g.addEdge(3, 4);    
    g.displayAdjacencyMatrix();
    cout << endl;
    g.displayAdjacencyList();
    cout << endl;
    g.BFS(0);
    g.DFS(0);   
    return 0;
}