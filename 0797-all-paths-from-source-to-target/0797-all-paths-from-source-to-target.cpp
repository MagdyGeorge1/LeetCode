class Solution {
public:
    vector<int>path;
    vector<vector<int>>ans;
    int vis[100];
    void dfs(int node , vector<vector<int>>& graph)
    {
        vis[node] = 1;
        path.push_back(node);
        for(int ch : graph[node])
        {
            if(!vis[ch])
                dfs(ch , graph);
        }
        if(node == graph.size() -1 )
            ans.push_back(path);
        vis[node] = 0;
        path.pop_back();
                    
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        dfs(0 , graph);
        
        return ans;
    }
};