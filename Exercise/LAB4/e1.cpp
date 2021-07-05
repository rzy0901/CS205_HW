#include <iostream>
#include <cstring>
using namespace std;

struct Pizza
{
    string name;
    int diameter;
    double weight;
};

int main()
{
    Pizza *p = new Pizza;
    cout << "Enter the name of the pizza company: ";
    getline(cin, p->name);
    cout << "Enter the diameter of pizza (inches): ";
    cin >> p->diameter;
    cout << "Enter the weight of the pizza (g): ";
    cin >> p->weight;
    cout << "Displaying the information of the pizza" << endl;
    cout << "Company name: " << p->name << endl;
    cout << "Pizza diameter: " << p->diameter << " inches" << endl;
    cout << "Pizza weight: " << p->weight << " " << endl;
    delete p;
}