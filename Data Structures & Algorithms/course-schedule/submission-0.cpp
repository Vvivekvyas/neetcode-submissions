class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        vector<int>indegree(numCourses,0);

        for(auto preq : prerequisites){
            int course = preq[0];
            int pre = preq[1];

            adj[pre].push_back(course);
            indegree[course]++;
        }

        queue<int>q;
        for(int i=0 ; i<numCourses ; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        int count = 0;
        while(!q.empty()){
            int course = q.front();
            q.pop();
            count++;

            for(auto x : adj[course]){
                indegree[x]--;

                if(indegree[x] == 0){
                    q.push(x);
                }
            }
        }
        return count == numCourses;
    }
};
