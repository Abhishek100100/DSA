
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
// C++ program to How will you print name with numbers from 1 to n without using a loop?
void WithoutLoop(int n)
{
    if(n>0) 
    {
        WithoutLoop(n-1);
        cout << "Abhishek " << n << endl;
    }
}


int main()
{
    int num;
    cin >> num;
    WithoutLoop(num);
    return 0;
}




/* MISTAKE 1
This code was not printing numbers to the console only returning it.
class recurse{
    public: // access modifier
    int withoutloop(int num){ 
        if(num==1) return 1;
        return withoutloop(num-1);
    };
};

//Driver Code
int main(){
    int num;
    cin >> num;
    recurse abc;
    abc.withoutloop(num);
    return 0;
}
*/



/* APPROACH 2
// This way we can call it from class members
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class recursive{
    public:
    
    void WithoutLoop(int n)
    {
        if(n>0) 
        {
            WithoutLoop(n-1);
            cout << n << endl;
        }
    }
};


int main()
{
    int num;
    recursive abcd;
    cin >> num;
    abcd.WithoutLoop(num);
    return 0;
}
*/

