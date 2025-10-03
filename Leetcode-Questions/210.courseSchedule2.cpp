class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // This problem is similar to detecting cycle using topological sorting
        // will do this with kahn's algorithm
        // they have given vertices(num of courses) and edgelist(prerequisites)
        // problem 207 asks if possible, this question asks to return order

        // step 1 : declaration and initialisations
        vector<vector<int>> adjList(numCourses);
        vector<int> indegree(numCourses, 0);
        vector<int> ordering;
        queue<int> q;


        // step 2 : populate the indegree graph and convert the edge list into adjacency list
        for(auto it: prerequisites)
        {
            adjList[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }

        // step 3 : push the courses with no prerequsities into the queue first
        for(int i=0;i<numCourses;i++)
        {
            if(indegree[i]==0) q.push(i);
        }


        // step 4 : do the topological sorting
        while(!q.empty())
        {
            int course = q.front();
            q.pop();
            ordering.push_back(course);

            // since we elinated that course, the prior dependecy from the associated course reduces
            for(auto it: adjList[course])
            {
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        
        if(ordering.size()==numCourses) return ordering;
        else return {};
    }
};