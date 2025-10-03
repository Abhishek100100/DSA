 bool comp(pair<double, pair<double,double>> &a, pair<double, pair<double,double>> &b)
    {
        return a.first>b.first;
    }
    
    
class Solution {
  public:
   
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        
        // we can solve this using greedy algorithm
        // I will make a custom data structure that will store {ratio, {val,wt}}
        
        vector<pair<double, pair<double,double>>> ds;
    
        int n = val.size();
        
        for(int i=0;i<n;i++)
        {
            double ratio = ((double)val[i]/(double)wt[i]);
            ds.push_back({ratio, {(double)val[i],(double)wt[i]}});
        }
        
        // sorting with custom comparator
        sort(ds.begin(), ds.end(), comp);
        
        
        double currSize = 0;
        double price = 0;
        vector<pair<int,int>> ans;
        
        for(int i=0;i<n;i++)
        {
            double currVal = ds[i].second.first;
            double currWt = ds[i].second.second;
            double currRatio = ds[i].first;
            
            if(currSize+currWt<=capacity)
            {
                ans.push_back({currVal, currWt});
                price = price+currVal;
                currSize = currSize + currWt;
            }
            else
            {
                price = price + (capacity-currSize)*currRatio;
                ans.push_back({(capacity-currSize)*currRatio , (capacity-currSize)});
                break;
            }
            
        }
        
        return price;
        
    }
};
