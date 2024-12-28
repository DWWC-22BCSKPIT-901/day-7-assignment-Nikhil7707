/*Given a directed acyclic graph (DAG) of n nodes labeled from 0 to n - 1, find all possible paths from node 0 to node n - 1 and return them in any order.
The graph is given as follows: graph[i] is a list of all nodes you can visit from node i (i.e., there is a directed edge from node i to node graph[i][j]).
*/
#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<int>>& graph, vector<int>& path, vector<vector<int>>& result, int node, int target) {
    path.push_back(node);

    if (node == target) {
        result.push_back(path);
    } else {
        for (int next : graph[node]) {
            dfs(graph, path, result, next, target);
        }
    }

    path.pop_back();  // backtrack
}

vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    vector<vector<int>> result;
    vector<int> path;
    int target = graph.size() - 1;  // node n-1
    dfs(graph, path, result, 0, target);  // start DFS from node 0
    return result;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> graph(n);
    for (int i = 0; i < n; i++) {
        int size;
        cin >> size;
        graph[i].resize(size);
        for (int j = 0; j < size; j++) {
            cin >> graph[i][j];
        }
    }

    vector<vector<int>> result = allPathsSourceTarget(graph);

    for (const auto& path : result) {
        for (int node : path) {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}
