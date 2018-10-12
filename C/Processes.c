#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
	int i,k;

	for(i=0;i<3;i++)
	{
		if(fork()==0)
		{
			printf("Soy el hijo de %d (pid: %d)\n", (int) getppid(), (int) getpid());
			printf("Soy el padre de %d (pid: %d)\n", (int) getpid(), (int) getppid());

		
			if(i==0)
			{
				for(k=0;k<1;k++)
				{
					if(fork()==0)
					{
						printf("Soy el hijo de %d (pid: %d)\n", (int) getppid(), (int) getpid());
						
						printf("Soy el padre de %d (pid: %d)\n", (int) getpid(), (int) getppid());
						break;
						
					}
					

				}
			}
		
			break;
				

		
		}
		
	
			

	}

	while(1);

	return 0;
}
