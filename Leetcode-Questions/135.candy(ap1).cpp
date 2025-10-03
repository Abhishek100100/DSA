class Solution {
public:
    int candy(vector<int>& ratings) {
        // see while moving homes i dont care if a less rating home comes
        // after high rating, i wont give extra to the previous home 
        // it's one way movement
        
        // this can be solved using greedy algorithm
        // approach 1 : brute approach
        int size=ratings.size();
        vector<int>left(size,1);
        vector<int> right(size,1);
    
        // populating left array
        left[0]=1;
        for(int i=1;i<size;i++)
        {
            if(ratings[i]>ratings[i-1]) left[i]=left[i-1]+1;
        }

        // populating right array
        right[size-1]=1;
        for(int i=size-2;i>=0;i--)
        {
            if(ratings[i]>ratings[i+1]) right[i]=right[i+1]+1;
        }

        int sum=0;
        for(int i=0;i<size;i++) sum = sum + max(left[i],right[i]);

        return sum;
    }
};