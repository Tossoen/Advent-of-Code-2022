#include<iostream>
#include<fstream>


using namespace std;

enum selected{Rock, Paper, Scissor};
enum outcome{Win, Draw, Lose};


int convert(selected chosen)
{
    if(chosen == Rock)
        return 1;
    if(chosen == Paper)
        return 2;
    else
        return 3;
}

selected beats(selected const hand)
{
    selected beats;
    if (hand == Rock)
        beats = Scissor;
    else if (hand == Scissor)
        beats = Paper;
    else
        beats = Rock;

    return beats;
}


selected simulate(selected & opponent, outcome & oc)
{
    selected needed;
    
    if (oc == Draw)
        return opponent;
    else
    {
        needed = beats(opponent);
        if (oc == Lose)
            return needed;
        else
        {
            return beats(needed);
        }
    }
}


int main()
{
    

    ifstream ifs{"day_2_input.txt"};
    
    char one;
    char two;
    selected a;
    outcome b;

    int points;

    while (ifs >> one >> two)
    {
        
        switch(one)
        {
            case 'A':
                a = Rock;
                break;
            case 'B':
                a = Paper;
                break;
            case 'C':
                a = Scissor;
                break;
        }
        switch(two)
        {
            case 'X':
                b = Lose;
                break;
            case 'Y':
                b = Draw;
                break;
            case 'Z':
                b = Win;
                break;
        }

        selected hand = simulate(a,b);

        cout << "Your hand was :";

        if (hand == Rock)
            cout << " Rock";
        else if(hand == Paper)
            cout << " Paper";
        else 
            cout << " Scissor";

        cout << endl;

        if(b == Draw)
        {
            points += 3 + convert(hand);
        }
        else if(b == Win)
        {
            points += convert(hand) + 6;
        }
        else
        {
            points += convert(hand);
        }

        cout << "Points: "<< points << endl;
    

    }

    // A X -- Opponent chooses Rock - You need to Lose, so you choose Scissor
    // A Y -- Opponent chooses Rock - You need to Draw, so you choose Rock
    // A Z -- Opponent chooses Rock - You need to Win, so you choose Paper

    cout << "Total points: "<< points;
    return 0;
}