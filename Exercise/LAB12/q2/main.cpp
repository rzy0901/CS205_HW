#include <iostream>
#include "stack.h"

using namespace std;
int main()
{
    Stack st(3);
    Stack st2;
    cout<<st.push(1)<<endl;
    cout<<st.push(2)<<endl;
    cout<<st.push(3)<<endl;
    cout<<st.push(4)<<endl;
    st2 = st;
    Item it;
    for (int i = 0; i < 4; i++)
    {
        /* code */
        cout<<st.pop(it)<<", item:"<< it <<endl;
    }
    cout<<endl;
    Stack st3(st);
    st.~Stack();
    for (int i = 0; i < 3; i++)
    {
        /* code */
        cout<<st.pop(it)<<", item:"<< it <<endl;
    }
    cout<<endl;
    for (int i = 0; i < 4; i++)
    {
        /* code */
        cout<<st.push(1)<<endl;
    }
    return 0;
}