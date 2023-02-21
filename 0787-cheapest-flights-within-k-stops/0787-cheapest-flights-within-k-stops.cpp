class Solution {
public:
    
    vector<pair<int, int> > g[1000+10];
    int dist[10000];
    int n;
    int Dijkstra(int src ,int d , int k ) {
        for (int i = 0; i <= n; i++)
            dist[i] = 1e9;
        // dist[src] = 0;
        //                cost , node , num of cites
        priority_queue<pair<int, pair<int,int> > > pq;
        pq.push({0, {src , 0}});
        while (!pq.empty()) {
        int node = pq.top().second.first, curcost = -pq.top().first , num_of_stops =pq.top().second.second;
            pq.pop();           
            
            if(num_of_stops > k +1  or num_of_stops > dist[node])
                continue;
            dist[node] = num_of_stops;
             if(node == d)
                 return curcost;
            for (auto ch: g[node]) {
                int newcost = curcost + ch.second;                                   
                    pq.push({-newcost, {ch.first , num_of_stops + 1}});
                }
            
        }
        return  -1 ;
    }
    int findCheapestPrice(int n2, vector<vector<int>>& flights, int src, int dst, int k) {
        n = n2;
           // vector<int> dist(n2, numeric_limits<int>::max());
       for(auto it : flights)
           g[it[0]].emplace_back(it[1] , it[2]);
                        
        return Dijkstra(src , dst , k )  ;
    }
};