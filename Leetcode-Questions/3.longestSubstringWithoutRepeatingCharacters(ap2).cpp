class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // this can be solved with sliding window let's see
        int n = s.length();

        // sliding window
        int left=0, right=0, maxlen = 0;

        //hash to store the characters
        vector<int> count(256,0);
        
        //move right of the window
        while(right<n)
        {
            // mark the character as visited
            count[s[right]]++;

            // if the frequency is greater than 1
            while(count[s[right]]>1) 
            {
                //shrink the window from left and mark it unvisited
                count[s[left]]--;
                left++;
            } 

            // max length of the substring
            maxlen = max(maxlen, right-left+1);
            right++;
        }

        return maxlen;
    }
};