/*
    Implement C++ program for expression conversion as infix to postfix and its
    evaluation using stack based on given conditions:  Operands and operator,
    both must be single character, Input Postfix expression must be in a desired
    format, Only '+', '-', '*' and '/ ' operators are expected.
*/
#include <iostream>
using namespace std;

class Node{
private:
    char data;
    Node *next;
public:
    friend class Stack;
};

class Stack{
private:
    Node *t;
public:
    Stack(){
        t = NULL;
    }
    Node* createNode(char c){
        Node *temp = new Node;
        temp->data = c;
        temp->next = NULL;
        return temp;
    }
    void push(char c){
        Node *temp = createNode(c);
        if(t == NULL)
            t = temp;
        else{
            temp->next = t;
            t = temp;
        }
    }
    void pop(){
        Node *temp = t;
        t = t->next;
        delete temp;
    }
    char top(){
        return t->data;
    }
    bool isEmpty(){
        if(t == NULL)
            return true;
        return false;
    }
};

class Conversion{
private:
    string infix;
    string postfix;
    Stack s;
public:
    Conversion(string exp){
        infix = exp;
        postfix = "";
    }
    bool isOperand(char c){
        if(c>='0' && c<='9')
            return true;
        else if(c>='a' && c<='z')
            return true;
        else if(c>='A' && c<='Z')
            return true;
        return false;
    }
    bool isOperator(char c){
        if(c=='+' || c=='-' || c=='*' || c=='/')
            return true;
        return false;
    }
    int operatorWeight(char c){
        int weight = -1;
        switch(c){
        case '+':
            weight = 1;
            break;
        case '-':
            weight = 1;
            break;
        case '*':
            weight = 2;
            break;
        case '/':
            weight = 2;
            break;
        }
        return weight;
    }
    bool hasHigherPrecedence(char op1, char op2){
        int op1Weight = operatorWeight(op1);
        int op2Weight = operatorWeight(op2);
        return op1Weight >= op2Weight ? true : false;
    }
    string infixToPostfix(){
        int l = infix.length();
        for(int i=0; i<l; i++){
            if(isOperand(infix[i]))
                postfix = postfix + infix[i];
            else if(isOperator(infix[i])){
                while(!s.isEmpty() && s.top()!='(' && hasHigherPrecedence(s.top(), infix[i])){
                    postfix = postfix + s.top();
                    s.pop();
                }
                s.push(infix[i]);
            }
            else if(infix[i] == '(')
                s.push(infix[i]);
            else if(infix[i] == ')'){
                while(!s.isEmpty() && s.top()!='('){
                    postfix = postfix + s.top();
                    s.pop();
                }
                s.pop();
            }
            else
                continue;
        }
        while(!s.isEmpty()){
            postfix = postfix + s.top();
            s.pop();
        }
        return postfix;
    }
};
int main()
{
    string exp;
    cout<<"Enter the infix expression : ";
    getline(cin, exp);
    Conversion ob(exp);
    cout<<"The postfix expression is : "<<ob.infixToPostfix();
    return 0;
}
