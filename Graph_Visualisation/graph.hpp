#ifndef GRAPH_CPP
#define GRAPH_CPP

        // A C++ header file to implement graph with 'int' node(s) value(s).
        #include <bits/stdc++.h> 
        using namespace std; 

        // Graph is represented using adjacency list. Every node of 
        // adjacency list contains vertex number of the vertex to 
        // which edge connects. It also contains weight of the edge.
        class AdjListNode 
        { 
            int v; 
            int weight; 
        public: 
            AdjListNode(int _v, int _w) 
            { 
                v = _v; 
                weight = _w; 
            } 
            int getV() 
            { 
                return v; 
            } 
            int getWeight() 
            { 
                return weight; 
            } 
        };

        // Graph class represents a directed graph using adjacency 
        // list representation 
        class Graph 
        { 
            int V; // No. of vertices 

            // Pointer to an array containing adjacency lists 
            list<AdjListNode>* adj; 

            // This function uses DFS 
            void longestPathUtil(int, vector<bool> &, stack<int> &); 
        public: 
            Graph(int); // Constructor 
            ~Graph(); // Destructor 

            // function to add an edge to graph 
            void addEdge(int, int, int); 
        }; 

        Graph::Graph(int V) // Constructor 
        { 
            this->V = V; 
            adj = new list<AdjListNode>[V]; 
        } 

        Graph::~Graph() // Destructor 
        { 
            delete[] adj; 
        } 

        void Graph::addEdge(int u, int v, int weight) 
        { 
            AdjListNode node(v, weight); 
            adj[u].push_back(node); // Add v to u's list 
        } 

#endif
