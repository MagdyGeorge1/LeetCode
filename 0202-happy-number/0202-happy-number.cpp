class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> mp;
        while (n > 1)
        {            
            int tmp = n , sum = 0;
            while (tmp)
            {
                sum += (tmp%10) * (tmp%10);
                tmp/=10;
            }
           n = sum;
            if (mp.count(sum))
                return  false;
            mp.insert(sum);
        }
        return true;
    }
};