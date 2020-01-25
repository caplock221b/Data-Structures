/*
    Write C++ program to store first year percentage of students in array.
    Write function for sorting array of floating point numbers in ascending
    order using a) Selection Sort b) Bubble sort c) Insertion Sort d) Shell Sort
    e) Quick Sort, and display top five scores.
*/
#include <iostream>
using namespace std;

class Sort
{
private:
    int n;
    float *marks;
    string *name;
public:
    Sort()
    {
        cout<<"Enter the number of students whose record you wish to store : ";
        cin>>n;
        marks = new float[n];
        name = new string[n];
    }
    template <typename T>
    void swap(T *a, T *b)
    {
        T temp = *a;
        *a = *b;
        *b = temp;
    }
    void getRecord()
    {
        for(int i=0; i<n; i++)
        {
            cout<<"\nEnter the details of student "<<i+1<<" :"<<endl;
            cout<<"Name : ";
            cin>>name[i];
            cout<<"CGPA : ";
            cin>>marks[i];
        }
    }
    void SelectionSort()
    {
        int min;
        for(int i=0; i<n-1; i++)
        {
            min = i;
            for(int j=i+1; j<n; j++)
            {
                if(marks[j] < marks[min])
                    min = j;
            }
            if(min != i)
            {
                swap(&marks[i], &marks[min]);
                swap(&name[i], &name[min]);
            }
        }
    }
    void BubbleSort()
    {
        for(int i=0; i<n-1; i++)
        {
            for(int j=0; j<n-1-i; j++)
            {
                if(marks[j] > marks[j+1])
                {
                    swap(&marks[j], &marks[j+1]);
                    swap(&name[j], &name[j+1]);
                }
            }
        }
    }
    void InsertionSort()
    {
        int j;
        float x;
        string y;
        for(int i=1; i<n; i++)
        {
            j = i-1;
            x = marks[i];
            y = name[i];
            while(j>-1 && marks[j]>x)
            {
                marks[j+1] = marks[j];
                name[j+1] = name[j];
                j--;
            }
            marks[j+1] = x;
            name[j+1] = y;
        }
    }
    void ShellSort()
    {
        int j;
        float x;
        string y;
        for(int gap=n/2; gap>=1; gap/=2)
        {
            for(int i=gap; i<n; i++)
            {
                x = marks[i];
                y = name[i];
                j = i-gap;
                while(j>=0 && marks[j]>x)
                {
                    marks[j+gap] = marks[j];
                    name[j+gap] = name[j];
                    j = j-gap;
                }
                marks[j+gap] = x;
                name[j+gap] = y;
            }
        }
    }
    int partition(int l,int h)
    {
        float pivot = marks[l];
        int i=l,j=h;
        do
        {
            do
            {
                i++;
            }while(marks[i]<=pivot);
            do
            {
                j--;
            }while(marks[j]>pivot);
            if(i<j)
            {
                swap(&marks[i],&marks[j]);
                swap(&name[i],&name[j]);
            }
        }
        while(i<j);
        swap(&marks[l],&marks[j]);
        swap(&name[l],&name[j]);
        return j;
    }
    void QuickSort(int l,int h)
    {
        int j;
        if(l<h)
        {
            j = partition(l,h);
            QuickSort(l,j);
            QuickSort(j+1,h);
        }
    }
    void callQuickSort()
    {
        QuickSort(0, n);
    }
    void display()
    {
        cout<<"\nThe top 3 students are : "<<endl;
        cout<<"Name\tCGPA"<<endl;
        for(int i=n-1; i>=n-3; i--)
        {
            cout<<name[i]<<"\t"<<marks[i]<<endl;
        }
    }
    ~Sort()
    {
        delete []marks;
        delete []name;
    }
};
int main()
{
    Sort ob;
    ob.getRecord();
    int ch;
    cout<<"\nSort the record using -\n1. Selection Sort\n2. Bubble Sort\n3. Insertion Sort\n4. Shell Sort\n5. Quick Sort"<<endl;
    cout<<"Enter your choice - 1, 2, 3, 4 or 5 : ";
    cin>>ch;
    switch(ch)
    {
    case 1:
        ob.SelectionSort();
        ob.display();
        break;
    case 2:
        ob.BubbleSort();
        ob.display();
        break;
    case 3:
        ob.InsertionSort();
        ob.display();
        break;
    case 4:
        ob.ShellSort();
        ob.display();
        break;
    case 5:
        ob.callQuickSort();
        ob.display();
        break;
    default:
        cout<<"Please enter valid choice next time."<<endl;
    }
    return 0;
}
