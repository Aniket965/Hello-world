#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <unordered_map>

using namespace std;

int DFS(unordered_map<int, vector<int>>& graph, int key, unordered_map<int, int>& marked, int *time, unordered_map<int, int>& finalTime) {
    *time = *time + 1;
    marked[key] = 1;
    for (int neighbor : graph[key]) {
        if (marked[neighbor] == 0) {
            if (DFS(graph, neighbor, marked, time, finalTime)) return 1;
        }
        else if (marked[neighbor] == 1) {
            marked[neighbor] = 2;
            return 1;
        }
    }
    marked[key] = 2;
    *time = *time + 1;
    finalTime[key] = *time;
    return 0;
}

int main(int argc, char const *argv[]) {

    FILE* inputFile = fopen(argv[1], "r");

    int numberVertices, numberEdges;
    fscanf(inputFile, "%d %d\n", &numberVertices, &numberEdges);

    //creates and fills a graph using inputFile data
    unordered_map<int, vector<int>> graph;
    //creates a vector that will hold the keys of DFS walking order
    set<int> order;
    //creates a vector that will check if the graph is of type 1 or 2
    set<int> defineType;

    int vertexA, vertexB;
    for (int i = 0; i < numberEdges; ++i) {
        fscanf(inputFile, "%d %d\n", &vertexA, &vertexB);
        //insert vertices on a set to make sure they'll be unique
        order.insert(vertexA);
        order.insert(vertexB);
        //insert vertices on graph
        graph[vertexA].push_back(vertexB);
        defineType.insert(vertexA);
    }
    fclose(inputFile);

    //marks vertices as unvisiteds
    unordered_map<int, int> marked;
    for (auto vertex : graph) {
        marked[vertex.first] = 0;
    }

    //creates a final time hashtable for graph
    unordered_map<int, int> finalTime;

    //inserts content of set on a vector so it can be ordered
    vector<int> vertices;
    for (int v : order) {
        vertices.push_back(v);
    }
    sort(vertices.begin(), vertices.end());

    FILE* outputFile = fopen(argv[2], "w");

    //runs DFS
    int isCycle = 0;
    int time = 0;
    for (int vertex : vertices) {
        if (marked[vertex] != 2) {
            if (DFS(graph, vertex, marked, &time, finalTime) == 1) {
                fprintf(outputFile, "0 -1\n");
                return 0;
            }
        }
    }

    //define the type of graph
    if (defineType.size() < numberVertices - 1)
        fprintf(outputFile, "2 ");
    else fprintf(outputFile, "1 ");

    //sort vertices according to finalTime in growing order
    sort(vertices.begin(), vertices.end(), [&finalTime](int a, int b) {
        return finalTime[a] < finalTime[b];
    });

    //prints output
    for (int v : vertices) {
        if (v == vertices.back()) fprintf(outputFile, "%d\n", v);
        else fprintf(outputFile, "%d, ", v);
    }

    fclose(outputFile);

    return 0;
}
