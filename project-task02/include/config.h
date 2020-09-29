
/*
    Name:       config.h
    
    Purpose:    Contain function declarations from config.c file
*/

#include "global.h"
#ifndef CONFIG_H
#define CONFIG_H

#define VALUE_LENGTH 200
#define KEY_LENGTH 100
#define BUFFER_LENGTH (VALUE_LENGTH + KEY_LENGTH)
#define PATH "/home/user/workspace/project-task02/src/config.ini"

bool get_config_value(char *filename, char *key, char *value, int *length);
int my_strcpy(char *destination, char *source);

#endif /* CONFIG_H */