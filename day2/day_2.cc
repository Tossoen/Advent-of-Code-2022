#include<iostream>
#include<fstream>


using namespace std;

enum selected{Rock, Paper, Scissor};

int simulate(selected playerOne, selected playerTwo)
{
    if(playerOne == playerTwo)
        return 0; //draw
    if((playerOne == Rock && playerTwo == Scissor) ||
    (playerOne == Paper && playerTwo == Rock) ||
    (playerOne == Scissor && playerTwo == Paper)
    )
        return 1; //player one wins
    else
        return 2; //player two wins
}

int convert(selected chosen)
{
    if(chosen == Rock)
        return 1;
    if(chosen == Paper)
        return 2;
    else
        return 3;
}

int main()
{
    

    ifstream ifs{"day_2_input.txt"};
    
    char one;
    char two;
    selected a;
    selected b;

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
                b = Rock;
                break;
            case 'Y':
                b = Paper;
                break;
            case 'Z':
                b = Scissor;
                break;
        }

        int result = simulate(b,a);

        if(result == 0)
        {
            points += 3 + convert(b);
        }
        else if(result == 1)
        {
            points += convert(b) + 6;
        }
        else
        {
            points += convert(b);
        }

    

    }

    cout << "Total points: "<< points;
    return 0;
}