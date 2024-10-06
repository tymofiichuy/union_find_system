#include "test_graph.hpp"
#include <iostream>
#include<random>

using namespace std;

test_graph::test_graph(int size){
    vertices = size;
    edges = nullptr;
}

void test_graph::reset_edges(){
    while(edges){
        edge_node* temp = edges;
        edges = edges->next;
        delete temp;
    }
}

test_graph::~test_graph(){
    this->reset_edges();
}

void test_graph::add_edge(edge e){
    edge_node* node = new edge_node();
    node->value = e;
    if(edges){
        edges->prev = node;
        node->next = edges;        
    }
    edges = node;
}

void test_graph::random_graph(int min_weight, int max_weight, int probability){
    random_device rd;
    mt19937 mt (rd());
    uniform_int_distribution<float> dist_w (min_weight, max_weight);
    uniform_int_distribution<int> dist_pr (1, 100);
    for(int i = 1; i <= vertices; i++){
        for(int j = i+1; j <= vertices; j++){
            if(dist_pr(mt) <= probability){
                this->add_edge({i, j, dist_w(mt)});
            }
        }
    }
}