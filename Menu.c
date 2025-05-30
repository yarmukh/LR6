#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <string.h>
#include "Menu.h"
#include "Search_menu.h"
#include "Data.h"

//#define MANUAL_TYPING


void menu(const char* file_name)
{
    functions sv = add;
    int index = 0;
    while (sv != exit_menu)
    {
        printf("\nChoose file function from list:\n"
            "1 Add record\n"
            "2 Delete record\n"
            "3 Search record\n"
            "4 Edit record\n"
            "5 Print all records\n"
            "6 Exit out of programm\n\n");
        if (scanf_c("%d", &sv) != 1)
        {
            printf("Input error!\n");
            continue;
        }
        switch (sv)
        {
        case add:
            add_record(file_name);
            break;
        case delrecord:
            printf("Enter record index to delete, enter 0 to go back\n");
            if (scanf_c("%d", &index) != 1 || index < 0)
            {
                printf("Input error!\n");
                break;
            }
            if (index == 0)
                break;
            delete_record(file_name, index);
            break;
        case search:
            search_menu(file_name);
            break;
        case edit:
            printf("Enter record index to edit, enter 0 to back\n");
            if (scanf_c("%d", &index) != 1 || index < 0)
            {
                printf("Input error!\n");
                break;
            }
            if (index == 0)
                break;
            edit_record(file_name, index);
            break;
        case print:
            putchar('\n');
            printf("Number of records - %d\n", print_records(file_name));
            break;
        case exit_menu:
            break;
        default:
            printf("Input error!\n");
            break;
        }
    }
}


static int print_records(const char* file_name)
{
    data person;
    FILE* file = fopen(file_name, "rb");
    if (file == NULL)
    {
        perror("File cannot be opened\n");
        return 0;
    }
    rewind(file);
    int i = 0;
    int j = 0;

    printf("%-5s %-48s %-15s %-23s %-23s %-5s\n", "Index", "Name", "Specialization", "Summa", "Rating", "Document");
    printf("\n");

    while (fread(&person, sizeof(person), 1, file) == 1)
    {
        i++;
        if (person.is_deleted != 1)
        {
            printf("%-5d %-48s %-15s %-23d %-23d %-5s\n", i, person.name, person.specialization, person.summa, person.rating, person.document ? "No" : "Yes");
            j++;
        }
    }
    fclose(file);
    return j;
}


static void edit_record(const char* file_name, int index)
{
    FILE* file = fopen(file_name, "rb+");
    if (file == NULL)
    {
        perror("File cannot be opened");
        return;
    }
    fseek(file, (index - 1) * sizeof(data), SEEK_SET);
    data person;
    fread(&person, sizeof(data), 1, file);
    if (person.is_deleted)
    {
        printf("Cannot edit a deleted record!\n");
        fclose(file);
        return;
    }
    printf("Enter full name:\n");
    scanf_c(" %[^\n]", person.name);
    printf("Enter specialization:\n");
    scanf_c(" %[^\n]", person.specialization);
    printf("Enter summa:\n");
    if (scanf_c("%d", &person.summa) != 1)
    {
        printf("Input error\n");
        return;
    }
    printf("Enter rating:\n");
    if (scanf_c("%d", &person.rating) != 1)
    {
        printf("Input error\n");
        return;
    }
    printf("Enter: Is the applicant submitted the original document (yes - 1/no - 0):\n");
    int document_int=0;
    bool document=0;
    if ((scanf_c("%d", &document_int) != 1 )||( (document_int != 0 && document_int != 1)))
    {
        printf("Input error!\n");
        return;
    }
    document = (document_int == 1);
    fseek(file, (index - 1) * sizeof(data), SEEK_SET);
    fwrite(&person, sizeof(person), 1, file);
    fclose(file);
}


static void delete_record(const char* file_name, int index)
{
    FILE* file = fopen(file_name, "rb+");
    if (file == NULL) {
        perror("File cannot be opened");
        return;
    }
    data person;
    fseek(file, (index - 1) * sizeof(data), SEEK_SET);
    if (fread(&person, sizeof(data), 1, file) != 1)
    {
        printf("Record does not exist!\n");
        fclose(file);
        return;
    }
    if (person.is_deleted)
    {
        printf("Record already deleted!\n");
        fclose(file);
        return;
    }
    person.is_deleted = 1;
    fseek(file, (index - 1) * sizeof(data), SEEK_SET);
    fwrite(&person, sizeof(data), 1, file);
    fclose(file);
    printf("Record successfully deleted!\n");
}


static void add_record(const char* file_name)
{
    data person = { 0 };
    FILE* file = fopen(file_name, "rb+");
    if (file == NULL)
    {
        file = fopen(file_name, "ab+");
        if (file == NULL)
        {
            perror("File cannot be opened or created");
            return;
        }
    }
    fseek(file, 0, SEEK_END);
#ifdef MANUAL_TYPING
    printf("Enter full name:\n");
    scanf_c(" %[^\n]", person.name);
    printf("Enter specialization:\n");
    scanf_c(" %[^\n]", person.specialization);
    printf("Enter summa:\n");
    if (scanf_c("%d", &person.summa) != 1)
    {
        printf("Input error\n");
        return;
    }
    printf("Enter rating:\n");
    if (scanf_c("%d", &person.rating) != 1)
    {
        printf("Input error\n");
        return;
    }
    printf("Enter: Is the applicant submitted the original document (yes - 1/no - 0):\n");
    int document_int;
    if (scanf_c("%d", &document_int) != 1 || (document_int != 0 && document_int != 1))
    {
        printf("Input error!\n");
        return;
    }
    bool document = (document_int == 1);
    fwrite(&person, sizeof(person), 1, file);
#else

    FILE* file_data = fopen("students.bin", "rb");
    if (file_data == NULL) {
        fclose(file);
        fclose(file_data);
        perror("File cannot be opened");
        return;
    }
    fseek(file_data, 0, SEEK_SET);
    while (fread(&person, sizeof(person), 1, file_data))
    {
        fwrite(&person, sizeof(person), 1, file);
    }
    fclose(file_data);

#endif
    fclose(file);
}