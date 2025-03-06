class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int total = n * n;  // Total numbers from 1 to n*n

        long long expectedSum = (long long)total * (total + 1) / 2;
        long long actualSum = 0;

        int xorAll = 0;     // XOR of all numbers from 1 to n*n
        int xorGrid = 0;    // XOR of all numbers in the grid

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                actualSum += grid[i][j];
                xorGrid ^= grid[i][j];
            }
        }

        for (int i = 1; i <= total; i++) {
            xorAll ^= i;
        }

        int xorMissingRepeated = xorAll ^ xorGrid;

        // Sum helps us find (repeated - missing)
        long long diff = actualSum - expectedSum;  // repeated - missing

        // xorMissingRepeated = repeated ^ missing
        // Now we have two equations:
        // 1. repeated - missing = diff
        // 2. repeated ^ missing = xorMissingRepeated
        // Use these two to find repeated and missing

        int repeated = 0, missing = 0;

        // To break into two numbers, we need to find one differing bit
        int differingBit = xorMissingRepeated & -xorMissingRepeated;  // Lowest differing bit

        int bucket1 = 0, bucket2 = 0;

        for (int i = 1; i <= total; i++) {
            if (i & differingBit)
                bucket1 ^= i;
            else
                bucket2 ^= i;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int val = grid[i][j];
                if (val & differingBit)
                    bucket1 ^= val;
                else
                    bucket2 ^= val;
            }
        }

        // One is missing and one is repeated
        // Use `diff` to figure out which is which
        if (actualSum - expectedSum > 0) {
            repeated = bucket1;
            missing = bucket2;
            if (repeated - missing != diff) swap(repeated, missing);
        } else {
            repeated = bucket2;
            missing = bucket1;
            if (repeated - missing != diff) swap(repeated, missing);
        }

        return { repeated,missing};
    }
};
