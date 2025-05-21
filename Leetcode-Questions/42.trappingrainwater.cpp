class Solution {
public:
    int trap(vector<int>& height) {
        //there are three ways to solve it, i am writing the O(n) TC and SC

        int ans=0;
        int n = height.size();

        if (n <= 2) return 0; //failed to add this condition

        //step 1 : maintain max left and max right array
        vector<int> maxL(n), maxR(n);
        //int maxLeft =  height[0];
        maxL[0] = height[0];
        //int maxRight =  height[n-1];
        maxR[n-1] = height[n-1];
        
        // forming the left max array
        for(int i=1;i<n;i++)
        {
            //maxLeft = max(maxLeft, height[i]);
            //maxL[i]= maxLeft;
            maxL[i]= max(maxL[i-1], height[i]);
        }

        // forming the right max array
        for(int j=n-2;j>=0;j--)
        {
            // maxRight = max(maxRight, height[j]);
            // maxR[j]=maxRight;
            maxR[j]= max(maxR[j+1], height[j]);
        }


        // step 2 : the water at current level is min(maxLeft,maxRight) - current height
        for(int k=1;k<n-1;k++)
        {
            int water = min(maxL[k], maxR[k]);
            if(water > height[k]) ans = ans + water - height[k];
        }

        return ans;
    }
};