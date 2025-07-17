class Solution {
private: 
    int countSetBits(int n)
    {
        int count=0;
        while(n)
        {
            n = n&(n-1);
            count++;
        }

        return count;
    }
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i=0;i<=n;i++)
        {
            ans.push_back(countSetBits(i));
        }
        return ans;
    }
};