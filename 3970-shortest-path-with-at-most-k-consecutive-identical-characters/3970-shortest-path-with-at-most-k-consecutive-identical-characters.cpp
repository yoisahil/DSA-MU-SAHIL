class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
        }

        // {dist, node, run}
        using T = tuple<long long, int, int>;
        priority_queue<T, vector<T>, greater<T>> pq;

        vector<int> bestRun(n, INT_MAX); // smallest run length already popped per node

        if (k < 1) return -1;
        pq.push({0, 0, 1});

        while (!pq.empty()) {
            auto [d, u, run] = pq.top();
            pq.pop();

            // dominated by an earlier (cheaper or equal) state with smaller/equal run
            if (bestRun[u] <= run) continue;
            bestRun[u] = run;

            if (u == n - 1) return (int)d;

            for (auto& [v, w] : adj[u]) {
                int newRun = (labels[v] == labels[u]) ? run + 1 : 1;
                if (newRun > k) continue;
                if (bestRun[v] <= newRun) continue;
                pq.push({d + w, v, newRun});
            }
        }
        return -1;
    }
};