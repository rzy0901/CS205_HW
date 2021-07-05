# CS205 C/ C++ Programming - Lab Assignment 2

**Name: **任振裕(Ren Zhenyu)

**SID: **11812214

## Part 1 - Analysis

+ Use the given criterion to calculate the distance.
+ Define some functions to format the input and handle the exceptions.
+ Use `struct` to define a city.

## Part 2 - Code

```c++
#include <iostream>
#include <cstring>
#include <fstream>
#include <math.h>
#include <vector>

#define MAX_NAME_LEN 35
#define ARRAY_SIZE 1000
#define CSV_FILE "world_cities.csv"
using namespace std;



struct City{
    string name;
    string province;
    string country;
    double latitude;
    double longitude;
};

vector<City> menu;

City* readCSV(const string filename) {
    City *arr;
    arr = new City[ARRAY_SIZE];
    ifstream myfile(filename);
    if(!myfile.is_open()){
        cout<<"Warning, can not open the file: "<<filename<<endl;
        exit(0);
    }
    string line;
    int count = 0;
    while(getline(myfile,line)){
        if(ARRAY_SIZE == 0){
            cout<<"Warning: The data was not loaded."<<endl;
            break;    
        }
        if(count >=  ARRAY_SIZE){
            cout<<"Warning: the max array size is not enough, data has been truncated with array size: "<<ARRAY_SIZE<<endl;
            break;    
        }
        string spilit[5];
        string temp = line;
        int pos = 0;
        int i = 0;
        while((pos=temp.find(",")) != string::npos){
            spilit[i++]=temp.substr(0,pos); //substr(start,len)
            temp.erase(0,pos+1);
        }
        
        spilit[i] = temp; //spilit[4] = temp;
        if(spilit[0].size()<=MAX_NAME_LEN){
            arr[count].name=spilit[0];
        }else{
            arr[count].name=spilit[0].substr(0,MAX_NAME_LEN);
            // cout<<"Warning: the max name len is not enough, the name of the city has been truncated. "<<endl;
            cout<<"Warning: Line "<<count<<": The original city name \""<<spilit[0]<<"\" has been truncated into: \""<<arr[count].name<<"\""<<endl;
        }
        if(spilit[2].size()<=MAX_NAME_LEN){
            arr[count].country=spilit[2];
        }else{
            arr[count].country=spilit[2].substr(0,MAX_NAME_LEN);
            // cout<<"Warning: the max name len is not enough, the country name of the city has been truncated. "<<endl;
            cout<<"Warning: Line "<<count<<": The original country name \""<<spilit[2]<<"\" has been truncated into: \""<<arr[count].country<<"\""<<endl;
        }
        arr[count].province = spilit[1];
        arr[count].latitude = stod(spilit[3]); //string to double
        arr[count].longitude = stod(spilit[4]);
        count++;
    }
    return arr;
}

bool match(string str, string pattern){
    int len1 = str.length();
    int len2 = pattern.length();
    if(len2 > len1){
        return 0;
    }
    for (int i = 0; i < len1-len2+1; i++)
    {
        bool flag = true;
        for (int j = 0; j < len2; j++)
        {
            if(toupper(str[i+j])!=toupper(pattern[j])){
                flag = false;
                break;
            }
        }
        if(flag){
            return true;
        }
    }
    return false;
} 

void trim(string &s)// remove whitespaces on both ends 
{
    if (s.empty()) 
    {
        return ;
    }
    s.erase(0,s.find_first_not_of(" "));
    s.erase(s.find_last_not_of(" ") + 1);
}



City readCity(City* cityList,int a){
    string temp ="";
    while (true)
    {
        if(a==1){
            cout<<"Enter the name of the first city: "<<endl;
        }
        if(a==2){
            cout<<"Enter the name of the second city: "<<endl;    
        }
        getline(cin,temp);
        trim(temp);
        if(temp.length()<3){
            cout<<"Invalid input, at least 3 letters needed."<<endl;
            continue;
        }
        if(match("bye",temp)){
            exit(0);
        }
        for (int i = 0; i < ARRAY_SIZE; i++)
        {
            if(match(cityList[i].name,temp)){
                menu.push_back(cityList[i]);
            }
        }
        if(menu.size()==0){
            cout<<"No such city exists, please input the city again."<<endl;
            continue;
        }
        if(menu.size()==1){
            menu.clear();
            return *(menu.begin());
        }
        if(menu.size()>1){
            cout<<"Please select one city from the below: "<<endl;
            for (int i = 0; i < menu.size(); i++)
            {
                cout<<menu[i].name<<endl;
            }
        }
        menu.clear();
    }
}

double degree2radian(double degree)
{
    return (double)degree * M_PI / 180;
}

double calcDistance(const City &city1, const City &city2) {
    double phi1 = degree2radian(90 - city1.latitude);
    double theta1 = degree2radian(city1.longitude);
    double phi2 = degree2radian(90 - city2.latitude);
    double theta2 = degree2radian(city2.longitude);
    double c = sin(phi1) * sin(phi2) * cos(theta1 - theta2) + cos(phi1) * cos(phi2);
    double result = 6371 * acos(c);
    return result;
}

int main() {
    City* cityList;
    cityList = readCSV(CSV_FILE);
    City city1,city2;
    while (true)
    {
        city1 = readCity(cityList,1);
        city2 = readCity(cityList,2);
        cout<<"The distance between the two city is "<<calcDistance(city1,city2)<<"km."<<endl;
    }
    return 0;
}
```

## Part 3 - Result & Verification

### Test case for part 1:

1. Initially set the maximum length for names (city and country name) to 25, and the array size to 800.

   + Input and output:

   ```
   Warning: Line 417: The original country name "Saint Vincent and the Grenadines" has been truncated into: "Saint Vincent and the Gre"
   Warning: Line 418: The original country name "Democratic Republic of the Congo" has been truncated into: "Democratic Republic of th"
   Warning: Line 454: The original city name "Las Palmas de Gran Canaria" has been truncated into: "Las Palmas de Gran Canari"
   Warning: Line 485: The original country name "Democratic Republic of the Congo" has been truncated into: "Democratic Republic of th"
   Warning: Line 641: The original country name "Federated States of Micronesia" has been truncated into: "Federated States of Micro"
   Warning: the max array size is not enough, data has been truncated with array size: 800
   Enter the name of the first city:  
   ```
   
   + In this case, there issues a warning when data is truncated.
   
2. Set the maximum length for names to 35, and the array size to 1000.

   + Input and output:

   ```
   Enter the name of the first city: 
   ```

   + Load data successfully, no warnings.

3. Rename the file to world_cities.tmp.

   + Input and output:

     ```
     Warning, can not open the file: world_cities.txt
     ```

### Test case for part 2:

1. With whitespace:

   + Input and output:

     ```
     Enter the name of the first city: 
      bye 
     ```

2. No such city, minimum acceptable length, bye, case-insensitive:

   + Input and output:

     ```
     Enter the name of the first city: 
     vberibverbuvibirebvorebvoubreouvb
     No such city exists, please input the city again.
     Enter the name of the first city: 
     12
     Invalid input, at least 3 letters needed.
     Enter the name of the first city: 
     BEIJing
     Enter the name of the second city: 
     beijing
     The distance between the two city is 0km.
     Enter the name of the first city: 
     BYE
     ```

3. Show the matched list:

   + Input and output:

     ```
     Enter the name of the first city: 
     NEW
     Please select one city from the below: 
     New Delhi
     New Orleans
     New York City
     Newcastle upon Tyne
     Newcastle
     Enter the name of the first city: 
     New York City
     Enter the name of the second city: 
     BEI 
     Please select one city from the below: 
     Beijing
     Beirut
     Ribeirão Preto
     Taibei
     Enter the name of the second city: 
     Taibei
     The distance between the two city is 12534.4km.
     Enter the name of the first city: 
     BYE
     ```

## Part 4 - Difficulties & Solutions

+ I met several bugs like `segmentation default`. These bugs were always drawn by incorrect coding syntax.
+ Write the method of `spilit a string` is quite chanllenged in CPP.