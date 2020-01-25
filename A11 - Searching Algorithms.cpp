/*
    a)	Write C++ program to store roll numbers of student in array who attended
        training program in random order. Write function for searching whether
        particular student attended training program or not using linear search
        and sentinel search.

	b)  Write C++ program to store roll numbers of student array who attended
        training program in sorted order. Write function for searching whether
        particular student attended training program or not using binary search.

*/
#include <iostream>
using namespace std;

class Search{
    int n;
    int *roll;
public:
    Search(){
        cout<<"Enter the number of students who attended the training program : ";
        cin>>n;
        roll = new int[n+1];
    }
    void getRoll(){
        cout<<"Enter the roll numbers of the students who attended the training program -"<<endl;
        for(int i=0; i<n; i++){
            cout<<"Enter roll number of student "<<i+1<<" : ";
            cin>>roll[i];
        }
    }
    void linearSearch(int key){
        int flag = 0;
        for(int i=0; i<n; i++){
            if(roll[i] == key){
                flag = 1;
                break;
            }
        }
        if(flag == 1)
            cout<<"Roll number "<<key<<" was present for the training program."<<endl;
        else
            cout<<"Roll number "<<key<<" did not attend the training program."<<endl;
    }
    void sentinelSearch(int key){
        roll[n] = key;
        int i = 0;
        while(roll[i]!=key){
            i++;
        }
        if(i<n)
            cout<<"Roll number "<<key<<" was present for the training program."<<endl;
        else
            cout<<"Roll number "<<key<<" did not attend the training program."<<endl;
    }
    void selectionSort(){
        int m, temp;
        for(int i=0; i<n-1; i++){
            m = i;
            for(int j=i+1; j<n; j++){
                if(roll[j] < roll[m])
                    m = j;
            }
            if(m!=i){
                temp = roll[i];
                roll[i] = roll[m];
                roll[m] = temp;
            }
        }
    }
    void binarySearch(int key){
        int low = 0;
        int high = n-1;
        int mid, flag = 0;
        while(low <= high){
            mid = (low+high)/2;
            if(roll[mid] == key){
                flag = 1;
                break;
            }
            else if(roll[mid] < key)
                low = mid+1;
            else
                high = mid-1;
        }
        if(flag == 1)
            cout<<"Roll number "<<key<<" was present for the training program."<<endl;
        else
            cout<<"Roll number "<<key<<" did not attend the training program."<<endl;
    }
};
int main()
{
    Search ob;
    ob.getRoll();
    int key, ch;
    cout<<"Enter the roll number which you want to search for : ";
    cin>>key;
    cout<<"\nMenu -\n1. Linear Search\n2. Sentinel Search\n3. Binary Search"<<endl;
    cout<<"Enter your choice - 1, 2 or 3 : ";
    cin>>ch;
    switch(ch){
    case 1:
        ob.linearSearch(key);
        break;
    case 2:
        ob.sentinelSearch(key);
        break;
    case 3:
        ob.selectionSort();
        ob.binarySearch(key);
        break;
    default:
        cout<<"Please enter valid choice next time.";
    }
    return 0;
}
