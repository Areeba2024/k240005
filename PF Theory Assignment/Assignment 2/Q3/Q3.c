#include<stdio.h>
int main()
{
	int i,j,k;
	int freq[3][20] = {0};
	char words[3][20];
	 for (i = 0; i < 3; i++) 
    {
        printf("Enter your words : ");
        scanf(" %[^\n]", words[i]);
    }
     for (i = 0; i < 3; i++) 
    {
        for (j = 0; words[i][j] != '\0'; j++) 
        {
             if (words[i][j] == -1) // skips the repeated elements
            { 
               continue;
            }
            freq[i][j] = 0; 
            for (k = j + 1; words[i][k] != '\0'; k++) //checks for the repeated character in the string and increments the frequency as per occurance
            { 
                if (words[i][j] == words[i][k] && words[i][j] != ' ') 
                {
                    freq[i][j]++;
                    words[i][k] = -1;
                    
                }
            }
        }
    }
    
     for (i = 0; i < 3; i++) 
    {
        for (j = 0; words[i][j] != '\0'; j++) 
        {
        	 if (words[i][j] == -1) // skips the repeated elements
            { 
               continue;
            }
            printf("%c",words[i][j]);
        }
       printf("\n");
        for (j = 0; words[i][j] != '\0'; j++) 
        {
        	if(freq[i][j] > 1)
            {
            	printf("Letter %c has been repeated for %d times ",words[i][j],freq[i][j]);
            	printf("\n");
            }
       }
      
    }
}
