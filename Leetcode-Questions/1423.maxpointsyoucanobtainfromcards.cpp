class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        // the questions asks us to choose combination from leftmost and rightmost until we get max sum
        // this can be solved with constant sized sliding window approach
        int n = cardPoints.size();
        int leftsum = 0, rightsum=0;
        int maxscore = 0;

        //step 1 : calculate sum when all the elements are leftmost
 
        //traversal for left sum
        for(int i=0;i<k;i++) leftsum = leftsum + cardPoints[i];
        maxscore = leftsum;


        //traversal for right sum
        int lindex = k-1;
        int rindex = n-1;
        for(int j=0;j<k;j++)
        {
            leftsum = leftsum - cardPoints[lindex];
            lindex--;
            rightsum = rightsum + cardPoints[rindex];
            rindex--;
            maxscore = max(maxscore, leftsum+rightsum);
        }

        return maxscore;
    }
};