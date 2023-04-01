class Solution {
public:
    struct DSU {
    vector<int> parent, size;

    DSU(int n) {
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int find_parent(int u) {
        if (u == parent[u])
            return u;
        return parent[u] = find_parent(parent[u]);
    }

    bool connect(int u, int v) {
        u = find_parent(u), v = find_parent(v);
        if (u == v)
            return 0;
        if (size[u] < size[v])
            swap(u, v);
        parent[v] = u;
        size[u] += size[v];
        return 1;
    }
};

    long long countPairs(int n, vector<vector<int>>& edges) {
        DSU dsu (n);
        for(auto iter : edges)
        {
            dsu.connect(iter[0] , iter[1]);
        }
        map<int,int>mp;
        for(int i = 0 ; i< n;i++)
        {
            int par = dsu.find_parent(i);
            if(!mp.count(par))
                mp[par] = dsu.size[par];
        }
        vector<int> ans;
        for(auto iter : mp)
            ans.push_back(iter.second);
        vector<int> suff(n+1 , 0);
        suff[ans.size() -1] = ans.back();
        for(int i = ans.size()-2 ; i >= 0 ; i--)        
            suff[i] += suff[i+1] + ans[i];
        long long res = 0;
        for(int i = 0 ; i< ans.size()-1 ;i++)        
            res += 1LL*ans[i]*suff[i+1];
        
        return res;
    }
};