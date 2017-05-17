//"Simple Betting game"
//"Jack Queen King" - computer shuffles these cards"
//player has to guess the position of queen.
//if he wins, he take 3*bet
//if he looses, he looses the bet amount.
//player has $100 initially
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
int cash = 100;

void Play(int bet)
{
    char C[3] = {'J','Q','K'};
    // printf ("Shuffing...\n");
    printf ("洗牌咯。。。\n");
    srand(time(NULL));//seeding random number generator
    int i;
    for (i = 0; i<5; i++)
    {
        int x = rand() % 3;
        int y = rand() % 3;
        int temp = C[x];
        C[x] = C[y];
        C[y] = temp;//swaps characters at position x and y
    }
    int playerGuess;
    // printf ("What's the position of queen - 1,2 or 3 ?");
    printf ("Q在几号 （1,2,3) : ");
    scanf ("%d",&playerGuess);
    if(C[playerGuess -1] == 'Q')
    {
        cash = cash + 3*bet;
        // printf ("You win ! Result = %c %c %c Total Cash = %d", C[0],C[1],C[2],cash);
        printf ("你赢啦！翻牌： %c %c %c 你的钱： %d 万美金", C[0],C[1],C[2],cash);

    }
    else
    {
        cash = cash - bet;
        // printf ("You Loose ! Result = \"%c %c %c\" Total Cash = %d\n", C[0 ],C[1],C[2],cash);
        printf ("你输了！翻牌： \"%c %c %c\" 你的钱: %d 万美金 \n",C[0],C[1],C[2],cash);
    }
}

int main()
{
    int bet;
    // printf ("Welcome to the Virtual Casino\n");
    printf ("欢迎来到澳门金沙赌城！\n");
    // printf ("Total cash = $%d\n", cash);
    printf ("我有100万美金，狂欢开始！\n");
    printf ("玩法：三张牌 “J Q K”，猜中Q，赢得三倍赌注！未猜中只扣掉赌注，每猜一次都进行洗牌！\n");
    while (cash > 0)
    {
        // printf ("What'S your bet?  $");
        printf ("\n请下赌注 $ : ");
        scanf("%d",&bet);
        if (bet == 0 || bet > cash) break;
        Play(bet);
        printf ("\n******************************************\n"); 
    }  
}
