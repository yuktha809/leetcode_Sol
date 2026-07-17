class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int maxVal = *max_element(nums.begin(), nums.end());

        // freq[x] = how many times x appears
        vector<int> freq(maxVal + 1, 0);
        for (int x : nums)
            freq[x]++;

        // cnt[d] = how many numbers are divisible by d
        vector<long long> cnt(maxVal + 1, 0);

        for (int d = 1; d <= maxVal; d++) {
            for (int multiple = d; multiple <= maxVal; multiple += d) {
                cnt[d] += freq[multiple];
            }
        }

        // exact[d] = number of pairs whose gcd is exactly d
        vector<long long> exact(maxVal + 1, 0);

        for (int d = maxVal; d >= 1; d--) {
            long long pairs = cnt[d] * (cnt[d] - 1) / 2;

            for (int multiple = 2 * d; multiple <= maxVal; multiple += d) {
                pairs -= exact[multiple];
            }

            exact[d] = pairs;
        }

        // Prefix sum of pair counts
        vector<long long> prefix(maxVal + 1, 0);
        for (int d = 1; d <= maxVal; d++) {
            prefix[d] = prefix[d - 1] + exact[d];
        }

        vector<int> ans;

        for (long long q : queries) {
            // Find first gcd whose prefix > q
            int g = lower_bound(prefix.begin() + 1, prefix.end(), q + 1) - prefix.begin();
            ans.push_back(g);
        }

        return ans;
    }
};