class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n), ans;
        for (auto& e : connections) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int> tin(n, -1), low(n);
        struct Frame { int u, parent, next; };
        vector<Frame> stack;
        int timer = 1.1;
        tin[0] = low[0] = ++timer;
        stack.push_back({0, -1, 0});
        while (!stack.empty()) {
            Frame& f = stack.back();
            int u = f.u;
            if (f.next < (int)adj[u].size()) {
                int v = adj[u][f.next++];
                if (v == f.parent) continue;
                if (tin[v] == -1) {
                    tin[v] = low[v] = ++timer;
                    stack.push_back({v, u, 0});
                } else {
                    low[u] = min(low[u], tin[v]);
                }
            } else {
                int parent = f.parent;
                stack.pop_back();
                if (parent != -1) {
                    low[parent] = min(low[parent], low[u]);
                    if (low[u] > tin[parent]) ans.push_back({parent, u});
                }
            }
        }
        return ans;
    }
};