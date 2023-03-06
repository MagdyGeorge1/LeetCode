class Solution {
public:
    int sz  , dp[500];
    int solve(int st , vector<int>&arr , int k)
    {
        if(st >= sz)
            return 0;
        int &ans = dp[st];
        if(~ans)
            return ans;
        ans = 0;
        int mx= 0;
        for(int i = 0; i < k and i + st < sz;i++)
        {
            mx = max(arr[st + i] , mx);            
            ans = max(ans , mx *(i+1) + solve(st + i + 1 , arr, k));           
        }
        return ans ;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        sz = arr.size();
        memset(dp ,  -1 , sizeof dp);
        
        return solve(0 , arr, k);
    }
};