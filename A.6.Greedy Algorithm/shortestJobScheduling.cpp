// User function Template for C++

//Back-end complete function Template for C++

class Solution {
  public:
    long long solve(vector<int>& bt) {
        // code here
        
        // Number of jobs
        int size = bt.size();
        long long totalWT = 0;   // total wait time for all jobs
        long long currentWT = 0; // wait time for current job
        
        sort(bt.begin(),bt.end());
        
        for(int i=0;i<size;i++)
        {
            totalWT = totalWT + currentWT;
            currentWT = currentWT + bt[i];
        }
        
        return totalWT/size;
    }
};