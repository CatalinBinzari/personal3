
/*
    Name:       login.h
    
    Purpose:    Contains function declarations from login.c file
*/

#ifndef LOGIN_H
#define LOGIN_H
#include "../include/global.h"

#define LOG(level, format, ...) _log(level, __FILE__, __LINE__, format, __VA_ARGS__)
void _log(const int level, const char *filename, const int line, const char *format, ...);

#endif /* LOGIN_H */
