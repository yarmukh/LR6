#ifndef MENU_H
#define MENU_H
#include <stdio.h>
#include <string.h>
#include "Menu.h"
#include "Search_menu.h"
#include "Data.h"
typedef enum //������������ ��� menu
{
    add = 1,
    delrecord,
    search,
    edit,
    print,
    exit_menu
} functions;

//�������� ����
void menu(const char* file_name);
//���������� ������/�������� ����� c �������� ����������� ����� - ������ � �� �������(� ���� �� �����, ����� ������� - ���
//���� � �������� ����� � �������� ����, ������ ������� ����������(50 �������) � �������� � ���� ���� ��������� ����������
static void add_record(const char* file_name);
//�������� ������ �� �������, ������� ����� ������������ ����� is_deleted
static void delete_record(const char* file_name, int index);
//�������������� ������(������ ������ �� �����)
static void edit_record(const char* file_name, int index);
//����������� ������� � �� ���������
static int print_records(const char* file_name);

#endif
