class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
       int n = position.size();
        int even = 0 ;
        
        for(int i : position)
            even += (i%2 ==0);
        
        return min(even , n -even);
    }
};