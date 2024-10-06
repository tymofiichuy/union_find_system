class union_find_table{
private:
    int un_power;
    int* r_array;
    int* next_array;
    int* list;
    int* size_array;
    int* internal_names;
    int* external_names;
public:
    int power;

    union_find_table(int size = 0);
    ~union_find_table();

    //"x" here is element
    int find(int x);
    //"x" and "y" here are external names
    int set_union(int x, int y);
};