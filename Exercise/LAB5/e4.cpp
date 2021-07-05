#include <iostream>
#include <cctype>
#include <cstring>
#include <fstream>

using namespace std;

int main() {
    char str1[30];
    string str2 = "", str3 = "";
    cout << "Please input a string: ";
    cin.getline(str1,30); // string str getline(cin,str);
    cout<<"\n\n";
    ofstream f1;
    ofstream f2;
    f1.open("f1.txt");
    if(f1.is_open()){
        for (size_t i = 0; i < strlen(str1); i++)
        {
            if(isalpha(str1[i]) || str1[i] == ' '||str1[i] == '\0'){
                str2 = str2 + str1[i];
            }else{
                str2 = str2 + " ";
            }
        }
        f1 << str2;
        cout<<"The content of f1.txt : "<<str2<<endl;
        f1.close();
    }
    f2.open("f2.txt");
    if(f2.is_open()){
        for (size_t i = 0; i < str2.length(); i++)
        {
            str3 += toupper(str2[i]);    
        }
        f2 << str3;
        cout<<"The content of f2.txt : " << str3 <<endl;
        f2.close();    
    }
    return 0;
}