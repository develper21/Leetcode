class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int xmin = nums1[0];
        bool odd = 0;

        for(auto& x : nums1) {
            xmin = min(xmin, x);
            odd |= x & 1;
        }

        return (xmin & 1) == odd;
    }
};