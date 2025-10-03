bool comp(pair<int,int> p1, pair<int,int> p2)
{
    return p1.second<p2.second;
}

class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(vector<int>& start, vector<int>& end) {
     
        // This can be solved using greedy algorithm to have maximum meeting
        // new data structure to hold the data
        vector<pair<int,int>> ds;
        int size = start.size();
        
        // pushing the given data into custom ds
        for(int i=0;i<size;i++)
        {
            ds.push_back({start[i],end[i]});
        }
        
        // sorting it in ascending order of end time
        sort(ds.begin(), ds.end(), comp);
        
        // final answer vector, in this question we just need to enter the maximum meeting that we can conduct
        vector<pair<int,int>> answer;
        answer.push_back(ds[0]);
        int startTime= ds[0].first;
        int endTime = ds[0].second;
        
        // loop over the ds and push the possible meeting slots into or ans array
        for(int i=1;i<size;i++)
        {
            int currStartTime = ds[i].first;
            int currFinishTime = ds[i].second;
            
            if(currStartTime>endTime)
            {
                answer.push_back(ds[i]);
                startTime = currStartTime;
                endTime = currFinishTime;
            }
        }
        
        return answer.size();
    }
};