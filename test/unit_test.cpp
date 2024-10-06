#include <iostream>
#include <gtest/gtest.h>
#include "union_find.hpp"
#include "test_graph.hpp"

using namespace std;

TEST(StructureTest, LNKTest){
  EXPECT_EQ(1, 1);
}

TEST(UnionFindTest, PositiveFindTest){
    union_find_table set_system(4);

    int res = set_system.find(2);

    EXPECT_EQ(res, 2);
}

TEST(UnionFindTest, NegativeFindTest){
    union_find_table set_system(4);
           
    EXPECT_ANY_THROW(set_system.find(5));
}

TEST(UnionFindTest, SingleUnionTest){
    union_find_table set_system(4);
    
    set_system.set_union(1, 3);
    int res = set_system.find(3);

    EXPECT_EQ(res, 1); 
}

TEST(UnionFindTest, MultipleUnionTest){
    union_find_table set_system(4);
    
    set_system.set_union(1, 3);
    set_system.set_union(1, 2);
    int res_1 = set_system.find(2);
    int res_2 = set_system.find(3);
    
    EXPECT_EQ(res_1, 2);
    EXPECT_EQ(res_2, 2); 
}

TEST(GraphTest, SimpleAddEdgeTest){
  test_graph graph(4);
  edge e;
  e.from = 1;
  e.to = 3;
  e.weight = 2;
  edge e_redir = e.redirect();

  graph.add_edge(e);
  
  EXPECT_TRUE(graph.edges->value == e_redir);
  EXPECT_TRUE(graph.edges->next->value == e);
}

TEST(GraphTest, ResetEdgeTest){
  test_graph graph(4);

  graph.add_edge({1, 3, 2});
  graph.reset_edges();
  
  EXPECT_TRUE(graph.edges == nullptr);
}

TEST(GraphTest, AddEdgeTest){
  test_graph graph(4);
  edge e_1;
  e_1.from = 1;
  e_1.to = 3;
  e_1.weight = 2;
  edge e_1_redir = e_1.redirect();
  edge e_2;
  e_2.from = 1;
  e_2.to = 2;
  e_2.weight = 4;
  edge e_2_redir = e_2.redirect();

  graph.add_edge(e_1);
  graph.add_edge(e_2);

  edge_node* temp = graph.edges;
  EXPECT_TRUE(temp->value == e_1_redir);
  temp = temp->next;
  EXPECT_TRUE(temp->value == e_1);
  temp = temp->next;
  EXPECT_TRUE(temp->value == e_2_redir);
  temp = temp->next;
  EXPECT_TRUE(temp->value == e_2);
}

TEST(GraphTest, AddEdgeToBeginningTest){
  test_graph graph(4);
  edge e_1;
  e_1.from = 1;
  e_1.to = 3;
  e_1.weight = 2;
  edge e_1_redir = e_1.redirect();
  edge e_2;
  e_2.from = 1;
  e_2.to = 2;
  e_2.weight = 1;
  edge e_2_redir = e_2.redirect();

  graph.add_edge(e_1);
  graph.add_edge(e_2);

  edge_node* temp = graph.edges;
  EXPECT_TRUE(temp->value == e_2_redir);
  temp = temp->next;
  EXPECT_TRUE(temp->value == e_2);
  temp = temp->next;
  EXPECT_TRUE(temp->value == e_1_redir);
  temp = temp->next;
  EXPECT_TRUE(temp->value == e_1);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}