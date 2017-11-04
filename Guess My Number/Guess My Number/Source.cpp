#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
int main()
{
	srand(static_cast<unsigned int>(time(0)));
	int randomNumber = rand();
	int randomNumber1;
	int guesses = 0;
	int myNumber;
	char answer;
	do
	{
		guesses = 0;
		randomNumber1 = (randomNumber % 100) + 1;
		do
		{
			guesses++;
			cout << "\nEnter a number: ";
			cin >> myNumber;
			if (myNumber > randomNumber1)
				cout << "Too high!";
			else if (myNumber < randomNumber1)
				cout << "Too low!";
			else cout << "That's is got it on " << guesses << " guesses!\n";
		} while (myNumber != randomNumber1);
		int highBorder;
		int lowBorder;
		randomNumber = rand();
		guesses = 0;
		randomNumber1 = (randomNumber % 100) + 1;
		highBorder = 101;
		lowBorder = 1;
		cin >> myNumber;
		guesses++;
		cout << "\nEnter a number :";
		cout << randomNumber1 << "\n";
		cin >> answer;
		if (answer == 'H')
		{
			highBorder = randomNumber1;
			randomNumber1 = (randomNumber % (highBorder - lowBorder)) + lowBorder;
		}
		else if (answer == 'L')
		{
			lowBorder = randomNumber1;
			randomNumber1 = (randomNumber % (highBorder - lowBorder)) + lowBorder;
		}
		else
		{
			cout << "That's is got it on " << guesses << " guesses!\n";
		}
		while (myNumber != randomNumber1)
		{
			randomNumber = rand();
			guesses++;
			cout << "\nEnter a number: ";
			cout << randomNumber1 << endl;
			cin >> answer;
			cout << "\n";
			if (answer == 'H')
			{
				highBorder = randomNumber1;
				randomNumber1 = (randomNumber % (highBorder - lowBorder)) + lowBorder;
			}
			else if (answer == 'L')
			{
				lowBorder = randomNumber1 + 1;
				randomNumber1 = (randomNumber % (highBorder - lowBorder)) + lowBorder;
			}
		}
		guesses++;
		cout << "\nEnter a number: ";
		cout << randomNumber1 << endl;
		cout << "That's is got it on " << guesses << " guesses!";
		cout << "Do you want to play again?[Y/N]";
		cin >> answer;
	} while (answer == 'Y');
	return 0;
}