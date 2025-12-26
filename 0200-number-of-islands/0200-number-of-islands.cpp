class Solution {

private:
    void bfs(int i, int j, vector<vector<int>>& vis, vector<vector<char>>& grid){
        vis[i][j] = 1;

        int dx[] = {-1, +1,0, 0};
        int dy[] = {0, 0, -1, +1};

        int n = grid.size();
        int m = grid[0].size();



        queue<pair<int,int>> q;
        q.push({i,j});

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;

            q.pop();

            for(int d = 0; d< 4; d++){
                int nrow = r + dx[d];
                int ncol  = c + dy[d];

                if(nrow>=0 && ncol>=0 && nrow<n && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol] == '1'){
                    q.push({nrow,ncol});
                    vis[nrow][ncol] = 1;
                }
            }
        }

    }
public:
    int numIslands(vector<vector<char>>& grid) {
        

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int> (m,0));
        int count = 0;
        for(int i = 0; i<n ;i++){
            for( int j = 0; j<m ;j++){

                if(!vis[i][j] && grid[i][j] == '1'){
                    count++;
                    bfs(i,j, vis, grid);
                }

            }
        }

        return count;
    }
};