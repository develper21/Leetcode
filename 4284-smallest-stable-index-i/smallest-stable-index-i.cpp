class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> suffix(n, 0);

        int mn = INT_MAX;
        for(int i = n - 1; i >= 0; i--) {
            mn = min(mn, nums[i]);
            suffix[i] = mn;
        }

        int mx = 0;
        for(int i = 0; i < n; i++) {
            mx = max(mx, nums[i]);
            int score = mx - suffix[i];
            if(score <= k) return i;
        }
        return -1;
    }
};