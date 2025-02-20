#include <iostream>
#include <vector>
#include <cstdlib>
#include <random>
#include <limits>
#include <queue>
#include <algorithm>
#include <numeric>
#include <fstream>

using namespace std;

// **GRAPH CLASS**
class Graph{

    private:

        int Vertice, Edge; // number of vertices and edges
        vector<vector<double>> adjMatrix; // weighted undirected adjacency matrix
        vector<double> nodeList; // node vector

    public:

        Graph(int vertices): Vertice(vertices), Edge(0){ // Vertice is initialized with vertices
            adjMatrix.resize(vertices, vector<double>(vertices, numeric_limits<double>::infinity()));
            for (int i = 0; i < vertices; i++) {
                adjMatrix[i][i] = 0;  // Distance to self is zero
            }
            nodeList.resize(vertices, 0);
        }

        int V(){
            return Vertice; // returns the number of Vertice in the graph
        }

        int E(){
            return Edge; // returns the number of Edge in the graph
        }

        void add_edge(int x, int y, double weight){
            if (x != y){ // distance to self is always zero
            adjMatrix[x][y] = weight; adjMatrix[y][x] = weight; // undirected and symmetric
            Edge++; // update the number of edge
            }
        }

        vector <int> neighbors(int y){
            vector <int> neighbors_vector; // neighbors_vector collect neighbors of y
            for(int i=0; i<Vertice; i++){
                if(adjMatrix[i][y]!=0){
                    neighbors_vector.push_back(i); // fill the neighbors vector
                }
            }
            return neighbors_vector;
        }

        double getEdgeValue(int x, int y){
            return adjMatrix[x][y]; // return given address of weighted graph
        }

        void setEdgeValue(int x, int y, double weight){
            adjMatrix[x][y] = weight; // weight of the given address is updated
        }

        void setNodeValue(int x, double weight){
            nodeList[x] = weight; // weight of the given place is updated in node list
        }

        double getNodeValue(int x){
            return nodeList[x]; // return the given place of the node's value
        }

        vector<pair<double, pair<int, int>>> getEdges() {
        vector<pair<double, pair<int, int>>> edges;
        for (int i = 0; i < Vertice; ++i) {
            for (int j = i + 1; j < Vertice; ++j) {
                if (adjMatrix[i][j] < numeric_limits<double>::infinity()) {
                    edges.emplace_back(adjMatrix[i][j], make_pair(i, j));
                }
            }
        }
        return edges;
    }
};

// ** UNION FIND CLASS**
class UnionFind{

    private:

        vector <int> parent, rank;

    public:

        UnionFind(int n): parent(n), rank(n, 0){
            iota(parent.begin(), parent.end(),0);
        }

        int find(int x){
            if (parent[x] != x){
                parent[x] = find(parent[x]);
            }
            return parent[x];
        }

        void unionSets(int x, int y){
            int rootX = find(x);
            int rootY = find(y);

            if (rootX != rootY) {
                if (rank[rootX] < rank[rootY]) {
                    parent[rootX] = rootY;
                } else if (rank[rootX] > rank[rootY]) {
                    parent[rootY] = rootX;
                } else {
                    parent[rootY] = rootX;
                    rank[rootX]++;
                }
            }
        }
};


// **MINIMUM SPANNING TREE CLASS**
class MinimumSpanningTree{   

    private:

        Graph& g;


    public:

        MinimumSpanningTree(Graph& graph): g(graph){}

        double kruskal(){
            vector <pair<double, pair<int, int>>> edges = g.getEdges();
            sort(edges.begin(), edges.end());

            UnionFind uf(g.V());
            double minSpan = 0.0;
            
            for (auto& edge : edges){
                double weight = edge.first;
                double u = edge.second.first;
                double v = edge.second.second;

                if (uf.find(u) != uf.find(v)){
                    uf.unionSets(u,v);
                    minSpan += weight;
                }
            }
            return minSpan;
        }

            
};

int main() {
    int vertices, i, j, weight;
    
    ifstream inputFile("input.txt");
    if (!inputFile) {
        cerr << "Error opening file" << endl;
        return 1;
    }

    inputFile >> vertices;
    Graph graph(vertices);

    while (inputFile >> i >> j >> weight) {
        graph.add_edge(i, j, weight);
    }

    inputFile.close();

    MinimumSpanningTree MST(graph);
    cout << "Total cost of MST using Kruskal's Algorithm: " << MST.kruskal() << endl;

    return 0;
}
