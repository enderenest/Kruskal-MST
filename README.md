# 🌿 Minimum Spanning Tree using Kruskal's Algorithm

## 📝 Project Overview

This project is an implementation of Kruskal's Algorithm to find the Minimum Spanning Tree (MST) of a weighted, undirected graph. It uses Union-Find data structure for cycle detection and edge union, along with a Graph class for representing the graph with an adjacency matrix.

---

## 🏛️ Key Components

### 1️⃣ Graph Class

Manages vertices, edges, and weights using an adjacency matrix.

Key functions:

add_edge(int x, int y, double weight) – Adds an edge between vertices x and y with a given weight.

V() – Returns the number of vertices.

E() – Returns the number of edges.

getEdges() – Returns all edges with their weights.

### 2️⃣ UnionFind Class

Implements the Union-Find data structure with path compression and union by rank.

Key functions:

find(int x) – Finds the root of the set containing x.

unionSets(int x, int y) – Unites the sets containing x and y.

### 3️⃣ MinimumSpanningTree Class

Uses Kruskal's Algorithm to compute the MST.

Key function:

kruskal() – Computes and returns the total weight of the Minimum Spanning Tree.

---

## ▶️ How to Run

The repository already contains a sample input file named sample.txt. You can use it directly to test the program.

Compile and run the program:

g++ main.cpp -o mst
./mst

---

## 📤 Sample Output

Total cost of MST using Kruskal's Algorithm: 19

---

## 🧑‍💻 Dependencies

C++11 or later

---

## 📫 Contact

Feel free to reach out for questions or contributions!
