#ifndef MENU_H
#define MENU_H

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
