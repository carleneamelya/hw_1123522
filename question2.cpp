// name : carlene 李佳玲
// student id : 1123522
// date of submission : 27 november 2024
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// Structure to represent a task with a name and priority
struct Task {
    string name;  // The name of the task
    int priority; // The priority of the task
};

// Function to swap two tasks
void swap(Task& a, Task& b) {
    Task temp = a;
    a = b;
    b = temp;
}

// Function to "bubble up" the task to maintain heap order
void bubbleUp(vector<Task>& heap, int index) {
    // Keep moving the task up the heap until it reaches its correct position
    while (index > 0 && heap[index].priority > heap[(index - 1) / 2].priority) {
        swap(heap[index], heap[(index - 1) / 2]);
        index = (index - 1) / 2; // Move to the parent node
    }
}

// Function to "bubble down" the task to maintain heap order
void bubbleDown(vector<Task>& heap, int index) {
    int leftChild = 2 * index + 1;   // Index of left child
    int rightChild = 2 * index + 2;  // Index of right child
    int largest = index;  // Assume the largest is the current task

    // Check if left child exists and has higher priority than current task
    if (leftChild < heap.size() && heap[leftChild].priority > heap[largest].priority) {
        largest = leftChild;
    }
    // Check if right child exists and has higher priority than the largest task
    if (rightChild < heap.size() && heap[rightChild].priority > heap[largest].priority) {
        largest = rightChild;
    }
    // If the largest is not the current task, swap and keep bubbling down
    if (largest != index) {
        swap(heap[index], heap[largest]);
        bubbleDown(heap, largest);  // Recursively move the task down
    }
}

// Function to insert a new task into the heap
void insertTask(vector<Task>& heap, const string& name, int priority) {
    Task newTask = {name, priority};
    heap.push_back(newTask);   // Add the task to the end
    bubbleUp(heap, heap.size() - 1);  // Move the task up to its correct position
}

// Function to get the highest priority task from the heap
Task getHighestPriorityTask(vector<Task>& heap) {
    if (heap.empty()) {
        throw runtime_error("No tasks available"); // Error if no tasks exist
    }

    Task highestPriorityTask = heap[0]; // The root has the highest priority

    // Move the last task to the root
    heap[0] = heap.back();
    heap.pop_back();  // Remove the last task
    bubbleDown(heap, 0);  // Reorganize the heap

    return highestPriorityTask;  // Return the highest priority task
}

int main() {
    int N; // Number of operations
    cout << "Enter the number of operations: ";
    cin >> N;
    cin.ignore(); // Ignore newline from previous input

    vector<Task> taskHeap;  // The heap to store tasks

    for (int i = 0; i < N; ++i) {
        string operation;
        cout << "Enter operation #" << (i + 1) << ": ";
        getline(cin, operation); // Read the entire operation line

        // Add a task to the heap
        if (operation.substr(0, 3) == "ADD") {
            string name;
            int priority;
            size_t pos = operation.find(' ', 4);  // Find the space after "ADD"
            name = operation.substr(4, pos - 4);  // Extract task name
            priority = stoi(operation.substr(pos + 1));  // Extract priority

            insertTask(taskHeap, name, priority);  // Add task to the heap
        }
        // Get the highest priority task
        else if (operation == "GET") {
            if (!taskHeap.empty()) {
                Task highestTask = getHighestPriorityTask(taskHeap);
                cout << highestTask.name << endl;  // Print task name
            } else {
                cout << "No tasks available!" << endl;  // Handle case with no tasks
            }
        }
    }

    // After all operations, display the remaining tasks in descending order of priority
    cout << "Remaining tasks: [";
    while (!taskHeap.empty()) {
        Task remainingTask = getHighestPriorityTask(taskHeap);
        cout << "('" << remainingTask.name << "', " << remainingTask.priority << ")";
        if (!taskHeap.empty()) cout << ", ";  // Add commas between tasks
    }
    cout << "]" << endl;  // Close the list

    return 0;  // End the program
}
