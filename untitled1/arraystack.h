#include "stack.h"
#include "arraylist.h"
#include <vector>
class ArrayStack : public Stack {
    // FIELD DECLARATION
    ArrayList* list;
    vector<string> k;
    int i=0;


public:
    ArrayStack() {
        list = new ArrayList();
    }

    void push(char num){
        list->insertLast(num);
    }

    char pop() {
        return list->removeLast();
    }

    char top() {
        return list->get(size());
    }

    int size() {
        return list->size();
    }

    bool isEmpty(){
        return size() == 0;
    }

    void print() {
        list->print();
    }
    void join(){

    }
    void printVector(){

        for (string s: k){

            cout<<s<<endl;

        }



    }

    void res(int size, int open, int close) {
        if(open==size&&size==close){
            char c[size*2];
            int i=size*2-1;
            while(!this->isEmpty()){
                c[i]=this->pop();
                i--;
            }
            string str=c;

            for(i=0;i<size*2;i++){
                this->push(str[i]);

            }
            k.push_back(str);

            return;

        }

        if(open<size){
            this->push('(');
            res( size, open+1,close);
            this->pop();


        }
        if(close<open){
            this->push(')');
            res( size, open,close+1);
            this->pop();
        }




    }

    int valid(string str, int open, int close){
        if(close>open&&close+open!=str.size()){

            return 1;//mismatch
        }
        else if(open+close==str.size()){
            if(open>close){
                return 3;
            }
            else if(close>open){
                return 2;
            }
            else{
                return 0;
            }
        }
        else{
            push(str[i]);

            if(open<str.size()&&str[i]=='('||str[i]=='{'||str[i]=='['){

                i++;
               return valid(str,open+1,close);
            }
            else if (open>=close){

                i++;
                return valid(str,open,close+1);
            }

        }
    }

    vector<string> &getK(){
        return k;
    }

};

