/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

string getDigit(vector<int> &setBits)
{
    if(setBits[0] == 1 && setBits[1] == 1 && setBits[2] == 1 && setBits[3] == 0 && setBits[4] == 1
       && setBits[5] == 1 && setBits[6] == 1)
       {
           return "0";
       }
    if(setBits[0] == 0 && setBits[1] == 0 && setBits[2] == 1 && setBits[3] == 0 && setBits[4] == 0
       && setBits[5] == 1 && setBits[6] == 0)
       {
           return "1";
       }
    if(setBits[0] == 1 && setBits[1] == 0 && setBits[2] == 1 && setBits[3] == 1 && setBits[4] == 1
       && setBits[5] == 0 && setBits[6] == 1)
       {
           return "2";
       }
    if(setBits[0] == 1 && setBits[1] == 0 && setBits[2] == 1 && setBits[3] == 1 && setBits[4] == 0
       && setBits[5] == 1 && setBits[6] == 1)
       {
           return "3";
       }
    if(setBits[0] == 0 && setBits[1] == 1 && setBits[2] == 1 && setBits[3] == 1 && setBits[4] == 0
       && setBits[5] == 1 && setBits[6] == 0)
       {
           return "4";
       }
    if(setBits[0] == 1 && setBits[1] == 1 && setBits[2] == 0 && setBits[3] == 1 && setBits[4] == 0
       && setBits[5] == 1 && setBits[6] == 1)
       {
           return "5";
       }
    if(setBits[0] == 1 && setBits[1] == 1 && setBits[2] == 0 && setBits[3] == 1 && setBits[4] == 1
       && setBits[5] == 1 && setBits[6] == 1)
       {
           return "6";
       }
    if(setBits[0] == 1 && setBits[1] == 0 && setBits[2] == 1 && setBits[3] == 0 && setBits[4] == 0
       && setBits[5] == 1 && setBits[6] == 0)
       {
           return "7";
       }
    if(setBits[0] == 1 && setBits[1] == 1 && setBits[2] == 1 && setBits[3] == 1 && setBits[4] == 1
       && setBits[5] == 1 && setBits[6] == 1)
       {
           return "8";
       }
    if(setBits[0] == 1 && setBits[1] == 1 && setBits[2] == 1 && setBits[3] == 1 && setBits[4] == 0
       && setBits[5] == 1 && setBits[6] == 1)
       {
           return "9";
       }
}

int MapToOutput(string num, unordered_map<char,int> &mapping)
{
    string token;
    stringstream ss(num);
    string ret;
    while(getline(ss,token,' '))
    {
        vector<int> setBits(7,0);
        for(char c: token)
        {
            setBits[mapping[c]] = 1;
        }
        ret += getDigit(setBits);
    }
    
    return stoi(ret);
}

int main()
{
    string line,token;
    int ans = 0;
    while(getline(cin,line))
    {
        stringstream ss1(line);
        string inputPatternsStr, outputStr; 
        while(getline(ss1,token,'|'))
        {
            if(inputPatternsStr.empty())
                inputPatternsStr = token;
            else
                outputStr = token;
        }
        
        stringstream ss2(inputPatternsStr);
        std::vector<string> outPut;
        string one, seven, six, nine, four, three, two;
        vector<string> sixLength, fiveLength;
        while(getline(ss2,token,' '))
        {
            switch(token.length())
            {
                case 2:
                    one = token;
                    break;
                
                case 3:
                    seven = token;
                    break;
                
                case 5:
                    fiveLength.push_back(token);
                    break;
                    
                case 6:
                    sixLength.push_back(token);
                    break;
                
                case 4:
                    four = token;
                    break;
            }
            
        }
        
        unordered_map<char,int> sevenSegMapping;
        
        // Step 1
        for(char c: seven)
        {
            if(one.find(c) == string::npos)
            {
                sevenSegMapping[c] = 0;
                break;
            }
        }
        
        // Step 2
        for(string num: fiveLength)
        {
            bool foundAll = true;
            for(char c: one)
            {
                if(num.find(c) == string::npos)
                {
                    foundAll = false;
                    break;
                }
            }
            
            if(foundAll)
            {
                three = num;
            }
        }
        
        // Step 3
        for(char c: four)
        {
            if(one.find(c) == string::npos)
            {
                if(three.find(c) != string::npos)
                {
                    sevenSegMapping[c] = 3;
                }
                else
                {
                    sevenSegMapping[c] = 1;
                }
            }
        }
        
        // Step 4
        for(char c: three)
        {
            if(four.find(c) == string::npos && seven.find(c) == string::npos)
            {
                sevenSegMapping[c] = 6;
            }
        }
        
        for(string num: fiveLength)
        {
            if(num == three)
                continue;
            
            bool found = false;
            for(char c: num)
            {
                if(sevenSegMapping[c] == 1)
                {
                    found = true;
                    break;
                }
            }
            
            if(found == false)
            {
                two = num;
            }
        }
        
        for(char c: one)
        {
            if(two.find(c) != string::npos)
            {
                sevenSegMapping[c] = 2;
            }
            else
            {
                sevenSegMapping[c] = 5;
            }
        }
        
        for(char c: two)
        {
            if(three.find(c) == string::npos)
            {
                sevenSegMapping[c] = 4;
                break;
            }
        }
        outputStr = outputStr.substr(1);
        ans += MapToOutput(outputStr,sevenSegMapping);
    }
    
    cout<<ans<<endl;

    return 0;
}
