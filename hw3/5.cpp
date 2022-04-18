//
// Created by sonichka on 14.01.2022.
//
#include "iostream"
#include "vector"
#include "../AVLtree.cpp"
#include "set"
#include<bits/stdc++.h>

using namespace std;

struct WeightMatrixGraph {
public:
    WeightMatrixGraph(int n) {
        verticesCount = n;
        vertices = new int *[n];

        for (int i = 0; i < n; ++i) {
            vertices[i] = new int[n];
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == j)
                    vertices[i][j] = 0;
                else
                    vertices[i][j] = 100000;
            }
        }
    }

    ~WeightMatrixGraph() {}

    void AddEdge(int from, int to, int weight) {
        vertices[from][to] = weight;
        vertices[to][from] = weight;
    }

    int VerticesCount() const {
        return verticesCount;
    }

    void mstPrimm(int edgeIdx) {
        int weightIndex = 0;
        int mst[verticesCount];
        int weights[verticesCount];

        mst[weightIndex] = edgeIdx;
        weightIndex++;

        for (int i = 0; i < verticesCount; ++i) {
            weights[weightIndex] = vertices[edgeIdx][i];
        }

        for (int i = 0; i < verticesCount; ++i) {
            int minWeight = 100000;
            int minIndex = 0;

            for (int j = 0; j < verticesCount; ++j) {
                if (weights[j] != 0 && weights[j] < minWeight) {
                    minWeight = weights[j];
                    minIndex = j;
                }
            }

            mst[weightIndex] =  minIndex + 1;
            weightIndex++;
            weights[minIndex] = 0;

            for (int j = 0; j < verticesCount; ++j) {
                if (weights[j] != 0 && vertices[minIndex][j] < weights[j]) {
                    weights[j] = vertices[minIndex][j];
                }
            }
        }
    }

private:
    int **vertices;
    int verticesCount;
};


//class MST {
//public:
//    void insert()
//private:
//    std::vector<std::pair> nodes;
//};