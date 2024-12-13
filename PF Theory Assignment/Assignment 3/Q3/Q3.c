#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int validateEmail(char* email) {
    if (email == NULL || strlen(email) == 0) {
        return 0;
    }

    int atCount = 0;
    for (int i = 0; email[i] != '\0'; i++) {
        if (email[i] == '@') {
            atCount++;
        }
    }
    if (atCount != 1) {
        return 0;
    }

    char* atPosition = strchr(email, '@');
    if (atPosition == NULL || strchr(atPosition, '.') == NULL) {
        return 0;
    }

    return 1;  
}

int main() {
    char* email = NULL;
    int max= 100;  
    int length = 0;

    email = (char*)malloc(max * sizeof(char));  

    if (email == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter email address: ");
    
    char ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {
        if (length + 1 >= max) {
            max *= 2;  
            email = (char*)realloc(email, max * sizeof(char));  
            if (email == NULL) {
                printf("Memory reallocation failed!\n");
                return 1;
            }
        }
        email[length++] = ch;
    }
    
    email[length] = '\0';  

    if (validateEmail(email)) {
        printf("Valid Email\n");
    } else {
        printf("Invalid Email\n");
    }

    free(email);

    return 0;
}
