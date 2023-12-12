class Solution{
    int minEle;
    stack<int> s;
    public:
    
       /*returns min element from stack*/
       int getMin(){
           
           //Write your code here
           if(s.empty()){
               return -1;
           }
           return minEle;
       }
       
       /*returns poped element from stack*/
       int pop(){
           
           //Write your code here
           int x=0;
           if(s.empty()){
               return -1;
           }
           else {
               
               if(s.top()>=minEle){
                    x =s.top();
                   s.pop();
               }
               else if(s.top()<minEle){
                    x = minEle;
                   minEle= 2*minEle-s.top();
                   s.pop();
               }
           }
           return x;   
       }
       
       /*push element x into the stack*/
       void push(int x){
           
           //Write your code here
           if(s.empty()){
               s.push(x);
               minEle=x;
           }
           else 
                if(x<minEle){
                     s.push(2*x-minEle);
                     minEle=x;
                }
                else if(x>=minEle){
                     s.push(x);
                }
       }
};
