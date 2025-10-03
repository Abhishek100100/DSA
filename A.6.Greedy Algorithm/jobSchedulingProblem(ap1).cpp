// gave runtime error with normal approach

bool comp(pair<int,int> p1, pair<int,int> p2)
    {
        if(p1.second>p2.second) return true;
        else if(p1.second==p2.second)
        {
            if(p1.first>p2.first) return true;
        }
        else return false;
    }
    

class Solution {
  public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
    
        // make a new vector of pairs and sort it according to the profit
        int size = deadline.size();
        vector<pair<int,int>> ds;
        
        // pushing the pairs into new ds
        for(int i=0;i<size;i++)
        {
            ds.push_back({deadline[i], profit[i]});
        }
        
        //sorting according to the profit is descending order
        sort(ds.begin(), ds.end(), comp);
        
        // max deadline to form the job schedulign array
        int maxDeadline = 0;
        for(auto it : ds)
        {
            maxDeadline = max(maxDeadline, it.first);
        }
        
        vector<int> job(maxDeadline+1,-1);
        int totalProfit =0;
        int count=0;
        
        // traversing the ds
        for(int i=0;i<size;i++)
        {
            int currentDeadline = ds[i].first;
            int currentProfit = ds[i].second;
            
            
            for (int j = currentDeadline; j > 0; j--) {
                if (job[j] == -1) {
                    // This slot is free, schedule the job
                    job[j] = i; // Store job index
                    totalProfit += currentProfit;
                    count++;
                    break; // Move to the next job in the outer loop
                }
            }
        }
        
        return {count, totalProfit};
        
    }
};