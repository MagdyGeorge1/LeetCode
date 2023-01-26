class Solution {
public:
    struct DSU {
    vector<int> parent, size;
    int forst;
    DSU(int n) {
        forst = n;
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
        forst--;
        return 1;
    }
};

    int findCircleNum(vector<vector<int>>& isConnected) {
        DSU dsu(isConnected.size());
        for(int i = 0;i<isConnected.size();i++)
        {
            for(int j = 0 ; j < isConnected[i].size() ;j++)
            {
                if(isConnected[i][j] )
                {
                     dsu.connect(i+1 , j+1);
                }
            }
        }
        return dsu.forst;
    }
};