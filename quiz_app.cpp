#include <bits/stdc++.h>
using namespace std ;

class quiz_app
{
private :
    string name ;
    int points = 0 ;
    string answer ;
public :
    void print_name()
    {
        cout << "YOUR NAME : " ; cin >> name ;
    }
    void first_question()
    {
        system("cls") ;
        cout << "\t\t\tFIRST QUESTION"<< endl ;
        cout << "\n1. What are access modifiers in C++ ?" << endl ;
        cout << "\n A. public" << endl << "\n B. private" << endl << "\n C. protected" << endl << "\n D. All" << endl ;
        cout << "\nAnswer : " ; cin >> answer ;
        if (answer == "D" || answer == "d") { points+=5 ; cout << "\nCorrect " << endl ; }
        else {cout << "\nIncorrect! " << endl  ;}
        answer = "" ;
    }
    void second_question()
    {
        system("\npause") ; system("cls");
        cout << "\t\t\tSECOND QUESTION"<< endl ;
        cout << "\n2. Which of the following is used for comments in C++ ?" << endl ;
        cout << "\n A.  /* comment */"<< endl << "\n B. //comment */" << endl << "\n C. // comment" << endl << "\n D. both // comment or /* comment */" << endl ;
        cout << "\nAnswer : " ; cin >> answer ;
        if (answer == "D" || answer == "d") {cout << "\nCorrect " << endl ; points+=5 ; }
        else { cout << "\nIncorrect! " << endl ; }
        answer = "" ;

    }
    void third_question()
    {
        system("\npause") ; system("cls") ;
        cout << "\t\t\tTHIRD QUESTION"<< endl ;
        cout << "\n3. Which of the following extension is used for user-defined header file in c++ ?" << endl ;
        cout << "\n A.  hg" << endl << "\n B. cpp" << endl << "\n C. h" << endl << "\n D. hf" << endl ;
        cout << "\nAnswer : " ; cin >> answer ;
        if (answer == "C" || answer == "c") {cout << "\nCorrect " ; points+=5 ; }
        else {cout << "\nIncorrect! " << endl ;}
        answer = "" ;
    }
    void forth_question()
    {
        system("\npause") ; system("cls") ;
        cout << "\t\t\tFORTH QUESTION"<< endl ;
        cout << "\n4. Which of the following is a correct identifier in C++ ?" << endl ;
        cout << "\n A. VAR_1234" << endl << "\n B. $var_name" << endl << "\n C. 7VARNAME" << endl << "\n D. 7var_name" << endl ;
        cout << "\nAnswer : " ; cin >> answer ;
        if (answer == "A" || answer == "a" ) {cout << "\nCorrect " ; points+=5 ; }
        else {cout << "\nIncorrect! " << endl ;}
        answer = "" ;
    }
    void fifth_question()
    {
        system("\npause") ; system("cls") ;
        cout << "\t\t\tFIFTH QUESTION"<< endl ;
        cout << "\n5. Which of the following is not a type of Constructor in C++ ?" << endl ;
        cout << "\n A. Default constructor" << endl << "\n B. Parameterized constructor" << endl << "\n C. Copy constructor" << endl << "\n D. Friend constructor" << endl ;
        cout << "\nAnswer : " ; cin >> answer ;
        if (answer == "d" || answer == "D" ) {cout << "\nCorrect " ; points+=5 ; }
        else {cout << "\nIncorrect! " << endl ;}
        answer = "" ;
    }
    int get_points()
    {
        return points ;
    }
    string get_name()
    {
        return name ;
    }


};
int main()
{
    bool flag = true ;
    char anothertime ;
    quiz_app p1 ;
    while(flag)
    {
        //first output ;
        cout << "\t\t\tHELLO TO THE QUIZ APP (C++ FANDAMINTALS)" << endl << endl ;
        cout << "THE INSTRUCTIONS IS :" << endl << "1. The exam consists of 5 questions " << endl << "2. There is no specific time to answer." << endl ; ;
        cout << "3. Each correct answer is worth 5 points." << endl << "4. Every incorrect answer is worth zero points." << endl << endl ;
        // methods of class quiz app ;
        p1.print_name() ;
        p1.first_question() ;
        p1.second_question() ;
        p1.third_question() ;
        p1.forth_question() ;
        p1.fifth_question() ;
        system("pause") ; system("cls") ;
        cout << "\nYOUR POINTS IS : " << p1.get_points() << endl ;
        system("\n\n\npause") ; system("cls") ;
        // another time ;
        cout << "\nAnother time " << p1.get_name() << " [y:n] : " ; cin >> anothertime ;
        cout << endl ;
        if(anothertime == 'n') {flag = false ;}
        else { system("cls") ; continue ; }

    }
    return 0 ;
}
