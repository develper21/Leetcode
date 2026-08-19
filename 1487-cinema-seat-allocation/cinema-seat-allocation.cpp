class Solution {
public:
    static int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        const int m = reservedSeats.size();
        unordered_map<int, int> seat;
        seat.reserve(m);

        for(auto& r : reservedSeats) {
            const int i = r[0] - 1, j = r[1] - 2;
            if(j < 0 || j >= 8) continue;
            seat[i] |= 1 <<j;
        }

        int sz = seat.size(), cnt = (n - sz)*2;
        const uint8_t A = 15, B = 15 << 2, C = 15 << 4, D = A|C;

        for(auto [_, S] : seat) {
            S =~ S;
            bool has2 = (S&D) == D,
            has1 = (!has2) && ((S&A) == A || (S&B) == B || (S&C) == C);
            cnt += has2 << 1;
            cnt += has1;
        }
        return cnt;
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();