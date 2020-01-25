/*
    Department of Computer Engineering has student's club named 'Pinnacle Club'.
    Students of Second, third and final year of department can be granted membership
    on request. Similarly one may cancel the membership of club.
    First node is reserved for president of club and last node is reserved for
    secretary of club. Write C++ program to maintain club member‘s information
    using singly linked list. Store student PRN and Name.

    Write functions to :
•	Add and delete the members as well as president or even secretary.
•	Compute total number of members of club
•	Display members
•	Display list in reverse order using recursion
•	Two linked lists exists for two divisions. Concatenate two lists Sort the singly linked list.

*/

#include <bits/stdc++.h>
using namespace std;

class Node{
private:
    string name;
    int prn;
    string pos;
    Node *next;
public:
    Node(){
        name = "";
        prn = 0;
        pos = "Member";
        next = NULL;
    }
    friend class PinnacleClub;
};

class PinnacleClub{
private:
    Node *head;
    Node *last;
    int cnt;
public:
    PinnacleClub(){
        head = NULL;
        last = NULL;
        cnt = 0;
    }
    Node* createNode(string name, int prn){
        Node *temp = new Node;
        temp->name = name;
        temp->prn = prn;
        return temp;
    }
    void insertNode(string name, int prn, int index){
        Node *temp = createNode(name, prn);
        if(index == 1 && cnt==0){
            head = temp;
            cnt++;
        }
        else if(index == 1 && cnt!=0){
            temp->next = head;
            head = temp;
            cnt++;
        }
        else if(index>1 && index<=cnt+1){
            Node *p = head;
            for(int i=0; i<index-2; i++)
                p = p->next;
            temp->next = p->next;
            p->next = temp;
            cnt++;
        }
        else
            cout<<"Index out of bounds!!"<<endl;
        Node *t = head;
        while(t->next != NULL)
            t = t->next;
        last = t;
    }
    void deleteNode(int n){
        if(head->prn == n){
            Node *t = head;
            head = head->next;
            delete t;
            cnt--;
            return;
        }
        Node *temp = head;
        Node *prev = NULL;
        while(temp->prn != n){
            prev = temp;
            temp = temp->next;
        }
        if(temp == NULL)
            cout<<"The record with the given PRN does not exist!!"<<endl;
        else{
            prev->next = temp->next;
            delete temp;
            cnt--;
        }
    }
    void reverseDisplay(Node *p){
        if(p == NULL){
            cout<<"\nName\t\tPosition\tPRN"<<endl;
            return;
        }
        else{
            reverseDisplay(p->next);
            cout<<p->name<<"\t\t"<<p->pos<<"\t"<<p->prn<<endl;
        }
    }
    void reversal(){
        reverseDisplay(head);
    }
    void display(){
        Node *p = head;
        cout<<"Name\t\tPosition\tPRN"<<endl;
        if(cnt == 1){
            p->pos = "President";
            cout<<p->name<<"\t\t"<<p->pos<<"\t"<<p->prn<<endl;
        }
        else if(cnt == 2){
            p->pos = "President";
            cout<<p->name<<"\t\t"<<p->pos<<"\t"<<p->prn<<endl;
            p = p->next;
            p->pos = "Secretary";
            cout<<p->name<<"\t\t"<<p->pos<<"\t"<<p->prn<<endl;
        }
        else{
            p->pos = "President";
            cout<<p->name<<"\t\t"<<p->pos<<"\t"<<p->prn<<endl;
            p = p->next;
            while(p->next != NULL){
                p->pos = "Member";
                cout<<p->name<<"\t\t"<<p->pos<<"\t"<<p->prn<<endl;
                p = p->next;
            }
            p->pos = "Secretary";
            cout<<p->name<<"\t\t"<<p->pos<<"\t"<<p->prn<<"\n"<<endl;
        }
    }
    void concatenate(PinnacleClub ob){
        last->next = ob.head;
        cnt = cnt + ob.retCount();
    }
    void sorting(){
        for(int i=0;i<cnt-1;i++){
            Node *temp=head->next;
            for(int j=0;j<cnt-i-3;j++){
                if(temp->prn > temp->next->prn){
                    swap(temp->prn, temp->next->prn);
                    swap(temp->name, temp->next->name);
                }
                temp=temp->next;
            }
        }
    }
    int retCount(){
        return cnt;
    }
};
int main(){
    PinnacleClub ob1, ob2;
    char ans;
    string n;
    int ind, num, ch;
    do{
        cout<<"Menu :\n1. Insert a member\n2. Delete a member\n3. Display the Club List in reverse\n4. Sort\n5. Get total members of the club"<<endl;
        cout<<"Enter your choice : ";
        cin>>ch;
        switch(ch){
        case 1:
            cout<<"Enter the name of member : ";
            cin>>n;
            cout<<"Enter the PRN of member : ";
            cin>>num;
            cout<<"Enter the position at which you wish to insert the member : ";
            cin>>ind;
            cout<<"\n";
            ob1.insertNode(n, num, ind);
            ob1.display();
            break;
        case 2:
            cout<<"Enter the PRN of the member whom you wish to delete : ";
            cin>>num;
            ob1.deleteNode(num);
            ob1.display();
            break;
        case 3:
            ob1.reversal();
            break;
        case 4:
            ob1.sorting();
            ob1.display();
            break;
        case 5:
            cout<<"\nThe total number of members in Pinnacle Club are : "<<ob1.retCount()<<endl;
            break;
        default:
            cout<<"Please enter a valid choice next time."<<endl;
        }
        cout<<"\nPerform another operation on the Pinnacle club list? (Enter y for yes and n for no) : ";
        cin>>ans;
        cout<<"\n";
    }while(ans == 'y');
    cout<<"Create a Club List for another division? (Enter y for yes and n for no) : ";
    cin>>ans;
    while(ans == 'y'){
        cout<<"Menu :\n1. Insert a member\n2. Delete a member\n3. Display the Club List in reverse\n4. Get total members of the club\n5. Concatenate the lists of both divisions"<<endl;
        cout<<"Enter your choice : ";
        cin>>ch;
        switch(ch){
        case 1:
            cout<<"Enter the name of member : ";
            cin>>n;
            cout<<"Enter the PRN of member : ";
            cin>>num;
            cout<<"Enter the position at which you wish to insert the member : ";
            cin>>ind;
            cout<<"\n";
            ob2.insertNode(n, num, ind);
            ob2.display();
            break;
        case 2:
            cout<<"Enter the PRN of the member whom you wish to delete : ";
            cin>>num;
            ob2.deleteNode(num);
            ob2.display();
            break;
        case 3:
            ob2.reversal();
            break;
        case 4:
            cout<<"\nThe total number of members in Pinnacle Club are : "<<ob2.retCount()<<endl;
            break;
        case 5:
            ob1.concatenate(ob2);
            ob1.display();
            break;
        default:
            cout<<"Please enter a valid choice next time."<<endl;
        }
        cout<<"\nPerform another operation on the Pinnacle club list? (Enter y for yes and n for no) : ";
        cin>>ans;
        cout<<"\n";
    }
    return 0;
}
