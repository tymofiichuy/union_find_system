#include "union_find.hpp"
#include <iostream>
#include <algorithm>

using namespace std;

//initialize "size" sets of power 1
union_find_table::union_find_table(int size){
    un_power = size;
    r_array = new int[size];
    next_array = new int[size];
    list = new int[size];
    size_array = new int[size];
    internal_names = new int[size];
    external_names = new int[size];

    for(int i = 0; i < un_power; i++){
        internal_names[i] = i;
        external_names[i] = i;
        r_array[i] = i; 
        list[i] = i; 
        //"-1" is a terminator here since "0" is a valid value
        next_array[i] = -1;
        size_array[i] = 1;
    }

    power = size;
}

union_find_table::~union_find_table(){
    delete[] r_array;
    delete[] next_array;
    delete[] list;
    delete[] size_array;
    delete[] internal_names;
    delete[] external_names;
}

int union_find_table::find(int x){
    if(x <= un_power){
        return external_names[r_array[x]];        
    }
    else{
        throw invalid_argument("Out of boundaries");
    }
}

int union_find_table::set_union(int x, int y){
    power--;

    x = internal_names[x];
    y = internal_names[y];
    if(size_array[x] > size_array[y]){
        swap(x, y);
    }
    int temp = list[x];
    int last;

    while(temp+1){
        r_array[temp] = y;
        last = temp;
        temp = next_array[temp];
    }

    size_array[y] += size_array[x];
    size_array[x] = 0;
    next_array[last] = list[y];
    list[y] = list[x];
    //!
    internal_names[external_names[x]] = y;
    external_names[y] = external_names[x];
    return external_names[y]; 
}