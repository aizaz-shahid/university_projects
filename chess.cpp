#include <iostream>
#include <conio.h>
#include <string>
#include <typeinfo>
using namespace std;
class piece
{
	string sign;
public:
	piece()
	{
		sign = "___";
	}
	virtual void setSign(string ch)
	{
		sign = ch;
	}
	virtual int getSign0()
	{
		int x=0;
		x=sign[0];
		x=x-48;
		return x;
	}
	virtual char getSign1()
	{
		return sign[1];
	}
	virtual	void display()
	{
		cout << sign;
	}
};
class king :public piece
{
	string sign;
public:
	king(string ch)
	{
		sign = ch;
	}
	virtual void setSign(string ch)
	{
		sign = ch;
	}
	virtual int getSign0()
	{
		int x=0;
		x=sign[0];
		x=x-48;
		return x;
	}
	virtual char getSign1()
	{
		return sign[1];
	}
	virtual	void display()
	{
		cout << sign;
	}
};
class queen :public piece
{
	string sign;
public:
	queen(string ch)
	{
		sign = ch;
	}
	virtual void setSign(string ch)
	{
		sign = ch;
	}
	virtual int getSign0()
	{
		int x=0;
		x=sign[0];
		x=x-48;
		return x;
	}
	virtual char getSign1()
	{
		return sign[1];
	}
	virtual	void display()
	{
		cout << sign;
	}
};
class ghora :public piece
{
	string sign;
public:
	ghora(string ch)
	{
		sign = ch;
	}
	virtual void setSign(string ch)
	{
		sign = ch;
	}
	virtual int getSign0()
	{
		int x=0;
		x=sign[0];
		x=x-48;
		return x;
	}
	virtual char getSign1()
	{
		return sign[1];
	}
	virtual	void display()
	{
		cout << sign;
	}
};
class feel :public piece
{
	string sign;
public:
	feel(string ch)
	{
		sign = ch;
	}
	virtual void setSign(string ch)
	{
		sign = ch;
	}
	virtual int getSign0()
	{
		int x=0;
		x=sign[0];
		x=x-48;
		return x;
	}
	virtual char getSign1()
	{
		return sign[1];
	}
	virtual	void display()
	{
		cout << sign;
	}
};
class Rooks :public piece
{
	string sign;
public:
	Rooks(string ch)
	{
		sign = ch;
	}
	virtual void setSign(string ch)
	{
		sign = ch;
	}
	virtual int getSign0()
	{
		int x=0;
		x=sign[0];
		x=x-48;
		return x;
	}
	virtual char getSign1()
	{
		return sign[1];
	}
	virtual	void display()
	{
		cout << sign;
	}
};
class pyada :public piece
{
	string sign;
public:
	pyada(string ch)
	{
		sign = ch;
	}
	virtual void setSign(string ch)
	{
		sign = ch;
	}
	virtual int getSign0()
	{
		int x=0;
		x=sign[0];
		x=x-48;
		return x;
	}
	virtual char getSign1()
	{
		return sign[1];
	}
	virtual	void display()
	{
		cout << sign;
	}
};
void display(piece *** ptr);
bool playerSelection(piece *** ptr,int count,int i,int j);
bool moveIsValid(piece *** ptr,int count,int i,int j,int k,int l);
void initialize(piece *** ptr);
void move(piece ***ptr, int count);


int main()
{
	bool gameOver = false;
	piece *** gb;
	gb = new piece **[8];
	for (int i = 0; i < 8; i++)
	{
		gb[i] = new piece *[8];
	}
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			gb[i][j] = new piece;
		}
	}
	initialize(gb);
	display(gb);



	int count = 0;
	while (gameOver != true)
	{
		if (count % 2 == 0)
			cout << "Player 1's turn" << endl;
		else
			cout << "Player 2's turn" << endl;
		move(gb, count);
		system("CLS");
		display(gb);
		count++;
	}
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			delete gb[i][j];
			gb[i][j] = NULL;
		}
		delete[] gb[i];
		gb[i] = NULL;
	}
	delete[] gb;
	gb = NULL;
	//getch();
	return 0;
}

void display(piece *** ptr)
{
	cout<<endl<<endl;
	cout<<"\t\t\t\t Guide Line"<<endl<<endl;
	cout<<"Use letters A-H for rows and numbers 0-7 for columns"<<endl<<endl<<endl<<endl<<endl<<endl;
	int cols[8]={0,1,2,3,4,5,6,7};
	char rows[8]={'A','B','C','D','E','F','G','H'};
	cout<<"\t";
	for(int i=0;i<8;i++)
	{
		cout<<cols[i]<<"\t";
	}
	cout<<endl<<endl;
	cout<<"   _________________________________________________________________"<<endl<<endl;
	
	
	
	for (int i = 0; i < 8; i++)
	{
		cout<<rows[i]<<" | \t";
		for (int j = 0; j < 8; j++)
		{
			ptr[i][j]->display();
			cout << "\t";
		}
		cout << endl << endl << endl;
	}
}

void move(piece ***ptr, int count)
{
	bool moveMade;
	moveMade=false;
	string from, to;
	int i = 0, j = 0, k = 0, l = 0;
	do
	{
	
		cout << "enter the position of the piece you want to move" << endl;
		cin >> from;
		cout << "enter the position where you want to place the piece" << endl;
		cin >> to;
		if (from[0] == 'A' || from[0] == 'a')
			i = 0;
		else if (from[0] == 'B' || from[0] == 'b')
			i = 1;
		else if (from[0] == 'C' || from[0] == 'c')
			i = 2;
		else if (from[0] == 'D' || from[0] == 'd')
			i = 3;
		else if (from[0] == 'E' || from[0] == 'e')
			i = 4;
		else if (from[0] == 'F' || from[0] == 'f')
			i = 5;
		else if (from[0] == 'G' || from[0] == 'g')
			i = 6;
		else if (from[0] == 'H' || from[0] == 'h')
			i = 7;
		j = from[1];
		j = j - 48;
		
		if (to[0] == 'A' || to[0] == 'a')
			k = 0;
		else if (to[0] == 'B' || to[0] == 'b')
			k = 1;
		else if (to[0] == 'C' || to[0] == 'c')
			k = 2;
		else if (to[0] == 'D' || to[0] == 'd')
			k = 3;
		else if (to[0] == 'E' || to[0] == 'e')
			k = 4;
		else if (to[0] == 'F' || to[0] == 'f')
			k = 5;
		else if (to[0] == 'G' || to[0] == 'g')
			k = 6;
		else if (to[0] == 'H' || to[0] == 'h')
			k = 7;
		l = to[1];
		l = l - 48;
		if(playerSelection(ptr,count,i,j) && moveIsValid(ptr,count,i,j,k,l))
		{
			
			if (typeid(*ptr[k][l]) == typeid(king))
			{
				delete ptr[k][l];
				ptr[k][l] = NULL;
				ptr[k][l] = ptr[i][j];
				ptr[i][j] = new piece;
				moveMade=true;
				display(ptr);
				if (count % 2 == 0)
					cout << "Player 1 won the game" << endl;
				else
					cout << "Player 2 won the game" << endl;
				exit(0);
			}
			else
			{
				delete ptr[k][l];
				ptr[k][l] = NULL;
				ptr[k][l] = ptr[i][j];
				ptr[i][j] = new piece;
				moveMade=true;
			}
		}
		else
		{
			cout<<"Move is invalid"<<endl;
		}
		
	}while(!moveMade);


}

bool playerSelection(piece *** ptr,int count,int i,int j)
{
	int x=0;
	x=ptr[i][j]->getSign0();
	if (count % 2 == 0 && x == 1)
		return true;
	else if(count % 2 !=0 && x == 2)
		return true;
	else
		return false;
}

bool moveIsValid(piece *** ptr,int count,int i,int j,int k,int l)
{
	if((i>7 || i<0) || (j>7 || j<0) || (k>7 || k<0) || (l>7 || l<0))
	{
		return false;
	}
	else if(ptr[i][j]->getSign0() == ptr[k][l]->getSign0())
	{
		return false;
	}
	else if(ptr[i][j]->getSign1() == 'P')
	{
		if (count % 2 == 0)
		{
			if(k!=(i+1) || l!=j)
			{
				if((k==(i+1) && l==(j+1)) || (k==(i+1) && l==(j-1)))
				{
					if(typeid(*ptr[k][l]) == typeid(piece))
					{
						return false;
					}
					else
					{
						return true;
					}
				}
				else
				{
					return false;
				}
			}
			else
			{
				if(typeid(*ptr[k][l]) != typeid(piece))
				{
					return false;
				}
				else
				{
					return true;
				}
			}
		}
		else
		{
			if(k!=(i-1) || l!=j)
			{
				if((k==(i-1) && l==(j+1)) || (k==(i-1) && l==(j-1)))
				{
					if(typeid(*ptr[k][l]) == typeid(piece))
					{
						return false;
					}
					else
					{
						return true;
					}
				}
				else
				{
					return false;
				}
			}
			else
			{
				if(typeid(*ptr[k][l]) != typeid(piece))
				{
					return false;
				}
				else
				{
					return true;
				}
			}
		}
	}
	else if(ptr[i][j]->getSign1() == 'G')
	{
		if((k==(i-2) && l==(j+1)) || (k==(i-2) && l==(j-1)) || (k==(i+2) && l==(j+1)) || (k==(i+2) && l==(j-1)) || (k==(i-1) && l==(j+2)) || (k==(i-1) && l==(j-2)) || (k==(i+1) && l==(j+2)) || (k==(i+1) && l==(j-2)))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else if(ptr[i][j]->getSign1() == 'R')
	{
		for(int x=i,y=j ; (x>=0 && x<=7) && (y>=0 && y<=7) ; x++)
		{
			if(x==k && y==l)
			{
				for(int x=i+1,y=j ; (x>=0 && x<=7) && (y>=0 && y<=7) ; x++)
				{
					if(x==k && y==l)
					{
						return true;
					}
					else if(typeid(*ptr[x][y]) != typeid(piece))
					{
						return false;
					}
				}
			}
		}
		for(int x=i,y=j ; (x>=0 && x<=7) && (y>=0 && y<=7) ; x--)
		{
			if(x==k && y==l)
			{
				for(int x=i-1,y=j ; (x>=0 && x<=7) && (y>=0 && y<=7) ; x--)
				{
					if(x==k && y==l)
					{
						return true;
					}
					else if(typeid(*ptr[x][y]) != typeid(piece))
					{
						return false;
					}
				}
			}
		}
		for(int x=i,y=j ; (x>=0 && x<=7) && (y>=0 && y<=7) ; y++)
		{
			if(x==k && y==l)
			{
				for(int x=i,y=j+1 ; (x>=0 && x<=7) && (y>=0 && y<=7) ; y++)
				{
					if(x==k && y==l)
					{
						return true;
					}
					else if(typeid(*ptr[x][y]) != typeid(piece))
					{
						return false;
					}
				}
			}
		}
		for(int x=i,y=j ; (x>=0 && x<=7) && (y>=0 && y<=7) ; y--)
		{
			if(x==k && y==l)
			{
				for(int x=i,y=j-1 ; (x>=0 && x<=7) && (y>=0 && y<=7) ; y--)
				{
					if(x==k && y==l)
					{
						return true;
					}
					else if(typeid(*ptr[x][y]) != typeid(piece))
					{
						return false;
					}
				}
			}
		}
	}
	else if(ptr[i][j]->getSign1() == 'K')
	{
		if(k!=(i+1) || l!=j)
			{
				if((k==(i+1) && l==(j+1)) || (k==(i+1) && l==(j-1)))
				{
					return true;
				}
				else
				{
					return false;
				}
			}
			else
			{
				return true;
			}
	}
	else if(ptr[i][j]->getSign1() == 'F')
	{
		for(int x=i,y=j ; (x>=0 && x<=7) && (y>=0 && y<=7) ; x++,y++)
		{
			if(x==k && y==l)
			{
				for(int x=i+1,y=j+1 ; (x>=0 && x<=7) && (y>=0 && y<=7) ; x++,y++)
				{
					if(x==k && y==l)
					{
						return true;
					}
					else if(typeid(*ptr[x][y]) != typeid(piece))
					{
						return false;
					}
				}
			}
		}
		for(int x=i,y=j ; (x>=0 && x<=7) && (y>=0 && y<=7) ; x++,y--)
		{
			if(x==k && y==l)
			{
				for(int x=i+1,y=j-1 ; (x>=0 && x<=7) && (y>=0 && y<=7) ; x++,y--)
				{
					if(x==k && y==l)
					{
						return true;
					}
					if(typeid(*ptr[x][y]) != typeid(piece))
					{
						return false;
					}
				}
			}
		}
		for(int x=i,y=j ; (x>=0 && x<=7) && (y>=0 && y<=7) ; x--,y++)
		{
			if(x==k && y==l)
			{
				for(int x=i-1,y=j+1 ; (x>=0 && x<=7) && (y>=0 && y<=7) ; x--,y++)
				{
					if(x==k && y==l)
					{
						return true;
					}
					if(typeid(*ptr[x][y]) != typeid(piece))
					{
						return false;
					}
				}
			}
		}
		for(int x=i,y=j ; (x>=0 && x<=7) && (y>=0 && y<=7) ; x--,y--)
		{
			if(x==k && y==l)
			{
				for(int x=i-1,y=j-1 ; (x>=0 && x<=7) && (y>=0 && y<=7) ; x--,y--)
				{
					if(x==k && y==l)
					{
						return true;
					}
					if(typeid(*ptr[x][y]) != typeid(piece))
					{
						return false;
					}
				}
			}
		}
		
		return false;
	}
	else if(ptr[i][j]->getSign1() == 'Q')
	{
		for(int x=i,y=j ; (x>=0 && x<=7) && (y>=0 && y<=7) ; x++)
		{
			if(x==k && y==l)
			{
				for(int x=i+1,y=j ; (x>=0 && x<=7) && (y>=0 && y<=7) ; x++)
				{
					if(x==k && y==l)
					{
						return true;
					}
					else if(typeid(*ptr[x][y]) != typeid(piece))
					{
						return false;
					}
				}
			}
		}
		for(int x=i,y=j ; (x>=0 && x<=7) && (y>=0 && y<=7) ; x--)
		{
			if(x==k && y==l)
			{
				for(int x=i-1,y=j ; (x>=0 && x<=7) && (y>=0 && y<=7) ; x--)
				{
					if(x==k && y==l)
					{
						return true;
					}
					else if(typeid(*ptr[x][y]) != typeid(piece))
					{
						return false;
					}
				}
			}
		}
		for(int x=i,y=j ; (x>=0 && x<=7) && (y>=0 && y<=7) ; y++)
		{
			if(x==k && y==l)
			{
				for(int x=i,y=j+1 ; (x>=0 && x<=7) && (y>=0 && y<=7) ; y++)
				{
					if(x==k && y==l)
					{
						return true;
					}
					else if(typeid(*ptr[x][y]) != typeid(piece))
					{
						return false;
					}
				}
			}
		}
		for(int x=i,y=j ; (x>=0 && x<=7) && (y>=0 && y<=7) ; y--)
		{
			if(x==k && y==l)
			{
				for(int x=i,y=j-1 ; (x>=0 && x<=7) && (y>=0 && y<=7) ; y--)
				{
					if(x==k && y==l)
					{
						return true;
					}
					else if(typeid(*ptr[x][y]) != typeid(piece))
					{
						return false;
					}
				}
			}
		}
		for(int x=i,y=j ; (x>=0 && x<=7) && (y>=0 && y<=7) ; x++,y++)
		{
			if(x==k && y==l)
			{
				for(int x=i+1,y=j+1 ; (x>=0 && x<=7) && (y>=0 && y<=7) ; x++,y++)
				{
					if(x==k && y==l)
					{
						return true;
					}
					else if(typeid(*ptr[x][y]) != typeid(piece))
					{
						return false;
					}
				}
			}
		}
		for(int x=i,y=j ; (x>=0 && x<=7) && (y>=0 && y<=7) ; x++,y--)
		{
			if(x==k && y==l)
			{
				for(int x=i+1,y=j-1 ; (x>=0 && x<=7) && (y>=0 && y<=7) ; x++,y--)
				{
					if(x==k && y==l)
					{
						return true;
					}
					if(typeid(*ptr[x][y]) != typeid(piece))
					{
						return false;
					}
				}
			}
		}
		for(int x=i,y=j ; (x>=0 && x<=7) && (y>=0 && y<=7) ; x--,y++)
		{
			if(x==k && y==l)
			{
				for(int x=i-1,y=j+1 ; (x>=0 && x<=7) && (y>=0 && y<=7) ; x--,y++)
				{
					if(x==k && y==l)
					{
						return true;
					}
					if(typeid(*ptr[x][y]) != typeid(piece))
					{
						return false;
					}
				}
			}
		}
		for(int x=i,y=j ; (x>=0 && x<=7) && (y>=0 && y<=7) ; x--,y--)
		{
			if(x==k && y==l)
			{
				for(int x=i-1,y=j-1 ; (x>=0 && x<=7) && (y>=0 && y<=7) ; x--,y--)
				{
						if(x==k && y==l)
					{
						return true;
					}
					if(typeid(*ptr[x][y]) != typeid(piece))
					{
						return false;
					}
				}
			}
		}
			
		return false;
	}
	
	
	return true;
}



void initialize(piece *** gb)
{
	delete gb[0][0];
	delete gb[0][1];
	delete gb[0][2];
	delete gb[0][3];
	delete gb[0][4];
	delete gb[0][5];
	delete gb[0][6];
	delete gb[0][7];
	delete gb[1][7];
	delete gb[1][6];
	delete gb[1][5];
	delete gb[1][4];
	delete gb[1][3];
	delete gb[1][2];
	delete gb[1][1];
	delete gb[1][0];
	delete gb[6][0];
	delete gb[6][1];
	delete gb[6][2];
	delete gb[6][3];
	delete gb[6][4];
	delete gb[6][5];
	delete gb[6][6];
	delete gb[6][7];
	delete gb[7][0];
	delete gb[7][1];
	delete gb[7][2];
	delete gb[7][3];
	delete gb[7][4];
	delete gb[7][5];
	delete gb[7][6];
	delete gb[7][7];




	gb[0][0] = NULL;
	gb[0][1] = NULL;
	gb[0][2] = NULL;
	gb[0][3] = NULL;
	gb[0][4] = NULL;
	gb[0][5] = NULL;
	gb[0][6] = NULL;
	gb[0][7] = NULL;
	gb[1][7] = NULL;
	gb[1][6] = NULL;
	gb[1][5] = NULL;
	gb[1][4] = NULL;
	gb[1][3] = NULL;
	gb[1][2] = NULL;
	gb[1][1] = NULL;
	gb[1][0] = NULL;
	gb[6][0] = NULL;
	gb[6][1] = NULL;
	gb[6][2] = NULL;
	gb[6][3] = NULL;
	gb[6][4] = NULL;
	gb[6][5] = NULL;
	gb[6][6] = NULL;
	gb[6][7] = NULL;
	gb[7][0] = NULL;
	gb[7][1] = NULL;
	gb[7][2] = NULL;
	gb[7][3] = NULL;
	gb[7][4] = NULL;
	gb[7][5] = NULL;
	gb[7][6] = NULL;
	gb[7][7] = NULL;

	gb[0][0] = new Rooks("1R");
	gb[0][1] = new ghora("1G");
	gb[0][2] = new feel("1F");
	gb[0][3] = new king("1K");
	gb[0][4] = new queen("1Q");
	gb[0][5] = new feel("1F");
	gb[0][6] = new ghora("1G");
	gb[0][7] = new Rooks("1R");
	gb[1][7] = new pyada("1P");
	gb[1][6] = new pyada("1P");
	gb[1][5] = new pyada("1P");
	gb[1][4] = new pyada("1P");
	gb[1][3] = new pyada("1P");
	gb[1][2] = new pyada("1P");
	gb[1][1] = new pyada("1P");
	gb[1][0] = new pyada("1P");
	gb[6][0] = new pyada("2P");
	gb[6][1] = new pyada("2P");
	gb[6][2] = new pyada("2P");
	gb[6][3] = new pyada("2P");
	gb[6][4] = new pyada("2P");
	gb[6][5] = new pyada("2P");
	gb[6][6] = new pyada("2P");
	gb[6][7] = new pyada("2P");
	gb[7][0] = new Rooks("2R");
	gb[7][1] = new ghora("2G");
	gb[7][2] = new feel("2F");
	gb[7][3] = new king("2K");
	gb[7][4] = new queen("2Q");
	gb[7][5] = new feel("2F");
	gb[7][6] = new ghora("2G");
	gb[7][7] = new Rooks("2R");
	
}
	
	
	
