# Algorithms Implementations in C++

This repository contains various algorithms implemented in C++ for educational and practical purposes. 
The implementations cover topics from data structures, searching, sorting, graph theory, linear programming, DP, greedy, combinatorics (optimization), string and much more.

Any use of abstract data types in this repository makes use of data structures I have previously defined and implemented in my [Data Structures Implementations](https://github.com/AtinChing/Data-Structures-Implementations) repository.

## Table of Contents
1. [Installation](#installation)
2. [Usage](#usage)
3. [Algorithms Implemented](#algorithms-implemented)
4. [Contributing](#contributing)
5. [License](#license)
6. [Troubleshooting](#troubleshooting)

## Installation

To run the algorithms on your local machine, follow these steps:
### Prerequisites

- C++ compiler (e.g., GCC (G++), Clang, or MSVC)
- ~~CMake (optional, for easier build setup)~~ (CMake documentation and support will be added in the future.)
### Steps for Setup

1. Clone this repository to your local machine:
    ```bash
    git clone https://github.com/AtinChing/Algorithms-Implementations.git
    ```

2. Navigate to the project directory:
    ```bash
    cd Algorithms-Implementations
    ```

3. Compile the code:

    **Using `g++` directly**:
    ```bash
    g++ -o out <algorithm name>.cpp
    ```
    It is obvious that you can name your output executable whatever you want to.
   
    CMake compilation commands will be added at a later date.
 
5. Run the compiled code:
    ```bash
    ./out
    ```

## Usage

This repository contains individual algorithm implementations. To run a specific algorithm, navigate to its corresponding directory and compile it as shown in the installation steps.

### Example

To run the **QuickSort** algorithm implementation:

1. Navigate to the `Sorting/` directory:
    ```bash
    cd Sorting
    ```

2. Compile the algorithm:
    ```bash
    g++ QuickSort.cpp -o quicksort
    ```

3. Run the compiled executable:
    ```bash
    ./quicksort
    ```
## Algorithms Implemented
Algorithm implementation status will be shown by ✅❌➖ (Complete, Incomplete, Ongoing).
### Searching:
- Linear search ✅
- Binary search ✅
- Interpolation search ✅
- Jump search ✅
- Exponential search ✅
- Ternary search ✅
- Fibonacci search ✅
### Sorting:
- Bubble sort ✅
- Quick sort ✅
- Selection sort ✅
- Insertion sort ✅
- Radix sort ❌
- Shell sort ❌
- Heap sort ❌
- Merge sort ✅
- Bucket sort ✅
- Tim sort ❌
- Bozo sort ❌
### Graph Theory:
- DFS (on graph and grid) ✅
- BFS (on graph and grid) ✅
- BFS shortest path on a graph ✅
- BFS shortest path on a grid ✅
- Topological sort (typical DFS) ✅
- Shortest/longest path on a DAG algorithm ✅
- Dijkstra's algorithm (Lazy) ✅
- Eager Dijkstra's algorithm (with D-ary heap optimization) ❌
- Bellman-Ford algorithm ✅
- A* Search ❌
- Floyd-Warshall algorithm ✅
- Bridges finder algorithm ✅
- Articulation points finder algorithm ✅
- Tarjan's Strongly Connected Components algorithm ✅
- Kahn's algorithm ✅
- Nearest neighbor algorithm (for TSP) ✅
- Travelling Salesman Problem algorithm (DP solution) ✅
- Eulerian Path finder algorithm ✅
- Kruskal's algorithm ✅
- Prim's (Lazy version) ❌ 
- Eager Prim's ❌
- Kosaraju's ❌
- Max Flow Ford Fulkerson ❌
- Unweighted Bipartite Matching ❌
- Mice and Owls problem ❌
- Elementary Math problem ❌
- Edmonds Karp algorithm ❌
- Capacity Scaling ❌
- Dinic's ❌

## Contributing

If you would like to contribute to this project, please follow these steps:

1. Fork the repository
2. Create a new branch for your changes
3. Commit your changes
4. Push your changes to your fork
5. Open a pull request

Please follow the conventions used in this project and write clear commit messages.
## License

This repository is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Troubleshooting

If you encounter any issues during installation or running the algorithms, please check the following:

- Ensure your C++ compiler is correctly installed and configured. I had a lot of problems like this throughout the development of this project.
- For any issues not covered, feel free to open an issue on this repository.

## Next Features
- Adding clearer comments that document each algorithm properly at the top of each source file.
- CMake compilation commands and documentation.
- Clang compilation commands and documentation.
- MVSC compilation commands and documentation.
- Ability for users to create their own graphs, through some sort of CLI or GUI, that can be used as input to test any algorithm of their choice.
---

**Feel free to explore, improve, and contribute to the project! All interest is heavily appreciated!**
