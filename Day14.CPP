/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string poly;
    cin>>poly;
    
    string line;
    getline(cin,line);
    
    map<char,long long> freq;
    unordered_map<string,long long> pairCount;
    for(int i=0; i<poly.length()-1; i++)
    {
        freq[poly[i]]++;
        pairCount[poly.substr(i,2)]++;
    }
    freq[poly[poly.length()-1]]++;
    
    unordered_map<string,char> insertions;
    while(getline(cin,line))
    {
        insertions[line.substr(0,2)] = line[6];
    }
    
    for(int i=0; i<40; i++)
    {
        unordered_map<string,long long> newPairCount;
        for(auto it = pairCount.begin(); it!= pairCount.end(); it++)
        {
            string pair = it->first;
            long long count = it->second;
            if(insertions.find(pair) != insertions.end())
            {
                char ch = insertions[pair];
                
                string s1 = pair[0] + string(1,ch);
                string s2 = string(1,ch) + pair[1];
                
                newPairCount[s1] += count;
                newPairCount[s2] += count;
                    
                freq[ch] += count;
            }
        }
        pairCount = newPairCount;
    }
    
    long long minCount = LLONG_MAX, maxCount = LLONG_MIN;
    for(auto it = freq.begin(); it != freq.end(); it++)
    {
        minCount = min(minCount,it->second);
        maxCount = max(maxCount,it->second);
    }
    cout<<minCount<<" "<<maxCount<<endl;
    cout<<maxCount-minCount<<endl;
}
