class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int>out_degree(1e5+10,0);
        for(int i = 0 ; i< n;i++)    
            for(int j = 0 ; j < 2  ;j++)        
                out_degree[edges[i][j]]++;
   
        return max_element(out_degree.begin() , out_degree.end()) -out_degree.begin() ;
    }
    
};