#include <iostream>
#include<stdlib.h>
#include<iomanip>
#include<ctime>
#include<conio.h>
#include<time.h>
#include<fstream>


using namespace std;
void printmap(void);
void assign(void);
void initial(bool);
void texture(int ,int);
void updatemap(void);
void changedir(char);
void move(int,int);
void clear(void);
void delay(unsigned int);
void collision(int ,int);
void generatefood(void);
void eat(int,int);
void cheat(void);

int map[20][20];
int snake[400];
int  food;
int headposx,headposy;
bool run;
int _kbhit( void );
char dir;
int xpos,ypos;
int direction;
int foodx,foody;
int oldfood;
int speed;
int foodpos,k;
int highscore=0;
int highscorefile,highscorefile2;


int main()
{
    bool home=true;
    bool play=true;
    while(play)
    {
        initial(home);
        printmap();
        while(run)
        {
            delay(speed);
            updatemap();
            clear();
            printmap();


        }
        clear();
        cout<<"\n\n\n\n\n\n\n\n\t\t\t  Game Over \n\t\t\t Score = "<<setw(3)<<(food-3)<<"\n";
        delay(1000);
        cout<<"\t\t Do you want to continue(y/n) ";
        char ch;
        home=false;
        ch=_getch();
        if(ch=='Y'||ch=='y')
            play=true;
        else
            play=false;
        if((food-3)>highscore)
        {
            highscore=(food-3);
            int spot,tot;
            srand((unsigned) time(0));
            tot=((rand()%100)+3);
            spot=(rand()%tot);
            highscorefile=(highscore<<2);
            highscorefile2=highscorefile*spot;
            ofstream myfile ;
            myfile.open("gamedata.dat");
            if(myfile.is_open())
            {
                myfile << (spot<<3)<<'\n';
                myfile << (tot<<1)<<'\n';
                for(int i=0;i<=tot;i++)
                {
                    if(i==spot)
                        myfile<<highscorefile<<'\n';
                    else
                        myfile<<(rand()%400)<<'\n';
                }
                myfile << highscorefile2;
                myfile.close();
            }
        }

        clear();
    }
    return 0;

}
void initial(bool home)
{
    int spot=0,tot=0,i=0,junk=0;
    headposx=10,headposy=10,food=3,direction=0,foodx=0,foody=0,oldfood=3,speed=150;
    ifstream myfile ;
    myfile.open("gamedata.dat");
    if(myfile.is_open())
    {
        myfile >> spot ;
        myfile >>tot;
        spot=(spot>>3);
        tot=(tot>>1);
        for(i=0;i<=(tot+1);i++)
        {
            if(myfile.eof())
                break;
            if(i==spot)
            myfile>>highscorefile;
            else
            myfile>>junk;
        }
        myfile.close();
    }
    highscore=(highscorefile>>2);
    ifstream ryfile ;
    ryfile.open("gamedata.dat");
    if((i!=(tot+2))&&ryfile.is_open()&&(junk!=(spot*highscorefile)))
      cheat();


    if(home)
    {
       cout<<"\n\n\n\n\n\n\n\n\t\t### #   # ##### #  # ####";
        cout<<"\n\t\t#   ##  # #   # # #  #";
        cout<<"\n\t\t### # # # ##### ##   ###";
        cout<<"\n\t\t  # #  ## #   # # #  #";
        cout<<"\n\t\t### #   # #   # #  # ####";
        cout<<"\n\n\t\t     Created by KP\n\t\t";
        system("pause");
    }
    for(int i=0;i<400;i++)
        snake[i]=0;
    snake[0]=(headposx*100)+headposy;
    snake[1]=((headposx-1)*100)+headposy;
    snake[2]=((headposx-2)*100)+headposy;
    run=true;
}

void printmap()
{
    assign();
    for(int i=0;i<22;i++)
        cout<<"* ";
    cout<<"\n*   Score   *  # #   ###  *   Highscore   *";
    cout<<"\n* * * * * * *  ##    ###  * * * * * * * * *\n";
    cout<<"*   "<<setw(3)<<(food-3)<<"     *  # #   #    *    ";
    if((food-3)<highscore)
        cout<<setw(3)<<highscore<<"        *\n";
    else
        cout<<setw(3)<<(food-3) <<"        *\n";
    for(int i=0;i<22;i++)
        cout<<"* ";
    cout<<endl;
    for(int i=0;i<20;i++)
    {
        cout<<"* ";
        for(int j=0;j<20;j++)
            texture(i,j);
        cout<<"* \n";
    }
    for(int i=0;i<22;i++)
        cout<<"* ";
    if(!run)
        delay(1000);
}

void assign()
{
    int x,y;
    y=snake[0]%100;
    x=snake[0]/100;
    collision(x,y);

    if(run)
     {
         for(int i=0;i<20;i++)
            for(int j=0;j<20;j++)
                map[i][j]=0;

        for(int i=1;i<food;i++)
        {
            y=snake[i]%100;
            x=snake[i]/100;
            map[y][x]=3;
        }
        y=snake[0]%100;
        x=snake[0]/100;
        map[y][x]=1;
        while(oldfood==food)
        {
            generatefood();
        }
        map[foody][foodx]=2;
        eat(x,y);
     }
}

void texture(int i, int j)
{
    switch(map[i][j])
    {
        case 0:cout<<"  ";
               break;
        case 3:cout<<"# ";
                break;
        case 1:cout<<"O ";
               break;
        default:cout<<"X ";
    }


}

void updatemap()
{
    if(_kbhit())
    {
        dir=_getch();
        changedir(dir);
    }
    switch(direction)
    {
        case 0:move(0,-1);
                 break;
        case 1:move(-1,0);
                 break;
        case 2:move(0,1);
                 break;
        case 3:move(1,0);
                 break;
    }
}

void changedir(char dir)
{
    switch(dir)
    {
        case 'w':if(direction!=2)
                    direction=0;
                 break;
        case 'd':if(direction!=1)
                    direction=3;
                 break;
        case 's':if(direction!=0)
                    direction=2;
                 break;
        case 'a':if(direction!=3)
                    direction=1;
                 break;
    }

}

void move(int xpos,int ypos)
{
    headposx+=xpos;
    headposy+=ypos;
    for(int i=food;i>0;i--)
        snake[i]=snake[i-1];
    snake[food]=0;
    snake[0]=(headposx*100)+headposy;
     for(int j=3;j<food;j++)
            if(snake[j]==snake[0])
                run=false;
}

void eat(int x,int y)
{
    if(map[headposy][headposx]==2)
    {
        food++;
        if((food-3)%10==0&&speed>50)
            speed-=10;
    }
}
void collision(int x,int y)
{
        if(x>19||x<0||y<0||y>19)
            run=false;
}

void generatefood()
{
    int i,j,k,foodpos=0;
    srand((unsigned) time(0));
    k=(rand()%200);
    k+=(rand()%200);
    k=((k*rand())%(401-food));
    while(foodpos<k)
    {
        for(i=0;i<20;i++)
        {
           for(j=0;j<20;j++)
           {

               if(map[i][j]==0)
                    foodpos++;
                if(foodpos==k)
                {
                    foodx=j;
                    foody=i;
                    foodpos++;
                    break;

                }
           }
        }
    }
    oldfood++;
}

void clear()
{
    system("cls");
}

void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}
void cheat()
{
    int a=0;
   ofstream myfile ;
    myfile.open("gamedata.dat");
    if(myfile.is_open())
    {
      myfile << a <<'\n' ;
      myfile << a <<'\n' ;
      myfile << (a+2) <<'\n';

        myfile.close();
    }
    highscore=0;
    highscorefile=0;
    cout<<"\n\n\n\n\n\n\n\n\t\tYou Have Failed at Decrypting \n\t\t\t Better Luck Next time \n";
    delay(5000);
    clear();
}
