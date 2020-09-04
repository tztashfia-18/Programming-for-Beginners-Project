#include <stdio.h>

struct Member {
    char name[30];
    int id;
    char contact[15];
    char email[50];
    char skill[100];
};

int INDEX = 0;
struct Member member[100];



void list()
{

    printf("\n\n\n");
    printf("press 1. Adding New Member Information:\n");
    printf("press 2. Search Member Information:\n");
    printf("press 3. Edit Member Information:\n");
    printf("press 4. Reduce Member Information:\n");
    printf("press 5. View App Forum Event List:\n");
    printf("press 6. Exit:\n");
    printf("\nInput Your Choice:\n");

}


void add_new()
{
    printf("\nAdd New -\n");

    printf("\nEnter Your Name:\n");
    fflush(stdin);
    scanf("%s", member[INDEX].name);
    fflush(stdout);

    printf("\nEnter Your ID:\n");
    scanf("%d", &member[INDEX].id);

    printf("\nEnter Your Contact Number:\n");
    fflush(stdin);
    scanf("%s", member[INDEX].contact);
    fflush(stdout);

    printf("\nEnter Your Email:\n");
    fflush(stdin);
    scanf("%s", member[INDEX].email);
    fflush(stdout);

    printf("\nEnter Your Skill:\n");
    fflush(stdin);
    scanf("%s", member[INDEX].skill);
    fflush(stdout);

    printf("\nNew Member Information Added\n\n");

    INDEX++;

}

void search()
{
    printf("\nSearch\n");

    int i;
    if (INDEX == 0) {
        printf("No Member\n");
    } else {
        for (i = 0; i < INDEX; i++) {
            printf("Member Name: %s\n", member[i].name);
            printf("Member ID: %d\n", member[i].id);
            printf("Contact: %s\n", member[i].contact);
            printf("email: %s\n", member[i].email);
            printf("Skill: %s\n", member[i].skill);
            printf("\n");
        }

    }

}

void edit()
{
    printf("\nEdit\n");

}


void reduce()
{
    printf("\nReduce\n");

}

void view_event()
{
    printf("\nView Events List -\n");

    printf("\a");

    printf("\n\t* C Programming For Beginners\n");
    printf("\t* C++ For Beginners\n");
    printf("\t* Mobile Application Developement\n");
    printf("\t* Web Application Developement\n");
    printf("\t* Git & Github\n");
    printf("\t* Python For Machine Learning\n");
}

int main()
{
    int option;


    printf("\t\t\t\t\t\t\t\t UIU APP FORUM MANAGEMENT SYSTEM\n");

    while(1)
    {
        list();

        scanf("%d", &option);

        if(option == 1)
        {
            add_new();
        }
        else if(option == 2)
        {
            search();
        }
        else if(option == 3)
        {
            edit();
        }
        else if(option == 4)
        {
            reduce();
        }
        else if(option == 5)
        {
            view_event();
        }

        else if(option == 6)
        {
            break;
        }

        else
        {
            printf("Invalid\n");
        }

    }

    return 0;
}
