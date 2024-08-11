class Solution {
public:
    void DFS(vector<vector<int>> &grid,int i,int j,vector<vector<bool>> &vis){
        if(i<0||j<0||i>=grid.size()||j>=grid[0].size()||vis[i][j]||grid[i][j]==0) return ;

        vis[i][j]=true;
        DFS(grid,i+1,j,vis);
        DFS(grid,i,j+1,vis);
        DFS(grid,i-1,j,vis);
        DFS(grid,i,j-1,vis);
        return ;
    }
    int solve(vector<vector<int>> & grid){
        int land=0;
        vector<vector<bool>> vis(grid.size(),vector<bool>(grid[0].size()));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1&&!vis[i][j]){
                    DFS(grid,i,j,vis);
                    land++;
                }
            }
        }
        return land;
    }

    int minDays(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int island=solve(grid);
        if(island>1||island==0){
            return 0;
        }
        else{
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(grid[i][j]==1){
                        grid[i][j]=0;
                        island=solve(grid);
                        if(island>1||island==0) return 1;
                         grid[i][j]=1;
                    }
               

                }
            }
        }
        return 2;

    }
};