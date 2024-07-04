#pragma once
#include "pch.h"
#include "queue"
#include "stack"
#include <iostream>
using namespace std;


//================== Graph using Adjacency Matrix  (Undirected) ================= //

class Graph
{
private:
    bool** adjMatrix;
    int numVertices;

public:
    Graph(int n)
    {
        numVertices = n;
        adjMatrix = new bool* [numVertices];
        for (int i = 0; i < numVertices; i++)
        {
            adjMatrix[i] = new bool[numVertices];
        }
        for (int i = 0; i < numVertices; i++)
        {
            for (int j = 0; j < numVertices; j++)
            {
                adjMatrix[i][j] = false;
            }
        }
    }

    void addEdge(int from, int to)
    {
        adjMatrix[from][to] = true;
        adjMatrix[to][from] = true;
    }

    bool isEdge(int i, int j)
    {
        return adjMatrix[i][j];
    }

    void print()
    {
        for (int i = 0; i < numVertices; i++)
        {
            for (int j = 0; j < numVertices; j++)
            {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    void addVertex()
    {
        int newMatrixsize = numVertices + 1;
        bool** newMatrix = new bool* [newMatrixsize];

        for (int i = 0; i < newMatrixsize; i++)
        {
            newMatrix[i] = new bool[newMatrixsize];
        }

        for (int i = 0; i < numVertices; i++)
        {
            for (int j = 0; j < numVertices; j++)
            {
                newMatrix[i][j] = adjMatrix[i][j];
            }
            newMatrix[i][numVertices] = false;
        }


        for (int j = 0; j < newMatrixsize; j++)
        {
            newMatrix[numVertices][j] = false;
        }


        for (int i = 0; i < numVertices; i++)
        {
            delete[] adjMatrix[i];
        }

        delete[] adjMatrix;
        adjMatrix = newMatrix;
        numVertices = newMatrixsize;
    }

    int getNumVertices()
    {
        return numVertices;
    }

    ~Graph()
    {
        for (int i = 0; i < numVertices; i++)
        {
            delete[] adjMatrix[i];
        }
        delete[] adjMatrix;
    }
};

//  ================== Graph using Adjacency List =================  //

class GraphNode
{
public:
    int data;
    GraphNode* next;

    GraphNode(int val)
    {
        data = val;
        next = NULL;
    }
};


class Graphh
{
private:
    int maxVertices;
    GraphNode** adjacencyList;  // 1d array pointing to pointers

public:
    Graphh(int max)
    {
        maxVertices = max;
        adjacencyList = new GraphNode * [maxVertices];

        for (int i = 0; i < maxVertices; i++)
        {
            adjacencyList[i] = NULL;
        }
    }

    //void insertEdge(int from, int to)
    //{
    //    GraphNode* newNode = new GraphNode(to);
    //    newNode->next = adjacencyList[from];
    //    adjacencyList[from] = newNode;
    //    newNode = new GraphNode(from);
    //    newNode->next = adjacencyList[to];
    //    adjacencyList[to] = newNode;
    //}

    // Function to insert an undirected edge between two vertices
    void insertEdge(int from, int to) {
        // Create a new graph node for the 'to' vertex and insert it at the beginning of the linked list at 'from'
        GraphNode* newNodeTo = new GraphNode(to);
        newNodeTo->next = adjacencyList[from];
        adjacencyList[from] = newNodeTo;

        // Create a new graph node for the 'from' vertex and insert it at the beginning of the linked list at 'to'
        GraphNode* newNodeFrom = new GraphNode(from);
        newNodeFrom->next = adjacencyList[to];
        adjacencyList[to] = newNodeFrom;
    }

    void display()
    {
        for (int i = 0; i < maxVertices; i++)
        {
            cout << "Vertex " << i << " : ";
            GraphNode* traverseList = adjacencyList[i];
            while (traverseList != NULL)
            {
                cout << traverseList->data << " --> ";
                traverseList = traverseList->next;
            }
            cout << endl;
        }
    }

    ~Graphh()
    {
        for (int i = 0; i < maxVertices; i++)
        {
            GraphNode* traverseList = adjacencyList[i];
            while (traverseList != NULL)
            {
                GraphNode* temp = traverseList;
                traverseList = traverseList->next;
                delete temp;
            }
        }
        delete[] adjacencyList;
    }

    // ========================== Depth First Search using Stack ============================ //

    void dfs(int start) {

        bool* visited = new bool[maxVertices];
        for (int i = 0; i < maxVertices; i++) {
            visited[i] = false;
        }

        stack<GraphNode*> Stack;
        GraphNode* current = adjacencyList[start];
        Stack.push(current);
        visited[start] = true;
        cout << "DFS Traversal starting from node 0: ";
        while (!Stack.empty()) {
            GraphNode* curr = Stack.top();
            Stack.pop();
            cout << start << " ";

            while (!visited[start] && curr) {
                if (!visited[curr->data]) {
                    Stack.push(curr);
                    start = curr->data;
                    visited[curr->data] = true;
                }
                curr = curr->next;
            }
        }

        cout << endl;
    }

    //  ======================= Count Cycles using Depth First Traversal ==================== //

    int countCycles()
    {
        int count = 0;
        int* vertices_Visited = new int[maxVertices];
        for (int i = 0; i < maxVertices; i++)
        {
            vertices_Visited[i] = 0;
        }

        for (int i = 0; i < maxVertices; i++)
        {
            if (!vertices_Visited[i])
            {
                int stack[100];
                int top = 0;

                stack[top++] = i;

                while (top > 0)
                {
                    int current = stack[--top];

                    if (!vertices_Visited[current])
                    {
                        vertices_Visited[current] = 1;
                        GraphNode* node = adjacencyList[current];
                        while (node != NULL)
                        {
                            if (!vertices_Visited[node->data]) {
                                stack[top++] = node->data;
                            }
                            else
                            {
                                if (node->data != current)
                                {
                                    count++;
                                }
                            }
                            node = node->next;
                        }
                    }
                }
            }
        }

        delete[] vertices_Visited;
        return (count / 2) - 1;
    }

    //Ques 04
    void bfsTraversal(int start)
    {
        bool* visited = new bool[maxVertices];
        for (int i = 0; i < maxVertices; ++i)
        {
            visited[i] = false;
        }

        queue<int> Queue;
        Queue.push(start);
        visited[start] = true;
        cout << "BFS Traversal starting from node " << start << ": ";
        while (!Queue.empty())
        {
            int current = Queue.front();
            Queue.pop();
            cout << current << " ";

            GraphNode* node = adjacencyList[current];
            while (node != NULL)
            {
                if (!visited[node->data])
                {
                    Queue.push(node->data);
                    visited[node->data] = true;
                }
                node = node->next;
            }
        }
        cout << endl;
        delete[] visited;
    }

};
