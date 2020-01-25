//============================================================================
// Name        : matrixVersion2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, ANSI-style
//============================================================================
/*
	Write C++ program for storing matrix. Write functions for :
		1.Check whether given matrix is upper triangular or not.
		2.Compute summation of diagonal elements.
		3.Compute transpose of matrix.
		4.Add, subtract and multiply two matrices.
		5.Check saddle point is present or not.
 */
#include <iostream>
using namespace std;

class Matrix{
int row, col;
int a[10][10];
public:
	void setA(){
		cout<<"Enter the number of rows and columns in your matrix : ";
		cin>>row>>col;
		cout<<"Enter the matrix elements : "<<endl;
		for(int i=0; i<row; i++){
			for(int j=0; j<col; j++)
				cin>>a[i][j];
			cout<<"";
		}
	}
	void checkUpTri(){
		if(row==col){
			int ctr=0;
			for(int i=0; i<row; i++){
				for(int j=0; j<col; j++){
					if(i+j > row && a[i][j]!=0){
						ctr++;
						break;
					}
				}
			}
			if(ctr!=0)
				cout<<"\nThe given matrix is not an upper triangular matrix.";
			else
				cout<<"\nThe given matrix is an upper triangular matrix.";
		}
		else
			cout<<"\nThe given matrix is not a square matrix, hence its upper triangular nature cannot be checked.";
	}
	int sumDiagonal(){
		int sum=0;
		if(row==col){
			for(int i=0; i<row; i++){
				for(int j=0; j<col; j++){
					if(i==j)
						sum+=a[i][j];
				}
			}
		}
		else
			cout<<"\nThe given matrix is not a square matrix. Diagonal elements are defined only for square matrices.";
		return sum;
	}
	void transpose(){
		cout<<"\nThe transpose of the given matrix is :"<<endl;
		for(int i=0; i<col; i++){
			for(int j=0; j<row; j++)
				cout<<a[j][i]<<" ";
			cout<<"\n";
		}
	}
	void add(Matrix ob){
		if(row==ob.row && col==ob.col){
			cout<<"\nThe sum of the two matrices is :"<<endl;
			for(int i=0; i<row; i++){
				for(int j=0; j<col; j++)
					cout<<a[i][j]+ob.a[i][j]<<" ";
				cout<<"\n";
			}
		}
		else{
			cout<<"\nSince the indices of the matrices are not same, they cannot be added."<<endl;
		}
	}
	void sub(Matrix ob){
		if(row==ob.row && col==ob.col){
			cout<<"\nThe subtraction of the two matrices is :"<<endl;
			for(int i=0; i<row; i++){
				for(int j=0; j<col; j++)
					cout<<a[i][j]-ob.a[i][j]<<" ";
				cout<<"\n";
			}
		}
		else
			cout<<"\nSince the indices of the matrices are not same, they cannot be subtracted."<<endl;
	}
	void mul(Matrix ob){
		int ctr=0;
		int mul[row][ob.col];
		if(col==ob.row){
			for(int i=0; i<row; i++){
				for(int j=0; j<ob.col; j++){
					mul[i][j]=0;
					for(int k=0; k<col; k++)
						mul[i][j] += a[i][k] * ob.a[k][j];
					if(ctr==0){
						cout<<"\nThe multiplication of the two matrices is :"<<endl;
						ctr++;
					}
					cout<<mul[i][j]<<" ";
				}
				cout<<"\n";
			}
		}
		else
			cout<<"Since the number of columns of first matrix is not equal to the number of rows of the second matrix,\n the two matrices cannot be multiplied."<<endl;
	}
};
int main() {
	Matrix ob1, ob2;
	int choice;
	ob1.setA();
	cout<<"\nPlease enter the choice of operation you want to perform from the list given to you : "<<endl;
	cout<<"1.Check whether given matrix is upper triangular or not."<<endl;
	cout<<"2.Compute summation of diagonal elements."<<endl;
	cout<<"3.Compute transpose of matrix."<<endl;
	cout<<"4.Add, subtract and multiply two matrices."<<endl;
	cout<<"5.Check saddle point is present or not."<<endl;
	cout<<"Enter your choice in the form 1 or 2 or 3 or 4 or 5 : ";
	cin>>choice;
	switch(choice){
	case 1:
		ob1.checkUpTri();
		break;
	case 2:
		cout<<"\nThe sum of diagonal elements of given matrix is "<<ob1.sumDiagonal()<<"."<<endl;
		break;
	case 3:
		ob1.transpose();
		break;
	case 4:
		cout<<"\nEnter the details of second matrix -"<<endl;
		ob2.setA();
		ob1.add(ob2);
		ob1.sub(ob2);
		ob1.mul(ob2);
		break;
	default:
		cout<<"\nPlease enter a valid choice next time!!"<<endl;
	}
	return 0;
}
