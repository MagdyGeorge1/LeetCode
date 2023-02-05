class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
     string res(s.size() , ' ');
        int idx = 0;
      for(int i : indices)
          res[i] = s[idx++];
        
        return res;
    }
};