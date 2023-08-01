#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>

extern char **environ;

int main()
{
    struct passwd *pw = getpwuid(getuid());
    const char *homedir = pw->pw_dir;

    char cLoginName[512];
    getlogin_r(cLoginName, sizeof(cLoginName));
    
    printf("Home directory of running process is : %s\n", homedir);
    printf("Logged in username is : %s\n", cLoginName);

    char **env = environ;

    // printf("Environment of running process is : \n");

    // for(;*env != NULL; env++)
    // {
    //     printf("%s : \n", *env);
    // }
   
    return 0;
}