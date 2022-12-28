#include<iostream>
#include<vector>
#include<fstream>
#include<algorithm>
#include<string>
#include<stack>
#include<iterator>

using namespace std;

void unique_elements(string::iterator & s, string::iterator & e, int const& size)
{
    string::iterator marker;

    string::iterator tmp = s;
 
    for(string::iterator it{tmp}; it != e; it++)
    {
        while(tmp != e)
        {
            if(*tmp == *it && tmp != it)
            {
                s = it+1;
                e = e + (size-distance(s,e));
                break;
            }

            tmp++;

        }
        tmp = s;
    }
}

void ex_1(ifstream & ifs)
{  
    string input;
    getline(ifs,input);

    string::iterator start_point = input.begin();
    string::iterator end_point = input.begin()+4;

    unique_elements(start_point,end_point,4);

    cout << distance(input.begin(),end_point);


}

void ex_2(ifstream & ifs)
{

    string input;
    getline(ifs,input);

    string::iterator start_point = input.begin();
    string::iterator end_point = input.begin()+14;

    unique_elements(start_point,end_point,14);

    cout << distance(input.begin(),end_point);
 
}

int main()
{
    ifstream ifs("day6_input.txt");
    string i{};

    getline(ifs,i); // 1 in top line of input document to run exercise 1, 2 to run exercise 2

    if (i == "1")
        ex_1(ifs);
    else if(i == "2")
        ex_2(ifs);

    
    return 0;
}