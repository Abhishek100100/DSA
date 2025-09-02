class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        // we need to satisfy maximum children we could with given cookies
        // we can apply greedy algorithm on this 

        int gsize = g.size();
        int ssize = s.size();
        int left=0 , right = 0, count=0;

        sort(g.begin(),g.end());
        sort(s.begin(),s.end());

        // Assuming the array is sorted as given in the examples
        while(left<gsize && right<ssize)
        {
            if(g[left]<=s[right]) 
            { 
                count++;
                left++;
                right++;
            }
            else right++;
        }

        return count;
    }
};