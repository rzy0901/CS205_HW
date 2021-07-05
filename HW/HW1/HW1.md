# CS205 C/ C++ Programming - Lab Assignment 1

**Name: **任振裕(Ren Zhenyu)

**SID: **11812214

## Part 1 - Analysis

+ Use the given criterion to calculate the distance.
+ Define some functions to format the input and handle the exceptions.
+ Use `struct` to define a city.

## Part 2 - Code

```c++
#include <iostream>
#include <string>
#include <sstream>
#include <math.h>

using namespace std;

template <typename T>
T stringToNum(string str)
{
    istringstream iss(str);
    T num;
    iss >> num;
    return num;
}
double degree2radian(double degree)
{
    return (double)degree * M_PI / 180;
}
string readCityName()
{
    string name;
    getline(cin, name);
    for (char &i : name)
    {
        if (!isalpha(i) && (i != ' ') && (i != ','))
        {
            cout << "Invalid city name, the input must be included in the alphabet!" << endl;
            exit(0);
        }
    }
    return name;
}

double readLatitude()
{
    string str;
    int count  = 0;
    double latitude;
    cin >> str;
    for (char &i : str)
    {
        if(i == '.'){
            count++;
        }
        if (count >=2)
        {
            cout << "Invalid value of latitude, please input a number." <<endl; 
            exit(0);
        }
        if (!isdigit(i) && (i != '.'))
        {
            cout << "Invalid value of latitude, please input a number." << endl;
            exit(0);
        }
    }
    latitude = stringToNum<double>(str);
    if (latitude < -90 || latitude > 90)
    {
        cout << "Invalid value of latitude, please input the latitude within the range of [-90,90]!" << endl;
        exit(0);
    }
    return latitude;
}

double readLongitude()
{
    string str;
    int count  = 0;
    double longitude;
    cin >> str;
    for (char &i : str)
    {   
        if(i == '.'){
            count++;
        }
        if (count >=2)
        {
            cout << "Invalid value of longitude, please input a number." <<endl; 
            exit(0);
        }
        if (!isdigit(i) && (i != '.'))
        {
            cout << "Invalid value of longitude, please input a number." << endl;
            exit(0);
        }
    }
    longitude = stringToNum<double>(str);
    if (longitude < -180 || longitude > 180)
    {
        cout << "Invalid value of longitude, please input the longitude within the range of [-180,180]!" << endl;
        exit(0);
    }
    return longitude;
}
struct City
{
    string name;
    double latitude;
    double longitude;
    double phi;
    double theta;
};

int main()
{
    City city1, city2;
    double c, d;
    double R = 6371;
    cout << "The first city: ";
    city1.name = readCityName();
    cout << "The latitude and longitude of the first city: ";
    city1.latitude = readLatitude();
    city1.longitude = readLongitude();
    cout << "The second city: ";
    cin.ignore();
    city2.name = readCityName();
    cout << "The latitude and longitude of the second city: ";
    city2.latitude = readLatitude();
    city2.longitude = readLongitude();

    city1.phi = degree2radian(90 - city1.latitude);
    city1.theta = degree2radian(city1.theta);
    city2.phi = degree2radian(90 - city2.latitude);
    city2.theta = degree2radian(city2.theta);
    c = sin(city1.phi) * sin(city2.phi) * cos(city1.theta - city2.theta) + cos(city1.phi) * cos(city2.phi);
    d = R * acos(c);
    cout << "The distance between " << city1.name << " and " << city2.name << " is " << d << " km" << endl;
    return 0;
}
```

## Part 3 - Result & Verification

### Test case #1 (correct input):

input:

```
The first city: Shenzhen, China
The latitude and longitude of the first city: 22.55 114.1
The second city: Beijing
The latitude and longitude of the second city: 39.9139 116.3917
```

output:

```
The distance between Shenzhen, China and Beijing is 1930.78 km
```

### Test case #2 (incorrect city name):

input:

```
The first city: @123#Shenzhen
```

output:

```
Invalid city name, the input must be included in the alphabet!
```

### Test case #3 (incorrect latitude or longitude):

input:

```
The first city: Beijing
The latitude and longitude of the first city: ABCDE.12345@ 12.3
```

output:

```
Invalid value of latitude, please input a number.
```

### Test case # 4 (Two many dots for a double number):

input: (wrong latitude 12.12.12)

```
The first city: Beijing
The latitude and longitude of the first city: 12.12.12 70 
```

output:

```
Invalid value of latitude, please input a number.
```

### Test case #5 (Latitude or longitude out of range):

input:

```
The first city: Beijing
The latitude and longitude of the first city: 100 70
```

output:

```
Invalid value of latitude, please input the latitude within the range of [-90,90]!
```

## Part 4 - Difficulties & Solutions

+ To handle the illegal input conveniently, choose string as the input.
+ Use `getline(cin,str);` and `cin.ignore(); ` to avoid the bugs brought by `cin`.