class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size(), m = tasks.size();
        
        // {weight, index}
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> freeServers;
        
        // {finishTime, weight, index}
        priority_queue<tuple<long long,int,int>, 
                       vector<tuple<long long,int,int>>, 
                       greater<>> busyServers;
        
        for (int i = 0; i < n; i++) {
            freeServers.push({servers[i], i});
        }
        
        vector<int> ans(m);
        long long time = 0;
        
        for (int j = 0; j < m; j++) {
            time = max(time, (long long)j);
            
            // Release servers that finished by current time
            while (!busyServers.empty() && get<0>(busyServers.top()) <= time) {
                auto [finish, w, idx] = busyServers.top();
                busyServers.pop();
                freeServers.push({w, idx});
            }
            
            // No free server: wait until the earliest one finishes
            if (freeServers.empty()) {
                time = get<0>(busyServers.top());
                while (!busyServers.empty() && get<0>(busyServers.top()) <= time) {
                    auto [finish, w, idx] = busyServers.top();
                    busyServers.pop();
                    freeServers.push({w, idx});
                }
            }
            
            // Assign task j to the best free server
            auto [w, idx] = freeServers.top();
            freeServers.pop();
            
            ans[j] = idx;
            busyServers.push({time + tasks[j], w, idx});
        }
        
        return ans;
    }
};