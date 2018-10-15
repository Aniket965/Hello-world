/* C Program - Add Two Matrices */
		
#include<stdio.h>
#include<conio.h>
void main()
{
	clrscr();
	int mat1[3][3], mat2[3][3], i, j, mat3[3][3];
	printf("Enter matrix 1 elements :");
	for(i=0; i<3; i++)
	{
		for(j=0; j<3; j++)
		{
			scanf("%d",&mat1[i][j]);
		}
	}
	printf("Enter matrix 2 elements :");
	for(i=0; i<3; i++)
	{
		for(j=0; j<3; j++)
		{
			scanf("%d",&mat2[i][j]);
		}
	}
	printf("Adding the two matrix to form the third matrix .....\n");
	for(i=0; i<3; i++)
	{
		for(j=0; j<3; j++)
		{
			mat3[i][j]=mat1[i][j]+mat2[i][j];
		}
	}
	printf("The two matrix added successfully...!!");
	printf("The new matrix will be :\n");
	for(i=0; i<3; i++)
	{
		for(j=0; j<3; j++)
		{
			printf("%d ",mat3[i][j]);
		}
		printf("\n");
	}
	getch();
  }
