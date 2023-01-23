class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
       //int out[100000 +10] = {} , cost[100000+10] ={};
        vector<int>out(n+10 , 0) , cost(n+10 , 0);
        for(auto iter : roads)    
            out[iter[0]]++,out[iter[1]]++;
        priority_queue<pair<int,int>>pq;
        for(int i = 0; i<=n;i++)
            if(out[i])
              pq.push({out[i] , i});
        sort(out.rbegin() , out.rend());
        int st = n;
        while(pq.size())
        {
            int node =  pq.top().second;
            cost[node] = n--;
            pq.pop();
        }
        long long res = 0;
        for(auto iter : roads)
            res+= (cost[iter[0]] + cost[iter[1]]);
        return res;
    }
};