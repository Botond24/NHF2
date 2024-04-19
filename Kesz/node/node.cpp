//
// Created by sziha on 16/04/2024.
//

#include "node.h"

Node::~Node() {
    delete inEdges;
    delete outEdges;
    delete name;
}

String& Node::getName() const {
    return *name;
}

String& Node::getName() {
    return *name;
}


Vector<Edge*> &Node::getInEdges() const {
    return *inEdges;
}

Vector<Edge*> &Node::getOutEdges() const {
    return *outEdges;
}

void Node::addInEdge(Edge *edge) {
    if (inEdges == nullptr) inEdges = new Vector<Edge*>();
    inEdges->push_back(edge);
}

void Node::addOutEdge(Edge *edge) {
    if (outEdges == nullptr) outEdges = new Vector<Edge*>();
    outEdges->push_back(edge);
}

Node::Node(const Node &other) {
    if (name != nullptr) delete name;
    if (inEdges != nullptr) delete inEdges;
    if (outEdges != nullptr) delete outEdges;
    name = new String(*other.name);
    inEdges = new Vector<Edge*>(*other.inEdges);
    outEdges = new Vector<Edge*>(*other.outEdges);
}


Node &Node::operator=(const Node &other) {
    if (this != &other) {
        if (name != nullptr) delete name;
        if (other.name != nullptr)
            name = new String(*other.name);
        if (inEdges != nullptr) delete inEdges;
        if (outEdges != nullptr) delete outEdges;
        if (other.inEdges != nullptr)
            inEdges = new Vector<Edge*>(*other.inEdges);
        if (other.outEdges != nullptr)
            outEdges = new Vector<Edge*>(*other.outEdges);
    }
    return *this;
}

Node::Node(char *name) : name(new String(strlen(name) + 1)), inEdges(nullptr), outEdges(nullptr) {
    strcpy(this->name->getData(), name);
}

void Node::removeInEdge(Edge *edge) {
    if (inEdges == nullptr) throw std::bad_alloc();
    inEdges->remove(edge);
}

void Node::removeOutEdge(Edge *edge) {
    if (outEdges == nullptr) throw std::bad_alloc();
    outEdges->remove(edge);
}


