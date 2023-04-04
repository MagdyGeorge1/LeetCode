class Solution {
public:
    vector<vector<int>> res;
    int dfn[100000+9] , low_link[100000 + 9];
    vector<int>adj[100000+10];
    int st = 1;
    void tarjan ( int node , int par)
    {
        dfn[node] = low_link[node] = st++;
        
        for(int ch : adj[node])
        {
            if(!dfn[ch]) // not-visted
            {
                tarjan(ch, node);
                low_link [node] =min(low_link[node] , low_link[ch]);
            }
            else if (ch != par) // visted in stack
            {
                low_link [node] =min(low_link[node] , dfn[ch]);
            }
        }
        
        if(low_link[node] == dfn[node] and par != -1)
            res.push_back({par , node});
        
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        
        
        for(auto iter : connections)
            adj[iter[0]].push_back(iter[1]),adj[iter[1]].push_back(iter[0]);
        
        tarjan (0, -1);
        return res;
    }
};