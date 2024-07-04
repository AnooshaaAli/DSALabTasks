#include "pch.h"
#include "main.h"
#include<iostream>

// Test AVL tree insertion
TEST(AVLTreeTest, Insertion) {
    AVLTree<int> avlTree;
    avlTree.insert(10);
    avlTree.insert(20);
    avlTree.insert(5);
    avlTree.insert(30);
    avlTree.insert(15);
    avlTree.insert(25);


    // Test the in-order traversal after insertion
    testing::internal::CaptureStdout();
    avlTree.display();
    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_EQ(output, "In-order traversal: 5 10 15 20 25 30 \n");
}

// Test AVL tree deletion
TEST(AVLTreeTest, Deletion) {
    AVLTree<int> avlTree;
    avlTree.insert(10);
    avlTree.insert(20);
    avlTree.insert(5);
    avlTree.remove(10);

    // Test the in-order traversal after deletion
    testing::internal::CaptureStdout();
    avlTree.display();
    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_EQ(output, "In-order traversal: 5 20 \n");
}

// Test AVL tree balancing
TEST(AVLTreeTest, Balancing) {
    AVLTree<int> avlTree;
    avlTree.insert(10);
    avlTree.insert(20);
    avlTree.insert(5);
    avlTree.insert(30);
    avlTree.insert(15);
    avlTree.insert(25);

    // The tree should be balanced after these insertions
    ASSERT_EQ(avlTree.getRoot()->data, 20);
    ASSERT_EQ(avlTree.getRoot()->height, 3);
    ASSERT_EQ(avlTree.getRoot()->left->data, 10);
    ASSERT_EQ(avlTree.getRoot()->right->data, 30);
    ASSERT_EQ(avlTree.getRoot()->right->left->data, 25);
    ASSERT_EQ(avlTree.getRoot()->left->left->data, 5);
    ASSERT_EQ(avlTree.getRoot()->left->right->data, 15);
}

// Test finding the smallest and largest elements in AVL tree
TEST(AVLTreeTest, FindSmallestAndLargest) {
    AVLTree<int> avlTree;
    avlTree.insert(10);
    avlTree.insert(20);
    avlTree.insert(5);
    avlTree.insert(30);
    avlTree.insert(15);
    avlTree.insert(25);

    ASSERT_EQ(avlTree.findSmallest()->data, 5);
    ASSERT_EQ(avlTree.findLargest()->data, 30);
}



//************************Q2**********************
// Test AVL tree getDiameter function
TEST(AVLTreeTest, GetDiameter1)
{
    AVLTree<int> avlTree;
    // Construct a tree
    avlTree.insert(10);
    avlTree.insert(20);
    avlTree.insert(30);
    avlTree.insert(40);
    avlTree.insert(50);
    avlTree.insert(25);

    // Calculate the diameter
    int diameter = avlTree.getDiameter();

    // Expected diameter for the given tree
    int expectedDiameter = 4;

    EXPECT_EQ(diameter, expectedDiameter);
}

TEST(AVLTreeTest, GetDiameter2)
{
    AVLTree<int> avlTree;
    // Construct a tree
    avlTree.insert(10);
    avlTree.insert(20);
    avlTree.insert(30);
    avlTree.insert(40);
    avlTree.insert(50);
    avlTree.insert(25);
    avlTree.insert(9);

    // Calculate the diameter
    int diameter = avlTree.getDiameter();

    // Expected diameter for the given tree
    int expectedDiameter = 5;

    EXPECT_EQ(diameter, expectedDiameter);
}

TEST(AVLTreeTest, GetDiameter3)
{
    AVLTree<int> avlTree;
    // Construct a tree
    avlTree.insert(10);

    // Calculate the diameter
    int diameter = avlTree.getDiameter();

    // Expected diameter for the given tree
    int expectedDiameter = 0;

    EXPECT_EQ(diameter, expectedDiameter);
}
