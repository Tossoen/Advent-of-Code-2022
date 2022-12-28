#include<iostream>
#include<vector>
#include<fstream>
#include<algorithm>
#include<string>

using namespace std;

int main()
{
    ifstream ifs("day_1_input.txt");
    string a{};
    int i{};
    vector<int> elves{};

    elves.push_back(0);
    while (getline(ifs,a))
        if (a != "")
            elves.back() += stoi(a);
        else 
            elves.push_back(0);
            
    elves.pop_back();
    
    sort(elves.begin(),elves.end());
    
    cout << elves[elves.size()-1] + elves[elves.size()-2] + elves[elves.size() -3 ];
    return 0;
}