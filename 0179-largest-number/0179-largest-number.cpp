class Solution {
public:
    
   static bool comp (int a , int b)
    {
        string a1 = to_string(a), b1 = to_string(b);
        return (a1+b1) > (b1 + a1);
    }
    string largestNumber(vector<int>& nums) {
        
        sort(nums.begin() , nums.end() ,comp );
        
        string res = "";
        if(nums[0] == 0)
            return "0";
        for(int i : nums)        
            res += to_string(i);
                       
        
        return res;
    }
};