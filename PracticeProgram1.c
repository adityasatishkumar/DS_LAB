#include<stdio.h>
#define SIZE 100

struct student
{
	int id;
	int age;
	int marks;
};


int main()
{
	struct student s[SIZE];
	int i,n;
	
	printf("Please enter the number of students:");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		printf("Enter the student id:\n");
		scanf("%d",&s[i].id);
		printf("Enter the age of the student:\n");
		scanf("%d",&s[i].age);
		printf("Enter the marks of the student:\n");
		scanf("%d",&s[i].marks);
	}
	
	printf("The details of student(s) who are qualified:\n");
	for(i=0;i<n;i++)
	{
		if(s[i].age>20 && s[i].marks>=65 && s[i].marks<=100)
		{
			printf("Student ID:%d\n",s[i].id);
			printf("Student age:%d\n",s[i].age);
			printf("Student marks:%d\n",s[i].marks);
		}	
	}
	return 0;
}
