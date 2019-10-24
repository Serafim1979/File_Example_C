#include<stdio.h>
#include<stdlib.h>

#define VAR 8

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
    //Editing a text file

    student x;

    int stud_id = 3;
    int grade_id = 1;
    int value = 3;
    long pos;
    int i, j;

    FILE *file = fopen("test2.txt", "r+t");
    if(!file)
    {
        perror("test2.txt");
        exit(1);
    }

    for(i = 0; i <= stud_id; ++i)
    {
        pos = ftell(file);
        fscanf(file, "%s", x.last_name);
        for(j = 0; j < MAXGRADES; ++j)
            fscanf(file, "%2d", &x.grade[j]);
        fscanf(file, "\n");
    }

    x.grade[grade_id] = value;

    fseek(file, pos, SEEK_SET);

    fprintf(file, "%s", x.last_name);
        for(j = 0; j < MAXGRADES; ++j)
            fprintf(file, "%2d", x.grade[j]);

    fclose(file);
    #endif // VAR

    #if VAR == 6
    //creating a direct access text file

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

    FILE *file = fopen("test3.txt", "wt");
    if(!file)
    {
        perror("test3.txt");
        exit(1);
    }

    for(i = 0; i < n; ++i)
    {
        fprintf(file, "%-*s", MAXLEN, group[i].last_name);
        for(j = 0; j < MAXGRADES; ++j)
            fprintf(file, "%2d", group[i].grade[j]);
        fprintf(file, "\n");
    }

    fclose(file);
    #endif // VAR

    #if VAR == 7
    //creating a direct access binary file

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

    FILE *file = fopen("test4.dat", "wb");
    if(!file)
    {
        perror("test4.dat");
        exit(1);
    }

    fwrite(group, sizeof(student), n, file);

    fclose(file);
    #endif // VAR

    #if VAR == 8
    //Editing a binary file

    student x;

    int stud_id = 3;
    int grade_id = 1;
    int value = 3;
    long pos;

    FILE *file = fopen("test4.dat", "r+b");
    if(!file)
    {
        perror("test4.dat");
        exit(1);
    }

    pos = stud_id * sizeof(student);
    fseek(file, pos, SEEK_SET);

    fread(&x, sizeof(student), 1, file);

    x.grade[grade_id] = value;

    fseek(file, pos, SEEK_SET);
    fwrite(&x, sizeof(student), 1, file);

    fclose(file);
    #endif // VAR

    system("pause");
    return 0;
}
