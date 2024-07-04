#include "pch.h"
#include "graph.h"
using namespace std;

//***************Matrix Based Graph Representation************
TEST(GraphTest1, AddEdge) {
    Graph myGraph(4);

    myGraph.addEdge(0, 1);
    myGraph.addEdge(1, 2);
    myGraph.addEdge(2, 0);
    myGraph.addEdge(2, 3);

    myGraph.print();
    // Check if the edges are added correctly
    EXPECT_TRUE(myGraph.isEdge(0, 1));
    EXPECT_TRUE(myGraph.isEdge(1, 2));
    EXPECT_TRUE(myGraph.isEdge(2, 0));
    EXPECT_TRUE(myGraph.isEdge(2, 3));


    // Check for non-existent edges
    EXPECT_FALSE(myGraph.isEdge(0, 3));
    EXPECT_FALSE(myGraph.isEdge(1, 3));

}

TEST(GraphTest1, AddVertex) {
    Graph myGraph(3);
    myGraph.print();

    myGraph.addVertex();
    myGraph.print();
    // Check if the vertex is added correctly
    EXPECT_EQ(4, myGraph.getNumVertices());

    // Check for edges with the new vertex
    EXPECT_FALSE(myGraph.isEdge(0, 3));
    EXPECT_FALSE(myGraph.isEdge(1, 3));
    EXPECT_FALSE(myGraph.isEdge(2, 3));
}



//***************Node Based Graph Representation************
TEST(GraphhTest, InsertandDisplay) {
    Graphh graph(5);

    graph.insertEdge(0, 1);
    graph.insertEdge(0, 2);
    graph.insertEdge(1, 3);
    graph.insertEdge(2, 4);

    // Redirect cout to a stringstream for testing
    testing::internal::CaptureStdout();
    graph.display();
    std::string output = testing::internal::GetCapturedStdout();

    std::cout << "Adjacency List is :\n" << output << std::endl;
}

//***********DFS************//
TEST(GraphhTest, DFSTraversal) {
    Graphh myGraph(7);

    myGraph.insertEdge(6, 7);
    myGraph.insertEdge(4, 6);
    myGraph.insertEdge(0, 4);
    myGraph.insertEdge(5, 6);
    myGraph.insertEdge(3, 5);
    myGraph.insertEdge(0, 3);
    myGraph.insertEdge(0, 2);
    myGraph.insertEdge(1, 6);
    myGraph.insertEdge(0, 1);
    myGraph.insertEdge(1, 3);

    testing::internal::CaptureStdout();
    myGraph.dfs(0);
    std::string output1 = testing::internal::GetCapturedStdout();

    // The BFS traversal from node 0 should be "0 2 1 3 "
    std::stringstream expectedOutput1;
    expectedOutput1 << "DFS Traversal starting from node 0: 0 4 6 7 5 3 2 1 " << std::endl;
    ASSERT_EQ(output1, expectedOutput1.str());



    //testing::internal::CaptureStdout();
    //myGraph.bfsTraversal(1);
    //std::string output2 = testing::internal::GetCapturedStdout();

    //// The BFS traversal from node 1 should be "1 3 2 0 "
    //std::stringstream expectedOutput2;
    //expectedOutput2 << "BFS Traversal starting from node 1: 1 3 2 0 " << std::endl;

    //ASSERT_EQ(output2, expectedOutput2.str());

}


//************Q3**************
TEST(GraphhTest, CountCycles) {
    Graphh myGraph(6);

    myGraph.insertEdge(0, 1);
    myGraph.insertEdge(1, 2);
    myGraph.insertEdge(2, 0);
    myGraph.insertEdge(1, 3);
    myGraph.insertEdge(3, 4);
    myGraph.insertEdge(4, 5);
    myGraph.insertEdge(5, 3);

    int cycleCount = myGraph.countCycles();

    // The graph has ist cycle: 0-1-2-0
    // The graph has 2nd cycle: 3-4-5
    ASSERT_EQ(cycleCount, 2);
}

TEST(GraphhTest, NoCycles) {
    Graphh myGraph(4);

    myGraph.insertEdge(0, 1);
    myGraph.insertEdge(1, 2);
    myGraph.insertEdge(2, 3);

    int cycleCount = myGraph.countCycles();

    // The graph has no cycles
    ASSERT_EQ(cycleCount, 0);
}



//********************Bonus Task*************
TEST(GraphhTest, BFSTraversal) {
    Graphh myGraph(4);

    myGraph.insertEdge(0, 1);
    myGraph.insertEdge(0, 2);
    myGraph.insertEdge(1, 2);
    myGraph.insertEdge(1, 3);

    testing::internal::CaptureStdout();
    myGraph.bfsTraversal(0);
    std::string output1 = testing::internal::GetCapturedStdout();

    // The BFS traversal from node 0 should be "0 2 1 3 "
    std::stringstream expectedOutput1;
    expectedOutput1 << "BFS Traversal starting from node 0: 0 2 1 3 " << std::endl;
    ASSERT_EQ(output1, expectedOutput1.str());



    testing::internal::CaptureStdout();
    myGraph.bfsTraversal(1);
    std::string output2 = testing::internal::GetCapturedStdout();

    // The BFS traversal from node 0 should be "1 3 2 0 "
    std::stringstream expectedOutput2;
    expectedOutput2 << "BFS Traversal starting from node 1: 1 3 2 0 " << std::endl;

    ASSERT_EQ(output2, expectedOutput2.str());

}
