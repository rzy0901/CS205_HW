#include <iostream>
#include <cstring>
#include <fstream>
#include "utf8.c"

#define ARRAY_SIZE 300
#define FILENAME "Blocks.txt"

using namespace std;

struct Block
{
    unsigned int start;
    unsigned int end;
    string block_name;
    int count = 0;
};

Block *readArray(string filename)
{
    Block *blockArray;
    blockArray = new Block[ARRAY_SIZE];
    ifstream myfile(filename);
    if (!myfile.is_open())
    {
        cout << "Error, can not open the file: " << filename << endl;
    }
    string temp = "";
    int i = 0;
    while (getline(myfile, temp))
    {
        if (temp[0] == '#' || temp == "")
        {
            continue;
        }
        int dot = temp.find_first_of('.');
        int semicolon = temp.find_first_of(';');
        blockArray[i].start = stoi(temp.substr(0, dot), nullptr, 16);
        blockArray[i].end = stoi(temp.substr(dot + 2, semicolon - dot - 2), nullptr, 16);
        blockArray[i].block_name = temp.substr(semicolon + 2);
        // cout << "Block[" << i << "]: start: " << blockArray[i].start << ", end: " << blockArray[i].end << ", name: " << blockArray[i].block_name << ", count: " << blockArray[i].count << endl;
        i++;
    }
    return blockArray;
}
//cd q3/build/
//cmake ..
//make
//./q3 < ../TEST\ DATA\ FOR\ LAB\ 4/sample.txt
int main()
{
    Block *blockArray = new Block[ARRAY_SIZE];
    blockArray = readArray(FILENAME);
    while (!cin.eof())
    {
        unsigned char *temp;
        string line;
        int bytes_in_char;
        getline(cin, line);
        temp = (unsigned char *)&(line[0]);
        while (*temp)
        {
            unsigned int code = utf8_to_codepoint(temp, &bytes_in_char);
            // cout << bytes_in_char << endl;
            if (code)
            {
                temp = temp + bytes_in_char;
            }
            else
            {
                temp++;
            }
            for (int i = 0; i < ARRAY_SIZE; i++)
            {
                if (code <= blockArray[i].end && code >= blockArray[i].start && blockArray[i].block_name != "")
                {
                    blockArray[i].count++;
                }
            }
        }
    }
    Block max = blockArray[0];
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        // cout << "Block[" << i << "]: name: " << blockArray[i].block_name << ", count: " << blockArray[i].count << endl;
        if (blockArray[i].count > max.count)
        {
            max = blockArray[i];
        }
    }
    cout << "Max's name: " << max.block_name << ", max's count:" << max.count << endl;
    return 0;
}
