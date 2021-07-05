#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    string str, match, str2 = "";
    int start;
    int count = -1;
    int index = 0;
    getline(cin, str);
    getline(cin, match);
    cin >> start;
    for (int i = 0; i < str.length(); i++)
    {
        str2 += str;
    }
    for (int i = start; i < str2.length(); i++)
    {
        if (index == match.length())
        {
            break;
        }
        count++;
        while (str2[i] == match[index])
        {
            index++;
            if (index == match.length())
            {
                cout << count << endl;
                exit(0);
            }
        }
    }
    cout << count << endl;
    return 0;
}