#include <bits/stdc++.h>
using namespace std;

char pl,cl;
char board[3][3]; 

struct Move
{
	int row,col;
};


//function to check if player won or not
bool isWin(char pl,char board[3][3])
{
	//check for rows
	for(int i=0;i<3;i++)
	{
		if(board[i][0]==pl && board[i][1]==pl && board[i][2]==pl)
			return true;
	}

	//check for columns
	for(int i=0;i<3;i++) 
	{
		if(board[0][i]==pl && board[1][i]==pl && board[2][i]==pl)
			return true;
	}

	//check for diagonals
	if(board[0][0]==pl && board[1][1]==pl && board[2][2]==pl)
		return true;

	if(board[0][2]==pl && board[1][1]==pl && board[2][0]==pl)
		return true;

	return false;
}



//function to check if board is over or not
bool isOver(char board[3][3])
{
	for(int i=0;i<3;i++) 
	{
		for(int j=0;j<3;j++) 
		{
			if(board[i][j]==' ')
				return false;
		}
	}
	return true;
}


//function to calculate score
int score(char p,int depth,char board[3][3])
{
	if(p==pl && isWin(p,board)==true) 
	{
		return 10-depth;
	}
	else if(p==cl && isWin(p,board)==true)
		return depth-10;
	else 
		return 0;
}

//function to apply minimax algorithm
int minimax(char board[3][3],int depth,char p) {
	int sc=score(p,depth,board);
	if(sc!=0)
		return sc;
	if(isOver(board)==true && sc==0)
		return 0;
	if(p==pl) {
		int best=-100;
		for(int i=0;i<3;i++) 
		{
			for(int j=0;j<3;j++) 
			{
				if(board[i][j]==' ') 
				{
					board[i][j]=p;
					best=max(best,minimax(board,depth+1,cl));
					board[i][j]=' ';
				}
			}
		}
		return best;
	}
	else if(p==cl)
	{
		int best=100;
		for(int i=0;i<3;i++) {
			for(int j=0;j<3;j++) {
				if(board[i][j]==' ')
				{
					board[i][j]=p;
					best=min(best,minimax(board,depth+1,pl));
					board[i][j]=' ';
				}
			}
		}
		return best;
	}
}

//function to calculate best move
Move FindBestMove(char board[3][3],char p) 
{
	Move best;
	int val=-1000;
	best.row=-1;
	best.col=-1;
	int i,j;
	for(i=0;i<3;i++) 
	{
		for(j=0;j<3;j++) 
		{
			if(board[i][j]==' ') 
			{
				board[i][j]=p; //make the move
				int value=minimax(board,0,cl); //start with the minimizing player
				board[i][j]=' '; //undo move

				//find the best move by calculating one giving highest positive return value
				if(value>val) 
				{
					best.row=i;
					best.col=j;
					val=value;
				}
			}
		}
	}
	return best;
}




//function to print board
void Draw()
{
	for(int i=0;i<3;i++) {
		for(int j=0;j<3;j++) {
			cout<<"|"<<board[i][j]<<"|";
		}
		cout<<endl;
		cout<<"---------";
		cout<<endl;
	}
}

//function to print opponent's moves
void Opponent(char board[3][3],char p)
{
	int x,y;
	cout<<"Enter x coordinate of the row u want to insert\n";
	cin>>x;
	cout<<"Enter y coordinate of the column u want to insert\n";
	cin>>y;
	if(board[x][y]==' ')
		board[x][y]=p;
	else {
		cout<<"Wrong Move! Exiting game !!!";
		exit(0);
	}
	Draw();
} 

//The main function
int main()
{
	char p;
	cout<<"Enter Your Choice: X or O"<<endl;
	cin>>cl;
	pl=(cl=='X')?'O':'X'; //pl is the computer player,cl is user
	
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			board[i][j]=' ';
		}
	}
	Draw();

	//Loop untill board is over
	while(!isOver(board))
	{
		if(pl=='X')
		{
			Move best=FindBestMove(board,pl);
			
			board[best.row][best.col]=pl;
			cout<<"\n\n\n";
			Draw();
			if(isWin(pl,board))
				break;
			cout<<"\n\n\n";
			if(!isOver(board))
				Opponent(board,cl);
			cout<<"\n\n\n";
			if(isWin(cl,board))
				break;
		}
		if(pl=='O')
		{
			cout<<"\n\n\n";
			Opponent(board,cl);
			if(isWin(cl,board))
				break;
			cout<<"\n\n\n";
			if(!isOver(board)) {
				Move best=FindBestMove(board,pl);
				board[best.row][best.col]=pl;
				
				Draw();
			}
			if(isWin(pl,board))
				break;
			cout<<"\n\n\n";
		}
	}
	if(isWin(pl,board)==true)
		cout<<"Computer Wins\n";
	else if(isWin(cl,board)==true)
		cout<<"You Win\n";
	else 
		cout<<"Draw\n";
	cout<<"GAME OVER\n";
}
