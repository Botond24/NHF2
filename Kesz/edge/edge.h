//
// Created by sziha on 16/04/2024.
//

#ifndef NHF_EDGE_H
#define NHF_EDGE_H

#include "../helper/vector.h"
#include "../node/node.h"
#include "../helper/memtrace.h"

class Node;
/**
 * Edge class
 */
class Edge
{
protected:
    int weight; /// The weight of the edge
    Node* from; /// The node from which the edge starts
    Node* to; /// The node at which the edge ends
public:
    /**
     * Edge constructor
     * @param from
     * @param to
     * @param weight
     */
    Edge(Node& from, Node& to, int weight) : weight(weight), from(&from), to(&to) {}
    /**
     * Edge constructor
     */
    Edge() : weight(0), from(nullptr), to(nullptr) {};
    /**
     * Returns the weight of the edge
     * @return weight
     */
    int getWeight() const;
    /**
     * Returns the node from which the edge starts
     * @return Node
     */
    Node& getFrom() const;
    /**
     * Returns the node at which the edge ends
     * @return Node
     */
    Node& getTo() const;
    /**
     * Sets the weight of the edge
     * @param w weight
     */
    void setWeight(int w);
    /**
     * Sets the node from which the edge starts
     * @param node
     */
    void setFrom(Node& node);
    /**
     * Sets the node at which the edge ends
     * @param node
     */
    void setTo(Node& node);
};

#endif //NHF_EDGE_H
