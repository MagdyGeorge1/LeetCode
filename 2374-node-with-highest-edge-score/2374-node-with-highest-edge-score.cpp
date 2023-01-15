class Solution {
public:
    int edgeScore(vector<int>& edges) {
         int n = edges.size();
        vector<long long> degree(2e5 +10 , 0);
        
        for(int i = 0 ; i< n; i++)
            degree[edges[i]]+=i;
        
        return max_element(degree.begin() , degree.end()) - degree.begin() ;
    }
};