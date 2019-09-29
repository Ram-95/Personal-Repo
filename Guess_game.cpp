/*
Guess Game
*/
#include<iostream>
#include <cstdlib>
#include<time.h>
using namespace std;
int main()
{

    int user_inp;


    // This generates a random number in range [1,10]
    int new_number;

    //The below line is important. This will randomize the numbers
    //The function time(NULL) will return the numbers of seconds elapsed in computer time.

    srand(time(NULL));
    new_number = (rand() % 10) + 1;


    // Checking if correct or not
    do
    {
        cout<<"Guess a Number!: \n";
        cin>>user_inp;
        if (user_inp < new_number)
        {
            cout<<"Your Number is less. Choose a Greater value..\n";
        }
        else if (user_inp > new_number)
        {
            cout<<"Your Number is greater. Choose a Lesser Value...\n";
        }
        else
            cout<<"\n\nYour Guess is CORRECT!!! Number is:" << new_number;

    }
    while(new_number != user_inp);

    return 0;
}
