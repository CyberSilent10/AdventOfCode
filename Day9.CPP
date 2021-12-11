/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

bool isWithinBounds(int n, int m, int i, int j)
{
    return (i>=0 && i<n && j>=0 && j<m);
}

void setTopBasins(vector<int> &topThreeBasins, int basinSize)
{
    if(topThreeBasins[0] < basinSize)
    {
        topThreeBasins[2] = topThreeBasins[1];
        topThreeBasins[1] = topThreeBasins[0];
        topThreeBasins[0] = basinSize;
        return;
    }
    
    if(topThreeBasins[1] < basinSize)
    {
        topThreeBasins[2] = topThreeBasins[1];
        topThreeBasins[1] = basinSize;
        return;
    }
    
    if(topThreeBasins[2] < basinSize)
    {
        topThreeBasins[2] = basinSize;
    }
    
    return;
}

int findBasinSize(int i, int j, vector<vector<int>> &matrix)
{
    std::queue<pair<int,int>> bfs;
    bfs.push(pair<int,int>(i,j));
    vector<pair<int,int>> neighbours = {{-1,0},{0,1},{1,0},{0,-1}};
    int ret = 1;
    vector<vector<bool>> visited(matrix.size(), vector<bool>(matrix[0].size(),false));
    visited[i][j] = true;
    int n = matrix.size(), m = matrix[0].size();
    while(!bfs.empty())
    {
        pair<int,int> cur = bfs.front();
        bfs.pop();
        for(pair<int,int> nb: neighbours)
        {
            int nexti = cur.first+nb.first, nextj = cur.second+nb.second;
            if(isWithinBounds(n,m,nexti,nextj) && !visited[nexti][nextj] && matrix[nexti][nextj] != 9)
            {
                bfs.push(pair<int,int>(nexti,nextj));
                visited[nexti][nextj] = true;
                ret++;
            }
        }
    }
    
    return ret;
}

int main()
{
    string line;
    vector<vector<int>> matrix;
    while(getline(cin,line))
    {
        vector<int> temp;
        for(int i=0; i<line.length(); i++)
        {
            temp.push_back(line[i] - '0');
        }
        matrix.push_back(temp);
    }
    
    vector<int> topThreeBasins = {INT_MIN, INT_MIN, INT_MIN};
    vector<pair<int,int>> neighbours = {{-1,0},{0,1},{1,0},{0,-1}};
    int n = matrix.size(), m = matrix[0].size(), ans = 0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            bool lowPoint = true;
            for(pair<int,int> nb: neighbours)
            {
                if(isWithinBounds(n,m,i+nb.first,j+nb.second) && matrix[i+nb.first][j+nb.second] <= matrix[i][j])
                {
                    lowPoint = false;
                    break;
                }
            }
            
            if(lowPoint)
            {
                int sz = findBasinSize(i,j,matrix);
                setTopBasins(topThreeBasins,sz);
            }
        }
    }
    cout<<topThreeBasins[0] * topThreeBasins[1] * topThreeBasins[2]<<endl;
    return 0;
}
