/*There is an undirected star graph consisting of n nodes labeled from 1 to n. A star graph is a graph where there is one center node and exactly n - 1 edges that connect the center node with every other node.
You are given a 2D integer array edges where each edges[i] = [ui, vi] indicates that there is an edge between the nodes ui and vi. Return the center of the given star graph.*/

#include <iostream>
using namespace std;

int findCenter(int edges[][2], int n) {
    if (edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1]) {
        return edges[0][0];
    }
    return edges[0][1];
}

int main() {
    int n; 
    cout << "Enter the number of edges: ";
    cin >> n;

    int edges[n][2]; 
    cout << "Enter the edges (u v format):\n";
    for (int i = 0; i < n; i++) {
        cin >> edges[i][0] >> edges[i][1];
    }

    int center = findCenter(edges, n);
    cout << "The center of the star graph is: " << center << endl;

    return 0;
}

