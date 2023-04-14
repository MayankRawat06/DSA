#include <iostream>
#include <vector>
#include <queue>
using namespace std;
void printDfs(int **edges, int n, int sv, bool *visited) {
    cout << sv << endl;
    visited[sv] = true;
    for(int i = 0; i < n; i++) {
        if(i != sv && edges[sv][i] && !visited[i]) printDfs(edges, n, i, visited);
    }
}
void printBfs(int **edges, int n, int sv, bool *visited) {
    queue<int> pendingNodes;
    pendingNodes.push(sv);
    visited[sv] = true;
    while(!pendingNodes.empty()) {
        int v = pendingNodes.front();
        pendingNodes.pop();
        cout << v << endl;
        for(int i = 0; i < n; i++) {
            if(i != v && !visited[i] && edges[v][i]) {
                visited[i] = true;
                pendingNodes.push(i);
            }
        }
    }
}
void BFS(int **edges, int n) {
    bool *visited = new bool[n];
    for(int i = 0; i < n; i++) {
        visited[i] = false;
    }
    for(int i = 0; i < n; i++) {
        if(!visited[i]) printBfs(edges, n, i, visited);
    }
}
void DFS(int **edges, int n) {
    bool *visited = new bool[n];
    for(int i = 0; i < n; i++) {
        visited[i] = false;
    }
    for(int i = 0; i < n; i++) {
        if(!visited[i]) printDfs(edges, n, i, visited);
    }
    delete[] visited;
}
int main() {
    int n, e;
    cin >> n >> e;
    int **edges = new int*[n];
    for(int i = 0; i < n; i++) {
        edges[i] = new int[n];
        for(int j = 0; j < n; j++) {
            edges[i][j] = 0;
        }
    }
    for(int i = 0; i < e; i++) {
        int s, d;
        cin >> s >> d;
        edges[s][d] = edges[d][s] = 1;
    }
   
    DFS(edges, n);
    // BFS(edges, n);
    for(int i = 0; i < n; i++) {
        delete[] edges[i];
    }
    delete[] edges;
}