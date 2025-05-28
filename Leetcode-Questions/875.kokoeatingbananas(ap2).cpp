// see the way to get the maximum element in a vector
class Solution {
public:
    long long hours(vector<int>&piles, int k)
    {
        long long totalhr = 0;
        for(auto it: piles) totalhr += ceil((it+k-1)/k);
        return totalhr;
    }

     int minEatingSpeed(vector<int>& piles, int h) {
       
       // Here we need to find a k (bananas/hr)
       // k is minimum #bananas that coco must eat to finish everything within h hours)
       // so we will apply binary search to find optimal K value
       
       int low = 1, high = *max_element(piles.begin(),piles.end());;
       int k = high;
       
       while(low<=high)
       {
            int mid = (low+high)/2;
            if(hours(piles,mid)<=h)
            {
                k = mid;
                high=mid-1;
            } 
            else low = mid+1;
       }

       return k;
    }

};