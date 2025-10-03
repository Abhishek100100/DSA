class Solution {
public:
    bool isPalindrome(string s) {
        //This is simple with two pointer approach
        //The only thing i was worrying was about how to check for valid alphanumeric character
        vector<char> cleanstr;

        //step 1 : form a clean string
        for(auto it : s)
        {   //for the numeric, i must consider them as char and not int
            if(it>='A' && it<='Z' || it>='a' && it<='z' || it>='0' && it<='9') cleanstr.push_back(tolower(it));
        }

        //step 2 : move two pointers over the cleanstr
        int left = 0;
        int right = cleanstr.size()-1;

        while(left<=right)
        {
            if(cleanstr[left]==cleanstr[right])
            {
                left++;
                right--;
            }
            else return false;
        }

        return true;
    }
};