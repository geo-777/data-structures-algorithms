class Solution {
public:
    bool dfs(vector<vector<int>>& adj,vector<int> &vis,int curr) {
        if(vis[curr]==2) return true;
        if(vis[curr]==1) return false;
        vis[curr]=1;
        for(int n: adj[curr]) {
            if(!dfs(adj,vis,n)) return false;
            
        }
        vis[curr]=2;
        return true;

    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> vis(numCourses,0);
        vector<vector<int>> adj(numCourses);

        for(auto &p : prerequisites) {
            adj[p[0]].push_back(p[1]);
        }
        for(int i=0; i<numCourses; i++) {
            if(!vis[i]) {
                if(!dfs(adj,vis,i)) return false;
            }

        }
        return true;
    }
};