#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
/*In  the  land  of  Puzzlevania,  Aaron,  Bob,  and  Charlie  had  an  argument  overwhich one of them was the greatest puzzler of all time. 
 To end the argumentonce and for all, they agreed on a duel to the death.  Aaron was a poor shooterand only hits his target with a probability of 1/3.  
 Bob was a bit better andhits his target with a probability of 1/2.  Charlie is an expert marksman andnever misses.  A hit means a kill and the person hit drops out of the duel. 
  Tocompensate for the inequities in their marksmanship skills,  it is decided thatthe contestants would fire in turns starting with Aaron, followed by Bob, andthen  by  Charlie.   
  The  cycle  would  repeat  until  there  was  one  man  standing.And  that  man  would  be  remembered  for  all  time  as  the  Greatest  Puzzler  ofAll Time.  
  An obvious and reasonably strategy is for each man to shoot at themost accurate shooter still alive, on the grounds that this shooter is the dead-liest and has the best chance of hitting back. 
   Write a program to simulate theduel  using  this  strategy.   Your  program  should  use  random  numbers  and  theprobabilities given in the problem to determine if a shooter hits the target.  
   You will  likely  want  to  create  multiple  subroutines  and  functions  to  complete  theproblem.  Once you can simulate a single duel, add a loop to your program thatsimulates 10,000 duels.  
   Count the number of times that each contestant winsand print the probability of winning for each contestant (e.g.  for Aaron yourprogram might output ”Aaron won 3595/10000 duels or 35.95%”).*/

// If the random answer is zero, the shot is successful.
int duello()
{
    bool aaron_alive = true;
    bool bob_alive = true;
    bool charlie_alive = true;

    while (true)
    {
        if (aaron_alive)
        { /// Aaron shoots charlie first because he has the highest probability of success

            if (charlie_alive)
            {
                if (rand() % 3 == 0)
                {                          // If Aaron gets random=0  of 3 shots, he hits his opponent.
                    charlie_alive = false; // If Aaron shoots successfully, Charlie gets shot.
                }
            }
            else if (bob_alive)
            {
                if (rand() % 3 == 0)
                {                      // If Aaron gets random=0  of 3 shots, he hits his opponent.
                    bob_alive = false; // If Aaron shoots successfully, Bob gets shot.
                }
            }
            else
            { /// bob and charlie, if both are dead.

                return 1;
            }
        }

        if (bob_alive)
        { /// Bob shoots charlie first because he has the highest probability of success

            if (charlie_alive)
            {
                if (rand() % 2 == 0)
                {                          // If Bob gets random=0 of 2 shots, he hits his opponent.
                    charlie_alive = false; // If Bob shoots successfully, Charlie gets shot.
                }
            }
            else if (aaron_alive)
            {
                if (rand() % 2 == 0)
                {                        // If Bob gets random=0 2 shots, he hits his opponent.
                    aaron_alive = false; // If Bob shoots successfully, Aaron gets shot.
                }
            }
            else
            { /// aaron and charlie, if both are dead.

                return 2;
            }
        }

        if (charlie_alive)
        { /// charlie hits bob first because he's the most successful after him.

            if (bob_alive)
            { ////There is no need for probability for Charlie because she always shoots well.

                bob_alive = false; // if bob is alive then it's charlie's turn bob is definitely shot.
            }
            else if (aaron_alive)
            {                        // There is no need for probability for Charlie because she always shoots well.
                aaron_alive = false; // if aaron is alive then it's charlie's turn aaron is definitely shot.
            }
            else
            { /// aaron and bob, if both are dead.

                return 3;
            }
        }
    }
}

int main()
{

    srand(time(nullptr)); // for random function.

    int aaron_wins = 0;
    int bob_wins = 0;
    int charlie_wins = 0;

    cout << "once for testing\n";
    int test = duello();
    if (test == 1)
    {
        cout << "Aaron won\n";
    }
    else if (test == 2)
    {
        cout << "Bob won\n";
    }
    else
    {
        cout << "Charlie won\n";
    }
    cout << "\n\n\nReal Game\n\n";

    for (int i = 0; i < 10000; i++)
    {
        int winner = duello();

        if (winner == 1)
        {
            aaron_wins++;
        }
        else if (winner == 2)
        {
            bob_wins++;
        }
        else
        {
            charlie_wins++;
        }
    }

    cout << "Aaron won " << aaron_wins << "/10000 duels or " << static_cast<double>(aaron_wins) / 100 << "%\n"; /// I cast it to get a comma percentile.
    cout << "Bob won " << bob_wins << "/10000 duels or " << static_cast<double>(bob_wins) / 100 << "%\n";
    cout << "Charlie won " << charlie_wins << "/10000 duels or " << static_cast<double>(charlie_wins) / 100 << "%\n";

    return 0;
}
