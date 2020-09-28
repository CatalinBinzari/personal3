
/*
    Name:       global.h
    
    Purpose:    Contains global declarations
*/

#ifndef GLOBAL_H
#define GLOBAL_H
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdint.h>
#define LOG_LEVEL INFO

enum LOG_LEVEL_T
{
    INFO = 0,
    WARNINGS_AND_ERRORS,
    ERRORS
};

#endif /* GLOBAL_H */
