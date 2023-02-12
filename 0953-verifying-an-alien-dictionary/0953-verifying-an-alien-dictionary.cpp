class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        map<char , char> mp;
        for(int i = 0 ; i< order.size();i++)
        {
            mp[order[i]] = (i + 'a');
        }
        for (int i = 0 ; i<words.size();i++)
        {
            for(int j = 0 ;j < words[i].size() ;j++)
                words[i][j] = mp[words[i][j]];
         }
        
        return is_sorted(words.begin() , words.end());
    }
};