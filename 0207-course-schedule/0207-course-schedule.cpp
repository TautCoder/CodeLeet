class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& p) {

        vector<vector<int>> adj(n);

        for(auto it : p ){
            adj[it[0]].push_back(it[1]);
        }

        vector<int> ans;
        vector<int> in(n);

        for(int i =0; i<n ;i++){
            for (auto it : adj[i]){
                in[it]++;
            }
        }

        queue<int> q;
        for(int i =0; i<n;i++){
            if(in[i]== 0){

                q.push(i);
            }
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();

            ans.push_back(node);

            for (auto it: adj[node]){
                in[it]--;
                if(in[it] == 0) q.push(it);
            }
        }

        if(ans.size() == n) return 1;
        return 0;

         
        
    }
};