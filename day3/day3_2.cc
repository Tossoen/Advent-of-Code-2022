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

    string compartmentOne;
    string compartmentTwo;
    string compartmentThree;

    while(ifs >> compartmentOne >> compartmentTwo >> compartmentThree)
    {
        set<char> duplicates; //using set to avoid duplicates of the same letter appearing multiple times in all compartments 


        for(auto v: compartmentOne)
        if (compartmentTwo.find(v) < compartmentTwo.length())
        {
            if (compartmentThree.find(v) < compartmentThree.length())
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