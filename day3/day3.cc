#include<iostream>
#include<vector>
#include<fstream>
#include<algorithm>
#include<string>
#include<set>

using namespace std;

int main()
{
    ifstream ifs("day3_input.txt");
    string line;
    vector<char> duplicates_total;

    while(getline(ifs,line))
    {
        string compartmentOne = line.substr(0,(line.length()/2));
        string compartmentTwo = line.substr((line.length()/2), line.length());

        set<char> duplicates; //using set to avoid duplicates of the same letter appearing multiple times in both compartments 

        for(auto v: compartmentOne)
            if (compartmentTwo.find(v) < compartmentTwo.length())
            {
                duplicates.insert(v); 
            }

        copy(duplicates.begin(),duplicates.end(), back_inserter(duplicates_total)); // Do push_back on all items in duplicate to duplicate_total
        
    }
    
    int priority_sum{};

    for(auto v: duplicates_total)
    {   
        if (isupper(v))
            priority_sum += int(v) -  64 + 26;
        else 
            priority_sum += int(v) - 96;
    }

    cout << priority_sum; 
    return 0;
}