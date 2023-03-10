class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int>indegree(n,0);
        for(auto iter : edges)        
            indegree[iter[1]]++;
        
        vector<int>ans;
        for(int i = 0 ; i<n;i++)        
            if(!indegree[i])
                ans.push_back(i);
        
        return ans;
    }
};