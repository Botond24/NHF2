//
// Created by sziha on 16/04/2024.
//

#include "edge.h"

int Edge::getWeight() const {
    return weight;
}

Node& Edge::getFrom() const {
    if (from == nullptr) throw std::bad_alloc();
    return *from;
}

Node& Edge::getTo() const {
    if (to == nullptr) throw std::bad_alloc();
    return *to;
}

void Edge::setWeight(int w) {
    weight = w;
}

void Edge::setFrom(Node &node) {
    from = &node;
}

void Edge::setTo(Node &node) {
    to = &node;
}
