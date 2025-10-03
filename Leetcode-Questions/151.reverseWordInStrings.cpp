class Solution {
public:
    string reverseWords(string s) {
       // we have to use stl string functions in this
       // step 1 : reverse the entire string
       // step 2 : reverse the individual word of this string 
       // step 3 : handle edge cases and return the ans

       string ans = "";
       int n = s.length();

       reverse(s.begin(),s.end());
       for(int i=0;i<n;i++)
       {
          string word = "";
          while(i<n && s[i] != ' ')
          {
            word += s[i] ;
            i++;
          }
          reverse(word.begin(), word.end());
          if(word.length()>0) ans +=  ' ' + word;
       }

       return ans.substr(1);
    }
};