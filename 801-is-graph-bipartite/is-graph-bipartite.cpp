class Solution {
public: 
bool dfs(int node,vector<vector<int>>&adj,vector<int>&color)
{
    for(int nei:adj[node])
    {
        if(color[nei]==-1)
        {
            color[nei]=1-color[node];
            if(!dfs(nei,adj,color)) return false;
        }
        else {
            if(color[nei]==color[node]) return false;
        }
    }
    return true;
}

    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>>adj(n);
        vector<int>vis(n,0);
         vector<int>color(n,-1);
         for(int i=0;i<n;++i)
         {
             for(int j=0;j<graph[i].size();++j)
             {
                adj[i].push_back(graph[i][j]);
             }
         }
         for(int i=0;i<n;++i)
         {
                if(color[i]==-1)
                {
                   color[i]=0;
                   if(!dfs(i,adj,color)) return false;
                }
         }


   return true;

        
    }
};