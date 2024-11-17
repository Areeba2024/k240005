#include<stdio.h>
#include<math.h>
#include<stdbool.h>
#include<string.h>

int BinaryToDecimal(int number)
{
    int digit, answer = 0, power = 0;
    bool flag = true;
    while (number > 0 && flag == true)
    {
        digit = number % 10;
        if (digit == 1 || digit == 0)
        {
            flag = true;
        }
        else
        {
            flag = false;
            printf("Invalid binary number\n");
            break;
        }
        answer = answer + (digit * pow(2, power));
        power++;
        number /= 10;
    }
    return flag ? answer : -1;
} //end BinaryToDecimal

int DecimalToBinary(int number)
{
    if (number == 0)
    {
        return 0;
    }

    return DecimalToBinary(number / 2) * 10 + number % 2;
} //end Decimal to Binary

void DecimalToHexadecimal(int number)
{
    int arr[32];
    int remain, count = 0, i;
    while (number > 0)
    {
        remain = number % 16;
        arr[count] = remain;
        count++;
        number = number / 16;
    }
    for (i = count - 1; i >= 0; i--)
    {
        if (arr[i] >= 10)
        {
            printf("%c", arr[i] - 10 + 'A');
        }
        else
        {
            printf("%d", arr[i]);
        }
    }
} //end Decimal to Hexadecimal

void HexadecimalToDecimal(char hexNumber[], int *decimal)
{
    int len = strlen(hexNumber);
    int sum = 0, base = 1;

    for (int i = len - 1; i >= 0; i--)
    {
        if (hexNumber[i] >= '0' && hexNumber[i] <= '9')
        {
            sum += (hexNumber[i] - '0') * base;
        }
        else if (hexNumber[i] >= 'A' && hexNumber[i] <= 'F')
        {
            sum += (hexNumber[i] - 'A' + 10) * base;
        }
        else if (hexNumber[i] >= 'a' && hexNumber[i] <= 'f')
        {
            sum += (hexNumber[i] - 'a' + 10) * base;
        }
        else
        {
            printf("Invalid hexadecimal number\n");
            *decimal = -1;
            return;
        }
        base *= 16;
    }
    *decimal = sum;
} //end Hexadecimal To Decimal

void BinaryToHexadecimal(int number)
{
    int decimal = BinaryToDecimal(number);
    if (decimal != -1)
    {
        printf("Binary to Hexadecimal = ");
        DecimalToHexadecimal(decimal);
        printf("\n");
    }
}//end Binary To Hexadecimal 

void HexadecimalToBinary(char hexNumber[])
{
    int decimal = 0;
    HexadecimalToDecimal(hexNumber, &decimal);

    if (decimal != -1)
    {
        printf("Hexadecimal to Binary = %d\n", DecimalToBinary(decimal));
    }
    else
    {
        printf("Invalid hexadecimal input, unable to convert.\n");
    }
}

int main()
{
    int choice, number, decimal;
    char hexNumber[20];

    printf("Select conversion option:\n");
    printf("1. Binary to Decimal\n");
    printf("2. Decimal to Binary\n");
    printf("3. Decimal to Hexadecimal\n");
    printf("4. Hexadecimal to Decimal\n");
    printf("5. Binary to Hexadecimal\n");
    printf("6. Hexadecimal to Binary\n");
    printf("Enter your choice (1-6): ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        printf("Enter a binary number: ");
        scanf("%d", &number);
        printf("Binary to Decimal = %d\n", BinaryToDecimal(number));
        break;

    case 2:
        printf("Enter a decimal number: ");
        scanf("%d", &number);
        printf("Decimal to Binary = %d\n", DecimalToBinary(number));
        break;

    case 3:
        printf("Enter a decimal number: ");
        scanf("%d", &number);
        printf("Decimal to Hexadecimal = ");
        DecimalToHexadecimal(number);
        printf("\n");
        break;

    case 4:
        printf("Enter a hexadecimal number: ");
        scanf("%s", hexNumber);
        HexadecimalToDecimal(hexNumber, &decimal);
        printf("Hexadecimal to Decimal = %d\n", decimal);
        break;

    case 5:
        printf("Enter a binary number: ");
        scanf("%d", &number);
        BinaryToHexadecimal(number);
        break;

    case 6:
        printf("Enter a hexadecimal number: ");
        scanf("%s", hexNumber);
        HexadecimalToBinary(hexNumber);
        break;
    
    default:
        printf("Invalid choice!\n");
        break;
    }

    return 0;
}
