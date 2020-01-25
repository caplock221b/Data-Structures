/*
    Second year Computer Engineering class, set A of students like Vanilla Ice-cream and set B of students like butterscotch ice-cream. Write C/C++ program to store two sets using linked list. compute and display
•	Set of students who like either vanilla or butterscotch or both  Set of students who like both vanilla and butterscotch
•	Set of students who like only vanilla not butterscotch
•	Set of students who like only butterscotch not vanilla
•	Number of students who like neither vanilla nor butterscotch.

*/
#include <iostream>
using namespace std;

class Node{
private:
    int roll;
    Node *next;
public:
    Node(){
        roll = 0;
        next = NULL;
    }
    friend class Icecream;
};

class Icecream{
private:
    Node *head;
    Node *last;
public:
    Icecream(){
        head = NULL;
        last = NULL;
    }
    void addNode(int data){
        Node *t = new Node;
        t->roll = data;
        t->next = NULL;
        if(head==NULL && last==NULL){
            head = last = t;
        }
        else{
            last->next = t;
            last = t;
        }
    }
    void deleteNode(int data){
        Node *p = head;
        Node *t = NULL;
        if(data == head->roll){
            Node *temp = head;
            head = head->next;
            delete temp;
        }
        else{
            while(p!=NULL && p->roll!=data){
                t = p;
                p = p->next;
            }
            t->next = p->next;
            delete p;
        }
    }
    void display(){
        Node *p = head;
        while(p!=NULL){
            cout<<p->roll<<" ";
            p = p->next;
        }
        cout<<"\n";
    }
    void intersectionLL(Icecream a, Icecream b){ // a = Vanilla, b = Butterscotch
        Node *x = a.head;
        while(x!=NULL){
            Node *y = b.head;
            while(y!=NULL){
                if(x->roll == y->roll){
                    addNode(x->roll);
                    break;
                }
                y = y->next;
            }
            x = x->next;
        }
        display();
    }
    void unionLL(Icecream a, Icecream b){ // a = Vanilla, b = Butterscotch
        Node *p = a.head;
        while(p->next!=NULL){
            addNode(p->roll);
            p = p->next;
        }
        p->roll = a.last->roll;
        p->next = b.head;
        while(p!=NULL){
            addNode(p->roll);
            p = p->next;
        }
        Node *x = head;
        while(x!=NULL){ // Remove duplicates
            Node *y = x->next;
            while(y!=NULL){
                if(x->roll == y->roll)
                    deleteNode(x->roll);
                y = y->next;
            }
            x = x->next;
        }
        display();
    }
    void eitherLL(Icecream a, Icecream b){ // a = Vanilla/Butterscotch, b = Intersection
        Node *temp = a.head;
        while(temp!=NULL){
            addNode(temp->roll);
            temp = temp->next;
        }
        Node *x = head;
        while(x!=NULL){
            Node *y = b.head;
            while(y!=NULL){
                if(x->roll == y->roll){
                    deleteNode(x->roll);
                    break;
                }
                y = y->next;
            }
            x = x->next;
        }
        display();
    }
};
int main()
{
    Icecream vanilla, butter, intersection, ob1, ob2, ob3, van;
    char choice;
    int ch, ctr = 0;
    int roll;
    do{
        cout<<"Enter roll number of student : ";
        cin>>roll;
        cout<<"Ice Cream Menu -\n1. Vanilla\n2. Butterscotch\n3. Both\n4. None"<<endl;
        cout<<"Enter students choice of ice cream - 1, 2, 3, or 4 : ";
        cin>>ch;
        switch(ch){
        case 1:
            vanilla.addNode(roll);
            van.addNode(roll);
            break;
        case 2:
            butter.addNode(roll);
            break;
        case 3:
            vanilla.addNode(roll);
            van.addNode(roll);
            butter.addNode(roll);
            break;
        case 4:
            ctr++;
            break;
        default:
            cout<<"Please enter valid choice next time!!"<<endl;
        }
        cout<<"\nRecord another student's choice? (Enter y for yes and for no) : ";
        cin>>choice;
    }while(choice == 'y');

    cout<<"\nSet of students who like both vanilla and butterscotch : ";
    intersection.intersectionLL(vanilla, butter);
    cout<<"Set of students who like either vanilla or butterscotch or both : ";
    ob1.unionLL(vanilla, butter);
    cout<<"\nSet of students who like only vanilla not butterscotch : ";
    ob2.eitherLL(van, intersection);
    cout<<"Set of students who like only butterscotch not vanilla : ";
    ob3.eitherLL(butter, intersection);
    cout<<"Number of students who like neither vanilla nor butterscotch : "<<ctr<<endl;
    return 0;
}
