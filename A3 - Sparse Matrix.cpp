#include <iostream>
using namespace std;

class Element{
    int row;
    int col;
    int val;
public:
    Element(){
        row = col = val = 0;
    }
    friend class SparseMatrix;
};

class SparseMatrix{
    int m;
    int n;
    int num;
    int arr[50][50];
    Element *a;
public:
    SparseMatrix(){
        m = n = num = 0;
        a = new Element[num];
    }
    void getA(){
        int r, c;
        cout<<"Enter number of rows in original matrix : ";
        cin>>r;
        cout<<"Enter number of columns in original matrix : ";
        cin>>c;
        cout<<"Enter the original matrix :"<<endl;
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                cin>>arr[i][j];
            if(arr[i][j] != 0)
                num++;
            }
        }
        a = new Element[num+1];
        a[0].row = m = r;
        a[0].col = n = c;
        a[0].val = num;
        int k=1;
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(arr[i][j]!=0){
                    a[k].row = i;
                    a[k].col = j;
                    a[k].val = arr[i][j];
                    k++;
                }
            }
        }
    }
    void display(){
        cout<<"The Sparse matrix is : "<<endl;
        for(int i=0; i<num+1; i++){
            cout<<a[i].row<<"\t"<<a[i].col<<"\t"<<a[i].val<<endl;
        }
    }
    void addSparse(SparseMatrix ob1, SparseMatrix ob2){
        if(ob1.m != ob2.m || ob1.n != ob2.n){
            cout<<"The two matrices are not compatible for adding as their indexes are not same."<<endl;
            return;
        }
        else{
            a[0].row = ob1.m;
            a[0].col = ob1.n;
            int i, j, k;
            i=j=k=1;
            while(i<=ob1.num && j<=ob2.num){
                if(ob1.a[i].row < ob2.a[j].row){
                    a[k] = ob1.a[i];
                    i++;
                    k++;
                }
                else if(ob1.a[i].row > ob2.a[j].row){
                    a[k] = ob2.a[j];
                    j++;
                    k++;
                }
                else{
                    if(ob1.a[i].col < ob2.a[j].col){
                        a[k] = ob1.a[i];
                        i++;
                        k++;
                    }
                    else if(ob1.a[i].col > ob2.a[j].col){
                        a[k] = ob2.a[j];
                        j++;
                        k++;
                    }
                    else{
                        a[k] = ob1.a[i];
                        a[k].val = ob1.a[i].val + ob2.a[j].val;
                        i++;
                        j++;
                        k++;
                    }
                }
            }
            while(i<=ob1.num){
                a[k] = ob1.a[i];
                i++;
                k++;
            }
            while(j<=ob2.num){
                a[k] = ob2.a[j];
                j++;
                k++;
            }
            a[0].val = k-1;
            num = k-1;
            display();
        }
    }
    void fastTranspose(){
        SparseMatrix trans;
        trans.a = new Element[num+1];
        trans.a[0].row = n;
        trans.a[0].col = m;
        trans.a[0].val = num;
        trans.num = num;
        int total[n];
        int index[n];
        for(int i=0; i<n; i++)
            total[i] = 0;
        int col_num, location;
        for(int i=1; i<=num; i++){
            col_num = a[i].col;
            total[col_num]++;
        }
        index[0] = 1;
        for(int i=1; i<n; i++)
            index[i] = index[i-1] + total[i-1];
        for(int i=1; i<=num; i++){
            col_num = a[i].col;
            location = index[col_num];
            index[col_num]++;
            trans.a[location].row = a[i].col;
            trans.a[location].col = a[i].row;
            trans.a[location].val = a[i].val;
        }
        trans.display();
    }
};
int main()
{
    SparseMatrix ob1, ob2, ob3;
    ob1.getA();
    ob1.display();
    cout<<"\n";
    ob1.fastTranspose();
    cout<<"\n";
    ob2.getA();
    ob2.display();
    cout<<"\n";
    ob2.fastTranspose();
    cout<<"\n";
    ob3.addSparse(ob1, ob2);
    return 0;
}
