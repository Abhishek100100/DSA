class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //Brute force approach by generating every substring until we dont see repeating characters
        int n = s.length();
        int maxLength = 0; // Stores the maximum length found so far

        // Outer loop: 'i' represents the starting index of the current substring
        for (int i = 0; i < n; ++i) {
            // Inner loop: 'j' represents the ending index of the current substring
            // For each 'i', we consider all substrings starting at 'i'
            // and ending at 'j' (where j >= i)
            vector<bool> visited(256, false); // Using a boolean array for ASCII characters
            
            for (int j = i; j < n; ++j) {
                // Check if the character s[j] has already been seen in the current substring s[i...j]
                if (visited[s[j]] == true) {
                    // If s[j] is a duplicate, then the substring s[i...j]
                    // contains repeating characters. Any further substring
                    // starting at 'i' (i.e., s[i...j+1], s[i...j+2], etc.)
                    // will also contain this duplicate.
                    // So, we break from this inner loop and move to the next starting 'i'.
                    break;
                } else {
                    // If s[j] is not a duplicate, mark it as visited for the current substring
                    visited[s[j]] = true;
                    // Update maxLength with the length of the current valid substring
                    // The length is (j - i + 1)
                    maxLength = max(maxLength, j - i + 1);
                }
            }
        }
        return maxLength;
    }
};
