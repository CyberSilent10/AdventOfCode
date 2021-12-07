/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

int getAdditionalFuel(vector<int> &nums, int x)
{
    int ret = 0;
    for(int i: nums)
    {
        int y = abs(i-x);
        ret += (y*(y+1))/2;
        // cout<<y<<" "<<(y*(y+1))/2<<endl;
    }
    return ret;
}

int main()
{
    string line;
    getline(cin,line);
    
    string token;
    stringstream ss(line);
    vector<int> nums;
    int maxNum = INT_MIN, minNum = INT_MAX;
    while(getline(ss,token,','))
    {
        nums.push_back(stoi(token));
        maxNum = max(stoi(token), maxNum);
        minNum = min(stoi(token), minNum);
    }
    
    int ans = INT_MAX;
    for(int start = minNum; start<=maxNum; start++)
    {
        //cout<<start<<" "<<getAdditionalFuel(nums,start)<<endl;
        ans = min(ans, getAdditionalFuel(nums,start));
    }
    cout<<ans<<endl;
    return 0;
}
