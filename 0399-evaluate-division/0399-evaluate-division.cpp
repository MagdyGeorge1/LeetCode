class Solution {
public:
    double ans[150][150];
    int vis[1000];
    void dfs(int node , double& prv , int par, int& dist ,   vector<vector<pair<int,double>>> &adj , bool&found)
    {        
        if(found)
            return;
        vis[node] = 1;
        for(auto ch : adj[node])
        {                                         
           if(vis[ch.first])
               continue;
             prv *= ch.second;   
            if(ch.first == dist )
                return found = 1, void();      
             dfs(ch.first , prv , node , dist , adj , found);    
            if(found)
                return;
            else
                prv /= ch.second;

        }
        
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        map<string, int> mp ;
        vector<vector<pair<int,double>>>adj(1e5+10);
        int  j = equations.size() + 1;
        for(int i = 1 ;  i <= equations.size();i++ , j++)
        {
            string u = equations[i-1][0] , v= equations[i-1][1];
            int tmp =i , tmp2 = j;
            if(mp.count(u))
                tmp = mp[u];
            if(mp.count(v))
                tmp2 = mp[v];
            mp[u]= tmp , mp[v] = tmp2;
            adj[tmp].emplace_back(tmp2 , values[i-1]);
             if (values[i-1] != 0)
                 adj[tmp2].emplace_back(tmp , 1/values[i-1]);
        }
              
        vector<double> res;
        
        for(auto iter : queries)
        {
            if(!mp.count(iter[0]) or !mp.count(iter[1]))
            {
                res.push_back(-1.0);
                continue;
            }
            int u = mp[iter[0]] , dist= mp[iter[1]] ;
            if(u == dist)
              {
                res.push_back(1.0);
                continue;
            }   
            double prv = 1.0;
            bool found = false;
            dfs(u , prv, 0 , dist , adj , found);
            memset(vis , 0 , sizeof vis);
            if(found)
                res.push_back(prv);
            else
                res.push_back(-1.0);
                
        }
        return res;
    }
};