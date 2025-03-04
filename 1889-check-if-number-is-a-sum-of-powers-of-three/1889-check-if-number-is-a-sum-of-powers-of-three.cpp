#include <cmath>  // for pow()

class Solution {
public:
    bool checkPowersOfThree(int n) {
        int i = 0;
        // Find the largest power of 3 that is ≤ n
        while (pow(3, i) <= n) {
            i++;
        }
        i--;  // Step back to the last valid power

        // Try to subtract powers of 3 from n
        while (i >= 0 && n > 0) {
            int power = pow(3, i);
            if (n >= power) {
                n -= power;
            }
            i--;
        }

        // If n is reduced to zero, n can be represented as sum of powers of 3
        return n == 0;
    }
};
