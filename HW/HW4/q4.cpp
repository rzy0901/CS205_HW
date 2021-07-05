#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;

void spilit(string& s, char delim, vector<string> &elems);

int main() 
{
    string filename = "lab_records.csv";
    // cout<<"Please input the filename: "<<endl;
    // getline(cin,filename);
    ifstream myfile(filename);
    if (!myfile.is_open())
    {
        cout << "Can not open " << filename << endl;
        exit(0);
    }
    string temp;
    int stu_count = 0;
    int* lab_sum = new int[14];
    double* lab_average = new double[14]; 
    int course_sum;
    double course_average;
    while (getline(myfile,temp))
    {
        stu_count++;
        vector<string> elems;
        spilit(temp,',',elems);
        for (int i=0;i<14;i++)
        {
            lab_sum[i] += stoi(elems[i+1]);
            course_sum += stoi(elems[i+1]);
        }
    }
    course_average = (double) course_sum/(14*stu_count);
    cout << "Course average score: "<<course_average<<endl;
    cout << "The lab ID of the average score of the lab is less than the average score of the course: "<<endl;
    for (int i = 0; i < 14; i++)
    {
        lab_average[i] = (double) lab_sum[i]/stu_count;
        if (lab_average[i] < course_average)
        {
            cout << "Lab "<<(i+1)<<" with average lab score: "<<lab_average[i]<<endl;
        }    
    }
}

void spilit(string& s, char delim, vector<string> &elems)
{
    stringstream ss(s);
    string temp;
    while (getline(ss,temp,delim))
    {
        elems.push_back(temp);
    }
}