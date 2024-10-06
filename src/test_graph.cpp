#include "test_graph.hpp"
#include "union_find.hpp"
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

bool edge::operator==(edge& in){
    return((this->from == in.from)
    &&(this->to == in.to)
    &&(this->weight == in.weight));
}

edge edge::redirect(){
    edge res;
    res.from = this->to;
    res.to = this->from;
    res.weight = this->weight;
    return res;
}

void test_graph::add_edge(edge e){
    edge_node* node = new edge_node();
    edge_node* rev_node = new edge_node();
    node->value = e;
    rev_node->value = e.redirect();

    node->prev = rev_node;
    rev_node->next = node;
    
    if(edges){
        edge_node* temp = edges;
        if(temp->value.weight >= e.weight){
            edges->prev = node;
            node->next = edges;
            edges = rev_node;
        }
        else{
            while(temp->next){
                if(temp->next->value.weight < e.weight){
                    temp = temp->next;
                }
                else{
                    break;
                }
            }
            edge_node* temp_poi = temp->next;
            temp->next = rev_node;
            rev_node->prev = temp;        
            if(temp_poi){
                temp_poi->prev = node;
                node->next = temp_poi;            
            }            
        }
    }
    else{
        edges = rev_node;
    }
}

void test_graph::min_spanning_tree(test_graph& out){
    out.reset_edges();
    union_find_table table(vertices);
    edge_node* temp = edges;
    int x, y;
    while(table.power > 1 && temp){
        x = table.find(temp->value.from);
        y = table.find(temp->value.to);
        if(x != y){
            table.set_union(x, y);
            out.add_edge(temp->value);
        }
        temp = temp->next->next;
    }
}

void test_graph::random_graph(int min_weight, int max_weight, int probability){
    this->reset_edges();
    random_device rd;
    mt19937 mt (rd());
    uniform_int_distribution<int> dist_w (min_weight, max_weight);
    uniform_int_distribution<int> dist_pr (1, 100);
    for(int i = 1; i <= vertices; i++){
        for(int j = i+1; j <= vertices; j++){
            if(dist_pr(mt) <= probability){
                this->add_edge({i, j, dist_w(mt)});
            }
        }
    }
}