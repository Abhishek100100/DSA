class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // note : we need to insert just 1 new interval here
        // we will make new result ds to store intervals
        // will push the left part until newInterval is not colliding
        // merge the colliding part, push it 
        // will push all the right part of the intervals

        int n=intervals.size();
        int newIntervalStart = newInterval[0];
        int newIntervalFinish = newInterval[1];
        vector<vector<int>> result;

        int i=0;
        // left part : unaffected intervals on LHS
        // end of current interval is less than start of new interval start time
        while(i<n && intervals[i][1]<newIntervalStart)
        {
            result.push_back(intervals[i]);
            i++;
        }

        // middle part : merging colliding intervals
        // start of current interval is less than equal to end of new interval end time
        while(i<n && intervals[i][0]<=newIntervalFinish)
        {
            newIntervalStart = min(newIntervalStart, intervals[i][0]);
            newIntervalFinish = max(newIntervalFinish, intervals[i][1]);
            i++;
        }
        result.push_back({newIntervalStart,newIntervalFinish});

        // right part : unaffected intervals on RHS
        while(i<n)
        {
            result.push_back(intervals[i]);
            i++;
        }

        return result;
    }
};