class Solution {
private:
    
    // step 3 : checking in a dfs fashion if it is possible to color the graph
    bool dfsCheck(int start, int col, vector<int> &color, vector<vector<int>>& graph)
    {
       color[start]=col;

       // check for it's adjacent nodes color
       for(auto it: graph[start])
       {
         if(color[it]==-1)
         {
            if (dfsCheck(it, !col, color,graph) == false) return false;
         }

         else if(color[it]==col) return false;
       }

       return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {

        // step 1 : ds declaration and misc
        int V = graph.size();  // number of nodes
        vector<int> color(V,-1); // visited color array
        
        
        // step 2 : since there are connected components in this graph, do this
        for(int i=0;i<V;i++)
        {
            // if the vertex is not yet visited then that's the starting node of that connected component
            if(color[i]==-1)
            {
                // check if it's possible to color alternatively
                if(dfsCheck(i, 0, color, graph)==false) return false;
            }
        }

        return true;
    }
};