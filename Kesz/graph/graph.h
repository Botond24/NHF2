//
// Created by sziha on 16/04/2024.
//

#ifndef NHF_GRAPH_H
#define NHF_GRAPH_H

#include "../helper/memtrace.h"
#include "../helper/vector.h"
#include "../node/node.h"
#include "../edge/edge.h"
#include <iostream>
#include <fstream>

/**
 * Graph class
 */
class Graph {
    Vector<Node>* nodes; /// Vector of nodes
    Vector<Edge>* edges; /// Vector of edges
public:
    /**
     * Graph constructor
     * @param nodes count
     * @param edges count
     */
    Graph(int nodes, int edges) : nodes(new Vector<Node>(nodes)), edges(new Vector<Edge>(edges)) {}
    /**
     * Graph constructor
     */
    Graph() : nodes(nullptr), edges(nullptr) {}
    /**
     * Graph copy constructor
     * @param other
     */
    Graph(const Graph& other);
    /**
     * Graph constructor
     * @param nodes
     * @param edges
     */
    Graph(const Vector<Node>& nodes, const Vector<Edge>& edges);
    /**
     * Graph destructor
     */
    ~Graph();
    /**
     * Operator == for graphs
     * @param other
     * @return bool
     */
    bool operator==(const Graph& other) const;
    /**
     * Operator != for graphs
     * @param other
     * @return bool
     */
    bool operator!=(const Graph& other) const;
    /**
     * Prints graph
     */
    void print() const;
    /**
     * Assign operator
     * @param other
     * @return Graph
     */
    Graph& operator=(const Graph& other);
    /**
     * Returns the nodes
     * @return Vector of nodes
     */
    Vector<Node>& getNodes() const;
    /**
     * Returns the edges
     * @return Vector of edges
     */
    Vector<Edge>& getEdges() const;
    /**
     * Adds an edge
     * @param edge
     */
    void addEdge(Edge& edge);
    /**
     * Deletes an edge
     * @param edge
     */
    void deleteEdge(Edge& edge);
    /**
     * Adds a node
     * @param node
     */
    void addNode(Node& node);
    /**
     * Gets a node by name
     * @param name
     * @return Node
     */
    Node& getNodeByName(String & name);
    /**
     * Gets a node by name
     * @param name
     * @return Node
     */
    Node& getNodeByName(char* name);
    /**
     * Gets a node by index
     * @param index
     * @return Node
     */
    Node &getNodeByIndex(size_t index);
    /**
     * Deletes a node by name
     * @param name
     */
    void deleteNodeByName(String & name);
    /**
     * Deletes a node by name
     * @param name
     */
    void deleteNodeByName(char* name);
    /**
     * Deletes a node by index
     * @param index
     */
    void deleteNodeByIndex(size_t index);
    /**
     * Loads a graph from a file
     * @param filename
     */
    void LoadGraph(const char* filename);
    /**
     * Saves a graph to a file
     * @param filename
     */
    void SaveGraph(const char* filename);
    /**
     * Generates Mermaid graph for the graph
     * @param filename
     */
    void PrintGraph(const char* filename);
};

#endif //NHF_GRAPH_H
