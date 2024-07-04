#include "pch.h"
#include "main.h"
#include<iostream>
using namespace std;

// Total test cases:2+2+1=5 ;
// // ****** TASK-1 ******
TEST(QueueTest, EnqueueAndDequeue) {
    Queue<int> q;
    q.enqueue(5);
    q.enqueue(3);
    q.enqueue(7);
    q.enqueue(4);
    q.enqueue(9);
    q.print(q);
    EXPECT_EQ(q.dequeue(), 5);
    EXPECT_EQ(q.dequeue(), 3);
    EXPECT_EQ(q.dequeue(), 7);
    EXPECT_EQ(q.dequeue(), 4);
    EXPECT_EQ(q.dequeue(), 9);
}

TEST(QueueTest, Front) {
    Queue<int> q;
    q.enqueue(5);
    q.enqueue(3);
    q.enqueue(7);
    std::cout << "After enquening element:" << std::endl;
    q.print(q);
    EXPECT_EQ(q.Front(), 5);

    q.dequeue();
    EXPECT_EQ(q.Front(), 3);
    q.print(q);
    q.dequeue();
    q.print(q);
    q.dequeue();
    q.print(q);
    EXPECT_EQ(q.Front(), -1); // Queue is empty, expect -1
}


// ****** Task-3 *****
// Test case to check if a string is a palindrome
TEST(PalindromeTest, IsPalindrome1) {
    Queue<char> charQueue;
    EXPECT_TRUE(charQueue.isPalindrome("racecar"));
    EXPECT_TRUE(charQueue.isPalindrome(" "));
    EXPECT_FALSE(charQueue.isPalindrome("hello"));
    EXPECT_FALSE(charQueue.isPalindrome("world"));
}
TEST(QueueTest, PalindromeTest2) {
    Queue<char> Q;
    std::string singleCharString = "RAdAR";
    EXPECT_TRUE(Q.isPalindrome(singleCharString));
}



//******** task2 *********
// Define a test fixture for process scheduling.
class ProcessSchedulingTest : public ::testing::Test
{
protected:
    // Declare or initialize any necessary variables and queues here

    // You might need to define methods to access the queues and other variables
    Queue<Process> newQueue;
    Queue<Process> readyQueue;
    Queue<Process> runningQueue;
    Queue<Process> blockedQueue;
    Queue<Process> terminatedQueue;
    // Create a random number of processes (between 5 and 10).
    int numProcesses = rand() % 6 + 5;

};

//Test case to check if the simulation completes successfully
TEST_F(ProcessSchedulingTest, SimulationCompletes)
{
    // You can call your simulateProcessScheduling function here

    simulateProcessScheduling(newQueue, readyQueue, runningQueue, blockedQueue, terminatedQueue, numProcesses);

    EXPECT_EQ(newQueue.is_empty(), true);
    EXPECT_NE(readyQueue.is_empty(), false);
    EXPECT_EQ(readyQueue.is_empty(), true);
    EXPECT_EQ(runningQueue.is_empty(), true);
    EXPECT_EQ(blockedQueue.is_empty(), true);
    EXPECT_NE(terminatedQueue.is_empty(), true);
    //Check if all processes are eventually terminated
    int p = 1;
    while (!terminatedQueue.is_empty()) {
        Process terminatedProcess = terminatedQueue.dequeue();
        cout << "terminatedProcess " << p << endl;
        p++;
        EXPECT_EQ(terminatedProcess.state, 4); // Terminated state
    }
}
