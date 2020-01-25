/*
 ============================================================================
 Name        : studentData.c
 Author      : acc
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
/*
	Write C/C++ program to store marks scored for first test of subject 'Data Structures and
	Algorithms' for N students. Compute
	I. The average score of class
	II. Highest score and lowest score of class
	III. Marks scored by most of the students
	IV. list of students who were absent for the test
*/
#include <stdio.h>
#include <stdlib.h>
struct Student{
	int marks[50];
};
void main() {
	struct Student ob;
	int n;
	printf("What is the strength of the class ?\n");
	scanf("%d", &n);

	int i, j;
	for(i=0; i<n; i++){ //To accept marks of students
		printf("Enter the Marks of Student %d in the first test of Data Structures and Algorithms.\n", (i+1));
		printf("Enter -1 if the Student was absent.\n");
		scanf("%d", &ob.marks[i]);
	}

	int sum=0, max=0, min=100, abs=0;
	for(j=0; j<n; j++){ //To compute sum of marks, max and min marks, and the absent students
		if(ob.marks[j]!=-1){
			sum+=ob.marks[j];
			if(ob.marks[j] > max)
				max = ob.marks[j];
			if(ob.marks[j] < min)
				min = ob.marks[j];
		}
		if(ob.marks[j]==-1){
			ob.marks[j]=0;
			abs++;
		}
	}

	int avg = sum/n;
	int ctr, maxCtr=0, M = 0;
	printf("\nThe average marks scored are : %d\n", avg);
	printf("The maximum marks scored are : %d\n", max);
	printf("The minimum marks scored are : %d\n", min);
	printf("The number of students who were absent : %d\n", abs);

	int temp;
	for(i=0; i<n-1; i++){ //To sort the array
		for(j=1; j<n; j++){
			if(ob.marks[j]<ob.marks[i]){
				temp = ob.marks[j];
				ob.marks[j] = ob.marks[i];
				ob.marks[i] = temp;
			}
		}
	}


	for(i=0; i<n; i++)
	{
		ctr=0;
		for(j=i+1; j<n; j++)
		{
			if(ob.marks[i]==ob.marks[j])
			{
				ctr++;
			}
			if(ctr>maxCtr)
			{
				M=ob.marks[i];
				maxCtr=ctr;
			}
		}
	}
	printf("Marks scored by most of the students : %d", M);
}
