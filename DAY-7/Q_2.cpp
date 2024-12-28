/*There is a bi-directional graph with n vertices, where each vertex is labeled from 0 to n - 1 (inclusive). The edges in the graph are represented as a 2D integer array edges, where each edges[i] = [ui, vi] denotes a bi-directional edge between vertex ui and vertex vi. Every vertex pair is connected by at most one edge, and no vertex has an edge to itself.
You want to determine if there is a valid path that exists from vertex source to vertex destination.
Given edges and the integers n, source, and destination, return true if there is a valid path from source to destination, or false otherwise.
*/

#include <iostream>
#include <queue>
using namespace std;

bool validPath(int n, int edges[][2], int m, int source, int destination) {
    int adj[n][n] = {0};
    for (int i = 0; i < m; i++) {
        adj[edges[i][0]][edges[i][1]] = 1;
        adj[edges[i][1]][edges[i][0]] = 1;
    }

    bool visited[n] = {false};
    queue<int> q;
    q.push(source);
    visited[source] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        if (node == destination) {
            return true;
        }

        for (int i = 0; i < n; i++) {
            if (adj[node][i] && !visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }

    return false;
}

int main() {
    int n, m, source, destination;
    cin >> n >> m;

    int edges[m][2];
    for (int i = 0; i < m; i++) {
        cin >> edges[i][0] >> edges[i][1];
    }

    cin >> source >> destination;

    if (validPath(n, edges, m, source, destination)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}
