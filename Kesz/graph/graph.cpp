//
// Created by sziha on 16/04/2024.
//

#include "graph.h"

Graph::Graph(const Graph& other) {
    if (nodes != nullptr) delete nodes;
    if (edges != nullptr) delete edges;
    if (other.nodes != nullptr)
        nodes = new Vector<Node>(*other.nodes);
    if (other.edges != nullptr)
        edges = new Vector<Edge>(*other.edges);
}

Graph& Graph::operator=(const Graph& other) {

    if (this != &other) {
        if (nodes != nullptr) delete nodes;
        if (edges != nullptr) delete edges;
        if (other.nodes != nullptr)
            nodes = new Vector<Node>(*other.nodes);
        if (other.edges != nullptr)
            edges = new Vector<Edge>(*other.edges);
    }
    return *this;
}

Graph::Graph(const Vector<Node> &nodes, const Vector<Edge> &edges) {
    if (this->nodes != nullptr && this->nodes != &nodes) delete this->nodes;
    if (this->edges != nullptr && this->edges != &edges) delete this->edges;
    this->nodes = new Vector<Node>(nodes);
    this->edges = new Vector<Edge>(edges);
}

bool Graph::operator==(const Graph &other) const {
    return *nodes == *other.nodes && *edges == *other.edges;
}

void Graph::print() const {
    for (size_t i = 0; i < nodes->getSize(); ++i) {
        Vector<Edge*> edgeTemp = (*nodes)[i].getOutEdges();
        for (size_t j = 0; j < edgeTemp.getSize(); ++j) {
            std::cout << edgeTemp[j]->getFrom().getName() << " --"<< edgeTemp[j]->getWeight() <<"-> " << edgeTemp[j]->getTo().getName() << std::endl;
        }
    }
}

Vector<Node> &Graph::getNodes() const {
    return *nodes;
}

Vector<Edge> &Graph::getEdges() const {
    return *edges;
}

void Graph::addEdge(Edge &edge) {
    if (edges == nullptr) edges = new Vector<Edge>();
    edges->push_back(edge);
}

void Graph::deleteEdge(Edge &edge) {
    if (edges == nullptr) throw std::bad_alloc();
    edges->remove(edge);
    edge.getFrom().removeInEdge(&edge);
    edge.getTo().removeOutEdge(&edge);
    delete &edge;
}

void Graph::addNode(Node &node) {
    if (nodes == nullptr) nodes = new Vector<Node>();
    nodes->push_back(node);
}

Node &Graph::getNodeByName(String& name) {
    for (size_t i = 0; i < nodes->getSize(); ++i) {
        if ((*nodes)[i].getName() == name) {
            return (*nodes)[i];
        }
    }
    throw std::invalid_argument("Node not found");
}

Node &Graph::getNodeByName(char *name) {
    for (size_t i = 0; i < nodes->getSize(); ++i) {
        if (strcmp((*nodes)[i].getName().getData(), name) == 0) {
            return (*nodes)[i];
        }
    }
    throw std::invalid_argument("Node not found");
}

Node &Graph::getNodeByIndex(size_t index) {
    return (*nodes)[index];
}

void Graph::deleteNodeByName(String& name) {
    if (nodes == nullptr) throw std::bad_alloc();
    for (size_t i = 0; i < nodes->getSize(); ++i) {
        if ((*nodes)[i].getName() == name) {
            nodes->remove((*nodes)[i]);
            for (int j = 0; j < (*nodes)[i].getOutEdges().getSize(); ++j) {
                deleteEdge(*((*nodes)[i].getOutEdges()[j]));
            }
            for (int j = 0; j < (*nodes)[i].getInEdges().getSize(); ++j) {
                deleteEdge(*((*nodes)[i].getInEdges()[j]));
            }
            return;
        }
    }
    throw std::invalid_argument("Node not found");
}

void Graph::deleteNodeByName(char *name) {
    for (size_t i = 0; i < nodes->getSize(); ++i) {
        if (strcmp((*nodes)[i].getName().getData(), name) == 0) {
            nodes->remove((*nodes)[i]);
            for (int j = 0; j < (*nodes)[i].getOutEdges().getSize(); ++j) {
                deleteEdge(*((*nodes)[i].getOutEdges()[j]));
            }
            for (int j = 0; j < (*nodes)[i].getInEdges().getSize(); ++j) {
                deleteEdge(*((*nodes)[i].getInEdges()[j]));
            }
            return;
        }
    }
    throw std::invalid_argument("Node not found");
}

void Graph::deleteNodeByIndex(size_t index) {
    nodes->remove((*nodes)[index]);
    for (int j = 0; j < (*nodes)[index].getOutEdges().getSize(); ++j) {
        deleteEdge(*((*nodes)[index].getOutEdges()[j]));
    }
    for (int j = 0; j < (*nodes)[index].getInEdges().getSize(); ++j) {
        deleteEdge(*((*nodes)[index].getInEdges()[j]));
    }
}

void Graph::LoadGraph(const char *filename) {
    if (nodes != nullptr) delete nodes;
    if (edges != nullptr) delete edges;
    nodes = new Vector<Node>();
    edges = new Vector<Edge>();
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::invalid_argument("File not found");
    }
    String line;
    file >> line;
    size_t last_sep = 0;
    for (size_t i = 0; i < line.getSize(); ++i) {
        if (line[i] == ' ') {
            Node *n = new Node(line.getSubVector(last_sep, i));
            addNode(*n);
            last_sep = i + 1;
        }
    }
    size_t curr_line = 0;
    while (file >> line) {
        last_sep = 0;
        for (size_t i = 0; i < line.getSize(); ++i) {
            if (line[i] == ' ') {
                int w = std::stoi(line.getSubVector(last_sep, i).getData());
                if (w == 0) continue;
                Edge *e = new Edge((*nodes)[curr_line], (*nodes)[i], w);
                (*nodes)[curr_line].addOutEdge(e);
                (*nodes)[i].addInEdge(e);
                addEdge(*e);
                last_sep = i + 1;
            }
        }
        curr_line++;
    }

    file.close();
}

void Graph::SaveGraph(const char *filename) {
    if (nodes == nullptr || edges == nullptr) throw std::bad_alloc();
    std::ofstream file(filename);
    for (size_t i = 0; i < nodes->getSize(); ++i) {
        file << (*nodes)[i].getName() << (i == nodes->getSize() - 1 ? "" : " ") ;
    }
    file << std::endl;
    for (size_t i = 0; i < nodes->getSize(); ++i) {
        Vector<Edge*> edgeTemp = (*nodes)[i].getOutEdges();
        size_t last_node = -1;
        for (size_t j = 0; j < edgeTemp.getSize(); ++j) {
            size_t curr_node = nodes->find(edgeTemp[j]->getTo());
            if (curr_node != last_node) {
                while ( last_node < curr_node) {
                    file << "0 ";
                    last_node++;
                }
                file << edgeTemp[j]->getWeight() << " ";
                last_node = curr_node + 1;
            }
        }
        file << std::endl;
    }

    file.close();
}

void Graph::PrintGraph(const char *filename) {
    if (nodes == nullptr || edges == nullptr) throw std::bad_alloc();
    std::ofstream file(filename);
    file << "```mermaid\nflowchart LR" << std::endl;
    for (size_t i = 0; i < nodes->getSize(); ++i) {
        Vector<Edge*> edgeTemp = (*nodes)[i].getOutEdges();
        for (size_t j = 0; j < edgeTemp.getSize(); ++j) {
            file << (*nodes)[i].getName() << "-- " << edgeTemp[j]->getWeight() << " -->" << edgeTemp[j]->getTo().getName() << std::endl;
        }
    }
    file << "```" << std::endl;

    file.close();
}

Graph::~Graph() {
    if (nodes != nullptr) delete nodes;
    if (edges != nullptr) delete edges;
}

bool Graph::operator!=(const Graph &other) const {
    return !(*this == other);
}
