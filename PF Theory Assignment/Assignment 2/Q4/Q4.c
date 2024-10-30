#include <stdio.h>
#include <string.h>

// Function to input words
void input_trans(char words[][10], char copy_words[][10],int *count) {
    int i;
     printf("Enter the number of elements: ");
    scanf("%d", count);  // Read the number of words
    getchar();  // Clear newline left by scanf
    for (i = 0; i < *count; i++) 
    {
        printf("Enter word %d: ", i + 1);
        fgets(words[i], 10, stdin);
        strcpy(copy_words[i],words[i]);
        words[i][strcspn(words[i], "\n")] = '\0';  // Remove newline character
        
    }
}

// Function to sort characters within each word
void arrange_trans(char copy_words[][10], int count) {
    char temp;
    int i, j, k;
    
    for (i = 0; i < count; i++) {
        int len = strlen(copy_words[i]);
        // Bubble sort for each word
        for (j = 0; j < len - 1; j++) {
            for (k = 0; k < len - j - 1; k++) {
                if (copy_words[i][k] > copy_words[i][k + 1]) {
                    // Swap characters
                    temp = copy_words[i][k];
                    copy_words[i][k] = copy_words[i][k + 1];
                    copy_words[i][k + 1] = temp;
                }
            }
        }
    }

    // Print sorted words
    for (i = 0; i < count; i++) {
        printf("Sorted word %d: %s\n", i + 1, copy_words[i]);
    }
}
void sort_trans(char copy_words[][10], int count)
{
    for(i=0;i< count;i++)
    {
        for(j=i+1;j<count;j++)
        {
            if(strcamp(copy_words[i],copy_words[j])==0)
            {
                sorted_array[]
                
            }
        }
    }
}
int main() {
    int count;
    char words[10][10]; 
    char copy_words[10][10];// Fixed array size for up to 10 words of max length 9 (+1 for null terminator)

    // Take input
    input_trans(words, copy_words,&count);

    // Sort characters within each word
    arrange_trans(copy_words, count);

    return 0;
}
