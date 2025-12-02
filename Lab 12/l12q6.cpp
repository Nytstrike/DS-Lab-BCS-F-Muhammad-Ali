#include <iostream>
using namespace std;

#define INF 999999
#define V 6

class Graph
{
private:
    int adjMatrix[V][V];

public:
    Graph()
    {
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                adjMatrix[i][j] = 0;
            }
        }
    }

    void addEdge(int u, int v, int weight)
    {
        adjMatrix[u][v] = weight;
        adjMatrix[v][u] = weight;
    }

    void dijkstra(int source, int target)
    {
        bool visited[V];
        int distance[V];
        int previous[V];
        for (int i = 0; i < V; i++)
        {
            visited[i] = false;
            distance[i] = INF;
            previous[i] = -1;
        }
        distance[source] = 0;
        while (!visited[target])
        {
            int selected_node = -1;
            int min_distance = INF;
            for (int v = 0; v < V; v++)
            {
                if (!visited[v] && distance[v] < min_distance)
                {
                    min_distance = distance[v];
                    selected_node = v;
                }
            }
            if (selected_node == -1)
            {
                break;
            }
            visited[selected_node] = true;
            for (int v = 0; v < V; v++)
            {
                if (adjMatrix[selected_node][v] > 0 && !visited[v])
                {
                    int alt = distance[selected_node] + adjMatrix[selected_node][v];
                    if (alt < distance[v])
                    {
                        distance[v] = alt;
                        previous[v] = selected_node;
                    }
                }
            }
        }
        cout << "Shortest path from " << char('A' + source) << " to " << char('A' + target) << ": ";
        printPath(previous, target);
        cout << "\nShortest distance: " << distance[target] << endl;
    }

    void printPath(int previous[], int target)
    {
        if (previous[target] == -1)
        {
            cout << char('A' + target);
            return;
        }
        printPath(previous, previous[target]);
        cout << " -> " << char('A' + target);
    }
};

int main()
{
    Graph g;
    g.addEdge(1, 0, 4);
    g.addEdge(1, 2, 9);
    g.addEdge(0, 3, 8);
    g.addEdge(2, 3, 6);
    g.addEdge(2, 4, 14);
    g.addEdge(4, 5, 3);
    g.addEdge(3, 5, 4);
    g.dijkstra(1, 4);
    return 0;
}