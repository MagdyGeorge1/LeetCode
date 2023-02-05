class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        int n = vals.size();
        vector<pair<int,int>>adj[n+10];
        for(auto iter : edges)
        {
            adj[iter[0]].emplace_back(vals[iter[1]] , iter[1]);
             adj[iter[1]].emplace_back(vals[iter[0]] , iter[0]);
        }
        int res = -1e9;
        for(int i = 0 ; i< n ;i++)
        {
            sort(adj[i].rbegin() , adj[i].rend());
            int sum = vals[i] , sz = adj[i].size();
            
            for(int j = 0 ;j < sz ;j++)
            {
               if(adj[i][j].first < 0 or j >= k) 
                   break;
                sum+=adj[i][j].first;
            }
            res = max(res , sum);
        }
       return res; 
            
    }
};