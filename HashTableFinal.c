//Sec: 3    BN: 2   Name: عزالدين احمد عثمان
//Sec: 3    BN: 3   Name: علاء ربيع سالم
//Sec: 3    BN: 5   Name: علي ماهر عبدالسلام
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#define TableSize 10
#define MaxName 256
#define DeletedNode (student*)(0xFFFFFFFFFFFFFFFFUL)
typedef struct student
{
    int id;
    int day,month,year;
    char name[MaxName];
    int score;
    struct student *next;
}student;
student * hashtable[TableSize]; //table array
//Birthday(closed hashing) linear and Quadratic Hash Function
int Birth_Day_Hash(int a, int b,int c)
{
    return (a+2*b+3*c) % TableSize;
}
//Name(open hashing) chaining hash function
unsigned int Name_hash(char *name)
{
    int length = strlen(name);
    unsigned int hashvalue = 0;
    for( int i=0; i < length; i++)
    {
        hashvalue += name[i];
        hashvalue = (hashvalue * name[i]) % TableSize;
    }
    return hashvalue;
}
//initialize
void init_hash_table()
{
    for(int i=0; i < TableSize; i++)
    {
        hashtable[i]=NULL;
    }
    //table is empty
}
int Memory = TableSize*sizeof(struct student);
int main()
{
    init_hash_table();
    int choice1,choice2,choice3; //switchs
    int i=0; //to insert
    char name[50];  int day, month, year; //data to insert
    student *newStudent;
    // Dynamically allocate an array in the memory using malloc()
    newStudent = (student*)malloc(1024 * sizeof(student));
    system("color 3");
    printf("\n**************************************\n");
    printf("\n               WELCOME                \n");
    printf("\n**************************************\n");
    printf("\nYour Table size is = %d\n", TableSize);
    printf("\n 1.Use Chaining \n");
    printf("\n 2.Use Linear Probing \n");
    printf("\n 3.Use Quadratic Probing \n");
    printf("\n 4.Exit \n");
    printf("\n\nEnter your choice: "); scanf("%d",&choice1);
    system("CLS");
    switch(choice1)
        {
        case 1:
            while(true)
            {
                printf("\n--------------------------------------\n");
                printf("\n Choose what to do using chaining  \n\n");
                printf("\n 1.Insert an element  \n");
                printf("\n 2.Delete an element \n");
                printf("\n 3.Search for an element \n");
                printf("\n 4.Print the table \n");
                printf("\n 5.Exit \n");
                printf("\nEnter your choice: ");
                scanf("%d",&choice2);
                system("CLS");
                switch(choice2)
                {
                    case 1:
                        printf("\nName : ");    scanf("%s",(newStudent[i].name));
                        printf("ID : ");        scanf("%d",(&newStudent[i].id));
                        printf("Day : ");       scanf("%d",(&newStudent[i].day));
                        printf("Month : ");     scanf("%d",(&newStudent[i].month));
                        printf("Year : ");      scanf("%d",(&newStudent[i].year));
                        printf("Score : ");     scanf("%d",(&newStudent[i].score));
                        chaining_insert(&newStudent[i]);
                        i++;
                        system("pause");
                        system("CLS");
                        break;
                    case 2:
                        printf("\nName : ");    scanf("%s",name);
                        chaining_delete(&name);
                        system("pause");
                        system("CLS");
                        break;
                    case 3:
                        printf("\nName : ");    scanf("%s",name);
                        chaining_search(&name);
                        system("pause");
                        system("CLS");
                        break;
                    case 4:
                        chaining_print_table();
                        system("pause");
                        system("CLS");
                        break;
                    case 5:
                        exit(0);
                        break;
                    default:
                        printf("\n Wrong Choice\n");
                        system("pause");
                        system("CLS");
                        break;
                }
            }
            break;
        case 2:
            while(true)
            {
                printf("\n--------------------------------------\n");
                printf("\n Choose what to do using Linear probing  \n\n");
                printf("\n 1.Insert an element  \n");
                printf("\n 2.Delete an element \n");
                printf("\n 3.Search for an element \n");
                printf("\n 4.Print the table \n");
                printf("\n 5.Exit \n");
                printf("\nEnter your choice: "); scanf("%d",&choice3);
                system("CLS");
                switch(choice3)
                {
                    case 1:
                        printf("\nName : ");    scanf("%s",(newStudent[i].name));
                        printf("ID : ");        scanf("%d",(&newStudent[i].id));
                        printf("Day : ");       scanf("%d",(&newStudent[i].day));
                        printf("Month : ");     scanf("%d",(&newStudent[i].month));
                        printf("Year : ");      scanf("%d",(&newStudent[i].year));
                        printf("Score : ");     scanf("%d",(&newStudent[i].score));
                        linear_probing_insert(&newStudent[i]);
                        i++;
                        system("pause");
                        system("CLS");
                        break;
                    case 2:
                        printf("\nName : ");    scanf("%s",name);
                        printf("Day : ");       scanf("%d",&day);
                        printf("Month : ");     scanf("%d",&month);
                        printf("Year : ");      scanf("%d",&year);
                        probing_delete(&name, day, month, year);
                        system("pause");
                        system("CLS");
                        break;
                    case 3:
                        printf("\nName : ");    scanf("%s",name);
                        printf("Day : ");       scanf("%d",&day);
                        printf("Month : ");     scanf("%d",&month);
                        printf("Year : ");      scanf("%d",&year);
                        probing_search(&name, day, month, year);
                        system("pause");
                        system("CLS");
                        break;
                    case 4:
                        probing_print_table();
                        system("pause");
                        system("CLS");
                        break;
                    case 5:
                        exit(0);
                        break;
                    default:
                        printf("\n Wrong Choice\n");
                        system("pause");
                        system("CLS");
                        break;
                }
            }
            break;
        case 3:
            while(true)
            {
                printf("\n--------------------------------------\n");
                printf("\n Choose what to do using Quadratic probing  \n\n");
                printf("\n 1.Insert an element  \n");
                printf("\n 2.Delete an element \n");
                printf("\n 3.Search for an element \n");
                printf("\n 4.Print the table \n");
                printf("\n 5.Exit \n");
                printf("\nEnter your choice: "); scanf("%d",&choice3);
                system("CLS");
                switch(choice3)
                {
                    case 1:
                        printf("\nName : ");    scanf("%s",(newStudent[i].name));
                        printf("ID : ");        scanf("%d",(&newStudent[i].id));
                        printf("Day : ");       scanf("%d",(&newStudent[i].day));
                        printf("Month : ");     scanf("%d",(&newStudent[i].month));
                        printf("Year : ");      scanf("%d",(&newStudent[i].year));
                        printf("Score : ");     scanf("%d",(&newStudent[i].score));
                        quadratic_probing_insert(&newStudent[i]);
                        i++;
                        system("pause");
                        system("CLS");
                        break;
                    case 2:
                        printf("\nName : ");    scanf("%s",name);
                        printf("Day : ");       scanf("%d",&day);
                        printf("Month : ");     scanf("%d",&month);
                        printf("Year : ");      scanf("%d",&year);
                        probing_delete(&name, day, month, year);
                        system("pause");
                        system("CLS");
                        break;
                    case 3:
                        printf("\nName : ");    scanf("%s",name);
                        printf("Day : ");       scanf("%d",&day);
                        printf("Month : ");     scanf("%d",&month);
                        printf("Year : ");      scanf("%d",&year);
                        probing_search(&name, day, month, year);
                        system("pause");
                        system("CLS");
                        break;
                    case 4:
                        probing_print_table();
                        system("pause");
                        system("CLS");
                        break;
                    case 5:
                        exit(0);
                        break;
                    default:
                        printf("\n Wrong Choice\n");
                        system("pause");
                        system("CLS");
                        break;
                }
            }
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("\n Wrong Choice\n");
            system("pause");
            system("CLS");
            break;
        }
    return 0;
}
//Chaining print
void chaining_print_table()
{
    printf("\n");
    for(int i=0; i < TableSize; i++)
    {
        if(hashtable[i] == NULL)
        {
            printf("\t%i\t---\n", i);
        }
        else
        {
            printf("\t%i\t",i);
            student *tmp = hashtable[i];
            while(tmp != NULL)
            {
                printf("%s - ", tmp->name);
                tmp = tmp->next;
            }
            printf("\n");
        }
    }
    printf("\nThe size of memory = %d Bytes \n", Memory);
    printf("\n");
}
//Linear and Quadratic probing print
void probing_print_table()
{
    printf("\n");
    for(int ii=0; ii < TableSize; ii++)
    {
        if(hashtable[ii] == NULL)
        {
            printf("\t%i\t---\n", ii);
        }
        else if(hashtable[ii] == DeletedNode)
            printf("\t%i\t---\n", ii);
        else
            printf("\t%i\tname: %s\tid: %d\tbirthday: %d/%d/%d\tscore: %d\n",ii,
                   hashtable[ii]->name,
                   hashtable[ii]->id,
                   hashtable[ii]->day, hashtable[ii]->month, hashtable[ii]->year,
                   hashtable[ii]->score);
    }
    printf("\n");
    printf("\nThe size of memory taken = %d Bytes\n\n", Memory);
}
//Chaining insert
void chaining_insert(student *s)
{
    if(s == NULL) return false;
    int index = Name_hash(s->name);
    s->next = hashtable[index];
    hashtable[index] = s;
    if(hashtable[index]->next != NULL)
    {
            Memory += 280;
    }

    return true;
}
//Chaining search
void chaining_search(char *name)
{
    int index = Name_hash(name);
    student *tmp = hashtable[index];
    while(tmp != NULL && strncmp(tmp->name, name, TableSize) != 0)
    {
        tmp = tmp->next;
    }
    if(tmp == NULL)
     { printf("\nElement doesn't exist in the table\n\n"); return; }
    else
    {
        printf("\nName is Found\n\n");
        printf("Name: %s \n", tmp->name);
        printf("ID: %d \n", tmp->id);
        printf("Birthday: %d/%d/%d \n", tmp->day, tmp->month, tmp->year);
        printf("Score: %d \n\n", tmp->score);
        return;
    }
}
//Chaining delete
void chaining_delete(char *name)
{
    int index = Name_hash(name);
    student *tmp = hashtable[index];
    student *prev = NULL;
    while(tmp != NULL && strncmp(tmp->name, name, TableSize) != 0)
    {
        prev = tmp;
        tmp = tmp->next;
    }
    if(tmp == NULL)
    {
        printf("\n\nElement doesn't exist in the table\n\n");
        return NULL;
    }
    if(prev == NULL)
    {
        //deleting the head
        hashtable[index] = tmp->next;
        printf("\n\nElement Deleted\n\n");
    }
    else
    {
        prev->next = tmp->next;
    }
    if(prev != NULL)
       {
           Memory -= 280;
           printf("\n\nElement Deleted\n\n");
       }
    return tmp;
}

//Linear probing insert
void linear_probing_insert(student *s)
{
    if(s == NULL) return false;
    int index = Birth_Day_Hash(s->day, s->month, s->year);
    for(int i=0; i < TableSize; i++)
    {
        int trial = (i + index) % TableSize;
        if(hashtable[trial] == DeletedNode)
        {
            hashtable[trial] = s;
            return true;
        }
        if(hashtable[trial] == NULL)
        {
            hashtable[trial] = DeletedNode;
            hashtable[trial] = s;
            return true;
        }
    }
    return false;
}
//Quadratic probing insert
void quadratic_probing_insert(student *s)
{
    if(s == NULL) return false;
    int index = Birth_Day_Hash(s->day, s->month, s->year);
    for(int i=0; i < TableSize; i++)
    {
        int trial = (index + i^2) % TableSize;
        if(hashtable[trial] == DeletedNode)
        {
            hashtable[trial] = s;
            return true;
        }
        if(hashtable[trial] == NULL)
        {
            hashtable[trial] = DeletedNode;
            hashtable[trial] = s;
            return true;
        }
    }
    return false;
}
//Linear and Quadratic probing search
void probing_search(char *name, int day, int month, int year)
{
    int index = Birth_Day_Hash(day, month, year);
    for(int i=0; i < TableSize; i++)
    {
        int trial = (index + i) % TableSize;
        if(hashtable[trial] == NULL)
        {
            printf("\nItem doesn't exit in the table\n");
            return; //not here
        }
        if(hashtable[trial] == DeletedNode) continue;
        if(strncmp(hashtable[trial]->name, name, TableSize) == 0 &&
           hashtable[trial]->day == day &&
           hashtable[trial]->month == month &&
           hashtable[trial]->year == year)
        {
            printf("\nplace= %d\n\n", trial);
            printf("Name: %s \n", hashtable[trial]->name);
            printf("ID: %d \n", hashtable[trial]->id);
            printf("Birthday: %d/%d/%d \n", hashtable[trial]->day, hashtable[trial]->month, hashtable[trial]->year);
            printf("Score: %d \n\n", hashtable[trial]->score);
            return;
        }
    }
    return;
}
//Linear and Quadratic probing delete
void probing_delete(char *name, int day, int month, int year)
{
    int index = Birth_Day_Hash(day,month,year);
    for(int i=0; i < TableSize; i++)
    {
        int trial = (index + i) % TableSize;
        if(hashtable[trial] == NULL)
        {
            printf("\n\nElement doesn't exist in the table\n\n");
            return NULL;
        }
        if(hashtable[trial] == DeletedNode) continue;
        if(strncmp(hashtable[trial]->name, name, TableSize) == 0 &&
           hashtable[trial]->day == day &&
           hashtable[trial]->month == month &&
           hashtable[trial]->year == year)
        {
            student *tmp = hashtable[trial];
            hashtable[trial] = DeletedNode;
            printf("\n\nElement Deleted\n\n");
            return;
        }
    }
    return NULL;
}
