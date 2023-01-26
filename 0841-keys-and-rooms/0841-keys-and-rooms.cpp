class Solution {
public:
    int vis[10000+10];
    void dfs(int node ,vector<vector<int>>& rooms)
    {
        vis[node] = 1;
        for(int ch : rooms[node])
            if(!vis[ch])
                dfs(ch, rooms);
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        dfs(0, rooms);
        for(int i= 0 ;i<rooms.size();i++)
            if(!vis[i])
                return 0;
    return 1;
    }
    
};