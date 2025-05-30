#ifndef SEARCH_MENU_H
#define SEARCH_MENU_H
#include <stdio.h>
#include <string.h>
#include "Menu.h"
#include "Search_menu.h"
#include "Data.h"

//������������ ��� search_menu ��� �������� � �������������
typedef enum
{
    name = 1,
    specialization,
    summa,
    rating,
    document,
    exit_search
} data_cord;
//����������� ���� ������ - ��������� �� �������
typedef int (*search_func)(const data*, const void*);
//���� ��� ������� ������
void search_menu(const char* file_name);

//���� ���������� ������� �� ������ ����� ��������� data, ��������� ���� 1 ���� 0, ������������ �� ���������� ���������
static int is_correct_name(const data* person, const void* value);
static int is_correct_specialization(const data* person, const void* value);
static int is_correct_summa(const data* person, const void* value);
//static int is_correct_subject(const data* person, const void* value);
static int is_correct_rating(const data* person, const void* value);
static int is_correct_document(const data* person, const void* value);
//��������������� ������� ������� ���������� ����� �� ���������
static void search_record(const char* file_name, search_func search_type, const void* value);
#endif