#include <stdio.h>

struct employee
{
    char name[31];
    int age;
    char phno[11];
    char email[31];
    float salary;
};

int main()
{
    struct employee e;
    FILE *fp;
    int choice;
    char c = 'Y';
    printf("===============================================================\n");
    printf("EMPLOYEE RECORD MANAGEMENT SYSTEM USING C\n\n");
    while (1)
    {
        printf("FUNCTIONS : \n");
        printf("1. Add Data\n");
        printf("2. Modify Data\n");
        printf("3. Delete Data\n");
        printf("4. View Data\n");
        printf("5. Exit\n\n");
        printf("Enter your choice (1, 2, 3, 4, 5) : ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                fp = fopen("Employee_Rec.txt", "ab");
                while (c == 'Y' || c == 'y')
                {
                    printf("\n\n---ADDING RECORD---\n");
                    printf("Enter Employee Name (max 30 char) : ");
                    scanf(" %[^\n]", e.name);
                    printf("Enter Employee Age : ");
                    scanf("%d", &e.age);
                    printf("Enter Employee Phone Number (max 10 digits) : ");
                    scanf(" %[^\n]", e.phno);
                    printf("Enter Employee Email (max 30 char) : ");
                    scanf(" %[^\n]", e.email);
                    printf("Enter Employee Salary : ");
                    scanf("%f", &e.salary);
                    printf("\nRecord Collected...\n");
                    fwrite(&e, sizeof(e), 1, fp);
                    printf("Record added...\n");
                    printf("Do you want to add another record? (Y/N) : ");
                    c = getche();
                }
                fclose(fp);
                break;
            case 4:
                printf("\n\n---VIEWING RECORDS---\n\n");
                fp = fopen("Employee_Rec.txt", "rb");
                rewind(fp);
                printf("--------------------------------------------------------\n");
                printf("| %31s | %3s | %11s | %31s | %8s |\n", "NAME", "AGE", "PHONE NO", "EMAIL", "SALARY");
                printf("--------------------------------------------------------\n");
                while (fread(&e, sizeof(e), 1, fp) == 1)
                {
                    printf("| %31s | %3d | %11s | %31s | %8.2f |\n", e.name, e.age, e.phno, e.email, e.salary);
                }
                printf("--------------------------------------------------------\n");
                fclose(fp);
                break;
            case 5:
                printf("\nExiting the program...\n");
                exit(0);
            default:
                printf("\nInvalid Choice\n");
                break;
        }
    }
    return 0;
}