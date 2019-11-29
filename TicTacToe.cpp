#include "iostream"
#include "iomanip"
#include "cstdlib"
#include "ctime"
#include "fstream"
#include "Windows.h"
#include "string"
#include "conio.h"
#include "stdio.h"
#pragma warning (disable : 4996)

using namespace std;

class TicTacToe
{
private:
	int **ar;
	int size;
	char mark;
	int id;
	string time1;
public:
	TicTacToe(int size) //Constructor ........
	{
		int num = 1;
		this->size = size;
		ar = new int*[size];
		for (int row = 0; row < size; row++)
		{
			ar[row] = new int[size];
			for (int col = 0; col < size; col++)
				ar[row][col] = num++;
		}
	}
	TicTacToe() //Constructor ........
	{
		int num = 1;
		this->size = 5;
		ar = new int*[size];
		for (int row = 0; row < size; row++)
		{
			ar[row] = new int[size];
			for (int col = 0; col < size; col++)
				ar[row][col] = num++;
		}
	}
	TicTacToe(const TicTacToe & Obj) //Copy Constructor ........
	{
		this->size = Obj.size;
		ar = new int*[size];
		for (int row = 0; row < size; row++)
		{
			ar[row] = new int[size];
			for (int col = 0; col < size; col++)
				ar[row][col] = Obj.ar[row][col];
		}
	}
	~TicTacToe()  //Destructor .........
	{
		for (int i = 0; i < size; i++)
			delete[]ar[i];
		delete[]ar;
	}
	int getSize()
	{
		return size;
	}
	char getMark()
	{
		return mark;
	}
	string getTime()
	{
		return time1;
	}
	int getId()
	{
		return id;
	}
	void setID(int id)
	{
		this->id = id;
	}
	void getMove(int n) // get Move for players....
	{
		int num;
		bool validMove = false;
		if (n == -1)
			mark = 'X';
		else
			mark = 'O';
		do
		{
			cin >> num;
			if (!cin)
			{
				cin.clear();
				cin.ignore(100, '\n');
			}
			cout << endl;
			if (num == 0)
			{
				ofstream file("game.txt", ios::app);
				time1 = currentDateTime();
				write(file);
				cout << "Your Game is Successfully Saved" << endl;
				file.close();
				//delete Array......
				for (int i = 0; i < size; i++)
					delete[]ar[i];
				delete[]ar;
				cout << "\n\tThank you for playing ...!!\n";
				std::system("pause");
				exit(0);
			}
			for (int row = 0; row < size; row++)
			{
				for (int col = 0; col < size; col++)
				{
					if (num == ar[row][col])
					{
						validMove = true;
						ar[row][col] = n;
					}
				}
			}
			if (!validMove)
			{
				cout << "Invalid Move, try again.\n";
				cout << "Enter move again : ";
			}
		} while (!validMove);
	}

	void getComputerMove() //get Move for Computer...
	{
		bool flag(false);
		mark = 'O';
		if (size == 3)
		{
			if (ar[1][1] == 5 && flag == false) {
				flag = true; ar[1][1] = -2;//for 5.
			}
			else if (ar[0][0] == ar[1][1] && ar[2][2] != -1 && ar[2][2] != -2) {
				flag = true; ar[2][2] = -2;//for 9
			}
			else if (ar[2][2] == ar[1][1] && ar[0][0] != -1 && ar[0][0] != -2) {
				flag = true; ar[0][0] = -2; //for 1
			}
			else if (ar[0][2] == ar[1][1] && ar[2][0] != -1 && ar[2][0] != -2) {
				flag = true; ar[2][0] = -2;//for 7
			}
			else if (ar[2][0] == ar[1][1] && ar[0][2] != -1 && ar[0][2] != -2) {
				flag = true; ar[0][2] = -2; //for 3
			}
			else
			{
				for (int i = 0; i < size; i++) // col 10 20
				{
					if (ar[2][i] == ar[1][i] && ar[0][i] != -1 && ar[0][i] != -2 && flag == false)
					{
						flag = true;
						ar[0][i] = -2;
						break; // for 1 2 3
					}
				}
				for (int i = 0; i < size; i++) // row 00 01
				{
					if (ar[i][0] == ar[i][1] && ar[i][2] != -1 && ar[i][2] != -2 && flag == false)
					{
						flag = true;
						ar[i][2] = -2;
						break;   //for 3 6 9
					}
				}
				for (int i = 0; i < size; i++) // col 00 10
				{
					if (ar[0][i] == ar[1][i] && ar[2][i] != -1 && ar[2][i] != -2 && flag == false)
					{
						flag = true;
						ar[2][i] = -2;
						break;   //for 7 8 9
					}
				}
				for (int i = 0; i < size; i++) // row 00 02
				{
					if (ar[i][0] == ar[i][2] && ar[i][1] != -1 && ar[i][1] != -2 && flag == false)
					{
						flag = true;
						ar[i][1] = -2;
						break; // for 2 5 8
					}
				}
				for (int i = 0; i < size; i++) // col 00 20
				{
					if (ar[0][i] == ar[2][i] && ar[1][i] != -1 && ar[1][i] != -2 && flag == false)
					{
						flag = true;
						ar[1][i] = -2;
						break; // for 4 5 6
					}
				}
				for (int i = 0; i < size; i++) // row 01 02
				{
					if (ar[i][2] == ar[i][1] && ar[i][0] != -1 && ar[i][0] != -2 && flag == false)
					{
						flag = true;
						ar[i][0] = -2;
						break; // for 1 4 7
					}
				}
				if (ar[0][0] == 1 && flag == false)
				{
					flag = true; ar[0][0] = -2; // for 1
				}
				if (flag == false)
					extra();
			}
		}
		if (size == 4)
		{
			if (ar[0][0] == 1 && flag == false) {
				flag = true; ar[0][0] = -2; // for 1
			}
			else if (ar[0][0] == ar[1][1] && ar[0][0] == ar[2][2] && ar[3][3] != -1 && ar[3][3] != -2) {
				flag = true; ar[3][3] = -2; // for 16
			}
			else if (ar[0][3] == ar[1][2] && ar[0][3] == ar[2][1] && ar[3][0] != -1 && ar[3][0] != -2) {
				flag = true; ar[3][0] = -2; // for 13
			}
			else if (ar[0][3] == ar[1][2] && ar[0][3] == ar[3][0] && ar[2][1] != -1 && ar[2][1] != -2) {
				flag = true; ar[2][1] = -2; // for 10
			}
			else if (ar[0][3] == ar[3][0] && ar[0][3] == ar[2][1] && ar[1][2] != -1 && ar[1][2] != -2) {
				flag = true; ar[1][2] = -2; // for 7
			}
			else if (ar[3][0] == ar[1][2] && ar[3][0] == ar[2][1] && ar[0][3] != -1 && ar[0][3] != -2) {
				flag = true; ar[0][3] = -2; // for 4
			}
			else
			{
				for (int i = 0; i < size; i++) // row 00 01 02
				{
					if (ar[i][0] == ar[i][1] && ar[i][0] == ar[i][2] && ar[i][3] != -1 && ar[i][3] != -2 && flag == false)
					{
						flag = true;
						ar[i][3] = -2;
						break; // for 4 8 12 16
					}
				}
				for (int i = 0; i < size; i++) // row 00 02 03
				{
					if (ar[i][0] == ar[i][2] && ar[i][0] == ar[i][3] && ar[i][1] != -1 && ar[i][1] != -2 && flag == false)
					{
						flag = true;
						ar[i][1] = -2;
						break; // for 2 6 10 14
					}
				}
				for (int i = 0; i < size; i++) // row 01 02 03
				{
					if (ar[i][2] == ar[i][1] && ar[i][2] == ar[i][3] && ar[i][0] != -1 && ar[i][0] != -2 && flag == false)
					{
						flag = true;
						ar[i][0] = -2;
						break; // for 1 5 9 13
					}
				}
				for (int i = 0; i < size; i++) // row 00 01 03
				{
					if (ar[i][0] == ar[i][1] && ar[i][0] == ar[i][3] && ar[i][2] != -1 && ar[i][2] != -2 && flag == false)
					{
						flag = true;
						ar[i][2] = -2;
						break; // for 3 7 11 15
					}
				}
				for (int i = 0; i < size; i++) // col 00 10 20
				{
					if (ar[0][i] == ar[1][i] && ar[0][i] == ar[2][i] && ar[3][i] != -1 && ar[3][i] != -2 && flag == false)
					{
						flag = true;
						ar[3][i] = -2;
						break; // for 13 14 15 16
					}
				}
				for (int i = 0; i < size; i++) // col 00 20 30
				{
					if (ar[0][i] == ar[2][i] && ar[0][i] == ar[3][i] && ar[1][i] != -1 && ar[1][i] != -2 && flag == false)
					{
						flag = true;
						ar[1][i] = -2;
						break; // for 5 6 7 8
					}
				}
				for (int i = 0; i < size; i++) // col 10 20 30
				{
					if (ar[2][i] == ar[1][i] && ar[2][i] == ar[3][i] && ar[0][i] != -1 && ar[0][i] != -2 && flag == false)
					{
						flag = true;
						ar[0][i] = -2;
						break; // for 1 2 3 4
					}
				}
				for (int i = 0; i < size; i++) // col 00 10 30
				{
					if (ar[0][i] == ar[1][i] && ar[0][i] == ar[3][i] && ar[2][i] != -1 && ar[2][i] != -2 && flag == false)
					{
						flag = true;
						ar[2][i] = -2;
						break; // for 9 10 11 12
					}
				}
				if (ar[1][1] == 6 && flag == false)
				{
					flag = true; ar[1][1] = -2; // for 6
				}
				if (ar[2][2] == 11 && flag == false)
				{
					flag = true; ar[2][2] = -2; // for 11
				}
				if (flag == false)
					extra();
			}
		}
		if (size == 5)
		{
			if (ar[0][0] == 1 && flag == false) {
				flag = true; ar[0][0] = -2; // for 1
			}
			else if (ar[0][0] == ar[1][1] && ar[0][0] == ar[2][2] && ar[0][0] == ar[3][3] && ar[4][4] != -1 && ar[4][4] != -2) {
				flag = true; ar[4][4] = -2; // for 25
			}
			else if (ar[0][0] == ar[1][1] && ar[0][0] == ar[2][2] && ar[0][0] == ar[4][4] && ar[3][3] != -1 && ar[3][3] != -2) {
				flag = true; ar[3][3] = -2; // for 19
			}
			//2nd Diagonal..........
			else if (ar[1][3] == ar[2][2] && ar[1][3] == ar[3][1] && ar[1][3] == ar[4][0] && ar[0][4] != -1 && ar[0][4] != -2) {
				flag = true; ar[0][4] = -2; // for 5
			}
			else if (ar[0][4] == ar[2][2] && ar[0][4] == ar[3][1] && ar[0][4] == ar[4][0] && ar[1][3] != -1 && ar[1][3] != -2) {
				flag = true; ar[1][3] = -2; // for 9
			}
			else if (ar[0][4] == ar[1][3] && ar[0][4] == ar[2][2] && ar[0][4] == ar[4][0] && ar[3][1] != -1 && ar[3][1] != -2) {
				flag = true; ar[3][1] = -2; // for 17
			}
			else if (ar[0][4] == ar[1][3] && ar[0][4] == ar[3][1] && ar[0][4] == ar[2][2] && ar[4][0] != -1 && ar[4][0] != -2) {
				flag = true; ar[4][0] = -2; // for 21
			}
			else
			{
				for (int i = 0; i < size; i++) // row 00 01 02 03
				{
					if (ar[i][0] == ar[i][1] && ar[i][0] == ar[i][2] && ar[i][0] == ar[i][3] && ar[i][4] != -1 && ar[i][4] != -2 && flag == false)
					{
						flag = true;
						ar[i][4] = -2;
						break; // for 5 10 15 20 25
					}
				}
				for (int i = 0; i < size; i++) // row 00 02 03 04
				{
					if (ar[i][0] == ar[i][2] && ar[i][0] == ar[i][3] && ar[i][0] == ar[i][4] && ar[i][1] != -1 && ar[i][1] != -2 && flag == false)
					{
						flag = true;
						ar[i][1] = -2;
						break; // for 2 7 12 17 22
					}
				}
				for (int i = 0; i < size; i++) // row 01 02 03 04
				{
					if (ar[i][2] == ar[i][1] && ar[i][2] == ar[i][3] && ar[i][2] == ar[i][4] && ar[i][0] != -1 && ar[i][0] != -2 && flag == false)
					{
						flag = true;
						ar[i][0] = -2;
						break; // for 1 6 11 16 21
					}
				}
				for (int i = 0; i < size; i++) // row 00 01 03 04
				{
					if (ar[i][0] == ar[i][1] && ar[i][0] == ar[i][3] && ar[i][0] == ar[i][4] && ar[i][2] != -1 && ar[i][2] != -2 && flag == false)
					{
						flag = true;
						ar[i][2] = -2;
						break; // for 3 8 13 18 23
					}
				}
				for (int i = 0; i < size; i++) // row 00 01 02 04
				{
					if (ar[i][0] == ar[i][1] && ar[i][0] == ar[i][2] && ar[i][0] == ar[i][4] && ar[i][3] != -1 && ar[i][3] != -2 && flag == false)
					{
						flag = true;
						ar[i][3] = -2;
						break; // for 4 9 14 19 24
					}
				}
				for (int i = 0; i < size; i++) // col 00 10 20 30
				{
					if (ar[0][i] == ar[1][i] && ar[0][i] == ar[2][i] && ar[0][i] == ar[3][i] && ar[4][i] != -1 && ar[4][i] != -2 && flag == false)
					{
						flag = true;
						ar[4][i] = -2;
						break; //for 21 22 23 24 25
					}
				}
				for (int i = 0; i < size; i++) // col 00 20 30 40
				{
					if (ar[0][i] == ar[2][i] && ar[0][i] == ar[3][i] && ar[0][i] == ar[4][i] && ar[1][i] != -1 && ar[1][i] != -2 && flag == false)
					{
						flag = true;
						ar[1][i] = -2;
						break; // for 6 7 8 9 10
					}
				}
				for (int i = 0; i < size; i++) // col 10 20 30 40
				{
					if (ar[2][i] == ar[1][i] && ar[2][i] == ar[3][i] && ar[2][i] == ar[4][i] && ar[0][i] != -1 && ar[0][i] != -2 && flag == false)
					{
						flag = true;
						ar[0][i] = -2;
						break; // for 1 2 3 4 5
					}
				}
				for (int i = 0; i < size; i++) // col 00 10 30 40
				{
					if (ar[0][i] == ar[1][i] && ar[0][i] == ar[3][i] && ar[0][i] == ar[4][i] && ar[2][i] != -1 && ar[2][i] != -2 && flag == false)
					{
						flag = true;
						ar[2][i] = -2;
						break; // for 11 12 13 14 15
					}
				}
				for (int i = 0; i < size; i++) // col 00 10 20 40
				{
					if (ar[0][i] == ar[1][i] && ar[0][i] == ar[2][i] && ar[0][i] == ar[4][i] && ar[3][i] != -1 && ar[3][i] != -2 && flag == false)
					{
						flag = true;
						ar[3][i] = -2;
						break; // for 16 17 18 19 20
					}
				}
				if (ar[1][1] == 7 && flag == false)
				{
					flag = true; ar[1][1] = -2; // for 7
				}
				if (ar[2][2] == 13 && flag == false)
				{
					flag = true; ar[2][2] = -2; // for 13
				}
				if (ar[3][3] == 19 && flag == false)
				{
					flag = true; ar[3][3] = -2; // for 19
				}
				if (flag == false)
					extra();
			}
		}
		return;
	}

	void extra()
	{
		int num = 1;
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				if (num == ar[i][j]) {
					ar[i][j] = -2;
					break;
				}
				num++;
			}
		}
	}

	bool determine_Winner(int num)
	{
		//for Row Check ...............
		for (int row = 0; row < size; row++)
		{
			int count = 0;
			for (int col = 0; col < size; col++)
			{
				if (ar[row][col] == num)
					count++;
				if (count == size)
					return true;
			}
		}
		//for Column check.............
		for (int col = 0; col < size; col++)
		{
			int count = 0;
			for (int row = 0; row < size; row++)
			{
				if (ar[row][col] == num)
					count++;
				if (count == size)
					return true;
			}
		}
		//for Diagonal checck...........
		int count1 = 0;
		for (int row = 0; row < size; row++)
		{
			if (ar[row][row] == num)
				count1++;
			if (count1 == size)
				return true;
		}
		int count2 = 0;
		for (int row = 0, col = size - 1; row < size; row++, col--)
		{
			if (ar[row][col] == num)
				count2++;
			if (count2 == size)
				return true;
		}
		return false;
	}

	bool determineDraw()
	{
		int N = 1;
		for (int row = 0; row < size; row++)
		{
			for (int col = 0; col < size; col++)
			{
				if (ar[row][col] == N++)
					return false;
			}
		}
		return true;
	}

	void show() //print board of game....
	{
		std::system("cls");
		cout << "\n\n\n\t";
		for (int i = 0; i < 5 * (size)+2; i++)
		{
			cout << "-";
		}
		cout << endl;
		for (int row = 0; row < size; row++)
		{
			cout << "\t|";
			for (int col = 0; col < size; col++)
			{
				if (ar[row][col] == -1)
					cout << setw(3) << 'X' << " |";
				else if (ar[row][col] == -2)
					cout << setw(3) << 'O' << " |";
				else
					cout << setw(3) << ar[row][col] << " |";
			}
			cout << "\n\t";
			for (int i = 0; i < 5 * (size)+2; i++)
			{
				cout << "-";
			}
			cout << endl;
		}
	}
	void selectLocation1()		//this function will take input from the current user and mark the
	{							//current symbol of player at that location.
		int location;
		string location1;
		ofstream file("game.txt", ios::app);
		if (mark == 'X')
		{
			cout << "Press S to save the Game" << endl << endl;

			cout << "Enter Player 1 location : ";
		}
		else
		{
			cout << "Press S to save the Game" << endl << endl;

			cout << "Enter Player 2 Location : ";
		}
		cin >> location1;
		if (location1 == "s" || location1 == "S")
		{
			time1 = currentDateTime();
			write(file);
			cout << "Your Game is Successfully Saved" << endl;
			file.close();
			exit(0);
		}
		else
		{
			int location=stoi(location1);
			if (location>0 && location <= size * size)
			{
				for (int i = 0; i<size; i++)
				{
					for (int j = 0; j<size; j++)
					{
						if (ar[i][j] == location)
						{
							if (mark == 'X')
								ar[i][j] = -1;
							else if (mark == 'Y')
								ar[i][j] = -2;
						}
					}
				}
			}
			else		//if the user enter the number out of the available locations then the selecting location function is called again
			{
				cout << "You have entered a wrong location, please select again" << endl;
				selectLocation1();
			}
		}

	}
	void selectLocation()		//this function will take input from the current user and mark the 
	{							//current symbol of player at that location.
		string location1;
		char char1 = 's';
		char char2 = 'S';
		bool again = false;
		ofstream file("game.txt", ios::app);
		if (mark == 'X')
		{
			cout << "Press S to save the Game" << endl << endl;

			cout << "Human: Select a Location: ";
		}
		if (mark == 'X')
		{
			cin >> location1;
			if (location1 == "s" || location1 == "S")
			{
				time1 = currentDateTime();
				write(file);
				cout << "Your Game is Successfully Saved" << endl;
				file.close();
				exit(0);
			}
			else
			{
				int location=stoi(location1);
				if (location>0 && location <= size * size)
				{
					for (int i = 0; i<size; i++)
					{
						for (int j = 0; j<size; j++)
						{
							if (ar[i][j] == location)
								ar[i][j] = -1;

						}
					}
				}
				else		//if the user enter the number out of the available locations then the selecting location function is called gain
				{
					cout << "You have entered a wrong location please select again" << endl;
					system("pause");
					selectLocation();
				}
			}
		}
		if (mark == 'Y')
		{
			getComputerMove();
		}
	}
	void changePlayer()		//this funtion will change the player for the next turn if current player is 
	{						//player 1 it will change to player 2 and vice versa.and will change the mark too
		if (mark == 'X')
		{
			mark = 'Y';
			//player = "Player2";
		}
		else if (mark == 'Y')
		{
			mark = 'X';
			//player = "Player1";
		}
	}
	void playHuman()		//in this functions all the functions are called that will run the complete game.
	{
		id = 2;
		bool status(false);
		char choice;
		system("cls");
		show();
		while(!status)
		{
			selectLocation1();
			changePlayer();
			system("cls");
			show();
			if (determine_Winner(-1) && status == false)
			{
				status = true;
				cout << "\n\t\tPlayer 1 win !!!\n";
				std::system("pause");
				//break;
			}
			if (determine_Winner(-2) && status == false)
			{
				status = true;
				cout << "\n\t\tPlayer 2 win !!!\n";
				std::system("pause");
				//break;
			}
			if (determineDraw() == true && status == false)
			{
				status = true;
				cout << "\nDraw !!!\n";
				std::system("pause");
				//break;
			}
		}
	}

	void playComputer()		//in this functions all the functions are called that will run the complete game.
	{
		id = 1;
		bool status(false);
		char choice;
		system("cls");
		show();
		while (status == false)
		{
			selectLocation();
			changePlayer();
			system("cls");
			show();
			if (determine_Winner(-1) && status == false)
			{
				status = true;
				cout << "\n\t\tPlayer 1 win !!!\n";
				std::system("pause");
				//break;
			}
			if (determine_Winner(-2) && status == false)
			{
				status = true;
				cout << "\n\t\tPlayer 2 win !!!\n";
				std::system("pause");
				//break;
			}
			if (determineDraw() == true && status == false)
			{
				status = true;
				cout << "\nDraw !!!\n";
				std::system("pause");
				//break;
			}
		}
	}
	void write(ofstream & out)
	{
		out << id << endl << time1 << endl << mark << endl  << size << endl;
		for (int i = 0; i<size; i++)
			for (int j = 0; j<size; j++)
				out << ar[i][j] << ' ';
		out << endl;
	}
	void read(istream & in)
	{
		in >> id;
		in >> time1;
		in >> mark >> size;
		for (int i = 0; i<size; i++)
			for (int j = 0; j<size; j++)
				in >> ar[i][j];
	}
	string currentDateTime() {
		time_t     now = time(0);
		struct tm  tstruct;
		char       buf[80];
		tstruct = *localtime(&now);
		strftime(buf, sizeof(buf), "%d/%m/%Y--%I:%M:%S.%p", &tstruct);
		return buf;
	}

};

void SetColor(int);
void Instruction();
void play();
void GameStart(int);
void Exit();
void playAgain();
void showGrid(int);
void Play();
void select();
void start();

int main() // Main function ..........
{
	start();
	return 0;
}
void SetColor(int value)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), value);
}
void start()
{
	std::system("cls");
	TicTacToe temp;
	SetColor(12);
	cout << "\n\n";
	cout << "\t\t**** ** ****   **** **** ****   **** **** ****" << endl;
	cout << "\t\t **  ** *       **  *  * *       **  *    *  *" << endl;
	cout << "\t\t **  ** *       **  **** *       **  *    *  *" << endl;
	cout << "\t\t **  ** ****    **  *  * ****    **  **** ****" << endl << endl;
	std::system("pause");
	std::system("cls");
	SetColor(15);
	cout << "\t--------------------------------";
	cout << "\n\t     Welcome to Tic Tac Toe\n";
	cout << "\t--------------------------------";
	SetColor(5);
	int choice;
	cout << "\n\n\t1. Load a Saved Game.\n\t2. Delete a Saved Game.\n\t3. New Game.";
	SetColor(9);
input:
	cout << "\n\nEnter your choice : ";
	cin >> choice;
	if (choice == 1)
		GameStart(1);
	else if (choice == 2)
		GameStart(2);
	else if (choice == 3)
		GameStart(3);
	else if (choice == 0)
		Exit();
	else
	{
		cout << "\nInvalid number, enter right one..!!";
		goto input;
	}
}
void GameStart(int n)
{
	int load, del;
	int save = 1;
	TicTacToe obj1;
	if (n == 1)
	{
		ifstream file("game.txt");
		if (!file)
		{
			cout << "\tGame is not exist.\n" << endl;
			std::system("pause");
			exit(0);
		}
		obj1.read(file);
		while (!file.eof())
		{
			cout << save << ". Game saved at " << obj1.getTime() << endl;
			obj1.read(file);
			save++;
		}
		file.close();
		if (save == 1) {
			cout << "\tGame is not exist.\n" << endl;
			std::system("pause");
		}
		else
		{
			cout << "Which State You want to load: ";
			cin >> load;
			if (load >= 1 && load <= save)
			{
				ifstream file("game.txt");
				for (int i = 1; i < load; i++)
					obj1.read(file);

				obj1.read(file);
				ofstream out("gametemp.txt");
				obj1.write(out);
				out.close();
				file.close();
				cout << "Load Successful!" << endl;
			}
			else
			{
				cout << "Please Enter from the given option" << endl;
				std::system("pause");
				exit(0);
			}
		}
		std::system("pause");
		if (obj1.getId() == 1)
			obj1.playComputer();
		else if (obj1.getId() == 2)
			obj1.playHuman();
	}
	if (n == 2)
	{
		ifstream file("game.txt");
		if (!file)
		{
			cout << "\tGame is not exist.\n" << endl;
			std::system("pause");
			exit(0);
		}
		obj1.read(file);
		while (!file.eof())
		{
			cout << save << ". Game save at " << obj1.getTime() << endl;
			obj1.read(file);
			save++;
		}
		file.close();
		if (save == 1) {
			cout << "\tGame is not exist.\n" << endl;
			std::system("pause");
		}
		else
		{
			cout << "Which State you want to delete: ";
			cin >> del;
			ifstream file("game.txt");
			ofstream temp("temp.txt");
			for (int i = 1; i<del; i++)
			{
				obj1.read(file);
				obj1.write(temp);
			}
			obj1.read(file);
			for (int i = del + 1; i<save; i++)
			{
				obj1.read(file);
				obj1.write(temp);
			}
			file.close();
			temp.close();
			std::remove("game.txt");
			std::rename("temp.txt", "game.txt");
		}
		cout << "Delete Successful!" << endl;
		std::system("pause");
		start();
	}
	if (n == 3)
	{
		std::system("cls");
		int Choice;
		SetColor(15);
		cout << "\t--------------------------------";
		cout << "\n\t     Welcome to Tic Tac Toe\n";
		cout << "\t--------------------------------";
		SetColor(10);
		cout << "\n\nEnter 1 for Game Instruction.\nEnter 2 for Play Game.\nEnter 3 for Exit.\n";
		SetColor(3);
		cout << "\nEnter your Choice : ";
		cin >> Choice;
		system("cls");
		if (Choice == 1)
		{
			Instruction();
			system("pause");
			system("cls");
			select();
		}
		else if (Choice == 2)
		{
			select();
		}
		else
			Exit();
	}

}
void Instruction()
{
	SetColor(13);
	cout << "\nTic Tac Toe Game Rules:\n";
	cout << "The object of the game is to get  X's or O's in a row/coloum/diagonal.\n";
	cout << "The player 1 mark 'X' first move.\nThen Player 2 Or Computer mark 'O' second move and so on.\n";
	cout << "You should enter the Number which you want to mark.\n";
	cout << "For quit the game, press '0' .\n\n";
}
void select()
{
	std::system("CLS");
	SetColor(14);
	int choice;
	cout << "Welcome to Tic - Tac - Toe\n";
	cout << "\n\t1. Single Player (Human vs Computer)\n";
	cout << "\t2. Two Player (Human vs Human)\nChoice : ";
	cin >> choice;
	if (choice == 1)
		Play();
	else if (choice == 2)
		play();
}
void play()
{
	SetColor(15);
	cout << "Select playing grid\n\t1. 3 X 3\n\t2. 4 X 4\n\t3. 5 X 5\n\nFor quit enter '0'.";
	int number;
	SetColor(9);
input:
	cout << "\nChoice : ";
	cin >> number;
	if (number < 0 || number > 3)
	{
		SetColor(6);
		cout << "\nInvalid Choice, try again. ";
		goto input;
	}
	system("cls");
	if (number == 0) Exit();
	int grid = number + 2;
	TicTacToe Game(grid);
	Game.setID(2);
	cout << "The board location are as follows:\n";
	showGrid(grid);
	bool status(false);
	while (!status)
	{
		cout << "Press 0 to save the Game \n ";
		cout << "\nEnter move (Play 1): ";
		Game.getMove(-1);
		Game.show();
		if (Game.determine_Winner(-1) == true)
		{
			status = true;
			cout << "\n\t\tPlayer 1 win !!!\n";
			break;
		}
		if (Game.determineDraw() == true)
		{
			status = true;
			cout << "\nDraw !!!\n";
		}
		else
		{
			cout << "Press 0 to save the Game \n ";
			cout << "\nEnter move (Player 2): ";
			Game.getMove(-2);
			Game.show();
			if (Game.determine_Winner(-2) == true)
			{
				status = true;
				cout << "\n\t\tPlayer 2 win !!!\n";
				break;
			}
			if (Game.determineDraw() == true)
			{
				status = true;
				cout << "\n\t\tDraw !!!\n";
			}
		}
	}
	playAgain();
}
void Play()
{
	SetColor(10);
	cout << "Select playing grid\n\t1. 3 X 3\n\t2. 4 X 4\n\t3. 5 X 5\n\nFor quit enter '0'.";
	cout << "\nChoice : ";
	int number;
	cin >> number;
	system("cls");
	if (number == 0) Exit();
	int grid = number + 2;
	TicTacToe Game(grid);
	Game.setID(1);
	cout << "\nThe board location are as follows:\n\n";
	showGrid(grid);
	bool status(false);
	while (!status)
	{
		cout << "Press 0 to save the Game \n ";
		cout << "\nHuman: Select a location: ";
		Game.getMove(-1);
		Game.show();
		if (Game.determine_Winner(-1) == true)
		{
			status = true;
			cout << "\n\t\tHuman Wins !!!\n";
			break;
		}
		if (Game.determineDraw() == true)
		{
			status = true;
			cout << "\nDraw !!!\n";
		}
		else
		{
			Game.getComputerMove();
			Game.show();
			if (Game.determine_Winner(-2) == true)
			{
				status = true;
				cout << "\n\t\tComputer wins !!!\n";
				break;
			}
			if (Game.determineDraw() == true)
			{
				status = true;
				cout << "\n\t\tDraw !!!\n";
			}
		}
	}
	playAgain();
}
void Exit()
{
	cout << "\n\tThank you for coming !!!\n";
	system("pause");
	exit(0);
}
void playAgain()
{
	char ch;
	cout << "\nDo you want to play again (y/n)? \n";
	cout << "Your choice : ";
	cin >> ch;
	if (ch == 'Y' || ch == 'y')
		select();
}
void showGrid(int size)
{
	system("cls");
	cout << "\n\n\n\t";
	for (int i = 0; i < 5 * (size)+2; i++)
	{
		cout << "-";
	}
	cout << endl;
	int n = 1;
	for (int row = 0; row < size; row++)
	{
		cout << "\t|";
		for (int col = 0; col < size; col++)
			cout << setw(3) << n++ << " |";
		cout << "\n\t";
		for (int i = 0; i < 5 * (size)+2; i++)
			cout << "-";
		cout << endl;
	}
}