#include<stdio.h>
#include<string.h>
#include<stdlib.h> 
struct 
{ 
	char dname[10],fname[10][10]; 
	int fcnt; 
}dir; 

int main() 
{ 
	int i,j,ch; 
	char f[30]; 
	dir.fcnt = 0; 
	printf("*** SINGLE LEVEL DIRECTORY ***"); 
	printf("\nEnter name of directory: "); 
	scanf("%s", dir.dname); 
	printf("\nCHOICES\n 1.Create File\n2.Delete File\n3.Search File\n4.Display Files\n5.Exit\n"); 
	while(1) 
	{ 
		printf("\nEnter your choice: "); 
		scanf("%d",&ch); 
		switch(ch) 
		{
			case 1: printf("Enter the name of the file: "); 
					scanf("%s",dir.fname[dir.fcnt]); 
					dir.fcnt++; 
					break; 	
			case 2: printf("Enter the name of the file: "); 
					scanf("%s",f); 
					for(i=0;i<dir.fcnt;i++) 
					{ 
						if(strcmp(f, dir.fname[i])==0) 
						{ 
							printf("File %s is deleted from location %d.\n",f,i+1);
							for(j=i;j<dir.fcnt;j++) 
							{ 
								if(j<dir.fcnt-1) 
								strcpy(dir.fname[j],dir.fname[j+1]); 
							} 
							break;
						} 
					} 
					if(i==dir.fcnt) 
						printf("File %s not found.\n",f); 
					else dir.fcnt--; 
					break; 
			case 3: printf("Enter the name of the file: "); 
					scanf("%s",f); 
					for(i=0;i<dir.fcnt;i++) 
					{ 
						if(strcmp(f, dir.fname[i])==0) 
						{ 
							printf("File %s is found at location %d.\n", f, i+1); 
							break; 
						} 
					} 
					if(i==dir.fcnt) 
						printf("File %s not found.\n",f); 
						break; 
			case 4:if(dir.fcnt==0)
					printf("Directory Empty.\n"); 
					else 
					{ 
						printf("The Files are: "); 
						for(i=0;i<dir.fcnt;i++) 
							printf("\t%s",dir.fname[i]); 
					} 
					printf("\n"); 
					break; 
			default: exit(0); 
		} 
	} getch(); 
}

