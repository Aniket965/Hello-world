#include <iostream>
#include<stdlib.h>
#include<iomanip>
#include<ctime>
#include<conio.h>
#include<time.h>

using namespace std;

void initial(void);
void gennextblock(void);
void createblock(void);
void updatemap(void);
void movedir(char);
void blockmapassign(void);
void nxtblockassign(void);
void mapassign(void);
int right(void);
int left(void);
int down(void);
void clears(void);
void printmap(void);
void delay(unsigned);
int rotateacl(void);
int rotatecl(void);
void texture(int);
void statue(void);
bool rotatecalc(int,int,int,int);

int map[19][15];
int blockpos[4][2];
int blockposmap[4][2];
int nxtblock[4][4];

bool play,gennext;
int orient,block1comp,block2comp,curblock,nxblock,blockrotx=0,blockroty=0,downcount=0,score=0;


int main()
{
    initial();
    while(play)
    {
        updatemap();
        clears();
        printmap();
        delay(50);
    }
    cin.ignore();
    return 0;
}

void initial()
{
    play=true;
    for(int i=0;i<19;i++)
        for(int j=0;j<14;j++)
            map[i][j]=0;
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            nxtblock[i][j]=0;
    srand((unsigned) time(0));
    block1comp=rand()%6;
    block2comp=rand()%6;
    orient=rand()%2;
}

void updatemap()
{
    if(curblock==nxblock)
    {
        createblock();
        gennext=true;
        curblock++;
        blockmapassign();
    }
    if(gennext)
        gennextblock();
    if(_kbhit())
    {
        movedir(_getch());
    }
    if(downcount==3)
    {
       down();
       downcount=0;
    }
    downcount++;
    mapassign();

}

void movedir(char dir)
{
     switch(dir)
    {
        case 'w':rotateacl();
                 break;
        case 'd':right();
                 break;
        case 's':rotatecl();
                 break;
        case 'a':left();
                 break;
    }

}

void gennextblock()
{
    srand((unsigned) time(0));
    block1comp=rand()%6;
    do{block2comp=rand()%6;}while(block2comp==block1comp);
    orient=rand()%2;
    createblock();
    nxtblockassign();
    gennext=false;
}
void createblock()
{
   if(!orient)
   {
       blockpos[0][0]=1,blockpos[0][1]=1;
       blockpos[1][0]=1,blockpos[1][1]=2;
       switch(block1comp)
       {
           case 0: blockpos[2][0]=0,blockpos[2][1]=1;
                   break;
           case 1: blockpos[2][0]=1,blockpos[2][1]=0;
                   break;
           case 2: blockpos[2][0]=2,blockpos[2][1]=1;
                   break;
           case 5: blockpos[2][0]=0,blockpos[2][1]=2;
                   break;
           case 4: blockpos[2][0]=1,blockpos[2][1]=3;
                   break;
           case 3: blockpos[2][0]=2,blockpos[2][1]=2;
                   break;
       }
       switch(block2comp)
       {
           case 0: blockpos[3][0]=0,blockpos[3][1]=1;
                   break;
           case 1: blockpos[3][0]=1,blockpos[3][1]=0;
                   break;
           case 2: blockpos[3][0]=2,blockpos[3][1]=1;
                   break;
           case 5: blockpos[3][0]=0,blockpos[3][1]=2;
                   break;
           case 4: blockpos[3][0]=1,blockpos[3][1]=3;
                   break;
           case 3: blockpos[3][0]=2,blockpos[3][1]=2;
                   break;
       }
   }
   else
   {
       blockpos[0][0]=1,blockpos[0][1]=2;
       blockpos[1][0]=2,blockpos[1][1]=2;
       switch(block1comp)
       {
           case 0: blockpos[2][0]=1,blockpos[2][1]=1;
                   break;
           case 1: blockpos[2][0]=0,blockpos[2][1]=2;
                   break;
           case 2: blockpos[2][0]=1,blockpos[2][1]=3;
                   break;
           case 5: blockpos[2][0]=2,blockpos[2][1]=1;
                   break;
           case 4: blockpos[2][0]=3,blockpos[2][1]=2;
                   break;
           case 3: blockpos[2][0]=2,blockpos[2][1]=3;
                   break;
       }
       switch(block2comp)
       {
           case 0: blockpos[3][0]=1,blockpos[3][1]=1;
                   break;
           case 1: blockpos[3][0]=0,blockpos[3][1]=2;
                   break;
           case 2: blockpos[3][0]=1,blockpos[3][1]=3;
                   break;
           case 5: blockpos[3][0]=2,blockpos[3][1]=1;
                   break;
           case 4: blockpos[3][0]=3,blockpos[3][1]=2;
                   break;
           case 3: blockpos[3][0]=2,blockpos[3][1]=3;
                   break;
       }
   }
    if((block1comp>3)&&(block2comp>3))
       {
           blockpos[0][0]+=blockpos[1][0];
           blockpos[1][0]=blockpos[0][0]-blockpos[1][0];
           blockpos[0][0]-=blockpos[1][0];
           blockpos[0][1]+=blockpos[1][1];
           blockpos[1][1]=blockpos[0][1]-blockpos[1][1];
           blockpos[0][1]-=blockpos[1][1];
       }
}

void blockmapassign()
{
    srand((unsigned) time(0));
    int blockfact;
    blockfact=rand()%11+1;
    for(int i=0;i<4;i++)
        blockposmap[i][0]=blockpos[i][0],blockposmap[i][1]=blockpos[i][1]+blockfact;

}

void nxtblockassign()
{
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            nxtblock[i][j]=0;
    for(int i=0;i<4;i++)
        nxtblock[blockpos[i][0]][blockpos[i][1]]=1;
}

void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}

void mapassign()
{
    for(int i=0;i<19;i++)
        for( int j=0;j<15;j++)
            if(map[i][j]!=2)
                map[i][j]=0;
    for(int i=0;i<15;i++)
        if(map[3][i]==2)
            play=false;
    for(int i=0;i<4;i++)
    {
        map[blockposmap[i][0]][blockposmap[i][1]]=1;
    }
}
void clears()
{
    system("cls");
}

int down()
{
    for(int i=0;i<4;i++)
        if((blockposmap[i][0]>17)||(map[blockposmap[i][0]+1][blockposmap[i][1]]==2))
        {
            statue();
            return 0;
        }

    for(int i=0;i<4;i++)
        blockposmap[i][0]++;
    return 0;

}

void statue()
{
    for(int i=0;i<4;i++)
        map[blockposmap[i][0]][blockposmap[i][1]]=2,blockposmap[i][0]=0,blockposmap[i][1]=0;
    nxblock++;
    score+=4;
}

int right()
{
    for(int i=0;i<4;i++)
        if((blockposmap[i][1]==14)||(map[blockposmap[i][0]][blockposmap[i][1]+1]==2))
          return 0;
    for(int i=0;i<4;i++)
        blockposmap[i][1]+=1;
    return 0;
}

int left()
{
    for(int i=0;i<4;i++)
        if((blockposmap[i][1]==0)||(map[blockposmap[i][0]][blockposmap[i][1]-1]==2))
          return 0;
    for(int i=0;i<4;i++)
        blockposmap[i][1]-=1;
    return 0;
}

int rotateacl()
{
    for(int i=1;i<4;i++)
        if(rotatecalc(blockposmap[i][0],blockposmap[i][1],1,-1))
            return 0;
    for(int i=1;i<4;i++)
    {
        rotatecalc(blockposmap[i][0],blockposmap[i][1],1,-1);
        blockposmap[i][0]=blockroty;
        blockposmap[i][1]=blockrotx;
    }
    return 0;
}

int rotatecl()
{
    for(int i=1;i<4;i++)
        if(rotatecalc(blockposmap[i][0],blockposmap[i][1],-1,1))
            return 0;
    for(int i=1;i<4;i++)
    {
        rotatecalc(blockposmap[i][0],blockposmap[i][1],-1,1);
        blockposmap[i][0]=blockroty;
        blockposmap[i][1]=blockrotx;
    }
    return 0;
}
bool rotatecalc(int blocky,int blockx,int dir,int dir1)
{
        int swapno=0;                                       //(a,b) become; (b,-a)
        blockroty=(blocky-blockposmap[0][0])*dir;
        blockrotx=(blockx-blockposmap[0][1])*dir1;             //swapno=a
        swapno=blockroty;                               //a=b
        blockroty=blockrotx;                            //b=-a
        blockrotx=swapno;
        blockrotx+=blockposmap[0][1];
        blockroty+=blockposmap[0][0];
    if((map[blockroty][blockrotx]==2)||(blockroty>18)||(blockrotx<0)||(blockrotx>14))
        return true;
    else
        return false;
}
void printmap()
{

    for(int i=0;i<22;i++)
        cout<<"* ";
    cout<<endl;
    for(int i=0;i<19;i++)
    {
        cout<<"* ";
        if(i==4)
        {
            for(int z=0;z<21;z++)
                cout<<"* ";
            cout<<endl<<"* ";
        }

            for(int j=0;j<15;j++)
                texture(map[i][j]);
            cout<<"* ";

            for(int k=0;k<4;k++)
            {
                if(i<4)
                    texture(nxtblock[i][k]);
                if(i==4)
                {
                    cout<<setw(4)<<score<<"    ";
                    break;
                }
                if(i>=5)
                    cout<<"  ";
            }
            cout<<"*  "<<endl;
    }
    for(int i=0;i<22;i++)
        cout<<"* ";
    cout<<endl;
}

void texture(int tex)
{
    switch(tex)
    {
        case 0:cout<<"  ";
                break;
        case 1:
        case 2:cout<<"# ";
    }

}
