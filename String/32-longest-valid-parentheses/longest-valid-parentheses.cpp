class Solution {
public:
    int longestValidParentheses(string s) {
        int f[2] = {0}, b[2] = {0}, res = 0, n = s.size();

        for(int i = 0; i < n; i++) {
            f[s[i] & 1]++;
            if(f[0] == f[1]) res = max(res, f[1] << 1);
            if(f[0] < f[1]) f[0] = f[1] = 0;

            b[s[n - 1 - i] & 1]++;
            if(b[0] == b[1]) res = max(res, b[1] << 1);
            if(b[0] > b[1]) b[0] = b[1] = 0;
        }

        return res;
    }
};