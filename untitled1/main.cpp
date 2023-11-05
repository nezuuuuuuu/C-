#include <iostream>

#include "arraystack.h"
using namespace std;




int main() {
    Stack* stack = new ArrayStack();

    int n;
    string str;
    int i=0;
    cout<<"Enter pair count: "<<endl;
    cin>>n;
    stack->res(n, 0,0);
    stack-> printVector();







//   cout<<"Enter: "<<endl;
//   cin>>str;
//   cout<<"size of str: "<<str.size()<<endl;
//    int k=stack->valid(str,0,0);
//    if(k==1){
//        cout<<"Input mismatch";
//    }
//    if(k==0){
//        cout<<"Input valid";
//    }
//    if(k==3){
//        cout<<"missing close";
//    }
//    if(k==2){
//        cout<<"missing open";
//    }
//
//    return 0;
}

