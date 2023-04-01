class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        vector<string> s;
         string tmp;
        for(char c : text)
        {
            if(isspace(c))
            {
                // cout << tmp<<endl;
                s.push_back(tmp);
                tmp.clear();
                continue;
                
            }
           tmp.push_back(c);        
           

        }
        s.push_back(tmp);
        set<char> st (brokenLetters.begin() , brokenLetters.end());
        int cnt = 0;
        for(string c : s)
        {
            bool ok = 1;
            // cout <<c <<endl;
            for(char c2 : c)
            {
                if(st.count(c2))
                       ok= 0;
            }
            if (ok)
                cnt ++;
        }
        
        return cnt;
    }
};