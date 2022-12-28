#include<iostream>
#include<vector>
#include<fstream>
#include<algorithm>
#include<string>
#include<stack>
#include<iterator>

using namespace std;

struct file
{
    file(int const& s, string const& n)
    :name(n), size(s)
    {}

    string name;
    int size;
};

class file_system
{
    struct directory;
    public:
    

    file_system()
    : root(new directory("root")), current()
    {
        current = root;
        cout << "CREATED FILE SYSTEM " << current->name << endl;
    }

    void traverse_forw(string const& dirName)
    {
        cout << current->name;
        current = current->find_dir(dirName);
        cout << " --> " << current->name << endl;
        
    }

    void traverse_back()
    {
        cout << current->name;
        current = current->prev;
        cout << " <-- "  << current->name << endl;
    }   
 
    void create_dir(string const& name)
    {
        current->next.push_back(new directory{name,current});
        cout << "dir " << name << endl;
    }

    void create_file(int const& size,string const& name)
    {
        current->files.push_back(file{size,name});
        cout << "file " << size << ' ' << name << endl;
    }

    void list_files()
    {
        cout << "LISTING FILES: " << endl;
        for(auto dir: current->next)
            cout << dir->name << endl;
        for(auto file: current->files)
            cout << file.name << endl;

    }

    void calculate_dir_size() //find out the size -> LESS THAN 100000
    {

        int totalSize{}; //to check if total size is less than 100000, could have checked all values in v but this is quicker
        vector<int> v;

        traverse_tree(root,totalSize,v);
        cout << totalSize << endl;

    }



    void traverse_tree(directory* d, int & s, vector<int> & v) //using postorder tree traversal
    {

        if(d == nullptr || s > 100000)
            return;
        
        int a{};

        for(auto it: d->next)
        {
            traverse_tree(it,s,v);
            a++;

            if (a == d->next.size() && d->name != "root")
                s = s * 2; 


        
            /* cout <<  */
        }

        s+=d->dir_size();
        
        if (s > 100000)
        {
            s-= d->dir_size();
        }   
        cout << d->name << ' ';
    }

    private:

    struct directory
    {
        directory(string const& s, directory* const& p = nullptr)
        : name(s),files(),next(),prev(p)
        {}

        directory* find_dir(string const& dirName)
        {
            for(auto it: next)
            {
                if(it->name == dirName)
                    return it;
            }
        }

        int dir_size()
        {
            int size{};
            for(auto j: files)
            {
                size += j.size;
            }
            return size;
        }
 

        string name;
        vector<file> files;
        vector<directory*> next; 
        directory* prev;
    };

    directory* root;
    directory* current;

};

void ex_1(ifstream & ifs)
{  
    string line;
    file_system f;

    while(getline(ifs,line))
    {
        if(line[0] == '$')
            if(line.substr(2,2) == "cd")
                if(line.substr(5,2) == "..")
                    f.traverse_back();
                else
                    f.traverse_forw(line.substr(5,(line.size()-3)));
            else
                f.list_files();
        else
        {
            if(line.substr(0,3) == "dir")
                f.create_dir(line.substr(4,(line.size()-3)));
            else
            {
                string size;
                string name;
                bool b{0};

                for(auto t: line)
                {
                    if (isspace(t))
                        b = 1;
                    else 
                        if(b)
                            name += t;
                        else
                            size += t;
                }

                f.create_file(stoi(size),name);

            }
        }



    } 

    f.calculate_dir_size();
}

void ex_2(ifstream & ifs)
{


}

int main()
{
    ifstream ifs("day7_input.txt");
    string i{};

    getline(ifs,i); // 1 in top line of input document to run exercise 1, 2 to run exercise 2

    if (i == "1")
        ex_1(ifs);
    else if(i == "2")
        ex_2(ifs);

    
    return 0;
}