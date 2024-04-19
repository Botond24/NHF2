//
// Created by sziha on 16/04/2024.
//

#ifndef NHF_NODE_H
#define NHF_NODE_H

#include <cstdlib>
#include <cstring>
#include "../helper/vector.h"
#include "../edge/edge.h"
#include "../helper/memtrace.h"

class Edge;

/**
 * Node class.
 */
class Node
{
    String* name; /// Name of the node
    Vector<Edge*>* inEdges; /// Vector of in edges
    Vector<Edge*>* outEdges; /// Vector of out edges
public:
    /**
     * Node constructor.
     * @param name
     */
    explicit Node(char* name);
    /**
     * Node constructor.
     * @param name
     */
    explicit Node(String& name) : name(new String(name)), inEdges(nullptr), outEdges(nullptr) {};
    /**
     * Node constructor.
     */
    Node() : name(nullptr), inEdges(nullptr), outEdges(nullptr) {};
    /**
     * Node copy constructor.
     * @param other
     */
    Node(const Node& other);
    /**
     * Node assignment operator.
     * @param other
     * @return Node
     */
    Node& operator=(const Node& other);
    /**
     * Node destructor.
     */
    ~Node();
    /**
     * Returns the name of the node.
     * @return name
     */
    [[nodiscard]] String& getName() const;
    /**
     * Returns the name of the node.
     * @return
     */
    String& getName();
    /**
     * Returns the incoming edges of the node.
     * @return Vector of edges
     */
    [[nodiscard]] Vector<Edge*>& getInEdges() const;
    /**
     * Returns the outgoing edges of the node.
     * @return Vector of edges
     */
    [[nodiscard]] Vector<Edge*>& getOutEdges() const;
    /**
     * Adds an incoming edge to the node.
     * @param edge
     */
    void addInEdge(Edge* edge);
    /**
     * Adds an outgoing edge to the node.
     * @param edge
     */
    void addOutEdge(Edge* edge);
    void removeInEdge(Edge* edge);
    void removeOutEdge(Edge* edge);
};

#endif //NHF_NODE_H
