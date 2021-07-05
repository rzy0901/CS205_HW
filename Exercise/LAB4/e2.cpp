#include <iostream>
using namespace std;

struct CandyBar
{
    char name[20];
    double weight;
    int calories;
};

int main()
{   
    CandyBar *arr;
    arr = new (nothrow) CandyBar[3];
    cout<<"Please input three CandyBar's information:"<<endl;
    for(int i=0;i<3;++i) {
        cout << "Enter brand name of candy bar: ";
        cin.get(arr[i].name, 20);
        cout << "Enter the weight: ";
        cin >> arr[i].weight;
        cout << "Enter the calories: ";
        cin >> arr[i].calories;
        cin.ignore();
    }
    cout<<endl;
    cout<<"Displaying the CandyBar array contents"<<endl;
    for(int i=0;i<=2;++i) {
        cout << "Brand: " << arr[i].name << endl;
        cout << "Weight: " << arr[i].weight << endl;
        cout << "Calories: " << arr[i].calories << endl;
    }
    delete [] arr;
    // cout<<endl;
    // CandyBar great=arr[0];
    // for(int i=1;i<=2;++i) {
    //     if (arr[i].calories/arr[i].weight>great.calories/great.weight)
    //     {
    //         great =arr[i];
    //     }
    // }
    // cout<<"The greatest calories per weight is: "<<endl;
    // cout<<"Brand name: "<<great.name<<endl;
    // printf("Calories per weight: %.4f",great.calories/great.weight);
    return 0;
}