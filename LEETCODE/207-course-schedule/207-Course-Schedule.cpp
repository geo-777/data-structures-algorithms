class Solution {
public:
    bool dfs(vector<vector<int>>& prerequisites,vector<int> &vis,int curr) {
        if(vis[curr]==2) return true;
        if(vis[curr]==1) return false;
        vis[curr]=1;
        for(int i=0; i<prerequisites.size(); i++) {
            if(prerequisites[i][0]==curr){
                if(!dfs(prerequisites,vis,prerequisites[i][1])) return false;
            }
        }
        vis[curr]=2;
        return true;

    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> vis(numCourses,0);
        for(int i=0; i<numCourses; i++) {
            if(!vis[i]) {
                if(!dfs(prerequisites,vis,i)) return false;
            }

        }
        return true;
    }
};