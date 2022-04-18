#include "iostream"
#include "vector"
#include "queue"
#include<bits/stdc++.h>

using namespace std;

struct ListGraph {
public:
    explicit ListGraph(int vertices_count) : vertices(vertices_count) {}

    ~ListGraph() {}

    void AddEdge(int from, int to) {
        vertices[from].push_back(to);
        vertices[to].push_back(from);
    }

    virtual int VerticesCount() const {
        return vertices.size();
    }

    int bfs(int from, int to);

private:
    std::vector<std::vector<int>> vertices;
};

int ListGraph::bfs( int from, int to) {
    std::vector<int> path (VerticesCount(), INT_MAX);
    std::vector<int> parent (VerticesCount(), INT_MAX);
    std::vector<int> counted(VerticesCount(), 0);

    std::queue<int> q;

    q.push(from);
    path[from] = 0;
    parent[from] = -1;
    counted[from] = 1;

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (auto& next: vertices[v]) {

            if (path[next] == path[v] + 1) {
                counted[next] += counted[v];
            }

            if (path[next] > path[v] + 1) {
                counted[next] = 0;
                counted[next] += counted[v];
                path[next] = path[v] + 1;
                parent[next] = v;
                q.push(next);
            }
        }
    }
    return counted[to];
}

//int main() {
//    int v;
//    cin >> v;
//    int n;
//    cin >> n;
//    int from, to;
//    std::vector<int> result;
//
//    ListGraph listGraph(v);
//
//    for (int i = 0; i < n; ++i) {
//        int v1, v2;
//        cin >> v1 >> v2;
//        listGraph.AddEdge(v1, v2);
//    }
//
//    cin >> from >> to;
//
//    cout << listGraph.bfs(from, to);
//}