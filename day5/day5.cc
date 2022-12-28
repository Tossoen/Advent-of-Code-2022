#include<iostream>
#include<vector>
#include<fstream>
#include<algorithm>
#include<string>
#include<stack>
#include<queue>

using namespace std;

vector<stack<char>> fix_stack(vector<vector<char>> & q)
{
    vector<stack<char>> st(q.size());

    for(int i{}; i < q.size(); i++)
    {
        for(int x{q[i].size()}; x > 0; x--)
        {
            st[i].push(q[i][x-1]);
        }
        
    }
    return st; 
}

void ex_1(ifstream & ifs)
{

    string s;

    int size{};
    getline(ifs,s);
    size = ((s.length() - 1) + 2) / 4 ; //Potentially wrong?

    ifs.close();
    ifs.open("day5_input.txt");
    getline(ifs,s);

    vector<vector<char>> reversed_stacks(size);
    
    while(getline(ifs,s))
    {
        if (s == "")
            break;

        for(int i{}; i < s.length()-1; i++)
            if (isupper(s[i]))
                reversed_stacks[(i-1)/4].push_back(s[i]);
    }   

    vector<stack<char>> stacks(size); 

    stacks = fix_stack(reversed_stacks);

    int from;
    int to;
    int amount;
    string discard;

    while(ifs >> discard >> amount >> discard >> from >> discard >> to)
    {
        for(int i{}; i < amount; i++)
        {
            stacks[to-1].push(stacks[from-1].top());
            stacks[from-1].pop();
        }
    }
 
    string result;

    for(auto v: stacks)
    {
        cout << "::::";
        result += v.top();
        while(!v.empty())
        {
            char a = v.top();
            v.pop();
        }
        cout << endl;
    } 
    
    cout << result;
    
}

void ex_2(ifstream & ifs)
{

    string s;

    int size{};
    getline(ifs,s);
    size = ((s.length() - 1) + 2) / 4 ; //Potentially wrong?

    ifs.close();
    ifs.open("day5_input.txt");
    getline(ifs,s);

    vector<vector<char>> reversed_stacks(size);
    
    while(getline(ifs,s))
    {
        if (s == "")
            break;

        for(int i{}; i < s.length()-1; i++)
            if (isupper(s[i]))
                reversed_stacks[(i-1)/4].push_back(s[i]);
    }   

    vector<stack<char>> stacks(size); 

    stacks = fix_stack(reversed_stacks);

    int from;
    int to;
    int amount;
    string discard;

    while(ifs >> discard >> amount >> discard >> from >> discard >> to)
    {
        vector<char> v;
        for(int i{}; i < amount; i++)
        {
            v.push_back(stacks[from-1].top());            

            /* stacks[to-1].push(stacks[from-1].top());  */
            stacks[from-1].pop();
        }

        for(int j{v.size()}; j > 0; j--)
        {
            stacks[to-1].push(v[j-1]);
        }
    }
 
    string result;

    for(auto v: stacks)
    {
        cout << "::::";
        result += v.top();
        while(!v.empty())
        {
            char a = v.top();
            cout << a;
            v.pop();
        }
        cout << endl;
    } 
    
    cout << result;
    
}

int main()
{
    ifstream ifs("day5_input.txt");
    string i{};

    getline(ifs,i); // 1 in top line of input document to run excercise 1, 2 to run excercise 2

    if (i == "1")
        ex_1(ifs);
    else if(i == "2")
        ex_2(ifs);

    
    return 0;
}