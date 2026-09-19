# Movie Studio Optimization System

**Optimization of Movie Scene Scheduling and Equipment Allocation Using Activity Selection and 0/1 Knapsack Algorithms**

A single C program that solves two classic optimization problems commonly faced by film production studios:

1. **Scene Scheduling** – Select the maximum number of non-overlapping scenes on a single premium shooting set (Activity Selection – Greedy).
2. **Equipment Allocation** – Choose the best combination of equipment/props under a limited budget/weight capacity (0/1 Knapsack – Dynamic Programming).

---

## Features

- Automatically assigns Scene IDs (Scene 1, Scene 2, …) — no need to type IDs manually.
- Clean interactive console interface.
- Optimal solutions guaranteed by the algorithms used.
- Clear output showing selected scenes and selected equipment items.

---

## Algorithms Used

### Stage 1 – Activity Selection (Greedy)

- Sort all scenes by finishing time.
- Greedily pick the scene that finishes earliest and is compatible with the previously selected scene.
- **Time Complexity:** O(n log n) due to sorting (simple bubble sort used for educational clarity).

### Stage 2 – 0/1 Knapsack (Dynamic Programming)

- Classic DP table `dp[i][w]` = maximum value achievable using the first `i` items with capacity `w`.
- Backtracking is performed to recover the exact set of selected items.
- **Time Complexity:** O(n × capacity)

---

## How to Compile & Run

### Prerequisites
- Any standard C compiler (GCC recommended)

### Compile
```bash
gcc movie_studio_optimizer.c -o movie_studio_optimizer
```

### Run
```bash
./movie_studio_optimizer
```

---

## Sample Input / Output

### Stage 1 – Scene Scheduling
```
Enter number of scenes to schedule: 5

Enter Start and End time for Scene 1: 5 7
Enter Start and End time for Scene 2: 2 3
Enter Start and End time for Scene 3: 4 7
Enter Start and End time for Scene 4: 6 8
Enter Start and End time for Scene 5: 9 11
```

**Selected Scenes:**
```
Scene 2 (Start: 2, End: 3)
Scene 1 (Start: 5, End: 7)
Scene 5 (Start: 9, End: 11)
Total Non-Overlapping Scenes Selected: 3
```

### Stage 2 – Equipment Allocation
```
Enter number of equipment items available: 4

Enter weight and value of item 1: 2 5
Enter weight and value of item 2: 3 7
Enter weight and value of item 3: 4 9
Enter weight and value of item 4: 5 11

Enter equipment budget (maximum allowed weight): 10
```

**Result:**
```
Maximum Production Value Achieved: 23
Items included in the optimal solution:
Item 4  (Weight = 5, Value = 11)
Item 2  (Weight = 3, Value = 7)
Item 1  (Weight = 2, Value = 5)
```

---

## Project Structure

```
movie-studio-optimization/
├── movie_studio_optimizer.c   # Main source code
├── README.md                  # This file
└── LICENSE                    # MIT License
```

---

## Author

**Mohammad Razin Masud**  
ID: 243014111  
Course: Algorithm Lab (CSE 2202)  
Section: 3  
Semester: Fall 2025  
University of Liberal Arts Bangladesh  

Submitted to: Fatema Khan, Lecturer, Department of CSE

---

## References

- Cormen, Leiserson, Rivest, Stein — *Introduction to Algorithms*
- Standard Greedy Algorithm & Dynamic Programming materials

---

## License

This project is released under the MIT License. See the [LICENSE](LICENSE) file for details.
