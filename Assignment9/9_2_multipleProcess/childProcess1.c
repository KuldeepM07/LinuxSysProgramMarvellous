#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int fd = 0;
    int fdNewFile = 0;
    int iCountCapitalLetters = 0;
    char cBuffer[512];
    int iRetValReadBytes = 0;
    int iITR = 0;

    printf("Reading capital letters from file: %s\n", argv[0]);

    fd = open(argv[0], O_RDONLY);
    if(fd == -1)
    {
        printf("Unable to open demo.txt file\n");
        return -1;
    }

    // Create new file for writing
    fdNewFile = open("count.txt", O_WRONLY | O_APPEND);
    if(fdNewFile == -1)
    {
        printf("Creating file : %d\n", fdNewFile);
        fdNewFile = creat("count.txt", 0777);
        if(fdNewFile == -1)
        {
            printf("Unable to create output file");
            return -1;
        }
    }
    printf("File opened woith FD : %d\n", fdNewFile);

    while((iRetValReadBytes = read(fd, cBuffer, sizeof(cBuffer))) != 0)
    {
        for(iITR = 0;iITR<iRetValReadBytes;iITR++)
        {
            if(cBuffer[iITR] >= 'A' || cBuffer[iITR] <= 'Z')
            {
                iCountCapitalLetters++;
            }
        }
    }

    sprintf(cBuffer, "Capital letters count in %s: %d\n", argv[0], iCountCapitalLetters);
    write(fdNewFile, cBuffer, strlen(cBuffer));

    close(fd);
    close(fdNewFile);


    return 0;
}