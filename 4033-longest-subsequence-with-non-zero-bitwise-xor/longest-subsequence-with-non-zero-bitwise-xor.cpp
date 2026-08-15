class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        auto tot = 0, nonZero = 0;

        for(auto& n : nums) {
            nonZero |= n > 0;
            tot ^= n;
        }

        return nonZero * (nums.size() - !tot);
    }
};