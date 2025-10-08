#include <bits/stdc++.h> 
vector<int> getSecondOrderElements(int n, vector<int> a) {
    
    // Second largest
    int largest = a[0];
    int slargest = -1;

    for(int i=1;i<n;i++)
    {
        if(a[i]>largest)
        {
            slargest = largest;
            largest = a[i];
        }

        else if (a[i] < largest && a[i] > slargest)
        {
            slargest = a[i];
        }
    }

    // Second Smallest
    int smallest = a[0];
    int ssmallest = INT_MAX ; 
    
    for(int i=1;i<n;i++)
    {
        if(a[i] < smallest)
        {
            ssmallest = smallest;
            smallest = a[i];
        }

        else if (a[i] > smallest && a[i] < ssmallest)
        {
            ssmallest = a[i];
        }
    }

    
    return {slargest,ssmallest};
}
