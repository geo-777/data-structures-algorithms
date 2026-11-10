class Solution {
public:
    void dfs(vector<vector<char>>& grid, int r, int c,vector<vector<bool>>& visited,int m, int n) {

        if(r < 0 || c<0 || r >=m || c >=n) return;
        if(visited[r][c]) return;
        if(grid[r][c]=='0') return;        
        visited[r][c]=true;

        dfs(grid,r+1,c,visited,m,n);
        dfs(grid,r-1,c,visited,m,n);
        dfs(grid,r,c+1,visited,m,n);
        dfs(grid,r,c-1,visited,m,n);
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n=grid[0].size();
        int c=0;

        vector<vector<bool>>visited (m, vector<bool>(n,false));

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(!visited[i][j]) {
                    if(grid[i][j]=='1'){
                        dfs(grid,i,j,visited,m,n);
                        c++;
                    }
                }
            }
        }
        return c;
    }   
};