class Solution {
public:
    int candy(vector<int>& ratings) {
        // see while moving homes i dont care if a less rating home comes
        // after high rating, i wont give extra to the previous home 
        // it's one way movement
        
        // this can be solved using greedy algorithm
        // approach 2 : better approach, we dont need a right array
        int size=ratings.size();
        vector<int>left(size,1);
    
        // populating left array
        left[0]=1;
        for(int i=1;i<size;i++)
        {
            if(ratings[i]>ratings[i-1]) left[i]=left[i-1]+1;
        }

        
        int right=1;
        int sum=max(left[size-1], right);
        for(int i=size-2;i>=0;i--) 
        {
            if(ratings[i]>ratings[i+1]) right++;
            else right=1;
            sum = sum + max(left[i],right);
        }
        
        return sum;
    }
};