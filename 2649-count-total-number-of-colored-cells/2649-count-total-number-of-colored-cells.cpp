#include <vector>
using namespace std;

class Solution {
public:
    long long coloredCells(int n) {
        // int size = 2 * n - 1;
        // vector<vector<int>> grid(size, vector<int>(size, 0));

        // int center = n - 1;
        // grid[center][center] = 1;

        // if (n == 1) return 1;

        // floodFill(grid, center, center, n - 1);

        // long long count = 0;
        // for (int i = 0; i < size; i++) {
        //     for (int j = 0; j < size; j++) {
        //         if (grid[i][j] == 1) count++;
        //     }
        // }
        // return count;
        return 1 + 4LL*n*(n-1)/2;
    }

    // void floodFill(vector<vector<int>>& grid, int x, int y, int remainingSteps) {
    //     if (remainingSteps == 0) return;

    //     int size = grid.size();

    //     // Directly handle 4 directions
    //     int dx[] = {-1, 1, 0, 0};
    //     int dy[] = {0, 0, -1, 1};

    //     for (int dir = 0; dir < 4; dir++) {
    //         int nx = x + dx[dir];
    //         int ny = y + dy[dir];

    //         if (nx >= 0 && ny >= 0 && nx < size && ny < size && grid[nx][ny] == 0) {
    //             grid[nx][ny] = 1;
    //             floodFill(grid, nx, ny, remainingSteps - 1);
    //         }
    //     }
    // }
};
