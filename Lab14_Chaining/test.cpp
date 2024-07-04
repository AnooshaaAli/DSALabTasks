#include "pch.h"
#include"main.h"


//****************Q1***************


TEST(HashMapTest, InsertAndSearch) {
    HashMap mp;

    // Insert key-value pairs
    mp.insert(1, 101);
    mp.insert(2, 202);
    mp.insert(3, 303);
    mp.insert(23, 103);

    // Search for inserted values
    EXPECT_EQ(mp.search(1), 101);
    EXPECT_EQ(mp.search(2), 202);
    EXPECT_EQ(mp.search(3), 303);
    EXPECT_EQ(mp.search(23), 103);
}

TEST(HashMapTest, RemoveAndSearch) {
    HashMap mp;

    // Insert key-value pairs
    mp.insert(1, 101);
    mp.insert(2, 202);
    mp.insert(3, 303);

    // Remove a key and search for it
    mp.remove(2);
    EXPECT_EQ(mp.search(2), -1);  // Key 2 should not be found after removal
    EXPECT_EQ(mp.search(1), 101);  // Other keys should still be present
    EXPECT_EQ(mp.search(3), 303);
}

TEST(HashMapTest, RemoveAndSearch2) {
    HashMap mp;

    // Insert key-value pairs
    mp.insert(1, 101);
    mp.insert(2, 202);
    mp.insert(3, 303);
    mp.insert(23, 103);

    // Remove a key and search for it
    mp.remove(23);
    EXPECT_EQ(mp.search(2), 202);  // Key 2 should not be found after removal
    EXPECT_EQ(mp.search(1), 101);  // Other keys should still be present
    EXPECT_EQ(mp.search(3), 303);
    EXPECT_EQ(mp.search(23), -1);
}

TEST(HashMapTest, SearchNonExistentKey) {
    HashMap mp;

    // Searching for a key that has not been inserted
    EXPECT_EQ(mp.search(1), -1);
}

//****************Q2***************
TEST(HashMapTest1, FindMajorityElement)
{
    // Test Case 1
    HashMap hashTable1;
    hashTable1.insert(0, 3);
    hashTable1.insert(1, 2);
    hashTable1.insert(2, 3);
    EXPECT_EQ(hashTable1.findMajorityElement(), 3);
}

TEST(HashMapTest2, FindMajorityElement)
{
    // Test Case 2
    HashMap hashTable2;
    hashTable2.insert(3, 2);
    hashTable2.insert(4, 2);
    hashTable2.insert(5, 1);
    hashTable2.insert(6, 1);
    hashTable2.insert(7, 2);
    EXPECT_EQ(hashTable2.findMajorityElement(), 2);
}

TEST(HashMapTest3, FindMajorityElement)
{
    // Test Case 1
    HashMap hashTable3;
    EXPECT_EQ(hashTable3.findMajorityElement(), -1);

}

TEST(HashMapTest4, FindMajorityElement)
{
    // Test Case 2
    HashMap hashTable2;
    hashTable2.insert(1, 2);
    hashTable2.insert(4, 3);
    hashTable2.insert(14, 1);
    hashTable2.insert(6, 6);
    hashTable2.insert(7, 12);
    hashTable2.insert(10, 8);
    hashTable2.insert(11, 2);
    hashTable2.insert(21, 5);



    EXPECT_EQ(hashTable2.findMajorityElement(), 2);
}
