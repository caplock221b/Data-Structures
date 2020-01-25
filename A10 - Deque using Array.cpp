/*
    A double-ended queue (deque) is a linear list in which additions and
    deletions may be made at either end. Obtain a data representation mapping a
    deque into a one-dimensional array. Write C++ program to simulate deque
    with functions to add and delete elements from either end of the deque.
*/
#include <iostream>
using namespace std;

class Deque
{
private:
    int a[100];
    int rear,front;
public:
    Deque()
    {
        rear=-1;
        front=-1;
    }
    bool IsEmpty()
    {
        if(rear==-1 && front==-1)
            return true;
        else
            return false;
    }
    void insertRear(int x)
    {
        if(rear==-1 && front==-1){
            rear=0;
            front=0;
            a[rear]=x;
        }
        else{
            rear=rear+1;
            a[rear]=x;
        }
    }
    void insertFront(int x)
    {
        if(rear==-1 && front==-1){
            rear=0;
            front=0;
            a[rear]=x;
        }
        else{
            for(int i=rear; i>=front; i--)
                a[i+1]=a[i];
            a[front]=x;
            rear=rear+1;
        }

    }
    void deleteRear()
    {
        if(IsEmpty() || front>rear)
            cout<<"\t\t\tQueue is Empty !!!!\n";
        else
            rear=rear-1;
    }
    void deleteFront()
    {
        if(IsEmpty() || front>rear)
            cout<<"\t\t\tQueue is Empty !!!!\n";
            else
                front=front+1;
    }
    void display()
    {
        if(IsEmpty() || front>rear)
            cout<<"\t\t\tQueue is Empty !!!!\n";
        else{
            cout<<"\tFront-->\t";
            for(int i=front; i<=rear; i++)
                cout<<a[i]<<" ";
            cout<<"\t<--Rear\n\n";
        }
    }
};
int main()
{
    int x,y;
    Deque d;
    char ch='y';
    do
    {
        cout<<"Enter your choice\n\t\t1.Insert at front\n\t\t2.Insert at rear\n\t\t3.Delete at front\n\t\t4.Delete at rear\n\n";
        cin>>x;
        switch(x)
        {
        case 1:
            cout<<"Enter the element to be inserted : ";
            cin>>y;
            cout<<"\n";
            d.insertFront(y);
            d.display();
            break;
        case 2:
            cout<<"Enter the element to be inserted : ";
            cin>>y;
            cout<<"\n";
            d.insertRear(y);
            d.display();
            break;
        case 3:
            d.deleteFront();
            d.display();
            break;
        case 4:
            d.deleteRear();
            d.display();
            break;
        default:
            cout<<"Enter correct choice next time ...........\n\n";
        }
        cout<<"Do you want to continue (y/n) ?\n";
        cin>>ch;
    }while(ch == 'y');
    return 0;
}
