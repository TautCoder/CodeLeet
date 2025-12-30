//nbm
class Solution {
public:
    bool isMagic(vector<vector<int>>& g, int r, int c) {
        // center must be 5
        if (g[r+1][c+1] != 5) return false;

        vector<int> freq(10, 0);

        // check numbers 1 to 9 and uniqueness
        for (int i = r; i < r + 3; i++) {
            for (int j = c; j < c + 3; j++) {
                int val = g[i][j];
                if (val < 1 || val > 9 || freq[val]++)
                    return false;
            }
        }

        // check rows and columns
        for (int i = 0; i < 3; i++) {
            int rowSum = 0, colSum = 0;
            for (int j = 0; j < 3; j++) {
                rowSum += g[r + i][c + j];
                colSum += g[r + j][c + i];
            }
            if (rowSum != 15 || colSum != 15)
                return false;
        }

        // check diagonals
        if (g[r][c] + g[r+1][c+1] + g[r+2][c+2] != 15)
            return false;
        if (g[r][c+2] + g[r+1][c+1] + g[r+2][c] != 15)
            return false;

        return true;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;

        for (int i = 0; i + 2 < n; i++) {
            for (int j = 0; j + 2 < m; j++) {
                if (isMagic(grid, i, j))
                    count++;
            }
        }
        return count;
    }
};
