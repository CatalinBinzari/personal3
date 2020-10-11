/*
    Name:       config.h
    
    Purpose:    Contain function declarations from config.c file
*/

#include "global.h"
#ifndef CONFIG_H
#define CONFIG_H

#define ADDITIONAL_CHARACTER_LENGTH 4
#define KEY_LENGTH 100
#define ADDRESS_LENGTH 16
#define ADDRESS_BUFFER_LENGTH (KEY_LENGTH + ADDRESS_LENGTH + ADDITIONAL_CHARACTER_LENGTH)
#define PATH "build/servers.ini"

bool get_server_address(char *filename, char *key, struct sockaddr_in *address);
bool is_valid(const char *read_ip, unsigned short read_port);
bool validate_number(char *str);
bool is_ip_address(const char *ip);

#endif /* CONFIG_H */
