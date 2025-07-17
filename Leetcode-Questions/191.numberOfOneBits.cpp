class Solution {
public:
    int hammingWeight(int n) {
        int count=0;

        // until the number becomes zero we can do bitwise and of n and n-1
        while(n)
        {
            n=n&(n-1);
            count++;
        }

        return count;
    }
};