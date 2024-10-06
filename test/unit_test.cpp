#include <iostream>
#include <gtest/gtest.h>
#include "union_find.hpp"

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

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}