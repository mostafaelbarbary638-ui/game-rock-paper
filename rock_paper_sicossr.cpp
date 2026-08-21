#include <iostream>
#include <bits/stdc++.h>
#include <time.h>

using namespace std;

int main()
{
    bool flag = true ;
    while (flag)
    {
        srand(time(NULL));
        char *letters = "rps" ;
        int random_letters = rand() % 3 ;
        char move1 ;
        cout << "\t\t" << "     Welcome to Stone Paper Scissor Game" << endl << endl ;
        cout << "\t\tEnter r for ROCK, p for PAPER, s for SCISSOR" << endl ;
        cout << "\t\t\t\t    " ;
        cin >> move1 ;
        \
        char move2 = letters[random_letters] ;
        if (move1 == move2)
        {
            cout << "\n" ;
            cout << "It's a draw!" << endl  ;
            cout << "Tie game!" << endl  ;
            cout << "your move : " << move1 << endl ;
            cout << "computer move : " << letters[random_letters] ;
        }
        else if (move1 == 'r' && move2 == 'p' || move1 == 'p' && move2 == 'r')
        {
            cout << "\n" ;
            cout << "Paper wins!" << endl ;
            cout << "your move : " << move1 << endl ;
            cout << "computer move : " << letters[random_letters] ;
        }
        else if (move1 == 'p' && move2 == 's' || move1 == 's' && move2 == 'p')
        {
            cout << "\n" ;
            cout << "Scissor wins!" << endl ;
            cout << "your move : " << move1 << endl ;
            cout << "computer move : " << letters[random_letters] ;
        }
        else if (move1 == 's' && move2 == 'r' || move1 == 'r' && move2 == 's')
        {
            cout << "\n" ;
            cout << "Rock wins!" << endl ;
            cout << "your move : " << move1 << endl ;
            cout << "computer move : " << letters[random_letters] ;
        }
        cout << "\n\n\t\t\t" ;
        cout  << "another game! " ;
        cout  <<"Yes [y]  or   No [n] : " ;
        char another ;
        cin >> another ;
        if(another == 'y')
        {
            system("cls") ;
            continue ;
        }
        else
        {
            cout << "\n\n\t\t\tthanks see you soon!" ;
            flag = false ;
        }
        return 0;
    }

}