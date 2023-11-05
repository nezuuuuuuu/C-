#include<vector>


class Stack {
public:
    virtual void push(char) = 0;
    virtual char pop() = 0;
    virtual char top() = 0;
    virtual int size() = 0;
    virtual bool isEmpty() = 0;
    virtual void res(int size, int open,int close)=0;

    virtual void printVector()=0;
    // MUST NOT HAVE PRINT (WHY)
    virtual void print() = 0;
    virtual int valid(std::string str, int open, int close) = 0;
    virtual std::vector<std::string> &getK() = 0;
};
