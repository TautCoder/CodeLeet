class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>>q;
        vector<vector<int>> vis(n, vector<int>(m,0));

          for(int i = 0; i < n; i++) {
            // Left boundary
            if(grid[i][0] == 1) {
                q.push({i, 0});
                vis[i][0] = 1;
            }
            // Right boundary
            if(grid[i][m-1] == 1) {
                q.push({i, m-1});
                vis[i][m-1] = 1;
            }
        }

        for(int j = 0; j < m; j++) {
            // Top boundary
            if(grid[0][j] == 1) {
                q.push({0, j});
                vis[0][j] = 1;
            }
            // Bottom boundary
            if(grid[n-1][j] == 1) {
                q.push({n-1, j});
                vis[n-1][j] = 1;
            }
        }
        

        int dx[] = {-1,0,+1,0};
        int dy[] = {0,+1,0,-1};

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            

            for(int i = 0; i< 4; i++){
                int nrow = r + dx[i];
                int ncol = c + dy[i];
                
                if(nrow >=0 && ncol >=0 && nrow<n && ncol<m && grid[nrow][ncol]==1 && vis[nrow][ncol] ==0 ){
                    vis[nrow] [ncol] = 1;
                    q.push({nrow,ncol});
                    
                }
            }

            
        }

        int count = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1 && vis[i][j] == 0) {
                    count++;
                }
            }
        }

        return count;

        

        
    }
};