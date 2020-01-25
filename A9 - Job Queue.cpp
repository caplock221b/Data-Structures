/*
    Queues are frequently used in computer programming, and a typical example is
    the creation of a job queue by an operating system. If the operating system
    does not use priorities, then the jobs are processed in the order they enter
    the system. Write C++ program for simulating job queue. Write functions to
    add job and delete job from queue.
*/
#include <iostream>
using namespace std;

class Node{
private:
    string name;
    Node *next;
public:
    Node(){
        name = "";
        next = NULL;
    }
    friend class Queue;
};

class Queue{
private:
    Node *front;
    Node *rear;
    int count;
public:
    Queue(){
        front = NULL;
        rear = NULL;
    }
    Node* createNode(string n){
        Node *temp = new Node;
        temp->name = n;
        temp->next = NULL;
        return temp;
    }
    void enqueue(string n){
        Node *temp = createNode(n);
        if(front == NULL || rear == NULL)
            front = rear = temp;
        else{
            rear->next = temp;
            rear = temp;
        }
    }
    void dequeue(){
        if(front == NULL)
            return;
        else{
            Node *temp = front;
            front = front->next;
            delete temp;
        }
    }
    void display(){
        Node *temp = front;
        if(temp == NULL)
            cout<<"\nQueue is empty!!"<<"\n";
        else{
            cout<<"\nThe Queue is : ";
            while(temp->next!=NULL){
                cout<<temp->name<<" | ";
                temp = temp->next;
            }
            cout<<temp->name<<"\n";
        }
    }
};
int main()
{
    Queue job;
    char ans;
    string n;
    int ch;
    do{
        cout<<"Menu -\n1. Enqueue (Add an interviewee to the queue)\n2. Dequeue (Delete the first interviewee from the front of the queue)"<<endl;
        cout<<"Enter your choice 1 or 2 : ";
        cin>>ch;
        cin.ignore(256, '\n');
        switch(ch){
        case 1:
            cout<<"Enter the name of interviewee : ";
            getline(cin, n);
            job.enqueue(n);
            job.display();
            break;
        case 2:
            job.dequeue();
            job.display();
            break;
        default:
            cout<<"\nPlease enter valid choice next time."<<endl;
        }
        cout<<"Perform another operation on the queue of interviewees? (Enter y for yes and n for no) : ";
        cin>>ans;
        cout<<"\n";
    }while(ans == 'y');
    return 0;
}
