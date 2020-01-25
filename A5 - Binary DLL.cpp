/*
    Write C++ program for storing binary number using doubly linked lists.
    Write functions :
        •	To compute 1‘s and 2‘s complement
        •	Add two binary numbers
*/
#include <iostream>
using namespace std;

class Node{
private:
    int bit;
    Node *prev;
    Node *next;
public:
    Node(){
        prev = NULL;
        next = NULL;
    }
    friend class BinaryLinkedList;
};

class BinaryLinkedList{
private:
    Node *first;
    Node *last;
    int num;
public:
    void convertToBinary(int x){
        int rem;
        num = x;
        first = last = NULL;
        while(x != 0){
            Node *p = new Node;
            rem = x%2;
            p->bit = rem;
            if(first == NULL && last == NULL){
                first = p;
                last = p;
            }
            else{
                p->next = first;
                first->prev = p;
                first = p;
            }
            x = x/2;
        }
    }
    void getOnesComplement(){
        Node *p = first;
        while(p != NULL){
            if(p->bit == 0)
                p->bit = 1;
            else
                p->bit = 0;
            p = p->next;
        }
    }
    void getTwosComplement(){
        int carry = 1;
        Node *p = last;
        while(p != NULL){
            if(p->bit == 1 && carry == 1){
                p->bit = 0;
                carry = 1;
            }
            else if((p->bit == 0 && carry == 1) || (p->bit == 1 && carry == 0)){
                p->bit = 1;
                carry = 0;
            }
            else{
                p->bit = 0;
                carry = 0;
            }
            p = p->prev;
        }
    }
    void toConvertBinaryToTwosComplement(){
        convertToBinary(num);
        Node *p = new Node;
        p->bit = 0;
        p->next = first;
        first->prev = p;
        first = p;
        getOnesComplement();
        getTwosComplement();
    }
    void addBinaryNumbers(BinaryLinkedList &ob1, BinaryLinkedList &ob2){
        Node *a = ob1.last; // Starting from the LSB of first number
        Node *b = ob2.last; // Starting from the LSB of second number
        int carry = 0;
        BinaryLinkedList sum; // Store result of addition in "sum"
        sum.first = sum.last = new Node;
        while(a != NULL && b != NULL){
            if(a->bit == 0 && b->bit == 0 && carry == 0){
                sum.first->bit = 0;
                carry = 0;
            } // Check for these values of a, b and carry : 000 001 010 011 100 101 110 111
            else if((a->bit == 1 && b->bit == 0 && carry == 0) || (a->bit == 0 && b->bit == 1 && carry == 0) || (a->bit == 0 && b->bit == 0 && carry == 1)){
                sum.first->bit = 1;
                carry = 0;
            }
            else if((a->bit == 0 && b->bit == 1 && carry == 1) || (a->bit == 1 && b->bit == 0 && carry == 1) || (a->bit == 1 && b->bit == 1 && carry == 0)){
                sum.first->bit = 0;
                carry = 1;
            }
            else{
                sum.first->bit = 1;
                carry = 1;
            }
            a = a->prev;
            b = b->prev;
            Node *t = new Node;
            t->next = sum.first;
            sum.first->prev = t;
            sum.first = t;
        }
        while(a != NULL){
            if(carry == 0){
                sum.first->bit = a->bit;
                carry = 0;
            }
            else{
                if(a->bit == 0){
                    sum.first->bit = 1;
                    carry = 0;
                }
                else{
                    sum.first->bit = 0;
                    carry = 1;
                }
            }
            a = a->prev;
            Node *t = new Node;
            t->next = sum.first;
            sum.first->prev = t;
            sum.first = t;
        }
        while(b != NULL){
            if(carry == 0){
                sum.first->bit = b->bit;
                carry = 0;
            }
            else{
                if(b->bit == 0){
                    sum.first->bit = 1;
                    carry = 0;
                }
                else{
                    sum.first->bit = 0;
                    carry = 1;
                }
            }
            b = b->prev;
            Node *t = new Node;
            t->next = sum.first;
            sum.first->prev = t;
            sum.first = t;
        }
        if(carry == 1)
            sum.first->bit = 1;
        else
            sum.first = sum.first->next;
        cout<<"\n\nAddition of the two numbers is : ";
        sum.display();
    }
    void display(){
        Node *p = first;
        while(p != NULL){
            cout<<p->bit<<" ";
            p = p->next;
        }
    }
};
int main()
{
    BinaryLinkedList num1, num2, num3;
    int x, y;
    cout<<"Enter first number : ";
    cin>>x;
    cout<<"The numbers binary representation is : ";
    num1.convertToBinary(x);
    num1.display();
    cout<<"\nThe number's 1's complement representation is : ";
    num1.getOnesComplement();
    num1.display();
    cout<<"\nThe number's 2's complement representation is : ";
    num1.toConvertBinaryToTwosComplement();
    num1.display();

    cout<<"\nEnter second number : ";
    cin>>y;
    cout<<"The numbers binary representation is : ";
    num2.convertToBinary(y);
    num2.display();
    cout<<"\nThe number's 1's complement representation is : ";
    num2.getOnesComplement();
    num2.display();
    cout<<"\nThe number's 2's complement representation is : ";
    num2.toConvertBinaryToTwosComplement();
    num2.display();

    num1.convertToBinary(x);
    num2.convertToBinary(y);
    num3.addBinaryNumbers(num1, num2);
    return 0;
}
