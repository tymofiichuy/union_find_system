struct edge{
    int from;
    int to;
    int weight;

    bool operator==(edge&);
    edge redirect();
};

struct edge_node{
    edge value;
    edge_node* next = nullptr;
    edge_node* prev = nullptr;
};

class test_graph{
public:
    int vertices;
    edge_node* edges = nullptr;

    test_graph(int size = 0);
    ~test_graph();

    void reset_edges();
    void add_edge(edge);
    void random_graph(int min_weight, int max_weight, int probability);
    //void sort_edges(edge_node* start, edge_node* end);
};