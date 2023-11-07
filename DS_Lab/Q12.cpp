#include <iostream>
#include <queue>
#include <stack>
using namespace std;
class Graph{
public:
    Graph(int vertices) : V(vertices){
        adjList = new int *[V];
        for (int i = 0; i < V; ++i){
            adjList[i] = new int[V];
            for (int j = 0; j < V; ++j){
                adjList[i][j] = 0;
            }
        }
    }
    void addEdge(int u, int v){
        adjList[u][v] = 1;
    }
    void bfs(int start){
        bool *visited = new bool[V];
        for (int i = 0; i < V; ++i){
            visited[i] = false;
        }
        queue<int> q;
        q.push(start);
        visited[start] = true;
        cout << "BFS Traversal: ";
        while (!q.empty()){
            int u = q.front();
            q.pop();
            cout << u << " ";
            for (int v = 0; v < V; ++v){
                if (adjList[u][v] && !visited[v]){
                    q.push(v);
                    visited[v] = true;
                }
            }
        }
        cout << endl;
        delete[] visited;
    }
    void dfs(int start){
        bool *visited = new bool[V];
        for (int i = 0; i < V; ++i){
            visited[i] = false;
        }
        stack<int> s;
        s.push(start);
        cout << "DFS Traversal: ";
        while (!s.empty()){
            int u = s.top();
            s.pop();
            if (!visited[u]){
                cout << u << " ";
                visited[u] = true;
            }
            for (int v = 0; v < V; ++v){
                if (adjList[u][v] && !visited[v]){
                    s.push(v);
                }
            }
        }
        cout << endl;
        delete[] visited;
    }
    ~Graph(){
        for (int i = 0; i < V; ++i){
            delete[] adjList[i];
        }
        delete[] adjList;
    }
private:
    int V;
    int **adjList;
};
int main(){
    int numVertices = 7;
    Graph graph(numVertices);
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(2, 5);
    graph.addEdge(3, 6);
    int startNode = 0;
    graph.bfs(startNode);
    graph.dfs(startNode);
    return 0;
}

