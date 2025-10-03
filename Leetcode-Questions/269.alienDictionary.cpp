class Solution {
private:
   
    vector<int> topoSort(int V, vector<vector<int>> &adjList) {
        vector<int> indegree(V, 0);
        vector<int> toposort;
        queue<int> q;

        // Step 1: Calculate in-degrees for all nodes
        for (int i = 0; i < V; i++) {
            for (auto it : adjList[i]) {
                indegree[it]++;
            }
        }

        // Step 2: Push all nodes with in-degree 0 to the queue
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        // Step 3: Standard BFS traversal for Kahn's Algorithm
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            toposort.push_back(node);

            for (auto it : adjList[node]) {
                indegree[it]--;
                if (indegree[it] == 0) {
                    q.push(it);
                }
            }
        }
        
        // Return the sorted list.
        return toposort;
    }

public:
    string findOrder(vector<string> &words) {
        int N = words.size();
        
        // Adjacency list for 26 possible characters
        vector<vector<int>> adjList(26);
        
        // A set to count the number of unique characters present in the words.
        set<char> uniqueChars;
        for(auto word : words) {
            for(auto c : word) {
                uniqueChars.insert(c);
            }
        }
        
        for (int i = 0; i < N - 1; i++) {
            string s1 = words[i];
            string s2 = words[i+1];
            int len = min(s1.length(), s2.length());
            
            bool differenceFound = false;
            for (int j = 0; j < len; j++) {
                if (s1[j] != s2[j]) {
                    adjList[s1[j] - 'a'].push_back(s2[j] - 'a');
                    differenceFound = true;
                    break;
                }
            }
            
            // Handle the invalid prefix case
            if (!differenceFound && s1.length() > s2.length()) {
                return ""; // Invalid ordering
            }
        }

        // Get the topological sort of all 26 letters
        vector<int> alphaOrder = topoSort(26, adjList);

        // Build the result string by only including characters that were in the input
        string ans = "";
        for (int it : alphaOrder) {
            // Check if the character represented by 'it' was one of the unique chars
            if (uniqueChars.count(char(it + 'a'))) {
                ans += char(it + 'a');
            }
        }

        // If the resulting string's length is not equal to the number of unique
        // characters, it means some characters were part of a cycle and were not
        // included in the topological sort.
        if (ans.length() == uniqueChars.size()) {
            return ans;
        } else {
            return ""; // Cycle detected
        }
    }
};