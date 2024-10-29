#include <stdio.h>
int main() {
    int i, j, k;
    char slogans[3][20];
    int freq[3][20] = {0};

    // Input slogans
    for (i = 0; i < 3; i++) 
    {
        printf("Enter your slogan: ");
        scanf(" %[^\n]", slogans[i]); // This will read the entire string including spaces
    }
    
    for (i = 0; i < 3; i++) 
    {
        for (j = 0; slogans[i][j] != '\0'; j++) 
        {
             if (slogans[i][j] == -1) // skips the repeated elements
            { 
               continue;
            }
            freq[i][j] = 1; //initialize the frequency array to 1
            for (k = j + 1; slogans[i][k] != '\0'; k++) 
            { //checks for the repeated character in the string and increments the frequency as per occurance
                if (slogans[i][j] == slogans[i][k] && slogans[i][j] != ' ') 
                {
                    freq[i][j]++;
                    slogans[i][k] = -1;
                    
                }
            }
        }
    }

    // Print frequencies
    for (i = 0; i < 3; i++) {
        if (i ==0)
        {
            printf("For \"buy now\":");
        }
        if (i ==1)
        {
            printf("For \"save big\":");
        }
        if (i ==2)
        {
            printf("For \"limited offer\":");
        }
        int comma = 1;
        printf("{");
        for (j = 0; slogans[i][j] != '\0'; j++) 
        {
          
            if (slogans[i][j] == -1) //checks for the repeated one and skips it
            { 
               continue;
            }
             if(!comma) // to avoid placing comma at the end , uses flag
            {
                printf(",");
            }
            comma = 0;
            printf("'%c':%d", slogans[i][j], freq[i][j]); //prints the characters along with their frequency for each slogan
        }
        printf("}");
        printf("\n");
    }

    return 0;
}
