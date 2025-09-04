#include <iostream>
#define MAXLEN 10
using namespace std;
struct stack{
    int arr[MAXLEN];
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
struct stack push(struct stack S, int data ){
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
        cout<< S.arr[i]<<endl;
    }
}

int main(){
    struct stack S;
    S=init();
    int a ,b,c;
    cout<<"------MENU------"<<endl;
    cout<<"---1.push()---"<<endl;
    cout<<"---2.pop()---"<<endl;
    cout<<"---3.isEmpty()---"<<endl;
    cout<<"---4.isFull()---"<<endl;
    cout<<"---5.display()---"<<endl;
    cout<<"---6.peek---"<<endl;
    cout<<"---7.EXIT---"<<endl;
    
    a=0;
    while(a!=7){
    cout<<"Enter your choice:  "<<endl;
    cin>>a;
    
    if(a==1){
        cout<<"Enter the number of elements you want to enter: "<<endl;
        cin>>b;
        cout<<"Enter the elements: "<<endl;
        for( int j=0; j<b ; j++){
            cin>>c;
            S=push(S,c);
        }
    }
    else if (a==2){
      S=pop(S);
    }
    else if(a==3){
        if(isEmpty(S)){
            cout<<"TRUE"<<endl;
        }
        else{
            cout<<"FALSE"<<endl;
        }
    }
    else if(a==4){
        if(isFull(S)){
            cout<<"TRUE"<<endl;
        }
        else{
            cout<<"FALSE"<<endl;
        }
    }
    else if(a==5){
        cout<<"The stack elements are: "<<endl;
        display(S);
    }
    else if(a==6){
        cout<<"The topmost element is :-  "<<endl;
        peek(S);
    }
    else if(a==7){
        cout<<"EXIT"<<endl;
    }
    else{
        cout<<"INVALID CHOICE"<<endl;
    }
}
}