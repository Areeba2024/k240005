#include <stdio.h>

int matchsticks_to_win(int num_matchsticks) {
    
    int remainder = num_matchsticks % 5;
    
    if (remainder == 0) 
    {
        return -1;  
    } else 
    {
        return remainder;  
    }
}

int main() {
    int num_matchsticks;
    int answer;
    printf("Enter the number of matchsticks: ");
    scanf("%d", &num_matchsticks);
    answer = matchsticks_to_win(num_matchsticks);
    
    if (answer == -1) 
    {
        printf(" Impossible for Player A to guarantee a win.\n");
    } 
    else 
    {
        printf("Player A should pick %d matchstick(s) on the first turn to guarantee a win.\n", answer);
    }

    return 0;
}
