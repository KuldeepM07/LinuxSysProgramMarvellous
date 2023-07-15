#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        printf("Invalid usage: Please provide file name\n");
        return -1;
    }

    struct stat FileDetails;
    if(stat(argv[1], &FileDetails) < 0)
    {
        printf("Invalid file name.\n");
        return -1;
    }

    printf("Information about file - %s\n", argv[1]);
    printf("---------------------------------------------\n");

    printf("File size:      %ld\n", FileDetails.st_size);
    printf("Number of links:%ld\n", FileDetails.st_nlink);
    printf("Inode number:   %ld\n", FileDetails.st_ino);

    printf("Number of blocks: %ld\n", FileDetails.st_blocks);


    return 0;
}