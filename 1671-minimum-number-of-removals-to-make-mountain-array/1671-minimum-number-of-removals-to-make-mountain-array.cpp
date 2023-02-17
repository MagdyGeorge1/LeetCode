class Solution {
public:
    int minimumMountainRemovals(vector<int>& arr) {
           int n = arr.size();
        int l[10000+10] ={}, r[10000+10]={} , mx = 0;

        for(int i =1 ; i < arr.size() ; i++){
            for(int j=0 ; j < i ; j++){
                if(arr[i] > arr[j] and l[i] < l[j] +1 ){
                    l[i] = l[j] + 1;                  
                }                  
            }
        }
      
       for(int i = n-2 ; i >= 0 ; i--){
            for(int j =i  ; j < n ; j++){
                if(arr[i] > arr[j] and r [i] < r[j] +1){
                    r[i] = r[j] + 1;               
                }              
            }          
        }
       for(int i = 0 ; i < n;i++ )
       {
          if(!l[i] or !r[i])
              continue;
           mx = max(mx , l[i] + r[i] +1);
       }
        return n - mx;
    }
    
};