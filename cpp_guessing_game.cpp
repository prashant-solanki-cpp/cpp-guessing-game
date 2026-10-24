#include <bits/stdc++.h>
using namespace std;

int main()
{
    unsigned int seed = chrono::steady_clock::now().time_since_epoch().count();

    mt19937 generator(seed);
    uniform_int_distribution<int> distribution(1, 100);

    int secretNumber = distribution(generator);

    cout << "========== number guessing game ==========" << endl;
    cout << "game rules:" << endl;
    cout << "1. system will generate a random number between 1 to 100, and you try to guess it." << endl;
    cout << "2. on the wrong guess, system will guide you whether the secret number is bigger or smaller." << endl;
    cout << "3. on the right guess, system returns you total attempt." << endl;
    cout << "let's start the game!!!!" << endl;
    cout << "==========================================" << endl;

    int guess;
    int attempt = 1;
    cout << "guess a number: ";
    while (!(cin >> guess))
    {
        cout << "enter a valid number!!!!!" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    while (guess != secretNumber)
    {
        if (guess < secretNumber)
        {
            attempt++;
            cout << "the number you guess is SMALLER!!!" << endl;
        }
        else if (guess > secretNumber)
        {
            attempt++;
            cout << "the number you guess is BIGGER!!!" << endl;
        }
        while (!(cin >> guess))
        {
            cout << "enter a valid number!!!!!" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    cout << "==========================================" << endl;
    cout << "your guess is RIGHT!!!!, the secret Number is " << secretNumber << endl;
    cout << "total number of attempt used is " << attempt << endl;
    cout << "==========================================" << endl;
    return 0;
}