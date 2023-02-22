class Solution {
public:
    
    bool valid(int i , int j , vector<vector<int>>& mat )
    {
        return (i >= 0 and i < mat.size() and j >= 0 and j< mat[0].size() );
    }
    

    void bfs(queue<pair<int,int>> & q , vector<vector<int>>& ans ,vector<vector<int>>& mat  )
    {
        int dx [4] = { 1 , -1 , 0 , 0};
        int dy [4] = { 0 , 0 , 1 , -1};
        while(q.size())
        {
            
            int x = q.front().first , y = q.front().second;
            
            q.pop();
            for(int i = 0 ; i < 4;i++)
            {
                int new_x = x + dx[i] , new_y = y + dy[i];
                if(valid(new_x , new_y , mat))
                {
                    if(ans[new_x][new_y] > ans[x][y] +1 )
                    {
                        ans[new_x][new_y] = ans[x][y] +1;
                        q.push({new_x , new_y});
                    }
                }
                
            }
        }
        
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
          
        vector<vector<int>> ans(mat.size() , vector<int>(mat[0].size() , 1e9));
        queue<pair<int,int>> q;
        for(int i = 0 ; i < mat.size() ; i++)
        {
            for(int j = 0 ; j < mat[i].size() ;j++)
            {
                if(!mat[i][j])
                  ans[i][j] = 0 , q.push({i, j}); 
            }
        }
        cout << ans[0][0]<<endl;
        bfs(q , ans , mat );
        
        return ans;
    }
};