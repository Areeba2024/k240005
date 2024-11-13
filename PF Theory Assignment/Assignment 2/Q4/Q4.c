#include <stdio.h>
#include <string.h>

// Function to input words
void input_trans(char words[][10], char copy_words[][10],int *count) {
    int i;
     printf("Enter the number of elements: ");
    scanf("%d", count);  
    getchar();  
    for (i = 0; i < *count; i++) 
    {
        printf("Enter word %d: ", i + 1);
        fgets(words[i], 10, stdin);
        strcpy(copy_words[i],words[i]);
        words[i][strcspn(words[i], "\n")] = '\0';  
        
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

    
}
void group_anagrams(char words[][10], char copy_words[][10], int count) {
    int grouped[10] = {0};  
    
    printf("Anagram groups:\n");
    for (int i = 0; i < count; i++) {
        if (grouped[i]) continue;  
        printf("['%s'", words[i]);
        grouped[i] = 1;

        for (int j = i + 1; j < count; j++) {
            if (!grouped[j] && strcmp(copy_words[i], copy_words[j]) == 0) {
                printf(",'%s'", words[j]);
                grouped[j] = 1;  
            }
        }
        printf("]");  
    }
}


int main() {
    int count;
    char words[10][10]; 
    char copy_words[10][10];
    input_trans(words, copy_words,&count);
    arrange_trans(copy_words, count);
    group_anagrams(words,copy_words,count);

    return 0;
}
