class Solution {
public:
    int vis[100000];
    bool dfs(int node ,  vector<vector<int>>& adj )
    {            
        bool not_cycle = 1;
        vis[node] =1 ;
        for(int ch : adj[node])
        {
            if(vis[ch] == 1)
              return  not_cycle &= 0 ;
            else if(!vis[ch])
              not_cycle &=  dfs(ch , adj);
        }
        
        vis[node] = 2;
        return not_cycle;
    }
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        int indegree[100000] ={};
        vector<vector<int>>adj(1e5);
        for(int i = 0 ; i < n ;i++)
        {
        if(leftChild[i] != -1)
            indegree[leftChild[i]] ++,adj[i].push_back(leftChild[i]);
        if(rightChild[i] != -1)
             indegree[rightChild[i]] ++,adj[i].push_back(rightChild[i]);
                
        }
        int root = -1 ,cnt = 0;
        for (int i = 0 ;i<n;i++)
        {
            if(indegree[i] > 1)
                return false;
            if(!indegree[i] and root == -1)
            {
                root = i;
                if (!dfs(i , adj))
                    return false;                                
            } 

        }
     for(int i = 0 ; i<n;i++)
         if(!vis[i])
             return false;
        return  1;
    }
};