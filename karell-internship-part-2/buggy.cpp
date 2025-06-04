#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

struct instruction
{
    string inst;
    int value;
    bool visited;
};

instruction getInst(string line)
{
    vector<string> newInst;
    stringstream ss(line);
    string token;
    while(getline(ss,token,' '))
    {
        newInst.push_back(token);
    }
    instruction i;
    i.inst = newInst[0];
    i.value = stoi(newInst[1]);
    i.visited = false;
    return i;
}

int main() 
{
    vector<instruction> insts;
    
    cout << "What file: ";
    string file;
    getline(cin,file);
    
    ifstream in;
    in.open(file);
    if(in.fail()) 
        cout << "File didn't open" << endl;
    
    string line;
    while(getline(in,line))
    {
        insts.push_back(getInst(line));
    }
    int acc = 0;
    int i = 0;
    while(true)
    {
        if(insts[i].visited == true)
        {
            break;
        }
        
        if(insts[i].inst == "acc")
        {
            acc += insts[i].value;
        }
        else if(insts[i].inst == "jmp")
        {
            insts[i].visited = true;
            i += insts[i].value;
            continue;
        }
        insts[i].visited = true;
        i++;
    }
    cout << acc << endl;
    return 0;
}