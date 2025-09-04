
    // Online C++ compiler to run C++ program online
#include <iostream>
#include <string>
#define MAXLEN 14
using namespace std;
struct stack{
    char arr[MAXLEN];
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
struct stack push(struct stack S, char data ){
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
        cout<<"UNDERFLOW CONDITION"<<endl;;
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

int main(){
    struct stack S;
    S=init();
string name="DataStructure";
 int size=14;
  for(int i=0;i<size-1;i++){
    S=push(S,name[i]);}
    display(S);
}
