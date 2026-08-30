class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int Max = 0, Min = 0;
        int n = nums.size();
        if(n == 1) {
            return 1;
        }

        for(int i = 0; i < n; i++) {
            if(nums[i] > nums[Max]) {
                Max = i;
            }

            if(nums[i] < nums[Min]) {
                Min = i;
            }
        }

        if(Min > Max) {
            swap(Min, Max);
        }

        return min(((n - Max) + min(Min + 1, Max - Min)), ((Min + 1) + min(n - Max, (Max - Min))));
    }
};