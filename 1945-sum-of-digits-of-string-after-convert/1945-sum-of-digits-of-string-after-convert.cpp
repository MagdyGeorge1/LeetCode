class Solution {
public:
    int getLucky(string s, int k) {
        string tmp ="" ;
        
        for(char c : s)
            tmp.append(to_string(c -'a' +1));
           int sum = 0;
    
        while(k--)
          {
              for(char c : tmp)
                  sum +=(c-'0');
            tmp = to_string (sum);
                 sum = 0;
          }
        return stoi(tmp);
    }
};