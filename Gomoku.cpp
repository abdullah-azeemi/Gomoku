#include <iostream>
#include<conio.h>
#include<fstream>
#include<windows.h>
#include<iomanip>

using namespace std;

#define capacity 500
void my_sleep(float num)
{
	for (double x = 0; x < 100000 * num; x++);
}
void init(char Board[][capacity], char P_sym[], int& dim, int& Nop, char P_name[][100], int& turn, char default_Sym, int& win_count)
{
	cout << "\n Enter Dimensions : ";
	cin >> dim;

	for (int ri = 0; ri < dim; ri++)
	{
		for (int ci = 0; ci < dim; ci++)
		{
			Board[ri][ci] = default_Sym;
		}
	}
	cout << "\n Enter the number of players : ";
	cin >> Nop;
	for (int i = 0; i < Nop; i++)
	{
		cout << "\n Enter the player's " << i + 1 << " name : ";
		cin >> P_name[i];
		cout << "\n Enter the palyer's " << i + 1 << " symbol : ";
		cin >> P_sym[i];
	}
	srand(time(0));
	turn = rand() % Nop;

	cout << "\n\n Enter the win count : ";
	cin >> win_count;
}
void print_Board(char Board[][capacity], int dim)
{
	system("cls");
	cout << "\n\n\t\t THE BOARD \n\n";

	for (int ri = 0; ri < dim; ri++)
	{
		for (int ci = 0; ci < dim; ci++)
		{
			cout << setw(3) << Board[ri][ci];
		}
		cout << "\n";
	}
}
bool isValid(char Board[][capacity], int rows, int cols, int dim, char default_sym)
{
	if (rows > dim || cols > dim || rows < 0 || cols < 0)
		return false;

	if (Board[rows][cols] != default_sym)
		return false;


	return true;
}
void player_turn(char Board[][capacity], char P_sym, int dim, int Nop, char P_name[][100], int turn, char default_sym)
{
	int rows, cols;
	cout << "\n\n " << P_name[turn] << "'s turn : ";
	cout << "\n\n Enter your Co-ordinates : ";
	do {
		cout << "\n Enter rows : ";
		cin >> rows;
		rows--;
		cout << "\n Enter Cols : ";
		cin >> cols;
		cols--;
	} while (isValid(Board, rows, cols, dim, default_sym) == false);
	Board[rows][cols] = P_sym;
}
bool check_diagonal1(char Board[][capacity], int dim, char P_sym[capacity], int turn, int win_count, int r, int c)
{
	int found = 0;
	for (int ri = r, ci = c; ri < dim, ci < dim; ri++, ci++)
	{
		if (Board[ri][ci] == P_sym[turn])
		{
			found += 1;
			if (found == win_count)
			{
				return true;
			}
		}
		else
			found = 0;
	}
	return false;
}
bool check_diagonal2(char Board[][capacity], int dim, char P_sym[capacity], int turn, int win_count, int r, int c)
{
	int found = 0;
	for (int ri = r, ci = c; ri < dim, ci >= 0; ri++, ci--)
	{
		if (Board[ri][ci] == P_sym[turn])
		{
			found += 1;
			if (found == win_count)
			{
				return true;
			}
		}
		else
			found = 0;
	}
	return false;
}
bool isWin(char Board[][capacity], char P_sym[], int dim, int turn, char default_sym, int win_count)
{
	int found;
	for (int ri = 0; ri < dim; ri++)
	{
		found = 0;
		for (int ci = 0; ci < dim; ci++)
		{
			if (Board[ri][ci] == P_sym[turn])
			{
				found += 1;
				if (found == win_count)
				{
					return true;
				}
			}
			else
				found = 0;
		}
	}

	for (int ci = 0; ci < dim; ci++)
	{
		found = 0;
		for (int ri = 0; ri < dim; ri++)
		{
			if (Board[ri][ci] == P_sym[turn])
			{
				found += 1;
				if (found == win_count)
				{
					return true;
				}
			}
			else
				found = 0;
		}
	}
	found = 0;


	for (int ri = 0; ri < dim; ri++)
	{
		for (int ci = 0; ci < dim; ci++)
		{
			if (Board[ri][ci] == P_sym[turn])
			{
				if (check_diagonal1(Board, dim, P_sym, turn, win_count, ri, ci) == true)
				{
					return true;
				}
				if (check_diagonal2(Board, dim, P_sym, turn, win_count, ri, ci) == true)
				{
					return true;
				}

			}
		}
	}
	/*for (int ri = 0; ri < dim; ri++)
	{
		for (int ci = 0; ci < dim; ci++)
		{
				if (Board[ri][ci] == P_sym[turn])
				{
					found += 1;
					if (found == win_count)
					{
						return true;
					}
				}
				else
					found = 0;
			}
		}
	}
	for (int ri = 0; ri < dim; ri++)
	{
		for (int ci = dim-1; ci >=0; ci--)
		{
			if (ri == ci)
			{
				if (Board[ri][ci] == P_sym[turn])
				{
					found += 1;
					if (found == win_count)
					{
						return true;
					}
				}
				else
					found = 0;
			}
		}
	}*/


	return false;
}


void computer_turns(char Board[][capacity], char P_sym[], int dim, int Nop, char P_name[][100], int turn, char default_sym)
{
	int rows, cols;
	cout << "\n\n Computer's turn : ";

	do {
		rows = rand() % dim;
		cols = rand() % dim;
	} while (isValid(Board, rows, cols, dim, default_sym) == false);
	Board[rows][cols] = P_sym[1];
}
void init2(char Board[][capacity], char P_sym[], int& dim, char P_name[][100], int& turn, char default_Sym, int& win_count)
{
	cout << "\n Enter Dimensions : ";
	cin >> dim;

	for (int ri = 0; ri < dim; ri++)
	{
		for (int ci = 0; ci < dim; ci++)
		{
			Board[ri][ci] = default_Sym;
		}
	}
	cout << "\n Enter the player's  name : ";
	cin >> P_name[0];
	cout << "\n Enter the player's  symbol : ";
	cin >> P_sym[0];
	cout << "\n Enter the computer's  symbol : ";
	cin >> P_sym[1];

	srand(time(0));
	turn = rand() % 2;

	cout << "\n Enter the win count : ";
	cin >> win_count;
}
bool isDraw(char Board[][capacity], char P_sym[], int dim, int turn, char default_sym, int win_count)
{
	for (int ri = 0; ri < dim; ri++)
	{
		for (int ci = 0; ci < dim; ci++)
		{
			if ((Board[ri][ci]) == default_sym)
			{
				return false;
			}
		}
	}
	return true;
}

int computer_turn(char Board[][capacity], char P_sym[], int dim, int Nop, char P_name[][100], int turn, char default_sym, int win_count)
{
	int rows, cols;
	cout << "\n\n Computer's turn : ";

	for (int ri = 0; ri < dim; ri++)
	{
		for (int ci = 0; ci < dim; ci++)
		{
			rows = ri, cols = ci;
			if (isValid(Board, rows, cols, dim, default_sym) == true)
			{


				Board[ri][ci] = P_sym[1];
				for (int win = win_count; win > win_count - 1; win--)
				{
					if (isWin(Board, P_sym, dim, 1, default_sym, win) == true)
					{
						return 0;
					}
				
			     	Board[ri][ci] = default_sym;
				    Board[ri][ci] = P_sym[0];

					if (isWin(Board, P_sym, dim, 0, default_sym, win) == true)
					{
						Board[ri][ci] = P_sym[1];
						return 0;
					}
				}

				Board[ri][ci] = default_sym;
			}
			if (ci == dim - 1 && ri == dim - 1)
			{
				do {
					rows = rand() % dim;
					cols = rand() % dim;
				} while (isValid(Board, rows, cols, dim, default_sym) == false);
				Board[rows][cols] = P_sym[1];
			}
		}
	}

	/*for (int ri = 0; ri < dim; ri++)
	{
		for (int ci = 0; ci < dim; ci++)
		{
			rows = ri, cols = ci;
			if (isValid(Board, rows, cols, dim, default_sym))
			{
					Board[ri][ci] = P_sym[1];
					if (isWin(Board, P_sym, dim, turn, default_sym, win))
					{
						return 0;
					}
					Board[ri][ci] = default_sym;

			}
		}
	}*/


}

int main2()
{
	cout << "\n\n\t\t G O M U K U \n\n\n";
	char Board[capacity][capacity], P_name[100][100], P_sym[capacity], default_sym = '-';
	int dim, turn, Nop, win_count;
	init(Board, P_sym, dim, Nop, P_name, turn, default_sym, win_count);
	print_Board(Board, dim);
	do
	{
		player_turn(Board, P_sym[turn], dim, Nop, P_name, turn, default_sym);
		print_Board(Board, dim);
		if (isWin(Board, P_sym, dim, turn, default_sym, win_count) == true)
		{
			cout << "\n\n The Winner is : " << P_name[turn];
			break;
		}
		turn = (turn + 1) % Nop;
	} while (true);
	_getch();
	return 0;
}
int main3()
{
	cout << "\n\n\t\t G O M U K U \n\n\n";
	char Board[capacity][capacity], P_name[100][100], P_sym[capacity], default_sym = '-';
	int dim, turn, Nop = 2, win_count;
	init2(Board, P_sym, dim, P_name, turn, default_sym, win_count);
	print_Board(Board, dim);
	do
	{
		if (turn == 0)
		{
			player_turn(Board, P_sym[turn], dim, Nop, P_name, turn, default_sym);
			print_Board(Board, dim);
			if (isWin(Board, P_sym, dim, turn, default_sym, win_count) == true)
			{
				cout << "\n\n The Winner is : " << P_name[0];
				break;
			}
			turn = (turn + 1) % Nop;
			if (isDraw(Board, P_sym, dim, turn, default_sym, win_count) == true)
			{
				cout << "\n\n The match is drawn ";
				cout << "\n Better Luck Next Time ";
				break;
			}
		}
		if (turn == 1)
		{
			cout << "\n\n Computer is Thinking :) ...... ";
			my_sleep(10000);
			computer_turn(Board, P_sym, dim, Nop, P_name, turn, default_sym, win_count);
			print_Board(Board, dim);
			if (isWin(Board, P_sym, dim, turn, default_sym, win_count) == true)
			{
				cout << "\n\n The Winner is : Computer ";
				break;
			}
			turn = (turn + 1) % Nop;
			if (isDraw(Board, P_sym, dim, turn, default_sym, win_count) == true)
			{
				cout << "\n\n The match is drawn ";
				cout << "\n Better Luck Next Time ";
				break;
			}
		}
	} while (true);
	return 0;
}

int main()
{

	cout << "\n\n\t\t G O M U K U ";
	cout << "\n\n MENU ";
	cout << "\n\n Single_Player : Press 1";
	cout << "\n Multiplayer   : Press 2";
	int choice;
	cout << "\n\n Your Choice : ";
	cin >> choice;
	if (choice == 1)
	{
		system("cls");
		cout << "\n\n\t\t G O M U K U \n\n\n";
		char Board[capacity][capacity], P_name[100][100], P_sym[capacity], default_sym = '-';
		int dim, turn, Nop = 2, win_count;
		init2(Board, P_sym, dim, P_name, turn, default_sym, win_count);
		print_Board(Board, dim);
		do
		{
			if (turn == 0)
			{
				player_turn(Board, P_sym[turn], dim, Nop, P_name, turn, default_sym);
				print_Board(Board, dim);
				if (isWin(Board, P_sym, dim, turn, default_sym, win_count) == true)
				{
					cout << "\n\n The Winner is : " << P_name[0];
					break;
				}
				turn = (turn + 1) % Nop;
				if (isDraw(Board, P_sym, dim, turn, default_sym, win_count) == true)
				{
					cout << "\n\n The match is drawn ";
					cout << "\n Better Luck Next Time ";
					break;
				}
			}
			if (turn == 1)
			{
				cout << "\n\n Computer is Thinking :) ...... ";
				my_sleep(10000);
				computer_turn(Board, P_sym, dim, Nop, P_name, turn, default_sym, win_count);
				print_Board(Board, dim);
				if (isWin(Board, P_sym, dim, turn, default_sym, win_count) == true)
				{
					cout << "\n\n The Winner is : Computer ";
					break;
				}
				turn = (turn + 1) % Nop;
				if (isDraw(Board, P_sym, dim, turn, default_sym, win_count) == true)
				{
					cout << "\n\n The match is drawn ";
					cout << "\n Better Luck Next Time ";
					break;
				}
			}
		} while (true);

	}
	if (choice == 2)
	{
		system("cls");
		cout << "\n\n\t\t G O M U K U \n\n\n";
		char Board[capacity][capacity], P_name[100][100], P_sym[capacity], default_sym = '-';
		int dim, turn, Nop, win_count;
		init(Board, P_sym, dim, Nop, P_name, turn, default_sym, win_count);
		print_Board(Board, dim);
		do
		{
			player_turn(Board, P_sym[turn], dim, Nop, P_name, turn, default_sym);
			print_Board(Board, dim);
			if (isWin(Board, P_sym, dim, turn, default_sym, win_count) == true)
			{
				cout << "\n\n The Winner is : " << P_name[turn];
				break;
			}
			turn = (turn + 1) % Nop;
		} while (true);
		_getch();
		return 0;
	}

	return 0;
}
