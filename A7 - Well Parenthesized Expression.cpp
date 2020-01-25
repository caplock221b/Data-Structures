/*
    In any language program mostly syntax error occurs due to unbalancing
    delimiter such as (),{},[]. Write C++ program using stack to check whether
    given expression is well parenthesized or not.
*/
#include <iostream>
using namespace std;

class Stack{
private:
    int t;
    char *a;
public:
    Stack(){
        t = -1;
        a = new char[100];
    }
    void push(char c){
        t++;
        a[t] = c;
    }
    void pop(){
        t--;
    }
    char top(){
        return a[t];
    }
    bool isEmpty(){
        if(t==-1)
            return true;
        else
            return false;
    }
};

class WellParenthesizedExp{
private:
    Stack s;
    string exp;
public:
    void getExp(string exp){
        this->exp = exp;
    }
    bool areAPair(char a, char b){
        if(a=='(' && b==')')
            return true;
        else if(a=='{' && b=='}')
            return true;
        else if(a=='[' && b==']')
            return true;
        return false;
    }
    bool isWellParenthesized(){
        int l=exp.length();
        for(int i=0; i<l; i++){
            if(exp[i]=='(' || exp[i]=='{' || exp[i]=='[')
                s.push(exp[i]);
            else if(exp[i]==')' || exp[i]=='}' || exp[i]==']'){
                if(areAPair(s.top(), exp[i]) && !s.isEmpty())
                    s.pop();
                else
                    return false;
            }
            else
                continue;
        }
        return s.isEmpty()?true:false;
    }
};
int main()
{
    char ch;
    string exp;
    WellParenthesizedExp ob;
    do{
        cout<<"Enter the expression : ";
        cin>>exp;
        ob.getExp(exp);
        if(ob.isWellParenthesized())
            cout<<"The expression is well-parenthesized.";
        else
            cout<<"The expression is not well-parenthesized.";
        cout<<"\nCheck for another expression ? (Enter y for yes and n for no) : ";
        cin>>ch;
        cout<<"\n";
    }while(ch == 'y');
    return 0;
}
