#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <utility>

// Custom comparator to sort jobs by profit in descending order
bool comp(const std::pair<int, int>& p1, const std::pair<int, int>& p2) {
    return p1.second > p2.second;
}

// DSU class for Job Sequencing
class DisjointSet {
private:
    std::vector<int> parent;

public:
    DisjointSet(int n) {
        parent.resize(n + 1);
        // Initially, each element is its own parent
        // std::iota fills the range [begin, end) with increasing values, starting with value
        std::iota(parent.begin(), parent.end(), 0);
    }

    // Finds the ultimate parent of a given time slot with path compression
    int find(int i) {
        if (parent[i] == i) {
            return i;
        }
        // Path compression: set parent to the root of the set
        return parent[i] = find(parent[i]);
    }

    // Union operation for Job Sequencing: always merge a slot with the one before it
    // This effectively marks a slot as occupied and makes the next available slot the one before it.
    void union_sets(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        // We always set the parent of the root of the first set to the root of the second set.
        // For job sequencing, we schedule a job in slot 'availableSlot' and then make the parent of
        // 'availableSlot' be 'availableSlot - 1'.
        if (root_i != root_j) {
            parent[root_i] = root_j;
        }
    }
};

class Solution {
public:
    std::vector<int> jobSequencing(std::vector<int>& deadline, std::vector<int>& profit) {
        int size = deadline.size();
        std::vector<std::pair<int, int>> ds;

        for (int i = 0; i < size; i++) {
            ds.push_back({deadline[i], profit[i]});
        }

        std::sort(ds.begin(), ds.end(), comp);

        int maxDeadline = 0;
        for (const auto& it : ds) {
            maxDeadline = std::max(maxDeadline, it.first);
        }
        
        DisjointSet dsu(maxDeadline);

        int totalProfit = 0;
        int jobCount = 0;

        for (int i = 0; i < size; i++) {
            int currentDeadline = ds[i].first;
            int currentProfit = ds[i].second;

            // Find the latest available slot for this job.
            // dsu.find(currentDeadline) will give the root of the set, which is the
            // latest available slot less than or equal to currentDeadline.
            int availableSlot = dsu.find(currentDeadline);

            // If a valid slot is found (not the dummy slot 0)
            if (availableSlot > 0) {
                totalProfit += currentProfit;
                jobCount++;
                
                // Union the current slot with the previous slot to mark it as occupied.
                dsu.union_sets(availableSlot, availableSlot - 1);
            }
        }
        
        return {jobCount, totalProfit};
    }
};