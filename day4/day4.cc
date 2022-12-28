#include<iostream>
#include<vector>
#include<fstream>
#include<algorithm>
#include<string>
#include<sstream>
#include<set>


using namespace std;

void ex_1(ifstream & ifs)
{
    vector<pair<int,int>> input;

    string line;
    
    while(getline(ifs,line))
    {
        pair<int,int> curr; //ERROR FÖR DET VAR CHAR

        stringstream ss(line);

        char throww{};

        ss >> curr.first >> throww >> curr.second;
        input.push_back(curr);
        ss >> throww >> curr.first >> throww >> curr.second;
        input.push_back(curr);



    }

    int total{};

    for(int i{}; i < input.size()-1; i=i+2)
    {
        if (((input[i].first <= input[i+1].first) && (input[i].second >= input[i+1].second))
        || ((input[i].first >= input[i+1].first) && (input[i].second <= input[i+1].second)))
        {   
            total++;
        }
        
    }
    cout << total;
}

void ex_2(ifstream & ifs)
{
    vector<pair<int,int>> input;

    string line;
    
    while(getline(ifs,line))
    {
        pair<int,int> curr; //ERROR FÖR DET VAR CHAR

        stringstream ss(line);

        char throww{};

        ss >> curr.first >> throww >> curr.second;
        input.push_back(curr);
        ss >> throww >> curr.first >> throww >> curr.second;
        input.push_back(curr);



    }

    int total{};

    for(int i{}; i < input.size()-1; i=i+2)
    {
        if ((input[i].second >= input[i+1].first) && (input[i+1].second >= input[i].first))
        {   
            total++;
        }
        
    }
    cout << total;
}

int main()
{
    ifstream ifs("day4_input.txt");
    string i{};

    getline(ifs,i); // 1 in input doc to run excersise 1, 2 to run excercise 2

    if (i == "1")
        ex_1(ifs);
    else if(i == "2")
        ex_2(ifs);

    
    return 0;
}