class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        int sum = 0 , prv = 0 , op = 0;
        // int l = upper_bound(nums.begin() , nums.end() , 0) - nums.begin();
        // if (l == nums.size())
        //     return 0;
        // cout << l ;
        for(int i = 0 ; i < nums.size() ; i++)
        {
           nums[i] -= min (nums[i] , prv);
            if ( nums[i] == 0)
                continue;
            op++;
            sum +=nums[i];
             prv = sum;
            if (sum >= nums.back())
                return op;
        }
            return op;
            
            
    }
};