#include <iostream>
#include <string>
#include <cmath>
#define MAXLEN 50
using namespace std;
struct stack{
    string arr[MAXLEN];
    int top;
};
 
//initialize
struct stack init(){
    struct stack S;
    S.top=-1;
    return S;
}
//if stack is full
int isFull( struct stack S){
        return(S.top==MAXLEN-1);
}
//if stack is empty
int isEmpty( struct stack S){
        return(S.top==-1);
}

//push
struct stack push(struct stack S, string data ){
    if(isFull(S)){
        cout<<"OVERFLOW CONDITION"<<endl;
    }
    else{
        S.top=S.top+1;
        S.arr[S.top]=data;
    }
    return S;
}
//pop
struct stack pop(struct stack S ){
    if(isEmpty(S)){
        cout<<"UNDERFLOW CONDITION"<<endl;
    }
    else{
        S.top=S.top-1;
        
    }
    return S;
    
}

//peek
void peek( struct stack S){
    if(isEmpty(S)){
        cout<<"UNDERFLOW CONDITION";}
    
    else{
    cout<<S.arr[S.top]<<endl;}
    
}
//display
void display(struct stack S){
    for (int i=S.top; i>=0;i--){
        cout<< S.arr[i];
    }
}

//precedence
int precedence(string a){
    
    if(a=="^"){
        return 4;
    }
    else if(a=="/" || a=="*"){
        return 3;
    }
     else if(a=="+"|| a=="-"){
        return 2;
    }
    else{
           return -1;
        }
 
}

struct stack add(struct stack s){
    int a, b , sum;
    a=stoi(s.arr[s.top]);
    s=pop(s);
    b=stoi(s.arr[s.top]);
    s=pop(s);
    sum=a+b;
    s=push(s,to_string(sum));
     return s;
    
}
 struct stack subtract(struct  stack s){
    int a, b , sub;
    a=stoi(s.arr[s.top]);
    s=pop(s);
    b=stoi(s.arr[s.top]);
    s=pop(s);
    sub=b-a;
    s=push(s,to_string(sub));
     return s;
}
struct stack multiply(struct stack s){
    int a, b , prod;
    a=stoi(s.arr[s.top]);
    s=pop(s);
    b=stoi(s.arr[s.top]);
    s=pop(s);
    prod=b*a;
   s=push(s,to_string(prod));
    return s;
}
struct stack  divide(struct  stack s){
    int a, b , quo;
    a=stoi(s.arr[s.top]);
    s=pop(s);
    b=stoi(s.arr[s.top]);
    s=pop(s);
    quo=b/a;
    s=push(s,to_string(quo));
     return s;
}

struct stack power(struct stack s){
    int a, b , power;
    a=stoi(s.arr[s.top]);
    s=pop(s);
    b=stoi(s.arr[s.top]);
    s=pop(s);
    power=pow(b,a);
    s=push(s,to_string(power));
    return s;
}
int main(){
  struct stack S1,s;
  S1=init();
   s=init();
  cout<<"Enter number of elements :  "<<endl;
  int n;
  cin>>n;
   string a[n]; 
  cout<<"Enter a postfix expression:  "<<endl;
  for(int i=0;i<=n-1;i++){
      cin>>a[i]; 
  }

 
  for(int i=0; i<=n-1;i++){
     if(a[i]!="+" && a[i]!="-" && a[i]!="*" && a[i]!="^" &&a[i]!="/" ){
        
         s=push(s,a[i]);
     }
     else if(n==1){
         cout<<s.arr[s.top];
     }
     else{
         if(n>=2){
             if(a[i]=="+"){
                 s=add(s);

             }
              else if(a[i]=="-"){
                 s=subtract(s);
             }
              else if(a[i]=="*"){
                 s=multiply(s);
             }
             else if(a[i]=="/"){
                 s=divide(s);
             }
             else{
                 s=power(s);
             }
             
         }
         
         else{
             cout<<"Error"<<endl;
         }
         
         
     }
    
  }
   display(s);
  
  
}