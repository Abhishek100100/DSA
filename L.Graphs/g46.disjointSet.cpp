#include<bits/stdc++.h>
#include <iostream>
using namespace std;

class DisjointSet
{
    private : 
    vector<int> parent, rank, size;

    public: 

    DisjointSet(int n)
    {
        //considering 1 based indexing
        parent.resize(n+1);
        rank.resize(n+1,0);
        size.resize(n+1,0);

        // making the parent of each node to itself
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
            size[i]=1;
        }
    }

    int findUltimateParent(int node)
    {
        // here we are doing path compression
        // we do this by recursively calling the function until we reach the ultimate parent
        if (parent[node] == node) return node;
        return parent[node] = findUltimateParent(parent[node]);
    }


    void unionByRank(int u, int v)
    {
        int ultimatepu = findUltimateParent(u);
        int ultimatepv = findUltimateParent(v);

        if(ultimatepu==ultimatepv) return;
        if(rank[ultimatepu] < rank[ultimatepv]) parent[ultimatepu] = ultimatepv;
        else if(rank[ultimatepu] > rank[ultimatepv]) parent[ultimatepv] = ultimatepu;
        else 
        {
            parent[ultimatepv] = ultimatepu;
            rank[ultimatepu]++;
        }
    }

    void unionBySize(int u, int v)
    {
        int ultimatepu = findUltimateParent(u);
        int ultimatepv = findUltimateParent(v);

        if(ultimatepu==ultimatepv) return;
        if(size[ultimatepu] < size[ultimatepv]) {
            parent[ultimatepu] = ultimatepv;
            size[ultimatepv] += size[ultimatepu];
        }
        else {
            parent[ultimatepv] = ultimatepu;
            size[ultimatepu] += size[ultimatepv];
        }
    }




};


int main()
{
    DisjointSet ds(7);
    ds.unionByRank(1, 2);
    ds.unionByRank(2, 3);
    ds.unionByRank(4, 5);
    ds.unionByRank(6, 7);
    ds.unionByRank(5, 6);
    // if 3 and 7 same or not
    if (ds.findUltimateParent(3) == ds.findUltimateParent(7)) {
        cout << "Same\n";
    }
    else cout << "Not same\n";

    ds.unionByRank(3, 7);

    if (ds.findUltimateParent(3) == ds.findUltimateParent(7)) {
        cout << "Same\n";
    }
    else cout << "Not same\n";
    return 0;
}