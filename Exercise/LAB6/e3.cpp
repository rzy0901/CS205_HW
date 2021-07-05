#include <iostream>
#include <sstream>

using namespace std;

template<typename T>
T stringToNum(string str) {
    istringstream iss(str);
    T num;
    iss >> num;
    return num;
}

int Fill_array(double arr [], int size) {
    int input_size;
    int actual_size = 0;
    string temp = "";
    cout << "Enter the size of the array: ";
    cin >> input_size;
    if (input_size > size)
    {
        cout << "Out of bound, max size available" << size <<endl;
        input_size = size;
    }
    cin.ignore();
    for (int i = 0; i < input_size; i++)
    {
        cout << "Enter value #"<<i+1<<" :";
        getline(cin,temp);
        for(char  &i : temp){
            if(!isdigit(i)&&(i != '.')){
                return actual_size;
            }
        }
        arr[i] = stringToNum<double>(temp);
        temp = "";
        actual_size += 1;
    }
    return actual_size;
}

void Show_array(double *arr, int size) {
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i];
        if(i!=size-1){
            cout << " ";
        }
    }
    cout<<endl;
}

void Reverse_array(double *arr, int size) {
    if(size>1){
        swap(arr[0],arr[size-1]);
        Reverse_array(arr+1,size-2);
    }
}

int main() {
    double arr[20];
    int len  =  Fill_array(arr,20);
    cout << len <<endl;
    cout << "The output is as follows:"<<endl;
    Show_array(arr,len);
    Reverse_array(arr,len);
    Show_array(arr,len);
    Reverse_array(arr+1,len-2);
    Show_array(arr,len);
    return 0;
}