class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int , int> freq;
        for(int i : nums)
            freq[i]++;
        for(auto iter : freq)
            if(iter.second == 1)
                return iter.first;
        
        return 0;
    }
};