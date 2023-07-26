//Delete middle element of a stack using recursion

#include <iostream>
#include <stack>
using namespace std;

void solv(stack<int>& st, int k)
{
    if (k == 1) {
        st.pop();
        return;
    }
    int temp = st.top();
    st.pop();
    solv(st, k - 1);
    st.push(temp);
}
void delemid(stack<int>& st, int stsize)
{
    if (st.empty() || stsize == 0) {
        return;
    } 

    int k = stsize / 2 + 1;
    solv(st, k);
}





int main()
{
    stack<int> st;

    //push elements into the stack
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);
    st.push(7);

    delemid(st, st.size());
    // Printing stack after deletion
    // of middle.
    while (!st.empty())
    {
        int p=st.top();
        st.pop();
        cout << p << " ";
    }
    return 0;
}