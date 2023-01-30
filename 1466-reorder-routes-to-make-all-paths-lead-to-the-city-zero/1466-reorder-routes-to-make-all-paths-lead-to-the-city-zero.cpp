class Solution {
public:
    int par[50000+10] , vis[50000+10], mx = 0;
    void bfs(vector<vector<int>> &adj)
    {
        queue<int> q;
        q.push(0);
        par[0]= -1;
        vis[0] =1;
        while(q.size())
        {
            int cur_node = q.front();           
            q.pop();
            for(int ch : adj[cur_node])
            {
                if(!vis[ch])
                {
                    par[ch] = cur_node;
                    vis[ch] = 1;                  
                    q.push(ch);
                } 
            }
        }
    }
    void dfs(int node, int parent,vector<vector<int>> &adj ,vector<int>&leafs)
    {
    int flag = 1;
   
    for (auto ch : adj[node]) {       
        if (ch != parent) {
            flag = 0;
            dfs(ch, node ,adj ,leafs);
        }
    }  
    if (flag == 1)
       leafs.push_back(node);
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>>adj(n);
        map<pair<int,int>,bool> mp ;
        set<pair<int,int>>s;
        for(auto iter : connections)
        {
            adj[iter[0]].push_back(iter[1]);
            adj[iter[1]].push_back(iter[0]);
            mp[{iter[0] , iter[1]}] = 1;
        }
        bfs(adj);
        vector<int>leafs;
        dfs(0 , -1 , adj , leafs);
        for(int i : leafs)
            cout << i << " ";
        for(int i : leafs)
        {       
            int node = i;
              while (par[node] != -1)
              {
                if(!mp.count({node , par[node]}))
                    s.insert({node , par[node]});
                  node = par[node];
              }
        }
        // for(auto iter : s)
        //     cout << iter.first << " " << iter.second<<endl;
        return s.size();
    }
};