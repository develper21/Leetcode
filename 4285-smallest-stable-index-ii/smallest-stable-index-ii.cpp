class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        int ansIdx = 0;         // index we're currently testing as the answer
        int globalMax = INT_MIN;          // biggest number seen anywhere so far
        int ansMax = INT_MIN;   // biggest number up to ansIdx

        for(int i = 0; i < n; i++){
            globalMax = max(globalMax, nums[i]);

            // only update the candidate's max while we're still inside its prefix
            if(i == ansIdx)
                ansMax = max(ansMax, nums[i]);

            // this number is below the allowed floor, jump past it
            if(nums[i] < ansMax - k){
                ansIdx = i + 1;
                ansMax = globalMax;
            }
        }

        return ansIdx < n ? ansIdx : -1;
    }
};