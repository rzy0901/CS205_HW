# include<iostream>

using namespace std;

template<typename T>
void reverse(T *array, int length) {
    // swap
    if(length > 1){
        swap(array[0],array[length-1]);
        reverse(array+1,length-2);
    }
}

int main(){
    int a[5];
    cout<<"Enter 5 integers:"<<endl;
    for (size_t i = 0; i < 5; i++)
    {
        cin>>a[i];
    }
    reverse(a,5);
    cout<<"The elements of the array in reverse order are:"<<endl;
    for (size_t i = 0; i < 5; i++)
    {
        cout<<a[i]<<" ";
    }
    printf("\n");
        
}


// 1 2 3 4 5