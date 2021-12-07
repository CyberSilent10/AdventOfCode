/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
#define NUM_DAYS 256

using namespace std;

int main()
{
    string line;
    getline(cin, line);
    
    stringstream ss(line);
    string token;
    vector<int> vec;
    while(getline(ss, token, ','))
    {
        vec.push_back(stoi(token));
    }
    
    long long ans = vec.size();
    
    vector<long long> fish(NUM_DAYS, 0);
    
    for(int x: vec)
    {
        int curDay = x;
        while(curDay<NUM_DAYS)
        {
            fish[curDay]++;
            curDay += 7;
            ans++;
        }
    }

    for(int i=0; i<NUM_DAYS; i++)
    {
        if(fish[i]>0)
        {
            //for(int x : fish[i])
            {
                int curDay = i+9;
                long long c = 0;
                while(curDay<NUM_DAYS)
                {
                    fish[curDay] += fish[i];
                    curDay += 7;
                    c++;
                }   
                ans += (c*fish[i]);
            }
        }
    }
    
    cout<<ans;

    return 0;
}
