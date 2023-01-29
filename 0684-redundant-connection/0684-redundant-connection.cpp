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
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int f , s ;
        DSU dsu(edges.size());
         for(auto iter : edges)
         {
             if(!dsu.connect(iter[0] , iter[1]))
                 f = iter[0], s= iter[1];
         }
   return {f,s};
    }
    
};