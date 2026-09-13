class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        vector<int>indegree(numCourses,0);

        for(auto p : prerequisites){
            int course = p[0];
            int pre = p[1];

            adj[pre].push_back(course);
            indegree[course]++;
        }

        queue<int>q;
        for(int i = 0 ; i < numCourses ; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        vector<int>ans;
        while(!q.empty()){
            int course = q.front();
            q.pop();

            ans.push_back(course);

            for(auto x : adj[course]){
                indegree[x]--;

                if(indegree[x] == 0){
                    q.push(x);
                }
            }
        }
        
        if(ans.size() == numCourses){
            return ans;
        }
        return {};
    }
};
