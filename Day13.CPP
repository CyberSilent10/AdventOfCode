/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    set<pair<int,int>> points;
    string line, token;
    while(getline(cin,line))
    {
        if(line.empty())
            break;
        stringstream ss(line);
        string x,y;
        while(getline(ss,token,','))
        {
            if(x.empty())
                x = token;
            else
                y = token;
        }
        points.insert({stoi(x),stoi(y)});
    }
    
    while(getline(cin,line))
    {
        set<pair<int,int>> newPoints;
        string fold = line.substr(11);
        int val = stoi(fold.substr(2));
        for(auto it = points.begin(); it != points.end(); it++)
        {
            if(fold[0] == 'x' && it->first > val)
            {
                newPoints.insert({val-(it->first-val), it->second});
            }
            else if(fold[0] == 'y' && it->second > val)
            {
                newPoints.insert({it->first, val-(it->second-val)});
            }
            else
            {
                newPoints.insert({it->first, it->second});
            }
        }
        points = newPoints;
    }
    
    int xLim = INT_MIN, yLim = INT_MIN;
    for(auto it = points.begin(); it != points.end(); it++)
    {
        xLim = max(xLim,it->second);
        yLim = max(yLim,it->first);
    }
 
    for(int i=0; i<=xLim; i++)
    {
        for(int j=0; j<=yLim; j++)
        {
            if(points.find({j,i}) != points.end())
            {
                cout<<"#";
            }
            else
            {
                cout<<".";
            }
        }
        cout<<endl;
    }
}
