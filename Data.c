#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <string.h>
#include "Menu.h"
#include "Search_menu.h"
#include "Data.h"
#include <stdarg.h>

int scanf_c(const char* format, ...) 
{
    va_list args;
    va_start(args, format);
    int result = vscanf(format, args);
    while (getchar() != '\n');
    va_end(args);
    return result;
}
