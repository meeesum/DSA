#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int numIslands(char grid[][50], int m, int n) {
        int numIslands = 0;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1') {
                    search(grid, i, j, m, n);
                    ++numIslands;
                }
            }
        }
        
        return numIslands;
    }

private:
    void search(char grid[][50], int i, int j, int m, int n) {
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == '0') {
            return;
        }
        
        grid[i][j] = '0';
        
        search(grid, i - 1, j, m, n);
        search(grid, i + 1, j, m, n);
        search(grid, i, j - 1, m, n);
        search(grid, i, j + 1, m, n);
    }
};

using namespace std;

int main() {
    Solution solution;
    
    int m, n;
    cout << "Enter the number of rows (m): ";
    cin >> m;
    cout << "Enter the number of columns (n): ";
    cin >> n;
    
    char grid[50][50];
    cout << "Enter the grid (each row as a string of '1's and '0's):" << endl;
    for (int i = 0; i < m; ++i) {
        string row;
        cin >> row;
        for (int j = 0; j < n; ++j) {
            grid[i][j] = row[j];
        }
    }
    
    int numIslands = solution.numIslands(grid, m, n);
    cout << "Number of islands: " << numIslands << endl;
    
    return 0;
}