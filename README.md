# Data Structure HW 2 
## Carlene 1123522

### QUESTION 1 : Binary Tree - Find the Diameter of a Binary Tree 
<br>
Problem Statement: 
<br>
Write a program to calculate the diameter of a binary tree. The diameter of a 
binary tree is the length of the longest path between any two nodes in the tree. 
The path may or may not pass through the root. 
You are required to: 
1.  Build the binary tree using level-order input. Use -1 to represent null 
nodes. 
2.  Implement a function to calculate the diameter of the binary tree 
efficiently using recursion. 
Input Format: 
1.  The first line contains a list of integers representing the level-order 
traversal of the binary tree. Use -1 for null nodes. 
Output Format: 
Print an integer representing the diameter of the binary tree.
<br> <br>
Example: 
<br>
Input: 
<br>
[1, 2, 3, 4, 5, 9, 10, 6, 7, 8, -1, -1 ,-1 ,11 , 12]  
<br> <br>
Output: 6 
<br>

---

### QUESTION 2 : Heap Sort - Build a Priority Queue for Tasks
<br>
Problem Statement: 
<br>
Write a program to manage a task priority queue using a max heap. Each task 
has a name and a priority level. Your program should allow: 
1.  Add a Task: Add a task with a given priority. 
2.  Get the Highest Priority Task: Remove and return the task with the 
highest priority. 
3.  Display the Remaining Tasks: Print the remaining tasks in descending 
order of priority. 
Input Format: 
1.  The first line contains an integer N, the number of operations. 
2.  The next N lines contain either: 
o "ADD task_name priority" to add a task. 
o "GET" to fetch the highest-priority task. 
Output Format: 
1.  For every "GET" operation, print the name of the task with the highest 
priority. 
2.  At the end, print the list of remaining tasks in descending order of 
priority.
<br> <br>
Example: 
<br>
Input:
<br>
8
<br>
ADD Task1 25
<br>
ADD Task2 50
<br>
ADD Task3 100
<br>
ADD Task4 75
<br>
GET
<br>
ADD Task5 90
<br>
ADD Task6 20
<br>
GET
<br> <br>
Output: 
<br>
Task3
<br>
Task5
<br>
Remaining tasks: [('Task4', 75), ('Task2', 50), ('Task1', 25), ('Task6', 20)]

---

### Question 3: Merge K Sorted Arrays Using Min Priority Queue 
You are given K sorted arrays of integers. Write a Python program to merge 
these arrays into a single sorted array using a Min Priority Queue. 
Your program should: 
1.  Insert the first element of each array into a Min Priority Queue along with 
the array index and element index. 
2.  Extract the smallest element from the queue, add it to the result array, and 
insert the next element from the same array into the queue. 
3.  Continue this process until all elements from all arrays are merged. 
 
Input Format 
1.  An integer K, the number of sorted arrays. 
2.  K sorted arrays, each entered on a new line, with elements separated by 
spaces. 
Output Format 
• A single line containing the merged sorted array. 
 <br>
Example:
<br>
Input:
<br> 
3 
<br> 
1 4 7 
<br> 
2 5 8 
<br> 
3 6 9 
<br> <br>
Output 
<br> 
Merged Array: [1, 2, 3, 4, 5, 6, 7, 8, 9] 

---
### Question 4: Schedule Tasks with Deadlines Using Max Priority Queue 
You are given N tasks, each with a profit and a deadline. Write a Python 
program to schedule the tasks such that the maximum profit is achieved, using a 
Max Priority Queue. 
Each task must be completed within its deadline (1-based index), and only one 
task can be scheduled at a time. 
 
Input Format 
1.  An integer N, the number of tasks. 
2.  N lines containing two integers each: profit and deadline of a task. 
Output Format 
1.  The maximum profit that can be achieved. 
2.  The list of scheduled tasks in the order they are executed. 
 
Example:
<br>
Input:
<br>
4 
<br>
100   2 
<br>
19   1 
<br>
27   2 
<br>
25   1 
<br> <br>
Example
<br>
Output 
<br>
Maximum Profit: 127 
<br>
Scheduled Tasks: [100, 27] 
<br> <br>
Explanation
<br>
o Input represents 4 tasks with (profit, deadline) as (100, 2), (19, 1), (27, 2), 
(25, 1). 
<br>
o Using a Max Priority Queue, tasks with higher profit are prioritized while 
ensuring deadlines are respected: 
<br>
o Task (100, 2) is scheduled in slot 2. 
<br>
o Task (27, 2) is scheduled in slot 1. 
<br>
o Total profit: 100 + 27 = 127
  
