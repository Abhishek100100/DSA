class Solution {
private:
    // step 3 : checking in a bfs fashion if it is possible to color the graph
    bool bfsCheck(int start, int V, vector<int> &color, vector<vector<int>>& graph)
    {
        color[start] = 0; // color 0
        queue<int> q; // queue for bfs traversal
        q.push(start); // pushing starting vertex
        
        // do bfs traversal
        while(!q.empty())
        {
            int node = q.front();
            q.pop();

            for(auto it: graph[node])
            {
                // if the node is not colored yet, color it with opposite of current node
                if(color[it]==-1)
                {
                    color[it] = !color[node];
                    q.push(it);
                }

                // if the node is colored with same color as node, then it voids the condition
                else if(color[it]==color[node])
                {
                    return false;
                }
            }
        }

        return true;

    }

public:
    bool isBipartite(vector<vector<int>>& graph) {

        // step 1 : ds declaration and misc
        int V = graph.size();  // number of nodes
        vector<int> color(V,-1); // visited color array
        
        
        // step 2 : since it is connected graph, do this
        for(int i=0;i<V;i++)
        {
            // if the vertex is not yet visited then that's the starting node of that connected component
            if(color[i]==-1)
            {
                // check if it's possible to color alternatively
                if(bfsCheck(i, V, color, graph)==false) return false;
            }
        }

        return true;
    }
};