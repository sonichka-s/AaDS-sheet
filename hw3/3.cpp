#include "iostream"
#include "vector"
#include "set"
#include<bits/stdc++.h>

using namespace std;

struct WeightGraph {
public:
    explicit WeightGraph(int n) : vertices(n) {}

    ~WeightGraph() {}

    void AddEdge(int from, int to, int weight) {
        vertices[from].push_back(std::make_pair(to, weight));
        vertices[to].push_back(std::make_pair(from, weight));

    }

    int MinLength(int from, int to);


private:
    std::vector<std::vector<std::pair<int, int>>> vertices;
};


int WeightGraph::MinLength(int from, int to) {
    std::vector<int> parent(vertices.size(), 0);
    std::vector<int> path(vertices.size(), INT_MAX);

    parent[from] = -1;
    path[from] = 0;
    std::set<std::pair<int, int>> pQueue;

    pQueue.insert(std::make_pair(0, from));

    while (!pQueue.empty()) {
        auto v = pQueue.begin();
        std::pair<int, int> vertex = *v;
        v = pQueue.erase(v);

        for (auto &next: vertices[vertex.second]) {
            if (path[next.first] == INT_MAX) {

                path[next.first] = path[vertex.second] + next.second;
                parent[next.first] = vertex.second;
                pQueue.insert(std::make_pair(path[next.first], next.first));
            }

            else if (path[next.first] > path[vertex.second] + next.second) {

                auto elem = pQueue.find(std::make_pair(path[next.first], next.first));
                elem = pQueue.erase(elem);

                path[next.first] = path[vertex.second] + next.second;
                parent[next.first] = vertex.second;

                pQueue.insert(std::make_pair(path[next.first], next.first));
            }
        }
    }
    return path[to];
}

//int main() {
//    int v;
//    cin >> v;
//    int n;
//    cin >> n;
//    int from, to;
//
//    WeightGraph weightGraph(v);
//
//    for (int i = 0; i < n; ++i) {
//        int v1, v2, weight;
//        cin >> v1 >> v2 >> weight;
//        weightGraph.AddEdge(v1, v2, weight);
//    }
//
//    cin >> from >> to;
//
//    cout << weightGraph.MinLength(from, to);
//}