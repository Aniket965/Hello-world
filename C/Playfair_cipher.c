//play fair encryption
#include<stdio.h>
#include<string.h>
int main()
{
	char key[26],plain[1000],cipher[1000],ch[1000][2],mat[5][5];
	int temp[26]={0};
	int size,i,j,x=0,y=0,k,index1[2],index2[2],z=0;
	printf("Enter your plaintext here\n");
	scanf("%s",plain);
	for(i=0;i<strlen(plain)-1;i+=2){
		if(plain[i]=='j')
			ch[x][0]='i';
		else
			ch[x][0]=plain[i];
		if(plain[i+1]=='j')
			ch[x][1]='i';
		else
			ch[x][1]=plain[i+1];
		if(ch[x][0]==ch[x][1]||i+1==strlen(plain)){
			ch[x][1]='x';
			i--;
		}     
		x++;
	}
	printf("Enter your key\n");
	scanf("%s",key);
	size = strlen(key);
	temp[10]=1;
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			if(size){
				mat[i][j]=key[y++];
				--size;
				temp[mat[i][j]-97]=1; 
			}
			else{
				for(k=0;k<26;k++){
					if(temp[k]==0){
						mat[i][j]=(char)(k+97);
						temp[k]=1;
						break;
					}
				}
			}
		}
	}
	for(i=0;i<x;i++){
		for(j=0;j<5;j++){
			for(k=0;k<5;k++){
				if(mat[j][k]==ch[i][0]){
					index1[0]=j;
					index2[0]=k;
				}
				else if(mat[j][k]==ch[i][1]){
					index1[1]=j;
					index2[1]=k;
				}
			}
		}
		if(index1[0]==index1[1]){
			if(index2[0]==4)
				cipher[z++]=(char)mat[index1[0]][1];
			else
				cipher[z++]=(char)mat[index1[0]][index2[0]+1];
			if(index2[1]==4)
				cipher[z++]=(char)mat[index1[1]][1];
			else
				cipher[z++]=(char)mat[index1[1]][index2[1]+1];
		}
		else if(index2[0]==index2[1]){
			if(index1[0]==4)
				cipher[z++]=(char)mat[0][index2[0]];
			else
				cipher[z++]=(char)mat[index1[0]+1][index2[0]];
			if(index1[1]==4)
				cipher[z++]=(char)mat[0][index2[1]];
			else
				cipher[z++]=(char)mat[index1[1]+1][index2[1]];
		}
		else{
			cipher[z++]=(char)mat[index1[0]][index2[1]];
			cipher[z++]=(char)mat[index1[1]][index2[0]];
		}
	}
	printf("Your cipher text is\n");
	for(i=0;i<z;i++)
		printf("%c",cipher[i]);
	return 0;
}
