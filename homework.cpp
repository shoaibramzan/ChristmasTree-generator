#include <iostream>
#include <iomanip>
#include <ctime>
#include <Windows.h>
using namespace std;


int main()
{
	void produceChristmasGreeting();	//prototypes
	void drawAXmasTree();
	bool agreeToContinue();
	SetConsoleTitle("Christmas Tree - Shoaib Ramzan");
	produceChristmasGreeting();

	do {							// creating a do while function for asking the user to agree to continue
		drawAXmasTree();

	} while (agreeToContinue());




	system("pause");
	return (0);
}
void produceChristmasGreeting()
{
	cout << "Shoaib Ramzan - Due on 11 December 2018" << '\n';		// name in program title
	struct tm dateTime;
	time_t now = time(0);
	localtime_s(&dateTime, &now);		// automatically obtaiing the right date and time


	cout << dateTime.tm_mday << " ";

	switch (1 + dateTime.tm_mon) //outputing the correct month
	{
	case 1:
		cout << "January";
	case 2:
		cout << "Febuary";
	case 3:
		cout << "March";
	case 4:
		cout << "April";
	case 5:
		cout << "May";
	case 6:
		cout << "June";
	case 7:
		cout << "July";
	case 8:
		cout << "August";
	case 9:
		cout << "September";
	case 10:
		cout << "October";
	case 11:
		cout << "November";
	case 12:
		cout << "December";
	}
	cout << " " << 1900 + dateTime.tm_year << ", " << dateTime.tm_hour << ":" << 1 + dateTime.tm_min << ":" << 1 + dateTime.tm_sec << "\n";


}
void drawAXmasTree()
{

	int getValidHeight();
	const int treeHeight(getValidHeight());
	void drawFoliage(int tH);
	void drawTrunk(int tH);
	int border = 1;
	while (border <= (treeHeight * 2) - 1)		// inputing the border to the code for the top part of the tree
	{
		cout << '.';
		border++;
	}
	cout << endl;
	drawFoliage(treeHeight);
	drawTrunk(treeHeight);
	border = 1;
	while (border <= (treeHeight * 2) - 1)		//dotted line border for the bottom part of the tree
	{
		cout << '.';
		border++;
	}
	cout << endl;

}
int getValidHeight()
{
	const int Minsize = 4;					//localising the varibales instead of global 
	const int Maxsize = 20;
	int treeHeightOUT;
	cout << "\nEnter the size of the tree (4-20): ";
	cin >> treeHeightOUT;
	while ((treeHeightOUT < Minsize) || (treeHeightOUT > Maxsize))		// using the min/ maxsize 
	{
		cout << "\nError: Invalid height! Enter the size of the tree (4-20): ";
		cin >> treeHeightOUT;
	}
	return treeHeightOUT;
}
void drawFoliage(int tH)
{
	char randomDecoration();			//declaring the procedure for random decoration
	void drawALineOfFoliage(int branchLine, int tH, char DECORATION);
	int branchLine = 1;
	while (branchLine <= (tH - 2))
	{

		drawALineOfFoliage(branchLine, tH, randomDecoration());
		branchLine = branchLine + 1;
	}
}
void drawALineOfFoliage(int branchLine, int tH, char DECORATION)
{
	const char Blank = ' ';
	const char Leaf = '#';
	char randomDecoration();	//declaring the prototype
	cout << '.';
	for (int i = 0; i < tH - branchLine - 2; i++)
	{
		cout << Blank;
	}
	for (int i = 0; i < (branchLine * 2) - 1; i++)
	{
		if (branchLine == 1)
			cout << DECORATION;
		else
			cout << Leaf;
	}
	cout << endl;
}
void drawTrunk(int tH)
{
	const char Blank = ' ';
	const char Wood = '|';
	int spaces;
	for (int trunkLine = 1; trunkLine <= 2; trunkLine += 1)
	{
		cout << '.';
		spaces = 1;
		while (spaces <= (tH - 3))
		{
			cout << Blank;
			spaces += 1;
		}

		cout << Wood << "\n";
		cout << '.';
		cout << endl;
	}

}
char randomDecoration()
{
	srand(time(0));
	int decorationNumber = (rand() % 4);
	char randomDecorationOUT;
	switch (decorationNumber)						//using switch function to declare different special characters
	{
	case 0: return randomDecorationOUT = '*';
		break;
	case 1: return randomDecorationOUT = '&';
		break;
	case 2: return randomDecorationOUT = '@';
		break;
	case 3: return randomDecorationOUT = '0';
		break;
	}

}
bool agreeToContinue()
{
	bool agreeToContinue;
	char agreeTo;
	cout << "\nWould you like another tree? (Y/N): ";		//asking the user to conntinue on with if and else statements
	cin >> agreeTo;
	if ((agreeTo == 'y') || (agreeTo == 'Y'))
	{
		agreeToContinue = true;
	}
	else
	{
		agreeToContinue = false;
	}
	return agreeToContinue;
}
