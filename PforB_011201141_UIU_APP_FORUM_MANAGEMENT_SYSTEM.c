#include<stdio.h>


struct Member

    {
    char name[30];
    char id[10];
    char contact[15];
    char email[50];
    char skill[100];

    }member;


void list()
{

    printf("\n\n\n");
    printf("press A. Adding New Member Information:\n");
    printf("press V. View All Member List:\n");
    printf("press S. Search Member Information:\n");
    printf("press E. Edit Member Information:\n");
    printf("press R. Reduce Member Information:\n");
    printf("press P. View App Forum Event List:\n");
    printf("press Q. Exit:\n");
    printf("\nInput Your Choice:\n");

}


void add_new()
{
    printf("\nAdd New -\n");

    FILE *f;
	char test;
	f = fopen("data.txt","ab+");

	if(f == 0)
	{
        f = fopen("data.txt","wb+");
		printf("\n\t\tPress any key to continue");
		getch();
	}

	while(1)
	{

		printf("\nEnter Name:\n");
        fflush(stdin);
        scanf("%[^\n]", &member.name);
        fflush(stdout);

		printf("\nEnter ID:\n");
		fflush(stdin);
        scanf("%[^\n]", member.id);
        fflush(stdout);

        printf("\nEnter Contact Number:\n");
        fflush(stdin);
        scanf("%[^\n]", member.contact);
        fflush(stdout);

        printf("\nEnter Email:\n");
        fflush(stdin);
        scanf("%[^\n]", member.email);
        fflush(stdout);

        printf("\nEnter Skill:\n");
        fflush(stdin);
        scanf("%[^\n]", member.skill);
        fflush(stdout);

		fwrite(&member,sizeof(member),1,f);
		fflush(stdin);
		printf("One Member Record Successfully Added");
		printf("\n\nPress ESC Key To Exit, \n\n\t Press Any Other Key To Add Other Record:");
		test = getch();

		if(test == 27) // As ASCII value of esc is 27
            break;
	}

	fclose(f);

    printf("\n\nEnter Any Key To Continue");
    getch();
}

void View_All()
{

    FILE *f;
	int i;
	if((f = fopen("data.txt","rb+")) == NULL)
		exit(0);


	printf("Member Name\t\tMember ID\tContact Number\tEmail\t\t\tSkill\n");

	for(i = 0; i<100; i++)

		printf("-");

	while(fread(&member,sizeof(member),1,f) == 1)
	{
		printf("\n%s\t\t%s\t%s\t%s\t\t%s\n",member.name, member.id, member.contact, member.email, member.skill);
	}

	printf("\n");
	for(i = 0; i<100; i++)

		printf("-");

    fclose(f);

    printf("\n\nEnter Any Key To Continue");
    getch();

}

void search()
{
    printf("\nSearch -\n");

    int i;
    FILE *f;
	char member_id[10];
	int flag = 1;

	f = fopen("data.txt","rb+");

	if(f == 0)
    {
        exit(0);
    }


	fflush(stdin);
	printf("Enter Member ID To search Info: ");
	scanf("%s", member_id);

	while(fread(&member, sizeof(member), 1, f) == 1)
	{
		if(strcmp(member.id,member_id) == 0)
		{
			printf(" Record Found\n\n");

			printf("\n\nMember Name\t\tMember ID\tContact Number\tEmail\t\t\tSkill\n");

			for(i = 0; i<100; i++)
            printf("-");
			printf("\n%s\t\t%s\t%s\t%s\t\t%s\n",member.name, member.id, member.contact, member.email, member.skill);
			flag = 0;
			break;
		}
		else if(flag == 1)
		{
			printf("Not Found");
		}
	}
	fclose(f);

	printf("\n\nEnter Any Key To Continue");
	getch();

}

void edit()
{
    printf("\nEdit -\n");

    FILE *f;
	char member_id[10];
	long int size = sizeof(member);
	if((f = fopen("data.txt","rb+")) == NULL)
    {
        exit(0);
    }

	printf("\n\nEnter Member ID To Edit Info:");
	scanf("%[^\n]",member_id);
	fflush(stdin);

	while(fread(&member, sizeof(member), 1, f) == 1)
	{
		if(strcmp(member.id,member_id) == 0)
		{

			printf("\nEnter Name:\n");
            fflush(stdin);
            scanf("%[^\n]", &member.name);
            fflush(stdout);

            printf("\nEnter ID:\n");
            fflush(stdin);
            scanf("%[^\n]", member.id);
            fflush(stdout);

            printf("\nEnter Contact Number:\n");
            fflush(stdin);
            scanf("%[^\n]", member.contact);
            fflush(stdout);

            printf("\nEnter Email:\n");
            fflush(stdin);
            scanf("%[^\n]", member.email);
            fflush(stdout);

            printf("\nEnter Skill:\n");
            fflush(stdin);
            scanf("%[^\n]", member.skill);
            fflush(stdout);

            fseek(f, -size, SEEK_CUR);

			fwrite(&member, sizeof(member), 1, f);
			break;

		}

	}

	printf("/nThe member_id %s Successfully Edited!!!!", member_id);
	fclose(f);

	printf("\n\nEnter Any Key To Continue: ");
	getch();
}


void reduce()
{
    printf("\nReduce -\n");

    FILE *f,*t;
	int i = 1;
	char member_id[10];

	if((t = fopen("temp.txt","w+")) == NULL)
    {
        exit(0);
    }

	if((f = fopen("data.txt","rb")) == NULL)
    {
        exit(0);
    }

	printf("\n\nEnter Member ID To Remove Info: ");
	fflush(stdin);

	scanf("%[^\n]", member_id);
	while(fread(&member, sizeof(member), 1, f) == 1)
	{
		if(strcmp(member.id,member_id) == 0)
		{
		    i = 0;
			continue;

		}
		else
        {
            fwrite(&member, sizeof(member), 1, t);
        }

	}
	if(i == 1)
	{
		printf("Member Id %s not found", member_id);
		fflush(stdin);
		remove("data.txt");
		fflush(stdin);
		rename("temp.txt","data.txt");
		printf("\n\nEnter any key to Continue");
		getch();

		fclose(f);
		fclose(t);

		main();
	}
    fflush(stdin);
    remove("data.txt");
	fflush(stdin);
	rename("temp.txt", "data.txt");
	system("cls");
	printf("\nThe member_id %s Successfully Deleted!!!!", member_id);

	fclose(f);
	fclose(t);

	printf("\n\nEnter Any Key To Continue");
	getch();

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

    printf("\n\nEnter Any Key To Continue");

}

int main()
{
    char option;


    printf("\t\t\t\t\t\t\t\t UIU APP FORUM MANAGEMENT SYSTEM\n");

    while(1)
    {
        list();

        option = getch(); // scanf("%s", option);

		option = toupper(option);

        switch(option)
		{
			case 'A':
				add_new();
				break;
			case 'V':
				View_All();
				break;
			case 'S':
				search()
				;break;
			case 'E':
				edit();
				break;
			case 'R':
				reduce();
				break;
			case 'P':
				view_event();
				break;
			case 'Q':
			    printf("\n\n\n\t\tTHANK YOU\n\n\n\n");
				exit(1);
				break;
			default:
				printf("\n\n\n\n\n\t\t\t\tIncorrect Input\n\nEnter any key to continue:");

				getch();
		}
	}

    return 0;
}

