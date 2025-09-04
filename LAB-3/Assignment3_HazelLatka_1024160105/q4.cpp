#include <iostream>
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

int main(){
  struct stack S1;
  S1=init();
  cout<<"Enter the number of elements: "<<endl;
  int n;
  cin>>n;
  string a[n];
  cout<<"Enter the elements:  "<<endl;
  for(int i=0;i<=n-1; i++){
      cin>>a[i];
  }
   for(int i=0;i<=n-1; i++){
      cout<<a[i]<<endl;
  }
  cout<<"\n";
  
  struct stack s2;
  s2=init();
  
  for(int i=0;i<=n-1;i++){
      if(a[i]=="(")
      {
        s2=push(s2,a[i]);
        
      }
      else if(a[i]==")"){
          while(!isEmpty(s2) && s2.arr[s2.top]!="(" ){
        cout<<s2.arr[s2.top]<<"\t";
          s2=pop(s2);
          }
          s2=pop(s2);
      }
     else if(a[i] != "+" && a[i] != "-" && a[i] != "*" && a[i] != "/" && a[i] != "^" && a[i] != "(" && a[i] != ")") {
    cout << a[i] << "\t"; 
}
      else{
          while(!isEmpty(s2) && s2.arr[s2.top]!="(" && precedence(s2.arr[s2.top])>=precedence(a[i])){
              cout<<s2.arr[s2.top]<<"\t";
              s2=pop(s2);
          }
           s2 = push(s2, a[i]);
          
      }
      
  }
   while (!isEmpty(s2)) {
        cout <<s2.arr[s2.top]<<"\t";
        s2 = pop(s2);
    }
    cout << endl;
}
  




    