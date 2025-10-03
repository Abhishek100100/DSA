class Solution {
public:

    int maxElement(vector<int>& piles)
    {
        int n= piles.size();
        int maxi=INT_MIN;
        //I was thinking of finding max with BS, 
        //but again array needs to be sorted first
        //will do linear search for now
        
        for(int i=0;i<n;i++) maxi = max(piles[i],maxi);
        return maxi;
    }

    long long computeHours(vector<int>& piles, int mid)
    {
        long long hours=0;
        for(int i=0;i<piles.size();i++)
        {
           hours = hours+(piles[i] + mid -1)/mid;  //here arithmetic ceil is used for integers
           //ceil works best for double/float numbers.
        }
        return hours;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        
        int low=1,high=maxElement(piles);
        int ans=-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(computeHours(piles,mid)<=h) 
            {
                ans=mid;
                high=mid-1; //since i am utilising less time to finish all
                //it means some lower index exists which will also get the job done
            }
            else low=mid+1;
        }

        return ans;
    }
};