class Solution {
public:
    int countPrimes(int n) {

        if (n <= 2)
            return 0;

        // Only store odd numbers
        vector<bool> prime(n, true);

        prime[0] = prime[1] = false;

        // 2 is prime
        int count = 1;

        for (int i = 3; (long long)i * i < n; i += 2) {

            if (prime[i]) {

                // Only mark odd multiples
                for (long long j = (long long)i * i;
                     j < n;
                     j += 2 * i) {

                    prime[j] = false;
                }
            }
        }

        // Count odd primes
        for (int i = 3; i < n; i += 2) {
            if (prime[i])
                count++;
        }

        return count;
    }
};