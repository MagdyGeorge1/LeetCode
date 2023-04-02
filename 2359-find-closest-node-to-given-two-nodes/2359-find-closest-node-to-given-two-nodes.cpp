class Solution {
public:
    vector<int>v[100000];
    int vis[100000];
    void dfs(int node , int d , vector<int>&dist)
    {
        vis[node] =1;
        dist[node] = d ;
        cout << node<< " ";
        for(int ch : v[node])
            if(!vis[ch])
                dfs(ch , d+1 , dist);
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        for(int i =0 ; i< edges.size();i++)
        {
            if(edges[i] == -1 )
                continue;
            v[i].push_back(edges[i]);
        }
        vector<int>dist1(edges.size(), INT_MAX) , dist2(edges.size() , INT_MAX);
        dfs(node1 , 1 , dist1 );
        memset(vis , 0 , sizeof vis);
        dfs(node2 , 1 , dist2);
        int idx = -1 , mn = INT_MAX;
        for(int i = 0 ; i < edges.size();i++)
        {
            if(max(dist1[i],dist2[i]) < mn)
            {
                mn = max(dist1[i],dist2[i]);
                idx = i;
            }
        }
        return idx ;
    }
};