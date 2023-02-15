class Solution {
public:
   int col[100000];
    void dfs (int node , int co ,  vector<vector<int>>& adj) 
    {
        col[node] = co;
     
        for(int i : adj[node])
        {
            if(col[i] == 0)
            {
                dfs(i , (co ==4)? 1 : co+1 , adj );
            }
            else if(col[i] == col[node])
               dfs(node , (co ==4)? 1 : co+1 , adj );                
        }
    }
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
       vector<vector<int>> adj(1e5+10);
        for(auto& it : paths)
            adj[it[0]].push_back(it[1]), adj[it[1]].push_back(it[0]);
        
        
        for(int i = 1 ; i<=n ;i++ )
        {
            if(!col[i])
              dfs(i , 1, adj);
        }
        vector<int>ans;
        for(int i =1; i<=n;i++)
            ans.push_back(col[i] );
        return ans;
    }
};