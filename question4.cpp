// name : carlene 李佳玲
// student id : 1123522
// date of submission : 27 november 2024
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// A structure to represent a task with profit and deadline
struct Task {
    int profit;    // Profit from the task
    int deadline;  // Deadline to complete the task
};

// Function to schedule tasks for maximum profit
void scheduleTasks(vector<Task>& tasks, int numTasks) {
    // Max heap to store tasks by profit
    auto compare = [](Task a, Task b) { return a.profit < b.profit; }; // Custom comparator for max heap
    priority_queue<Task, vector<Task>, decltype(compare)> taskHeap(compare);

    for (int i = 0; i < numTasks; i++) {
        taskHeap.push(tasks[i]); // Add all tasks to the heap
    }

    vector<bool> timeSlots(numTasks, false); // Track used slots
    int totalProfit = 0;                     // Total earned profit
    vector<int> scheduledProfits;            // Store profits of scheduled tasks

    // Process tasks in the order of highest profit
    while (!taskHeap.empty()) {
        Task currentTask = taskHeap.top(); // Task with highest profit
        taskHeap.pop();

        // Find the latest available slot within the deadline
        for (int slot = min(numTasks, currentTask.deadline) - 1; slot >= 0; slot--) {
            if (!timeSlots[slot]) { // If the slot is free
                timeSlots[slot] = true;      // Mark the slot as used
                totalProfit += currentTask.profit; // Add profit
                scheduledProfits.push_back(currentTask.profit); // Store profit
                break; // Stop looking for a slot
            }
        }
    }

    // Print results
    cout << "Maximum Profit: " << totalProfit << endl;
    cout << "Scheduled Tasks: [";
    for (size_t i = 0; i < scheduledProfits.size(); i++) {
        cout << scheduledProfits[i];
        if (i != scheduledProfits.size() - 1) {
            cout << ", "; // Add commas between profits
        }
    }
    cout << "]" << endl;
}

int main() {
    int numTasks; // Number of tasks
    cout << "Enter the number of tasks: ";
    cin >> numTasks;

    vector<Task> tasks; // List of all tasks

    // Input profit and deadline for each task
    cout << "Enter the tasks (profit, deadline):" << endl;
    for (int i = 0; i < numTasks; i++) {
        Task task;
        cin >> task.profit >> task.deadline;
        tasks.push_back(task); // Add task to the list
    }

    // Schedule tasks and calculate the maximum profit
    scheduleTasks(tasks, numTasks);

    return 0;
}
