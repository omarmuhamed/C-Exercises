#include <stdio.h>
#include <stdlib.h>

typedef struct nameStruct
{
    char first[20];
    char last[20];
} Name;
typedef struct SubjectStruct
{
    char name[20];
    int mid;
    int Final;
} Subject;
typedef struct studentStruct
{
    char id[11];
    Name name;
    int SubCount;
    Subject *subject;
} Student;

int scount;

Student *student;

Student *ReadStudents(int);

Subject *ReadSubjects(int);

void ListStudents(int);

void printStudent(Student *, int);

void Search();

int IDSearch(char *);

int string_compare(char *, char *);

void string_copy(char *, char *);

void AddStudent();

void RemoveStudent();

void EditStudent();

int main()
{
    int op;
    printf("Enter students count: ");
    scanf("%d", &scount);
    student = ReadStudents(0);
    system("cls");
QS:
    printf("1. Search for student\n2. Show statue\n3. List all students\n4. Add Student\n5. Delete Student\n6. Edit Student\n7. Exit\nOperation: ");
    scanf("%d", &op);
    switch (op)
    {
    case 1:
        system("cls");
        Search();
        break;
    case 2:
        system("cls");
        ListStudents(1);
        break;
    case 3:
        system("cls");
        ListStudents(2);
        break;
    case 4:
        system("cls");
        AddStudent();
        break;
    case 5:
        system("cls");
        RemoveStudent();
        break;
    case 6:
        system("cls");
        EditStudent();
        break;
    case 7:
        exit(0);
    default:
        printf("Wrong selection, try again.");
        goto QS;
    }
    goto QS;


}

Student *ReadStudents(int mode)
{
    int i;
    char id[11];
    if (mode == 0 || scount == 0)
    {
        if (scount == 0)
            scount++;
        student = (Student *) malloc(sizeof(Student) * scount);
        i = 0;
    }
    else
    {
        i = scount;
        scount++;
        student = (Student *) realloc(student, sizeof(Student) * scount);
    }
    for (; i < scount; i++)
    {
        fflush(stdin);
        printf("Enter first name: ");
        scanf("%s", (student + i)->name.first);
        printf("Enter last name: ");
        scanf("%s", (student + i)->name.last);
ID:
        printf("Enter ID no: ");
        scanf("%s", id);
        if (IDSearch(id) == 1)
        {
            printf("A student with the same ID exists.\n");
            goto ID;
        }
        string_copy((student + i)->id, id);
        printf("Enter subjects count: ");
        scanf("%d", &(student + i)->SubCount);
        (student + i)->subject = ReadSubjects((student + i)->SubCount);


    }
    return student;
}

Subject *ReadSubjects(int count)
{
    int i;
    Subject *subject = (Subject *) malloc(sizeof(Subject) * count);
    for (i = 0; i < count; i++)
    {
        fflush(stdin);
        printf("Enter subject's name: ");
        scanf("%[^\n]*c", (subject + i)->name);
        printf("Enter Vize score: ");
        scanf("%d", &(subject + i)->mid);
        printf("Enter Final score: ");
        scanf("%d", &(subject + i)->Final);
    }
    return subject;
}

void printStudent(Student *stud, int a)
{
    Student *ptr = stud;
    Subject *subptr = ptr->subject;
    int subcount = ptr->SubCount;
    double avg;
    char state;
    if (subcount > 0)
    {
        if (a == 1)
        {
            printf("Name: %s %s\nID: %s\n", ptr->name.first, ptr->name.last, ptr->id);
            printf("---------------------------------------------------------\n");
            printf("|\tName           | Vize |\tFinal |\tAverage | State |\n");
            printf("---------------------------------------------------------\n");
            for (int i = 0; i < subcount; i++)
            {
                avg = (subptr + i)->mid * 0.4 + (subptr + i)->Final * 0.6;
                if (avg > 60.0)
                {
                    state = 'G';
                }
                else
                {
                    state = 'K';
                }
                printf("|\t%-15s| %-5d|\t%-6d|\t%-8.2lf|   %c   |\n", (subptr + i)->name, (subptr + i)->mid,
                       (subptr + i)->Final, avg, state);
                printf("---------------------------------------------------------\n");

            }
        }
        else
        {
            printf("Name: %s %s\nID: %s\n", ptr->name.first, ptr->name.last, ptr->id);
            printf("-------------------------\n|\tName           \t|\n-------------------------\n");
            for (int i = 0; i < subcount; i++)
            {
                printf("|\t%-15s\t|\n-------------------------\n", (subptr + i)->name);
            }
        }
    }
    else
    {
        printf("Name: %s %s\nID: %s\n", ptr->name.first, ptr->name.last, ptr->id);
        printf("No subjects\n-------------------------\n");
    }
}

void ListStudents(int a)
{
    if (scount > 0)
    {
        for (int i = 0; i < scount; i++)
        {
            printStudent((student + i), a);
        }
    }
    else
    {
        printf("There are no students, add some students.\n");
    }
}

int string_compare(char *a, char *b)
{
    int i = 0;

    while (*(a + i) == *(b + i))
    {
        if (*(a + i) == '\0' || *(b + i) == '\0')
            break;
        i++;
    }
    if (*(a + i) == '\0' && *(b + i) == '\0')
        return 1;
    else
        return 0;
}

void Search()
{
    if (scount > 0)
    {
        Student *ptr = student;
        int i;
        char name[20];
        printf("Enter the first name: ");
        scanf("%s", name);
        for (i = 0; i < scount; i++)
        {
            if (string_compare((ptr + i)->name.first, name) == 1)
            {
                printStudent((ptr + i), 1);
            }
        }
    }
    else
    {
        printf("There are no students, add some students.\n");
    }
}

int IDSearch(char *id)
{
    Student *ptr = student;
    int found = 0, i;
    for (i = 0; i < scount; i++)
    {
        if (string_compare((ptr + i)->id, id) == 1)
        {
            found = 1;
            break;
        }
    }
    return found;
}

void string_copy(char *a, char *b)
{
    while ((*a++ = *b++))
    {
        ;
    }
}

void AddStudent()
{
    ReadStudents(1);
}

void RemoveStudent()
{
    if (scount > 0)
    {
        int i;
        int toberemoved;
        char id[11];
        for (i = 0; i < scount; i++)
        {
            printf("Name: %s %s\nID: %s\n----------------------------------------\n", (student + i)->name.first,
                   (student + i)->name.last, (student + i)->id);
        }
ReID:
        printf("Enter student ID: ");
        scanf("%s", id);
        for (i = 0; i < scount; i++)
        {
            if (string_compare((student + i)->id, id) == 1)
            {
                toberemoved = i;
                break;
            }
            if (i == scount - 1)
            {
                printf("Not found\n");
                goto ReID;
            }
        }

        for (i = toberemoved; i < scount - 1; i++)
        {
            *(student + i) = *(student + i + 1);
        }
        free(student + scount - 1);
        scount--;
    }
    else
    {
        printf("There are no students, add some students.\n");
    }
}
void EditStudent()
{
    if (scount > 0)
    {
        char id[11];
        int i,indx;
        int qs,qs1,subindx;
        for (i = 0; i < scount; i++)
        {
            printf("Name: %s %s\nID: %s\n-----------------------------\n", (student+i)->name.first,(student+i)->name.last,(student+i)->id);
        }
EdID:
        printf("Enter student's ID: ");
        scanf("%s", id);
        for(i = 0; i < scount; i++)
        {
            if(string_compare((student+i)->id, id)==1)
            {
                indx = i;
                break;
            }
            if (i == scount-1)
            {
                printf("Not found.\n");
                goto EdID;
            }
        }
        Student *stud = (student+indx);
        printStudent(stud, 0);
EDSTD:
        printf("What do you want to edit? \n1. Name\n2. ID\n3. Subjects\n4. Back to main menu\nOperation: ");
        scanf("%d", &qs);
        switch(qs)
        {
        case 1:
            printf("Enter first name: ");
            scanf("%s", stud->name.first);
            printf("Enter last name: ");
            scanf("%s", stud->name.last);
            printStudent(stud, 0);
            goto EDSTD;
        case 2:
            printf("Enter ID: ");
            scanf("%s", stud->id);
            printStudent(stud, 0);
            goto EDSTD;
        case 3:
            printf("-------------------------\n|\tName           \t|\n-------------------------\n");
            for (int i = 0; i < stud->SubCount; i++)
            {
                printf("|%d. %-15s\t|\n-------------------------\n",i+1,((stud->subject) + i)->name);
            }
EDSB:
            printf("1. Add subject\n2. Remove subject\n3. Back\noperation: ");;
            scanf("%d", &qs1);
            switch(qs1)
            {
            case 1:
                fflush(stdin);
                stud->subject = (Subject *)realloc(stud->subject,sizeof(Subject)*(stud->SubCount+1));
                printf("Subject name: ");
                scanf("%[^\n]*c", ((stud->subject)+stud->SubCount)->name);
                printf("Enter vize score: ");
                scanf("%d", &((stud->subject)+stud->SubCount)->mid);
                printf("Enter final score: ");
                scanf("%d", &((stud->subject)+stud->SubCount)->Final);
                stud->SubCount++;
                printStudent(stud, 0);
                goto EDSB;
            case 2:
                if (stud->SubCount > 0)
                {
                    system("cls");
                    printf("-------------------------\n|\tName           \t|\n-------------------------\n");
                    for (int i = 0; i < stud->SubCount; i++)
                    {
                        printf("|%d. %-15s\t|\n-------------------------\n",i+1,((stud->subject) + i)->name);
                    }
                    printf("Enter subject number: ");
                    scanf("%d", &subindx);
                    subindx--;
                    for(i = subindx; i < stud->SubCount-1; i++)
                    {
                        *((stud->subject)+i) = *((stud->subject)+i+1);
                        printStudent(stud, 0);
                    }
                    stud->SubCount--;
                }
                else
                {
                    printf("No subjects, add some subject.\n");
                    goto EDSB;
                }
                printStudent(stud, 0);
                goto EDSB;
            case 3:
                goto EDSTD;
            default:
                printf("Wrong selection, try again\n");
                goto EDSB;
            }
            printStudent(stud, 0);
            goto EDSTD;
        case 4:
            goto End;
        default:
            printf("Wrong selection\n");
            goto EDSTD;

        }
End:
        system("cls");
        printStudent(stud,0);
    }
    else
    {
        printf("There are no students, add some students\n");
    }
}
