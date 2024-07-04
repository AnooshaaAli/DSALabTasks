#include "pch.h"

#include "main.h"

////-------------1st Question Array Based Test Case-------------
//TEST(BinaryTreeTest, InOrderTraversal) {
//    BinaryTree tree;
//
//    // Insert elements into the binary tree
//    tree.insert(4);
//    tree.insert(2);
//    tree.insert(6);
//    tree.insert(1);
//    tree.insert(3);
//    tree.insert(5);
//    tree.insert(7);
//
//    // Check if the in-order traversal is correct
//    testing::internal::CaptureStdout();
//    tree.displayInorder();
//    std::string output = testing::internal::GetCapturedStdout();
//
//    // The expected output based on in-order traversal
//    std::string expected_output = "1 2 3 4 5 6 7 ";
//
//    ASSERT_EQ(output, expected_output);
//}



//////--------------2nd Question Node Based Test Case--------------
//#include"Header2.h"
//TEST(BinaryTreeTest, InsertAndDisplay) {
//    BinaryTree tree;
//    tree.insert(1);
//    tree.insert(2);
//    tree.insert(3);
//    tree.insert(4);
//    tree.insert(5);
//    tree.insert(6);
//
//    // Displaying the tree structure
//    std::cout << "Complete Binary Tree Structure:" << std::endl;
//    std::cout << "     " << "1" << std::endl;
//    std::cout << "    / \\" << std::endl;
//    std::cout << "   " << "2" << "   " << "3" << std::endl;
//    std::cout << "  / \\ / " << std::endl;
//    std::cout << "  "<<"4" << " " << "5" << " " << "6" << std::endl;
//
//    testing::internal::CaptureStdout();
//    tree.display();
//    std::string output = testing::internal::GetCapturedStdout();
//
//    ASSERT_EQ(output, "4 2 5 1 6 3 \n");
//}



//---------------3rd Question Test Cases---------------
#include"Header3.h"
TEST(KthSmallestTest, SampleTest) {
    // Create a sample binary tree
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->left->right = new TreeNode(2);
    root->right->right = new TreeNode(5);

    // Displaying the tree structure
    std::cout << "     " << "3" << std::endl;
    std::cout << "    / \\" << std::endl;
    std::cout << "   " << "1" << "   " << "4" << std::endl;
    std::cout << "  / \\ / \\" << std::endl;
    std::cout << "  "<<" " << " " << "2" << " " << " "<< " " << "5" << std::endl;


    // Test kthSmallest function with different values of k
    EXPECT_EQ(kthSmallest(root, 1), 1); 
    EXPECT_EQ(kthSmallest(root, 2), 2);  
    EXPECT_EQ(kthSmallest(root, 3), 3);  
    EXPECT_EQ(kthSmallest(root, 4), 4);  
}

TEST(KthSmallestTest, EmptyTreeTest) 
{
    // Test with an empty tree
    TreeNode* root = nullptr;
    EXPECT_EQ(kthSmallest(root, 1), -1);
}
