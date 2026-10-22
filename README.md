# 25 DSA Patterns — Campus Placement Practice Sheet (C++)

Built for a 3rd year B.Tech student (5th sem) preparing for **campus coding rounds**.

## How this is organized
25 topic folders, each with **3 hand-picked C++ questions** (75 total) that are
the most commonly asked in campus placement rounds (TCS, Infosys, Wipro, Cognizant,
product-based company on-campus rounds, HackerRank/HackerEarth style tests).

Each `.cpp` file is **self-contained and ready to compile** — it includes:
- Problem statement (as a comment)
- A worked example
- Approach explanation
- Time & Space complexity
- Clean, easy-to-follow C++ solution
- A `main()` with a sample test case so you can just compile and run

All 75 files have been compiled and verified to run correctly.

## Folder list (in recommended learning order)

| # | Folder | Focus |
|---|--------|-------|
| 01 | Two_Pointers | Sorted array problems |
| 02 | Sliding_Window | Subarray/substring problems |
| 03 | Fast_Slow_Pointers | Linked list cycle problems |
| 04 | Prefix_Sum | Range sum problems |
| 05 | Difference_Array | Range update problems |
| 06 | Binary_Search | Search space problems |
| 07 | Monotonic_Stack | Next greater/smaller problems |
| 08 | Monotonic_Queue | Sliding window max/min |
| 09 | HashMap_HashSet | Frequency/lookup problems |
| 10 | LinkedList_Manipulation | Pointer manipulation |
| 11 | Tree_DFS | Recursive tree traversal |
| 12 | Tree_BFS | Level order traversal |
| 13 | Backtracking | Combinatorial search |
| 14 | Divide_and_Conquer | Sorting/recursive splitting |
| 15 | Dynamic_Programming | Optimal substructure problems |
| 16 | Greedy_Algorithm | Locally optimal choices |
| 17 | Heap_PriorityQueue | Top-K / ordering problems |
| 18 | Graph_DFS | Connectivity/traversal |
| 19 | Graph_BFS | Shortest path (unweighted) |
| 20 | Union_Find | Connected components |
| 21 | Topological_Sort | Dependency ordering |
| 22 | Trie | Prefix-based string problems |
| 23 | Bit_Manipulation | Bitwise tricks |
| 24 | Segment_Tree | Range query + update (advanced) |
| 25 | Fenwick_Tree_BIT | Range sum / order stats (advanced) |

## How to use this for placement prep
1. **Weeks 1–3**: Topics 01–10 (fundamentals — most asked in every campus round)
2. **Weeks 4–6**: Topics 11–20 (trees, backtracking, DP, greedy, graphs — core rounds)
3. **Weeks 7–8**: Topics 21–25 (advanced — mainly for product-based companies)

For each topic:
- Read the problem in the `.cpp` comment block WITHOUT looking at the solution first.
- Try to solve it yourself (on paper or in a separate file).
- Then compare with the provided solution.
- Type out (don't copy-paste) the solution once to build muscle memory for syntax.

## How to compile and run any file
```bash
g++ -std=c++17 -o solution Q1_Example.cpp
./solution
```

Good luck with your placements! 🚀
