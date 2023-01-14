class Solution {
public:
    int minTimeToType(string word) {
        int prv =0 , res = 0 ;
        for(char c : word)
        {
            int tmp = abs((c-'a') - prv);
        res += min (tmp , 26 - tmp);
            res++;
            prv = c-'a';
        }
    return res;

    }
};