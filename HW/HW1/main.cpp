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