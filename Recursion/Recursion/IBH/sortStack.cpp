#include<iostream>
#include<stack>

void insertStack(std::stack<int>&st, int tempVal)
{
    if(st.empty() ||st.top()<=tempVal){
        st.push(tempVal);
        return;
    }
    int topVal = st.top();
    st.pop();
    insertStack(st, tempVal);
    st.push(topVal);
    return;

}

void sortStack(std::stack<int>&st)
{
    if(st.empty()){
        return;
    }
    int tempVal = st.top();
    st.pop();
    sortStack(st);
    insertStack(st, tempVal);
    return;
}

int main()
{
    std::stack<int>st;
    st.push(2);
    st.push(0);
    st.push(1);
    st.push(5);

    sortStack(st); 
    while (!st.empty())
    {
        std::cout<<st.top()<<std::endl;
        st.pop();
    }
    
    return 0;
    
}