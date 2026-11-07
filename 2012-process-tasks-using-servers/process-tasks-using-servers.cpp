class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> freeQ;
        priority_queue<pair<long, int>, vector<pair<long, int>>, greater<>>
            busyQ;

        for (int i = 0; i < servers.size(); i++) {
            freeQ.push({servers[i], i});}

        vector<int> ans;
        long time = 0;

        for (int j = 0; j < tasks.size(); j++) {
            time = max(time, (long)j);

            if (freeQ.empty())
                time = busyQ.top().first;

            while (!busyQ.empty() && busyQ.top().first <= time) {
                int i = busyQ.top().second;
                busyQ.pop();
                freeQ.push({servers[i], i});
            }

            int i = freeQ.top().second;
            freeQ.pop();

            ans.push_back(i);

            busyQ.push({time + tasks[j], i});
        }
        
        return ans;
    }
};