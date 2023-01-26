/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

int findTurnsToWin(unordered_map<int,pair<int,int>> &board, vector<int> &numbers, int &ans)
{
    vector<vector<int>> count(2, vector<int>(5,0));
    int turnsToWin = 0;
    for(int num: numbers)
    {
        turnsToWin++;
        if(board.find(num) != board.end())
        {
            ans -= num;   
            count[0][board[num].first]++;
            count[1][board[num].second]++;
            
            if(count[0][board[num].first] == 5 || count[1][board[num].second] == 5)
            {
                ans *= num;
                return turnsToWin;
            }
        }
    }
    
    return INT_MAX;
}

int main()
{
    string line,token;
    getline(cin,line);
    
    vector<int> numbers;
    stringstream ss(line);
    while(getline(ss,token,','))
    {
        numbers.push_back(stoi(token));
    }
    
    int maxTurnsToWin = INT_MIN, finalAns;
    while(getline(cin,line))
    {
        unordered_map<int,pair<int,int>> board;   
        int row = 0, totalSum = 0;
        while(row<5)
        {
            int col = 0;
            getline(cin,line);
            
            string curNum;
            for(int i=0; i<line.length(); i++)
            {
                if(line[i] == ' ' && !curNum.empty())
                {
                    //cout<<curNum<<" ";
                    board[stoi(curNum)] = pair<int,int>(row,col);
                    totalSum += stoi(curNum);
                    col++;
                    curNum = "";
                }
                else if(line[i] != ' ')
                {
                    curNum += line[i];
                }
            }
            //cout<<curNum;
            board[stoi(curNum)] = pair<int,int>(row,4);
            totalSum += stoi(curNum);
            row++;
            //cout<<endl;
        }
        //cout<<endl;
        int turnsToWin = findTurnsToWin(board,numbers, totalSum);
        if(turnsToWin>maxTurnsToWin)
        {
            maxTurnsToWin = turnsToWin;
            finalAns = totalSum;
        }
        // cout<<turnsToWin<<" "<<totalSum<<endl<<endl;
    }
    cout<<finalAns<<endl;
    return 0;
}
