/*
Project Overview:

The project will:
1. Take user input (a string)
2. Display a menu with string operations:
    * Reverse string (using recursion)
    * Count vowels and consonants (using pointers)
    * Check palindrome (using recursion)
    * Concatenate two strings (using pointers)
    * Find string length (using recursion)
3. Use separate functions for each task.
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

int StringLength(char *str);
void ReverseString(char *str, int nStart, int nEnd);
int IsPalindrome(char *str, int nStart, int nEnd);
int CountVowels(char *str);
void Concatenate(char *str1, char *str2);

int main()
{
    char str1[100],str2[100],TempStr[100];
    int nChoice;

    printf("Enter a string: ");
    scanf("%s", &str1);
    strcpy(TempStr, str1);

     do {
        printf("\n---- String Operations Menu ----\n");
        printf("1. Find Length (Recursion)\n");
        printf("2. Reverse String (Recursion)\n");
        printf("3. Check Palindrome (Recursion)\n");
        printf("4. Count Vowels and Consonants (Pointers)\n");
        printf("5. Concatenate another string (Pointers)\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &nChoice);
        getchar(); // clear newline from buffer

        switch (nChoice) 
        {
            case 1:
                printf("Length: %d\n", StringLength(str1));
                break;

            case 2:
                ReverseString(str1, 0, StringLength(str1) - 1);
                printf("Reversed: %s\n", str1);
                strcpy(str1,TempStr);
                break;

            case 3:
                if (IsPalindrome(str1, 0, StringLength(str1) - 1))
                    printf("It's a palindrome.\n");
                else
                    printf("Not a palindrome.\n");
                break;

            case 4:
                printf("Vowel Count: %d\n", CountVowels(str1));
                printf("Consonant Count: %d\n", StringLength(str1) - CountVowels(str1));
                break;

            case 5:
                printf("Enter another string: ");
                scanf("%s", &str2);
                Concatenate(str1, str2);
                printf("Concatenated: %s\n", str1);
                strcpy(str1, TempStr);
                break;

            case 6:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!!!\n");
        }

    } while (nChoice != 6);

    return 0;
}

int StringLength(char *str)
{
    if(*str == '\0')
        return 0;
    
    return 1 + StringLength(str + 1);
}

void ReverseString(char *str, int nStart, int nEnd)
{
    if (nStart >= nEnd)
        return;

    char temp = str[nStart];
    str[nStart] = str[nEnd];
    str[nEnd] = temp;

    ReverseString(str, nStart + 1, nEnd - 1);
}

int IsPalindrome(char *str, int nStart, int nEnd) 
{
    if (nStart >= nEnd)
        return 1;
    if (str[nStart] != str[nEnd])
        return 0;
    return IsPalindrome(str, nStart + 1, nEnd - 1);
}

int CountVowels(char *str) 
{
    int count = 0;
    while (*str) 
    {
        char ch = tolower(*str);
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            count++;
        str++;
    }
    return count;
}

void Concatenate(char *str1, char *str2) 
{
    while (*str1) str1++; // move pointer to end of str1
    while (*str2) 
    {
        *str1 = *str2;
        str1++;
        str2++;
    }
    *str1 = '\0';
}
