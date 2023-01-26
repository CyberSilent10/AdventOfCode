/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;


int getLeastCost(vector<vector<int>> &vec)
{
}

int main()
{
    vector<vector<int>> matrix;
    string line;
    while(getline(cin,line))
    {
        vector<int> row;
        for(char ch: line)
        {
            row.push_back(ch-'0');
        }
        matrix.push_back(row);
    }
    
    cout<<getLeastCost(matrix);
}
