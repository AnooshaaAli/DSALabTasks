#include "pch.h"
#include "main.h"

// 5+2 = 7 test cases
//**********************Task1 Testcases**********************
TEST(TestCaseName, Insertion) {
    BST<int> bst;

    // Insert elements into the BST
    bst.insert(50);
    bst.insert(30);
    bst.insert(20);
    bst.insert(40);
    bst.insert(70);
    bst.insert(60);
    bst.insert(80);

    // Test whether elements are correctly inserted
    EXPECT_TRUE(bst.search(50));
    EXPECT_TRUE(bst.search(30));
    EXPECT_TRUE(bst.search(20));
    EXPECT_TRUE(bst.search(40));
    EXPECT_TRUE(bst.search(70));
    EXPECT_TRUE(bst.search(60));
    EXPECT_FALSE(bst.search(90));
}

TEST(TestCaseName, Search) {
    BST<int> bst;

    // Insert elements into the BST
    bst.insert(50);
    bst.insert(30);
    bst.insert(20);
    bst.insert(40);
    bst.insert(70);
    bst.insert(60);
    bst.insert(80);

    // Test search functionality
    EXPECT_TRUE(bst.search(60));
    EXPECT_FALSE(bst.search(90));
}

TEST(TestCaseName, Traversals) {
    BST<int> bst;

    // Insert elements into the BST
    bst.insert(50);
    bst.insert(30);
    bst.insert(20);
    bst.insert(40);
    bst.insert(70);
    bst.insert(60);
    bst.insert(80);

    // Test in-order traversal
    testing::internal::CaptureStdout();
    bst.inOrderTraversal();
    string inOrderOutput = testing::internal::GetCapturedStdout();
    string expectedinOrder = "20 30 40 50 60 70 80 \n";
    EXPECT_EQ(inOrderOutput, expectedinOrder);

    // Test pre-order traversal
    testing::internal::CaptureStdout();
    bst.preOrderTraversal();
    string preOrderOutput = testing::internal::GetCapturedStdout();
    string expectedPreOrder = "50 30 20 40 70 60 80 \n";
    EXPECT_EQ(preOrderOutput, expectedPreOrder);

    // Test post-order traversal
    testing::internal::CaptureStdout();
    bst.postOrderTraversal();
    string postOrderOutput = testing::internal::GetCapturedStdout();
    string expectedPostOrder = "20 40 30 60 80 70 50 \n";
    EXPECT_EQ(postOrderOutput, expectedPostOrder);
}

TEST(TestCaseName, Deletion1) {
    BST<int> bst;

    // Insert elements into the BST
    bst.insert(50);
    bst.insert(30);
    bst.insert(20);
    bst.insert(40);
    bst.insert(70);
    bst.insert(60);
    bst.insert(45);
    bst.insert(35);
    bst.insert(19);


    // Remove an element from the BST
    bst.remove(19); //having no child means leaf node deletion
    bst.remove(70);  //having one child

    // Test whether elements are correctly removed
    EXPECT_TRUE(bst.search(20));
    EXPECT_TRUE(bst.search(30));
    EXPECT_FALSE(bst.search(19));
    EXPECT_FALSE(bst.search(70));
    EXPECT_TRUE(bst.search(50));
    EXPECT_TRUE(bst.search(20));
    EXPECT_TRUE(bst.search(40));
    EXPECT_TRUE(bst.search(60));
    EXPECT_FALSE(bst.search(80));
}


TEST(TestCaseName, Deletion2) {
    BST<int> bst;

    // Insert elements into the BST
    bst.insert(50);
    bst.insert(30);
    bst.insert(20);
    bst.insert(40);
    bst.insert(70);
    bst.insert(60);
    bst.insert(80);

    // Remove nodes 30 and 70 from the BST
    bst.remove(30);  //having two child
    bst.remove(70);  //having two child

    // Test post-order traversal after deletion
    testing::internal::CaptureStdout();
    bst.postOrderTraversal();
    string postOrderOutput = testing::internal::GetCapturedStdout();
    string expectedPostOrder = "20 40 60 80 50 \n";
    EXPECT_EQ(postOrderOutput, expectedPostOrder);
}




////**********************Task2 Testcases**********************
TEST(TestCaseName, LevelWiseTraversal1) {
    BST<int> bst;

    // Insert elements into the BST
    bst.insert(5);
    bst.insert(10);
    bst.insert(15);
    bst.insert(20);
    bst.insert(25);
    bst.insert(30);
    bst.insert(35);
    bst.insert(40);
    bst.insert(45);

    int leaf_count = bst.countleaf();
    cout << "leaf-count is: " << leaf_count << endl;;
    EXPECT_EQ(leaf_count, 1);
}

TEST(TestCaseName, LevelWiseTraversal2) {
    BST<int> bst;

    // Insert elements into the BST
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(35);
    bst.insert(60);
    bst.insert(78);
    bst.insert(2);
    bst.insert(21);

    int leaf_count = bst.countleaf();
    cout << "leaf-count is: " << leaf_count << endl;;
    EXPECT_EQ(leaf_count, 5);

    bst.remove(2);
    bst.remove(21);

    leaf_count = bst.countleaf();
    cout << "leaf-count is: " << leaf_count << endl;;
    EXPECT_EQ(leaf_count, 4);

    bst.remove(20);
    bst.remove(35);
    bst.remove(60);
    bst.remove(78);
    bst.remove(30);
    bst.remove(70);
    bst.remove(50);
    leaf_count = bst.countleaf();
    cout << "leaf-count is: " << leaf_count << endl;;
    EXPECT_EQ(leaf_count, 0);
}
