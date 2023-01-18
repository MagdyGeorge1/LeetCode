class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        int ans = 0 , n = nums.size();
        
        sort(nums.begin() , nums.end());
        for(int& i : nums)
        {
            if(i < 0 and k)    
                i*=-1 , k--;           
        }
          sort(nums.begin() , nums.end());
         if(k &1 )
             nums[0] *=-1;
        for(int i : nums)
            ans+=i;
       return ans;
            
    }
};