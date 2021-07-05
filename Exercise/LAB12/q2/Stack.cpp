#include "stack.h"

Stack::Stack(int n)
{
    top = -1;
    size = n;
    pitems = new Item[size];
}
Stack::Stack(const Stack & st)
{
    size = st.size;
    pitems = new Item[st.size];
    top = st.top;
    for (int i = 0; i < size; i++)
    {
        pitems[i] = st.pitems[i];
    }
}
Stack::~Stack()
{
    delete []pitems;
}
bool Stack::isempty() const
{
    if (top == -1)
        return true;
    else
        return false;
}
bool Stack::isfull() const
{
    if (top == size-1)
        return true;
    else
        return false;
}
bool Stack::push(const Item & item)
{
    if(!isfull()){
        top++;
        pitems[top] = item;
        return true;
    }else{
        return false;
    }
}
bool Stack::pop(Item & item)
{
    if(!isempty()){
        item = pitems[top];
        pitems[top] = 0;
        top--;
        return true;
    }else{
        return false;
    }
}
Stack & Stack::operator=(const Stack & st)
{
    if(this == &st){
        return *this;
    }
    delete []pitems;
    size = st.size;
    top = st.top;
    pitems = new Item[st.size];
    for (int i = 0; i < size; i++)
    {
        pitems[i] = st.pitems[i];
    }
    return *this;
}
