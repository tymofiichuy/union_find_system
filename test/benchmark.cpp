#include "test_graph.hpp"
#include <iostream>
#include<chrono>

using namespace std;

int main(){
    chrono::microseconds total(0);
    for(int i = 25; i <= 300; i = i+25){
        total = chrono::microseconds(0);
        test_graph in_graph(i);
        test_graph out_graph(i);        
        for(int j = 0; j < 10000; j++){
            in_graph.random_graph(1, 25, 10);
            auto start = chrono::high_resolution_clock::now();
            in_graph.min_spanning_tree(out_graph);
            auto end = chrono::high_resolution_clock::now();
            total += chrono::duration_cast<chrono::microseconds>(end - start);
            if(j%1000 == 0){
                cout << j/100 << "% ";
            }
        }
        cout << "100%\n";
        cout << "Kruskal algorithm test for " << i << " vertices: " << total.count()/10000 << " microseconds\n"; 
    }
    return 0;
}