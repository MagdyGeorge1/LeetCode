class Solution {
public:
    int vis[100000+10];
    vector<pair<int,int>>adj[100000+10];
    int dfs (int node)
    {
        vis[node] =1 ;
        int mn = 1e9;
        for(pair<int,int >  ch : adj[node])
        {
             mn = min(mn , ch.second);
            if(!vis[ch.first])
            {           
                mn = min(mn , dfs(ch.first));
            }
        }
        return mn;
    }
    
    int minScore(int n2, vector<vector<int>>& roads) {
       
        for(auto it : roads)
        {
            adj[it[0]].push_back({it[1] , it[2]});
            adj[it[1]].push_back({it[0] , it[2]});
        }
       
       
        return dfs(1);
    }
};