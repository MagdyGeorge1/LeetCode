class Solution {
public:
    int vis[100000];
    void dfs(int node ,    vector<vector<int>>&adj)
    {
        cout << node<<" ";
        vis[node] = 1;
        for( int ch : adj[node])
        {
            if(!vis[ch])
                dfs(ch , adj);               
        }
    }
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
       set<int> s(restricted.begin() , restricted.end());
        
        vector<vector<int>> adj(1e5+10);
        for(auto it : edges)
        {
            if(s.count(it[0]) or s.count(it[1]))
                continue;
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        dfs(0 , adj);
        int cnt = 1;
        for(int i = 1 ; i < n ;i++)
         cnt+=(vis[i]!=0);
        return cnt;
    }
};