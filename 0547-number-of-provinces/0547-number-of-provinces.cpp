class Solution {
public:
    void dfs(int node,int n, vector<vector<int>>& adj, vector<int>& vis){
        
        vis[node] = 1;
        
        for(int i = 0;i <n;i++){
            if(adj[node][i] && !vis[i]){
                dfs(i,n,adj,vis);
            }
        }
        
    }
    int findCircleNum(vector<vector<int>>& isConnected){
        int n = isConnected.size();
        int count = 0;

        vector<int> vis(n,0);
        

        for (int i = 0; i < n; i++) {
            if(!vis[i]){
                dfs(i,n, isConnected, vis);
                count++;
            }   
        }
            

        return count;
    }
};
