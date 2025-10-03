class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        // Declaring variables
        int totalGas=0, totalCost=0;

        //Computing total gas and cost
        for(auto it: gas) totalGas += it;
        for(auto it: cost) totalCost += it;

        if(totalCost>totalGas) return -1; // Elimination condition
        
        // searching for the unique index to cover the circular path
        int start=0; int currentGas = 0;
        for(int i=0;i<gas.size();i++)
        {
            currentGas+= gas[i]-cost[i];

            if(currentGas<0)
            {
               start=i+1;
               currentGas=0;
            } 
        }

        return start;
    }
};