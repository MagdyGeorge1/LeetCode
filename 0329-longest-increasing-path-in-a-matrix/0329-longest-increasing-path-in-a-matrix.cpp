class Solution {
public:
    int n, m , dp[200][200];
    bool valid (int i , int j)
    {
        return (i<0 or j<0 or i>=n or j>=m);
    }
    int dfs(int i , int j , int pre ,vector<vector<int>>& matrix )
    {
        if(valid(i ,j) or matrix[i][j] <= pre )
            return 0;
        
      int &ret = dp[i][j];
        if(~ret)
            return ret;
        pre = matrix[i][j];
        ret = 1+ max({dfs( i+1, j, pre , matrix),
                      dfs( i-1, j, pre,matrix),
                      dfs( i, j+1, pre,matrix),
                      dfs( i, j-1, pre ,matrix)});
        return ret;
          
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int mx = 0;
        n =  matrix.size();
        m = matrix[0].size();
        memset(dp , -1 , sizeof dp);
        for(int i = 0;i< matrix.size();i++)
        {
             for(int j = 0; j< matrix[i].size() ; j++)
             {
                 mx = max(mx , dfs(i, j , -1, matrix ));
             }
        }
        return mx;
    }
};