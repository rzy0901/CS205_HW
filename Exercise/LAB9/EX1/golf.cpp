#include<iostream>
#include "golf.h"
#include<cstring>
using namespace std;

void setgolf(golf& g, const char* name, int hc){
    cout<<"First version of setgolf function:"<<endl;
    strcpy(g.fullname,name);
    g.handicap = hc;
}

int setgolf(golf& g){
    char* temp = new char[40];
    cout<<"Second version of setgolf function:"<<endl;
    cout<<"Enter the fullname:";
    cin.getline(temp,40);
    strcpy(g.fullname,temp);
    cout<<"Enter the handicap:";
    cin >> g.handicap;
    if (g.fullname[0]=='\0')
    {
        return 0;
    }else{
        return 1;
    }
}

void handicap(golf& g, int hc){
    g.handicap=hc;
}

void showgolf(const golf& g){
    cout<<"The name of golf is "<<g.fullname<<" and its handicap is "<<g.handicap<<"."<<endl;
}