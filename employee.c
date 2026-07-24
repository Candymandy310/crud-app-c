#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct employee
{
    char eid[5];
    char ename[31];
    int eage;
    char ephno[11];
    char eemail[31];
    float esalary;
};

int main()
{
    struct employee e;
    FILE *fp;
    FILE *fpt;
    int choice;
    char c = 'Y';
    char id[5];

    printf("===============================================================\n");
    printf("EMPLOYEE RECORD MANAGEMENT SYSTEM USING C");
    while (1)
    {
        printf("\n\nFUNCTIONS : \n");
        printf("1. Add Data\n");
        printf("2. Modify Data\n");
        printf("3. Delete Data\n");
        printf("4. View Data\n");
        //printf(" Search Data\n");
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
                    printf("Enter Employee ID : ");
                    scanf(" %[^\n]", e.eid);
                    printf("Enter Employee Name (max 30 char) : ");
                    scanf(" %[^\n]", e.ename);
                    printf("Enter Employee Age : ");
                    scanf("%d", &e.eage);
                    printf("Enter Employee Phone Number (max 10 digits) : ");
                    scanf(" %[^\n]", e.ephno);
                    printf("Enter Employee Email (max 30 char) : ");
                    scanf(" %[^\n]", e.eemail);
                    printf("Enter Employee Salary : ");
                    scanf("%f", &e.esalary);
                    printf("\nRecord Collected...\n");
                    fwrite(&e, sizeof(e), 1, fp);
                    printf("Record added...\n");
                    printf("Do you want to add another record? (Y/N) : ");
                    scanf(" %c", &c);
                }
                fclose(fp);
                break;
            case 2:
                printf("\n\n---MODIFYING RECORDS---\n\n");
                fp = fopen("Employee_Rec.txt", "rb");
                fpt = fopen("temp.txt", "wb");
                printf("Enter the Employee ID of the record you want to modify : ");
                scanf(" %[^\n]", id);
                while (fread(&e, sizeof(e), 1, fp) == 1)
                {
                    if (strcmp(e.eid, id) == 0)
                    {
                        printf("\nMatching ID found...\n");
                        printf("\nEnter the NEW details : \n");
                        printf("Enter Employee Name (max 30 char) : ");
                        scanf(" %[^\n]", e.ename);
                        printf("Enter Employee Age : ");
                        scanf("%d", &e.eage);
                        printf("Enter Employee Phone Number (max 10 digits) : ");
                        scanf(" %[^\n]", e.ephno);
                        printf("Enter Employee Email (max 30 char) : ");
                        scanf(" %[^\n]", e.eemail);
                        printf("Enter Employee Salary : ");
                        scanf("%f", &e.esalary);
                        printf("\nRecord Collected...\n");
                        fwrite(&e, sizeof(e), 1, fpt);
                        printf("Record added...\n");
                        continue;
                    }
                    fwrite(&e, sizeof(e), 1, fpt);
                }
                fclose(fp);
                fclose(fpt);
                remove("Employee_Rec.txt");
                rename("temp.txt", "Employee_Rec.txt");
                break;
            case 3:
                printf("\n\n---DELETING RECORDS---\n\n");
                fp = fopen("Employee_Rec.txt", "rb");
                fpt = fopen("temp.txt", "wb");
                printf("Enter the Employee ID of the record you want to delete : ");
                scanf(" %[^\n]", id);
                while (fread(&e, sizeof(e), 1, fp) == 1)
                {
                    if (strcmp(e.eid, id) == 0)
                    {
                        printf("\nMatching ID found...\n");
                        printf("\nRecord deleted...\n");
                        continue;
                    }
                    fwrite(&e, sizeof(e), 1, fpt);   
                }
                fclose(fp);
                fclose(fpt);
                remove("Employee_Rec.txt");
                rename("temp.txt", "Employee_Rec.txt");
                break;
            case 4:
                printf("\n\n---VIEWING RECORDS---\n\n");
                fp = fopen("Employee_Rec.txt", "rb");
                rewind(fp);
                printf("-----------------------------------------------------------------------------------------------\n");
                printf("| %5s | %25s | %3s | %11s | %25s | %8s |\n", "ID", "NAME", "AGE", "PHONE NO", "EMAIL", "SALARY");
                printf("-----------------------------------------------------------------------------------------------\n");
                while (fread(&e, sizeof(e), 1, fp) == 1)
                {
                    printf("| %5s | %25s | %3d | %11s | %25s | %8.2f |\n", e.eid, e.ename, e.eage, e.ephno, e.eemail, e.esalary);
                }
                printf("-----------------------------------------------------------------------------------------------\n");
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