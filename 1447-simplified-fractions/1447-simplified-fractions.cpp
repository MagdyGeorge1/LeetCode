class Solution 
{
public:
    vector<string> simplifiedFractions(int n) 
    {
        vector < string > ret;
       for (int i = 2 ; i <= n ; i++)
       {

           for (int j = 1 ; j < i ; j++)
           {
               // if (i >= j)
               //     continue;
               if (__gcd(i , j) == 1)
               {
                   string tmp = to_string(j)+ "/" + to_string(i);
                   ret.push_back(tmp);
               }
           }
       }
        return ret;
    }
};