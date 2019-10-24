#include<stdio.h>
#include<stdlib.h>

#define VAR 5

#define MAXLEN 32
#define MAXGRADES 3

typedef struct
{
    char last_name[MAXLEN];
    int grade[MAXGRADES];
}student;

int main()
{
    #if VAR == 1
    //create text file
    FILE *file = fopen("test1.txt", "wt");
    if(!file)
    {
        perror("test1.txt");
        exit(1);
    }

    fputc('*', file);
    fputs("Hello world!\n", file);
    fprintf(file, "%d\n", 2019);

    fclose(file);
    #endif // VAR

    #if VAR == 2
    //read text file
    FILE *file = fopen("test1.txt", "rt");
    int x;
    char buf[256];

    if(!file)
    {
        perror("test1.txt");
        exit(1);
    }

    x = fgetc(file);
    putchar(x);
    fgets(buf, sizeof buf, file);
    fputs(buf, stdout);
    fscanf(file, "%d", &x);
    printf("%d\n", x);

    fclose(file);

    #endif // VAR

    #if VAR == 3
    //read text file unknow struct
    FILE *file = fopen("test1.txt", "rt");
    int x;

    if(!file)
    {
        perror("test1.txt");
        exit(1);
    }

    while((x = fgetc(file))!=EOF)
    {
        putchar(x);
    }

    fclose(file);

    #endif // VAR

    #if VAR == 4
    //create text file

    student group[] =
    {
        {
           "Ivanoff",       {5, 4, 4}
        },
        {
           "Petrasheffsky", {4, 3, 4}
        },
        {
           "Kim",           {5, 3, 5}
        },
        {
           "Pupkin",        {4, 2, 3}
        },
        {
           "Kuzin",         {5, 5, 5}
        }
    };

    const int n = sizeof group/sizeof *group;
    int i, j;

    FILE *file = fopen("test2.txt", "wt");
    if(!file)
    {
        perror("test2.txt");
        exit(1);
    }

    for(i = 0; i < n; ++i)
    {
        fprintf(file, "%s", group[i].last_name);
        for(j = 0; j < MAXGRADES; ++j)
            fprintf(file, "%2d", group[i].grade[j]);
        fprintf(file, "\n");
    }

    fclose(file);
    #endif // VAR

    #if VAR == 5
    //create text file

    student group[] =
    {
        {
           "Ivanoff",       {5, 4, 4}
        },
        {
           "Petrasheffsky", {4, 3, 4}
        },
        {
           "Kim",           {5, 3, 5}
        },
        {
           "Pupkin",        {4, 2, 3}
        },
        {
           "Kuzin",         {5, 5, 5}
        }
    };

    const int n = sizeof group/sizeof *group;
    int i, j;

    FILE *file = fopen("test2.txt", "wt");
    if(!file)
    {
        perror("test2.txt");
        exit(1);
    }

    for(i = 0; i < n; ++i)
    {
        fprintf(file, "%s", group[i].last_name);
        for(j = 0; j < MAXGRADES; ++j)
            fprintf(file, "%2d", group[i].grade[j]);
        fprintf(file, "\n");
    }

    fclose(file);
    #endif // VAR

    system("pause");
    return 0;
}
