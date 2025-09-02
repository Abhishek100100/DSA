class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        // if denom is 5 return nothing, if it's 10 then return 5, if it's 20 return 10,5 or 5,5,5
        // so we will apply greedy logic here and utilise the 10 rs bill first instead of 5 to serve customers.

        int size = bills.size();
        int five = 0, ten = 0;

        for(auto it: bills)
        {
            // outer if else condition to check the denomination
            if(it==5) five++;
            else if(it ==10)
            {
                if(five) 
                {
                    ten++;
                    five--;
                }
                else return false;
            }
            // this condition is for 20rs bill
            else
            {
                if(ten && five) 
                {
                    ten--;
                    five--;
                }
                else if(five>=3) five = five - 3;
                else return false;
            }
        }

        return true;
    }
};