class Solution {
public:
    int edgeScore(vector<int>& edges) {
         int n = edges.size();
        vector<long long> degree(2e5 +10 , 0);
        long long mn = 1e18 , mx = 0;
        for(int i = 0 ; i< n; i++)
        {
        degree[edges[i]]+=i;
        if(degree[edges[i]] > mx )
            mx = degree[edges[i]] , mn = edges[i];
            else if ( degree[edges[i]] == mx )
            {
                mn = min(1LL* edges[i] , mn);
            } 
            
        }
        
        return mn ;
    }
};