class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        unordered_set<int>s (begin(nums) , end(nums)); 
        

        vector<int> res;
        for(int i =1 ; i <= nums.size() ;i++)
        {
            if(!s.count(i))
                res.push_back(i);
        }
        return res;
    }
};