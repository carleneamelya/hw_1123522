// name : carlene 李佳玲
// student id : 1123522
// date of submission : 27 november 2024
#include <iostream>
#include <vector>
#include <queue>
#include <sstream> // To handle input easily

using namespace std;

// Structure to represent an element in the priority queue (min heap)
struct Element {
    int value;        // The value of the element
    int arrayIndex;   // The index of the array from which the element came
    int elementIndex; // The position of the element in the array
    
    // Constructor to initialize the heap element
    Element(int val, int arrIdx, int elemIdx) : value(val), arrayIndex(arrIdx), elementIndex(elemIdx) {}
    
    // Comparison function to make the heap a min-heap (smallest element at the top)
    bool operator>(const Element& other) const {
        return value > other.value;  // We want the smallest element on top
    }
};

// Function to merge K sorted arrays using a Min Priority Queue (min heap)
vector<int> mergeKSortedArrays(int numArrays, vector<vector<int>>& arrays) {
    // Create a min heap to store the smallest elements from each array
    priority_queue<Element, vector<Element>, greater<Element>> minHeap;
    
    // Insert the first element of each array into the min heap
    for (int i = 0; i < numArrays; i++) {
        if (!arrays[i].empty()) {
            minHeap.push(Element(arrays[i][0], i, 0)); // (value, array index, element index)
        }
    }

    vector<int> mergedArray;  // This will hold the final merged array

    // Process the heap until all elements are merged
    while (!minHeap.empty()) {
        // Extract the smallest element from the heap
        Element smallest = minHeap.top();
        minHeap.pop();

        // Add the smallest element to the merged array
        mergedArray.push_back(smallest.value);

        // If there are more elements in the same array, add the next element to the heap
        int nextElemIndex = smallest.elementIndex + 1;
        if (nextElemIndex < arrays[smallest.arrayIndex].size()) {
            // Push the next element from the same array into the heap
            minHeap.push(Element(arrays[smallest.arrayIndex][nextElemIndex], smallest.arrayIndex, nextElemIndex));
        }
    }

    return mergedArray;  // Return the merged and sorted array
}

int main() {
    int numArrays;  // Number of sorted arrays
    cout << "Enter the number of sorted arrays: ";
    cin >> numArrays;
    cin.ignore();  // Ignore any extra characters in the input buffer after entering numArrays
    
    vector<vector<int>> arrays(numArrays);
    
    // Input for each sorted array
    cout << "Enter the sorted arrays:\n";
    for (int i = 0; i < numArrays; i++) {
        cout << "Enter the elements of array " << (i + 1) << " (space-separated): ";
        string line;
        getline(cin, line);  // Read the whole line of numbers for the current array
        
        stringstream ss(line);  // Split the input line into individual numbers
        int num;
        while (ss >> num) {
            arrays[i].push_back(num);  // Add each number to the current array
        }
    }

    // Merge the arrays and get the sorted result
    vector<int> mergedArray = mergeKSortedArrays(numArrays, arrays);

    // Print the merged array
    cout << "Merged Array: [";
    for (int i = 0; i < mergedArray.size(); i++) {
        cout << mergedArray[i];
        if (i != mergedArray.size() - 1) cout << ", ";  // Print commas between numbers
    }
    cout << "]" << endl;

    return 0;
}

