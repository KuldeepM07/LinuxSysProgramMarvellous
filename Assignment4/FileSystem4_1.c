#include <stdio.h>

// Write a program which is used 
// to demonstrate concept of I/O redirection

// Usage
// Compile program gcc FileSystem4_1.c -o FileSystem4_1
// Create input.txt file with following text
// 10 20
// run program using file command
// ./FileSystem4_1 < input.txt > output.txt

int main(int argc, char *argv[])
{
    int iNo1 = 0;
    int iNo2 = 0;
    int iAddition = 0;

    scanf("%d", &iNo1);
    scanf("%d", &iNo2);

    iAddition = iNo1 + iNo2;

    printf("Addition is %d", iAddition);

    return 0;
}