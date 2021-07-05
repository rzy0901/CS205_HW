#include <iostream>
#include "candybar.h"
using namespace std;

void setCandyBar(CandyBar & cb){
    cout << "Enter brand name of a Candy bar: ";
    cin.getline(cb.brand, 30);
    cout << "Enter weight of the candy bar: ";
    cin >> cb.weight;
    cout << "Enter calories (an integer value) in the candy bar: ";
    cin >> cb.calorie;

}
void setCandyBar(CandyBar * cb){
    cout << "Enter brand name of a Candy bar: ";
    cin.getline(cb->brand, 30);
    cout << "Enter weight of the candy bar: ";
    cin >> cb->weight;
    cout << "Enter calories (an integer value) in the candy bar: ";
    cin >> cb->calorie;
}
void showCandyBar(const CandyBar & cb){
    cout << "Brand: " << cb.brand << endl;
    cout << "Weight: " << cb.weight << endl;
    cout << "Calories: " << cb.calorie << endl;
}
void showCandyBar(const CandyBar * cb){
    cout << "Brand: " << cb->brand << endl;
    cout << "Weight: " << cb->weight << endl;
    cout << "Calories: " << cb->calorie << endl;
}