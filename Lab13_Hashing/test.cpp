#include "pch.h"
#include"main.h"
#include<iostream>
using namespace std;


//*****************Q1****************
TEST(HashMapTest1, Linearpobing) {
    HashMap hashMap;
    hashMap.insert1(1, 10);
    hashMap.insert1(2, 20);
    hashMap.insert1(3, 30);
    hashMap.insert1(21, 50);
    EXPECT_TRUE(hashMap.search1(1));
    EXPECT_TRUE(hashMap.search1(2));
    EXPECT_TRUE(hashMap.search1(3));
    EXPECT_TRUE(hashMap.search1(21));
    EXPECT_THROW(hashMap.insert1(1, 40), std::runtime_error);
}

//**********Q2************
TEST(HashMapTest2, RandomProbing) {
    HashMap hashMap;
    hashMap.insert2(1, 10);
    hashMap.insert2(2, 20);
    hashMap.insert2(3, 30);
    hashMap.insert2(22, 50);

    EXPECT_THROW(hashMap.insert2(1, 40), std::runtime_error);
}


//*****************Q3**************************
TEST(HashMapTest3, QuadraticProbing) {
    HashMap hashMap;
    hashMap.insert3(1, 10);
    hashMap.insert3(2, 20);
    hashMap.insert3(3, 50);
    hashMap.insert3(41, 40);
    hashMap.insert3(5, 60);



    EXPECT_TRUE(hashMap.search3(1));
    EXPECT_TRUE(hashMap.search3(2));
    EXPECT_TRUE(hashMap.search3(3));
    EXPECT_TRUE(hashMap.search3(41));


    EXPECT_THROW(hashMap.insert3(1, 40), std::runtime_error);
}
