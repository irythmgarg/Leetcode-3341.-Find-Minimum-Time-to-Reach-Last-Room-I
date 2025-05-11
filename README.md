# Leetcode-3341.-Find-Minimum-Time-to-Reach-Last-Room-I
# ⏱️ Minimum Time to Reach Bottom-Right Cell in a Grid

This repository provides a solution to the problem of finding the **minimum time required to reach the bottom-right cell** of a grid, where each cell has a "time threshold" before it becomes accessible.

---

## 📌 Problem Statement

You're given an `m x n` grid where `grid[i][j]` represents the earliest time at which cell `(i, j)` can be entered.

You can move in four directions (up, down, left, right) and each move takes **1 unit time**. If you arrive at a cell **before** its available time, you must wait.

### Objective:
Calculate the **minimum time** to reach the bottom-right corner `(m-1, n-1)` from the top-left corner `(0, 0)`.

---

## 🧠 Approach

We use a modified version of **Dijkstra's Algorithm** to compute the shortest arrival time at each cell considering:

- **Waiting time** if the cell is not yet open.
- **Priority queue** to always expand the least costly node first.
- **Visited matrix** to store the minimum time to reach each cell.

---

## 📦 Input

- `grid`: a 2D vector of size `m x n` where each value represents the unlock time for a cell.

---

## 🧾 Example

```cpp
Input:
grid = {
    {0, 2, 4},
    {1, 3, 5},
    {2, 5, 6}
}

Output:
6
```


🚀 Features
Efficient for large grids using priority queue.

Handles waiting logic elegantly with max(0, grid[i][j] - current_time).

Clean implementation in C++ using STL.

---

🛠️ Tools Used
Language: C++

Data Structures:

priority_queue

vector

pair

---

📎 Related Topics

Graph Traversal

Dijkstra’s Algorithm

Shortest Path with Constraints

BFS with Weight Adjustments

---

👨‍💻 Author
Ridham Garg
B.Tech Computer Engineering
Thapar University, Patiala
Roll No: 102203014

📄 License
This project is licensed under the MIT License.

