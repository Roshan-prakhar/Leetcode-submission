class Solution {
public:
    bool isValid(int i,int j,int m,int n)
    {
        return i>=0&&i<m&&j>=0&&j<n;
    }

    bool solve(int rows,int cols,vector<vector<int>>& cells,int mid)
    {
        vector<vector<int>>grid(rows,vector<int>(cols,0));

        for(int i=0;i<mid;++i)
        {
            int x=cells[i][0]-1;
            int y=cells[i][1]-1;
            grid[x][y]=1;
        }

        queue<pair<int,int>>q;
        vector<vector<int>>vis(rows,vector<int>(cols,0));

        for(int j=0;j<cols;++j)
        {
            if(grid[0][j]==0)
            {
                q.push({0,j});
            }
        }

        int row[4]={-1,0,1,0};
        int col[4]={0,1,0,-1};

        while(!q.empty())
        {
            int i=q.front().first;
            int j=q.front().second;
            q.pop();

            if(vis[i][j]) continue;
            vis[i][j]=1;

            if(i==rows-1) return true;

            for(int k=0;k<4;++k)
            {
                int ni=i+row[k];
                int nj=j+col[k];

                if(isValid(ni,nj,rows,cols) &&
                   grid[ni][nj]==0 &&
                   vis[ni][nj]==0)
                {
                    q.push({ni,nj});
                }
            }
        }

        return false;
    }

    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int low=0;
        int high=cells.size();
        int ans=0;

        while(low<=high)
        {
            int mid=(low+high)>>1;

            if(solve(row,col,cells,mid))
            {
                ans=mid;
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }

        return ans;
    }
};