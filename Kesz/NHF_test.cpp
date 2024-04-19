//
// Created by sziha on 16/04/2024.
//

#include "NHF_test.h"

/*
 * TODO: tests:
 *  x  - graph loading
 *  x  - graph printing
 *  x  - mermaid printing
 *  x  - graph saving
 *  x  - edge adding
 *    - edge deleting
 *    - node adding
 *    - node deleting
 *    - node finding
 */

int main() {
    Graph g1 = Graph();
    g1.LoadGraph("graph1.txt");
    g1.SaveGraph("graph1_saved.txt");
    std::ifstream f1("graph1.txt");
    std::ifstream f2("graph1_saved.txt");
    std::string line1;
    std::string line2;
    while (std::getline(f1, line1) && std::getline(f2, line2)) {
        EXPECT_EQ(line1, line2);
    }
    f1.close();
    f2.close();
    g1.PrintGraph("graph1.md");
    g1 = Graph();
    Graph g2 = Graph();
    assert(g1 != g2);
    g2.LoadGraph("graph1.txt");
    assert(g1 == g2);
    g1.LoadGraph("graph1.txt");
    assert( g1 != g2 );
    g2.LoadGraph("graph1_saved.txt");
    assert( g1 != g2 );
    Edge e1 = Edge(g1.getNodeByIndex(0), g1.getNodeByIndex(1), 3);
    g1.addEdge(e1);
    assert(g1 == g2);
    g2.addEdge(e1);
    assert(g1 != g2);
    g1.print();
    g2.print();
    g1.SaveGraph("graph1_saved.txt");
    g2.PrintGraph("graph2.md");
    return 0;
}