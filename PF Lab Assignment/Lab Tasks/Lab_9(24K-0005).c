//Q1.

#include<stdio.h>
#include<stdbool.h>
#include<string.h>
int main()
{
    int i,j,len;
    int arr_flag[5] ={0};
	char words[5][20];
	for(i=0;i<5;i++)
	{
		printf("Enter word %d: ",i+1);
		scanf("%s",words[i]);
	}
	for(i=0;i<5;i++)
	{
		len = strlen(words[i]);
		arr_flag[i] = 0;
		for(j=0;j < len/2;j++)
		{
			if(words[i][j] != words[i][len-j-1])
			{
				arr_flag[i] = 1;
				break;
			}
		}
	}
	for(i=0;i<5;i++)
	{
	    if(arr_flag[i] == 0)
	{
		printf("%s is a Palindrome\n",words[i]);	
	}
	else 
	{
		printf("%s is not a Palindrome\n",words[i]);
	}
	}
	return 0;
}//end Q1 main

//Q2

#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int num1, num2;
    printf("Enter the first number: ");
    scanf("%d", &num1);
    printf("Enter the second number: ");
    scanf("%d", &num2);

    printf("\nBefore swapping:\n");
    printf("First number: %d\n", num1);
    printf("Second number: %d\n", num2);

    swap(&num1, &num2);

    printf("\nAfter swapping:\n");
    printf("First number: %d\n", num1);
    printf("Second number: %d\n", num2);

    return 0;
}//end Q2

//Q3

#include <stdio.h>
#include <stdbool.h>

bool isPrime(int number) {
    if (number <= 1) {
        return false;
    }
    for (int i = 2; i * i <= number; i++) {
        if (number % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int num;
    char choice;
    do {
        printf("Enter a number: ");
        scanf("%d", &num);

        if (isPrime(num)) {
            printf("%d is a prime number\n", num);
        } else {
            printf("%d is not a prime number\n", num);
        }

        
        printf("Do you want to check another number? Enter (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    return 0;
}//end Q3 main

//Q4

#include <stdio.h>

float calculate(float num1, float num2, char operator) {
    switch (operator) {
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        case '*':
            return num1 * num2;
        case '/':
            if (num2 != 0) 
            {
                return num1 / num2; 
            } else 
            {
                printf("Error: Division by zero is not allowed.\n");
                return 0;
            }
        default:
            printf("Error: Invalid operator.\n");
            return 0;
    }
}

int main() {
    float number1, number2, result;
    char operator;
    printf("Enter the first number: ");
    scanf("%f", &number1);

    printf("Enter the second number: ");
    scanf("%f", &number2);

    printf("Enter the operation (+, -, *, /): ");
    scanf(" %c", &operator);

    result = calculate(number1, number2, operator);
        
    if (operator == '+' || operator == '-' || operator == '*' || operator == '/') {
        printf("Result: %.2f %c %.2f = %.2f\n", number1, operator,number2, result);
    }

    return 0;  
}//end Q4 main

//Q5
#include <stdio.h>
#include <string.h>

// 
void reverseString(char str[], char reversed[]) {
    int len = strlen(str);
    int j = 0;
    for (int i = len - 1; i >= 0; i--) {
        reversed[j++] = str[i];
    }
    reversed[j] = '\0'; 
}

int main() {
    char str[100];
    char reversed[100];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    str[strcspn(str, "\n")] = '\0';
    reverseString(str, reversed);
    printf("Reversed string: %s\n", reversed);

    return 0;
}//end Q5 main



//Q6
#include <stdio.h>

void MaxMin(int arr[], int size, int *max, int *min) {
    *max = arr[0];
    *min = arr[0];
    
    for (int i = 1; i < size; i++) 
    {
        if (arr[i] > *max) 
        {
            *max = arr[i];
        }
        if (arr[i] < *min)
        {
            *min = arr[i];
        }
    }
}

int main() 
{
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int arr[n];
   
    for (int i = 0; i < n; i++) 
    {
        printf("Enter %d integer: ", i+1);
        scanf("%d", &arr[i]);
    }
    
    int max, min;
    MaxMin(arr, n, &max, &min);
    printf("Maximum element: %d\n", max);
    printf("Minimum element: %d\n", min);
    
    return 0;
}//end Q6 main




