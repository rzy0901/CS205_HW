#include <iostream>
#include <cstring>
using namespace std;

string trim(string &s)
{
    if (s.empty())
    {
        return "";
    }
    s.erase(0,s.find_first_not_of(" "));
    s.erase(s.find_last_not_of(" ")+1);
    return s;
}


int index(string commands[],int length, string command)
{
    for (int i = 0; i < length; i++)
    {
        if (commands[i] == command)
        {
            
            return i;
        }
    }
    return -1;
}

int main()
{
    string commands[] = {"start","stop","restart","reload","status","exit"};
    string command;
    while (true)
    {
        cout<<">";
        getline(cin,command);
        command = trim(command);
        // for (int i = 0; i < command.length(); i++)
        // {
        //     command[i] = tolower(command[i]);
        // }
        switch (index(commands,6,command))
        {
        case 5:
            cout << "System exits."<<endl;
            exit(0);
            break;
        case -1:
            cout << "Invalid command."<<endl;
            break;
        default:
            cout << "Command " << command << " recognized."<<endl;
            break;
        }
    }
    
}