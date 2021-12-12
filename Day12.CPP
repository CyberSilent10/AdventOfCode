/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

bool isSmallVisTwice = false;

bool isSmallCave(string cave)
{
    
    if(cave[0]>='a' && cave[0]<='z')
    {
        return true;
    }
    
    return false;
}

void getTotalPaths(unordered_map<string,vector<string>> &graph, int &ans, string cur, unordered_map<string,int> &visited)
{
    if(cur == "end")
    {
        ans++;
        return;
    }
    
    if(isSmallCave(cur))
    {
        if(visited[cur] == 1)
        {
            isSmallVisTwice = true;
        }
        visited[cur]++;
    }

    for(string cave: graph[cur])
    {
        if((visited[cave] == 0) || (visited[cave] == 1 && cave != "start" && !isSmallVisTwice))
        {
            getTotalPaths(graph,ans,cave,visited);
        }
    }
    
    if(visited[cur] == 2)
    {
        isSmallVisTwice = false;
    }
    
    if(visited[cur] > 0)
        visited[cur]--;
}

int main()
{
    unordered_map<string,vector<string>> graph;
    unordered_map<string,int> visited;
    string line, token;
    while(getline(cin,line))
    {
        string x, y;
        stringstream ss(line);
        while(getline(ss,token,'-'))
        {
            if(x.empty())
                x = token;
            else
                y = token;
        }

        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    int ans = 0;
    getTotalPaths(graph,ans,"start",visited);
    cout<<ans<<endl;
    return 0;
}
