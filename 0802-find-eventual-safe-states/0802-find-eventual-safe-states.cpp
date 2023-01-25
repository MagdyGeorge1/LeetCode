class Solution {
public:
    int vis[10000+10] , valid[10000+10];
    //  valid =1 not included
    bool dfs(int node  , vector<vector<int>>& graph)
    {
        // vis[node] = 1;
        //path.push_back(node);
        if (valid[node] != -1)
            return valid[node];
        int ret = 1;
        valid[node] = 0;
        for(int i : graph[node])
        {   
            ret &= dfs(i,graph);
            // if (!dfs(i,graph))
            //         return 0;
        }
     
        return valid[node] = ret ; 
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        memset(valid , -1, sizeof valid);
        vector<int> ans;
        for(int i = 0 ; i< n;i++)                     
                 dfs(i , graph);                                      
        
            
        for(int i = 0 ; i< n;i++)
        {
            if(valid[i])
                ans.push_back(i);
        }
        return ans;
        
    }
};