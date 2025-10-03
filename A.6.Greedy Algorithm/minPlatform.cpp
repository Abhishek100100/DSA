class Solution {
  public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        // code here
        
        // sorting both the arrival and departure array
        sort(arr.begin(),arr.end());
        sort(dep.begin(), dep.end());
        
        int count =0;
        int maxCount=0;
        
        int arrPointer=0,depPointer=0;
        int size = arr.size();
        
        while(arrPointer<size)
        {
            // for arrival
            if(arr[arrPointer]<=dep[depPointer])
            {
                count++;
                arrPointer++;
            }
            // for departure
            else
            {
                count--;
                depPointer++;
            }
            
            maxCount = max(maxCount, count);
        }
        
        return maxCount;
    }
};
