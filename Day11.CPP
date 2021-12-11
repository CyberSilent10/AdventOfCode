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

int getNumFlashes(vector<vector<int>> &matrix)
{
    int n = matrix.size(), m = matrix[0].size();
    vector<pair<int,int>> neighbours = {{-1,0},{0,1},{1,0},{0,-1},{-1,-1},{-1,1},{1,1},{1,-1}};
    int step = 0;
    while(1)
    {
        int ret = 0;
        step++;
        queue<pair<int,int>> flashing;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                matrix[i][j]++;
                
                if(matrix[i][j] == 10)
                {
                    ret++;
                    flashing.push(pair<int,int>(i,j));
                }
            }
        }
        
        while(!flashing.empty())
        {
            pair<int,int> cur = flashing.front();
            flashing.pop();
            
            for(pair<int,int> nb: neighbours)
            {
                int nexti = cur.first+nb.first, nextj = cur.second+nb.second;
                if(isWithinBounds(n,m,nexti,nextj))
                {
                    matrix[nexti][nextj]++;
                    if(matrix[nexti][nextj] == 10)
                    {
                        flashing.push(pair<int,int>(nexti,nextj));
                        ret++;
                    }
                }
            }
        }
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(matrix[i][j] >= 10)
                {
                    matrix[i][j] = 0;
                }
            }
        }
        
        if(ret == 100)
        {
            return step;
        }
    }
    
    return 0;
}

int main()
{
    string line;
    std::vector<vector<int>> matrix;
    while(getline(cin,line))
    {
        vector<int> temp;
        for(char c: line)
        {
            temp.push_back(c - '0');
        }
        matrix.push_back(temp);
    }
    
    cout<<getNumFlashes(matrix);

    return 0;
}
