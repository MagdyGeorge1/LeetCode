class Solution {
public:
    int vis[100000+10];
    void dfs(int node ,   vector<vector<int>>&adj)
    {
        vis[node] = 1;
        for(int ch : adj[node])
            if(!vis[ch])
                dfs(ch , adj);
    }
    int removeStones(vector<vector<int>>& stones) {
        
        vector<vector<int>>adj(stones.size());
        for(int i = 0; i< stones.size() ;i++)
        {
              for(int j = i+1; j< stones.size() ;j++)
              {
                  if(stones[i][0] == stones[j][0] or stones[i][1] == stones[j][1])
                  {
                      adj[i].push_back(j);
                      adj[j].push_back(i);
                  }
                      
              }
        }
        
        int cnt = 0;
        for(int i= 0 ; i< stones.size();i++)
        {
            if(!vis[i])
            {
                dfs(i , adj);
                cnt++;
            }
        }
        return (stones.size() - cnt);
    }
};