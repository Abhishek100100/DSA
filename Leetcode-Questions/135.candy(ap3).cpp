class Solution {
public:
    int candy(vector<int>& ratings) {        
        // this can be solved using greedy algorithm
        // approach 3 : optimal approach : slope approach
        int n=ratings.size();
        
        int i=1;
        int sum=1;
        while(i<n)
        {
            if(ratings[i]==ratings[i-1])
            {
                sum++;
                i++;
                continue;
            }

            // for increasing slope
            int peak=1;
            while(i<n && ratings[i]>ratings[i-1])
            {
                peak++;
                sum = sum+peak;
                i++;
            }

            // for declining slope
            int down =0;
            while(i<n && ratings[i]<ratings[i-1])
            {
                down++;
                sum=sum+down;
                i++;
            }
            down++;
            // check if peak is lesser than down
            if(down>peak) sum = sum + (down-peak);
        }

        return sum;
    }
};