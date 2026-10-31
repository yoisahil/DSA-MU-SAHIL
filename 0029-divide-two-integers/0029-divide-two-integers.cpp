class Solution {
public:
    int divide(int dividend, int divisor) {
        // Overflow case: INT_MIN / -1 exceeds INT_MAX
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;

        // Result is negative if exactly one operand is negative
        bool negative = (dividend < 0) != (divisor < 0);

        // Use long long to safely take absolute values (handles INT_MIN)
        long long a = llabs((long long)dividend);
        long long b = llabs((long long)divisor);

        long long result = 0;

        // Subtract the largest possible (divisor << k) each iteration
        for (int k = 31; k >= 0; k--) {
            if ((a >> k) >= b) {
                a -= (b << k);
                result += (1LL << k);
            }
        }

        return negative ? -result : result;
    }
};