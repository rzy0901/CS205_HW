#include <iostream>

using namespace std;

struct Cell
{
    int loss;
    int quantity;
    int label;
};

int main()
{
    Cell arr[6];
    Cell arr2[6];
    int count = 0;
    int index = 0;
    //input
    for (int i = 0; i < 6; i++)
    {
        cin >> arr[i].loss;
        cin >> arr[i].quantity;
        cin >> arr[i].label;
    }
    for (int i = 0; i < 6; i++)
    {
        if (arr[i].loss <= 2 && arr[i].loss >= 0 && arr[i].quantity >= 20 && arr[i].quantity <= 100 )
        {
            arr2[index] = arr[i];
            index++;
            count++;
        }
    }
    //sorting
    for (int i = 0; i < count - 1; i++)
    {
        for (int j = i + 1; j < count; j++)
        {
            if (arr2[i].loss > arr2[j].loss)
            {
                swap(arr2[i], arr2[j]);
            }
            else if (arr2[i].loss == arr2[j].loss)
            {
                if (arr2[i].quantity < arr2[j].quantity)
                {
                    swap(arr2[i], arr2[j]);
                }
                else if (arr2[i].quantity == arr2[j].quantity)
                {
                    if (arr2[i].label > arr2[j].label)
                    {
                        swap(arr2[i], arr2[j]);
                    }
                }
            }
        }
    }

    //output
    for (int i = 0; i < count; i++)
    {
        cout << arr2[i].loss << " " << arr2[i].quantity << " " << arr2[i].label << endl;
    }
    return 0;
}