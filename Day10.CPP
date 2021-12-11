#include <string>
#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

int getErrorScore(char ch)
{
    if(ch == ')')
        return 3;
    
    if(ch == ']')
        return 57;

    if(ch == '}')
        return 1197;

    if(ch == '>')
        return 25137;
    
    return 0;
}

char getCorrectionChar(char ch)
{
    if(ch == '[')
        return ']';
    
    if(ch == '(')
        return ')';
    
    if(ch == '{')
        return '}';
    
    if(ch == '<')
        return '>';
    
    return '_';
}

int getPoints(char c)
{
    if(c == ')')
        return 1;
    
    if(c == ']')
        return 2;
    
    if(c == '}')
        return 3;
    
    if(c == '>')
        return 4;
    
    return 0;
}

long long getCorrectionScore(stack<char> &st)
{
    string correctionSeq;
    
    while(!st.empty())
    {
        correctionSeq += getCorrectionChar(st.top());
        st.pop();
    }
    
    long long score = 0;
    
    for(char c: correctionSeq)
    {
        score *= 5;
        score += getPoints(c);
    }
    
    return score;
}

int main()
{
    string line;
    int errorScore = 0;
    vector<long long> scores;
    while(getline(cin,line))
    {
        bool isCorrupt = false;
        stack<char> st;
        for(char x: line)
        {
            if(x == '(' || x == '{' || x == '[' || x == '<')
            {
                st.push(x);
            }
            else if((x == ')' && st.top() == '(')
                    || (x == '}' && st.top() == '{')
                    || (x == ']' && st.top() == '[')
                    || (x == '>' && st.top() == '<'))
            {
                st.pop();
                continue;
            }
            else
            {
                isCorrupt = true;
                break;
            }
        }
        
        if(!isCorrupt)
        {
            scores.push_back(getCorrectionScore(st));
        }
    }
    
    sort(scores.begin(), scores.end());
    cout<<scores[(scores.size()-1)/2]<<endl; 
    return 0;
}
