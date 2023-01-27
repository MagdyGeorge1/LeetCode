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

    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        DSU dsu(edges.size());
        vector<int>indegree(edges.size()+1, -1);
        int bl1 =-1 , bl2 = -1;
        for(int i = 0 ; i<edges.size();i++ )
         {
            int u  = edges[i][0] , v = edges[i][1];   
             if(indegree[v] != -1)
             {
                 bl1 = i;
                 bl2 = indegree[v];
                 break;
             }
             indegree[v] = i;           
         }
        
        for(int i = 0 ; i<edges.size();i++ )  
        {
             int u  = edges[i][0] , v = edges[i][1];   
            if(i == bl1 )
                continue;
            if(!dsu.connect(u , v))
            {
                if(bl1 == -1)
                    return edges[i]; // detect cycle      
                else 
                    return edges[bl2];
            }
        }
      
        return edges[bl1];
    }
};