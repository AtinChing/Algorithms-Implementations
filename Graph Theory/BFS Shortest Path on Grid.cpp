// This function finds and returns a path to the desired cell in a grid (via BFS)
#include <deque>
#include <set>
#include <vector>
#include <iostream>
#include <algorithm>
#include <tuple>
using std::cout;
using std::deque;
using std::endl;
using std::set;
using std::tuple;
using std::vector;
using std::pair;
// Function if you want to see prev's status at the end and see what cells lead to what cells as fast as possible.
void print2DArray(tuple<int, int> arr[][7], int rows, int cols)
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            // Extract the values from the tuple
            int a, b;
            std::tie(a, b) = arr[i][j]; // Decomposes the tuple into a and b

            // Print the tuple values in (a, b) format
            std::cout << "(" << a << ", " << b << ") ";
        }
        std::cout << '\n'; // Newline after each row
    }
}
vector<pair<int, int>> BFSPathFinder(vector<vector<char>> grid, int sizeX, int sizeY, int startX, int startY)
{
    set<pair<int, int>> visited;
    visited.insert({startX, startY});
    tuple<int, int> prev[sizeY][7 /*sizeX*/]; // Holds previous visiter for each node. -1 means no parent/prev. This assumes graphs cant have nodes with value -1
    for (int i = 0; i < sizeY; ++i)
    {
        for (int j = 0; j < sizeX; ++j)
        {
            prev[i][j] = std::make_tuple(-1, -1);
        }
    }
    // Queue to store current coordinates as pairs (x, y) - CHANGED
    deque<pair<int, int>> queue; // **This is a key change** from two separate queues for x and y
    queue.push_back({startX, startY});
    int dr[4] = {0, 0, 1, -1};
    int dc[4] = {1, -1, 0, 0};
    int curX;
    int curY;
    int rr;
    int cc;
    while (queue.size() > 0)
    {
        auto [curX, curY] = queue.front();
        queue.pop_front();
        if (grid[curX][curY] == 'E')
        {
            vector<pair<int, int>> path = {{curX, curY}};
            while (prev[curX][curY] != tuple<int, int>(-1, -1))
            {
                auto [prevX, prevY] = prev[curX][curY];
                path.push_back({prevX, prevY});
                curX = prevX;
                curY = prevY;
            }
            std::reverse(path.begin(), path.end());
            return path;
        }
        for (int i = 0; i < 4; i++)
        {
            rr = curX + dr[i];
            cc = curY + dc[i];
            pair<int, int> tup = {rr, cc};
            if (rr >= 0 && rr < sizeX && cc >= 0 && cc < sizeY)
            {
                if(grid[rr][cc] != '#' && visited.find(tup) == visited.end())
                {
                    queue.push_back(tup);
                    visited.insert(tup);
                    prev[rr][cc] = {curX, curY};
                }
            }
        }
    }
    return {{-1, -1}};
}
int main()
{
    int rows = 5, cols = 7;

    // Create a 2D vector with 'rows' and 'cols'
    vector<vector<char>> array(rows, vector<char>(cols, '.'));

    // Fill the array with some sample data
    array[0][2] = '#';
    array[1][0] = '#';
    array[1][3] = '#';
    array[2][4] = '#';
    array[3][0] = '#';
    array[3][3] = '#';
    array[3][5] = '#';
    array[4][6] = '#';
    array[0][0] = 'S';
    array[4][3] = 'E';
    /*
        Above code creates following grid:
        {'S', '.', '#', '.', '.', '.', '.'},
        {'#', '.', '.', '#', '.', '.', '.'},
        {'.', '.', '.', '.', '#', '.', '.'},
        {'#', '.', '.', '#', '.', '#', '.'},
        {'.', '.', '.', 'E', '.', '.', '#'}
        E being where we want to reach.
    */
    auto result = BFSPathFinder(array, rows, cols, 0, 0);// rows == sizeX
    if (result.size() == 1 && std::get<0>(result[0]) == -1)
    {
        cout << "There is no path to the end!" << endl;
    }
    else
    {
        cout << "Path found!" << endl;
        cout << "The path was: ";
        int pathLength = result.size();
        for (int i = 0; i < pathLength - 1; i++)
        {
            cout << "[" << std::get<0>(result[i]) << ", " << std::get<1>(result[i]) << "] -> ";
        }
        cout << "[" << std::get<0>(result[pathLength-1]) << ", " << std::get<1>(result[pathLength-1]) << "]" << endl;
    }
    return 0;
}
