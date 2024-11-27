// name : carlene 李佳玲
// student id : 1123522
// date of submission : 27 november 2024
#include <iostream>
#include <queue>
#include <vector>
#include <sstream>
using namespace std;

// Define a structure for tree nodes
struct Node {
    int data;          // Value of the node
    Node* leftChild;   // Pointer to the left child
    Node* rightChild;  // Pointer to the right child

    // Constructor to initialize the node with a value
    Node(int value) : data(value), leftChild(nullptr), rightChild(nullptr) {}
};

// Function to build the tree from a level-order input
Node* createTree(const vector<int>& levelOrderValues) {
    if (levelOrderValues.empty() || levelOrderValues[0] == -1)
        return nullptr; // If the input is empty or root is -1, return null

    // Create the root node using the first value in the list
    Node* rootNode = new Node(levelOrderValues[0]);

    // Queue to keep track of nodes while building the tree
    queue<Node*> nodeQueue;
    nodeQueue.push(rootNode); // Add root node to the queue
    int index = 1; // Start from the second value in the list

    // Loop through and add left and right children for each node
    while (!nodeQueue.empty() && index < levelOrderValues.size()) {
        Node* currentNode = nodeQueue.front(); // Get the front node from the queue
        nodeQueue.pop(); // Remove the front node from the queue

        // If the left child exists, create and add it to the queue
        if (levelOrderValues[index] != -1) {
            currentNode->leftChild = new Node(levelOrderValues[index]);
            nodeQueue.push(currentNode->leftChild); // Add the left child to the queue
        }
        index++; // Move to the next value

        // If the right child exists, create and add it to the queue
        if (index < levelOrderValues.size() && levelOrderValues[index] != -1) {
            currentNode->rightChild = new Node(levelOrderValues[index]);
            nodeQueue.push(currentNode->rightChild); // Add the right child to the queue
        }
        index++; // Move to the next value
    }

    return rootNode; // Return the root node of the tree
}

// Helper function to calculate the tree's diameter recursively
int computeDiameter(Node* currentNode, int& maxDiameter) {
    if (!currentNode)
        return 0; // If the current node is null, return 0

    // Get the height of the left and right subtrees
    int leftHeight = computeDiameter(currentNode->leftChild, maxDiameter);
    int rightHeight = computeDiameter(currentNode->rightChild, maxDiameter);

    // Update the max diameter if the path through the current node is longer
    maxDiameter = max(maxDiameter, leftHeight + rightHeight);

    // Return the height of the current node
    return 1 + max(leftHeight, rightHeight);
}

// Function to find and return the diameter of the binary tree
int findTreeDiameter(Node* rootNode) {
    int maxDiameter = 0; // Initialize max diameter as 0
    computeDiameter(rootNode, maxDiameter); // Call helper function to compute diameter
    return maxDiameter; // Return the final diameter
}

int main() {
    // Ask user to input the level-order traversal
    cout << "Enter the level-order traversal of the binary tree (use -1 for null nodes):" << endl;
    string userInput;
    getline(cin, userInput); // Get the input as a string

    // Convert the input string into a list of integers
    vector<int> levelOrderValues;
    stringstream inputStream(userInput); // Convert input string to a stream
    int value;
    while (inputStream >> value) {
        levelOrderValues.push_back(value); // Add each number to the list
    }

    // Build the binary tree using the input list
    Node* rootNode = createTree(levelOrderValues);

    // Calculate and output the diameter of the tree
    int treeDiameter = findTreeDiameter(rootNode);
    cout << "Diameter of the binary tree: " << treeDiameter << endl;

    return 0; // End the program
}
