// Question Link : https://www.hackerrank.com/contests/itu-acm-algo-101-contest-22-23/challenges/tower-breakers-1
// Author : Ömer Faruk Erdem

//Time Complexity = O(1)
//Space Complexity = O(1)

/*
    In this question we are asked to determine the winner of the game that is given.
    Altough it seems complicated to find the winner it is not.
    
    NOTE :Every tower can be reduced to 1 since 1 divides any integer !

    If we examine the situtaions like :
_________________________________________________________________________________________________
    n=2  m=1
        There are 2 towers with 1 height.                       1 1
        Player 1 starts the game as a rule of the game.
        There is no move to do by Player 1 because all of the towers have height 1.
        To make a move we need to have towers that has heights's more than 1. (By the given rule 1 <= y < x)
        Winner will be Player 2 since there is no move to do by Player 1.
    
    ->We understood that m==1 (All towers's height is 1) is a special case. In that case Player 2 always wins.

    *To get further in the solution lets examine other situations
    
_________________________________________________________________________________________________  
    
    n=2 m=3

        In this case we have 2 towers with height 3             3 3
        So Player 1 can reduce first tower's height to 1        1 3 
        And Player 2 might do the same                          1 1
        In this case Player 1 loses because when he has to move there is no move option
_________________________________________________________________________________________________  

    n=3 m=3
        In this case we have 3 towers with height 3             3 3 3
        So Player 1 can reduce first tower's height to 1        1 3 3 
        And Player 2 might do the same to second tower          1 1 3
        Player 1 plays again                                    1 1 1
        And now Player 2 loses since there is no move to make
_________________________________________________________________________________________________  

    ************************************************************************************************
    *   Result: You should have noticed that when the number of the towers is even Player 2 wins   *
    *                                    and when the number of the towers is odd  Player 1 wins   *
    *   So we got the algorithm :                                                                  *
    *   -->If all of the towers's height is 1 Player 2 always wins                                 *
    *   -->If number of towers (n) is even Player 2 always wins                                    *
    *   -->If number of towers (n) is odd  Player 1 always wins                                    *
    ************************************************************************************************
*/

int towerBreakers(int n, int m) {
    // If the towers's height is one then Player 2 wins.
    if(m == 1) return 2;

    // If the number of towers is odd then Player 1 will win, otherwise Player 2.
    if( n%2 == 1) return 1;
    else return 2;
}