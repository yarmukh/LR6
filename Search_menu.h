#ifndef SEARCH_MENU_H
#define SEARCH_MENU_H
#include <stdio.h>
#include <string.h>
#include "Menu.h"
#include "Search_menu.h"
#include "Data.h"

//перечисление для search_menu для удобства и читабельности
typedef enum
{
    name = 1,
    specialization,
    summa,
    rating,
    document,
    exit_search
} data_cord;
//определение типа данных - указателя на функцию
typedef int (*search_func)(const data*, const void*);
//меню для функции поиска
void search_menu(const char* file_name);

//блок логических функций по разным полям структуры data, возращают либо 1 либо 0, взависимости от совпадения операндов
static int is_correct_name(const data* person, const void* value);
static int is_correct_specialization(const data* person, const void* value);
static int is_correct_summa(const data* person, const void* value);
//static int is_correct_subject(const data* person, const void* value);
static int is_correct_rating(const data* person, const void* value);
static int is_correct_document(const data* person, const void* value);
//вспомогательная функция которая активирует поиск по указателю
static void search_record(const char* file_name, search_func search_type, const void* value);
#endif