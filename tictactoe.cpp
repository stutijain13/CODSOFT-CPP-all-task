#include<iostream>
#include<string>

using namespace std;
char element[3][3] = { { '1','2','3' }, { '4','5','6' }, { '7','8','9' } };
int row;
int column;
char token = 'x';
bool tie = false;
string n1;
string n2;
void board();
void entry();
bool winCondition();
int main()
{
	cout << "Enter name of player one." << endl;
	getline(cin, n1);
	cout << "Enter name of player two." << endl;
	getline(cin, n2);
	cout << n1 << " goes first."<<endl;
	while (!winCondition())
	{
		board();
		entry();
		winCondition();
	}
	if (token == 'x' && tie == false)
	{
		cout << n2 << " wins!!!" << endl;
	}
	else if (token == 'O' && tie == false)
	{
		cout << n1 << " wins!!!" << endl;
	}
	else
	{
		cout << "its a draw!!!" << endl;
	}
	return 0;
}


void board()
{

	cout << "     |     |     " << endl;
	cout << "  " << element[0][0] << "  |  " << element[0][1] << "  |  " << element[0][2] << endl;
	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;
	cout << "  " << element[1][0] << "  |  " << element[1][1] << "  |  " << element[1][2] << endl;
	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;
	cout << "  " << element[2][0] << "  |  " << element[2][1] << "  |  " << element[2][2] << endl;
	cout << "     |     |    " << endl;
}
 

void entry()
{
	int pos;
	if (token == 'x')
	{
		cout << "player " << n1 << " please enter the position" << endl;
		cin >> pos;
	}
	if (token == 'O')
	{
		cout << "player " << n2 << " please enter the position" << endl;
		cin >> pos;
	}
	switch (pos)
	{
	case 1:
		row = 0;
		column = 0;
		break;
	case 2:
		row = 0;
		column = 1;
		break;
	case 3:
		row = 0;
		column = 2;
		break;
	case 4:
		row = 1;
		column = 0;
		break;
	case 5:
		row = 1;
		column = 1;
		break;
	case 6:
		row = 1;
		column = 2;
		break;
	case 7:
		row = 2;
		column = 0;
		break;
	case 8:
		row = 2;
		column = 1;
		break;
	case 9:
		row = 2;
		column = 2;
		break;
	default:
		cout << "incorrrect entry" << endl;
	}
	if (token == 'x' && element[row][column] != 'O' && element[row][column] != 'x')
	{
		element[row][column] = 'x';
		token = 'O';
	}
	else if (token == 'O' && element[row][column] != 'O' && element[row][column] != 'x')
	{
		element[row][column] = 'O';
		token = 'x';
	}
	else
	{
		cout << "there are no empty space" << endl;
		entry();
	}
	
}

bool winCondition()
{
	for (int i = 0; i < 3; i++)
	{
		if (element[i][0] == element[i][1] && element[i][1] == element[i][2] || element[0][i] == element[1][i] && element[1][i] == element[2][i])
		{
			return true;
		}
	}

	if ((element[0][0] == element[1][1] && element[1][1] == element[2][2]) || (element[0][2] == element[1][1] && element[1][1] == element[2][0]))
	{
		return true;
	}
	 
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (element[i][j] != 'x' && element[i][j] != 'O')
			{
				return false;
			}
		}
	}
	tie = true;
	return true;
}
