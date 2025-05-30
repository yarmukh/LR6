#include <stdbool.h>
#ifndef DATA_H
#define DATA_H

#define MAX_NAME_SIZE 50 // ������������ ������ �����
#define MAX_MISC_SIZE (MAX_NAME_SIZE / 2) // ������������ ������ �������, �������� � �.�.

#include <stdio.h>
#include <string.h>
#include "Menu.h"
#include "Search_menu.h"
#include "Data.h"
typedef struct data //��������� ��� 25 ��������
{
    char name[MAX_NAME_SIZE]; //���
    char specialization[MAX_MISC_SIZE]; // �������������
    int summa; // ����� ������ �� ������������� ����������
    int rating; // ����� � ��������
    bool document; // ������� ����� ��������� ��������� (����/�� ����)
    int is_deleted; // ���� �������� ������
} data;

int scanf_c(const char* format, ...); // ����������� ������� scanf � ������������� ������ stdin, ����������� ����� ���������� stdarg.h

#endif