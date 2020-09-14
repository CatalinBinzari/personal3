
/*
  Header:  string.h

  Purpose: Contains function declarations from file.c file
*/

#ifndef FILE_H
#define FILE_H
#include <stdbool.h>

#define product_file "/home/user/workspace/part3-task04/src/product.dat"

enum return_code
{
  NO_PRODUCTS_STORED = -5,
  PRODUCT_NOT_FOUND,
  PARAMETERS_INVALID,
  PRODUCT_CODE_ALREADY_IN_FILE,
  FILE_DOES_NOT_EXIST,
  SUCCESS
};

typedef struct product_data_t
{
  char product_code[6];
  char product_name[60];
  double price;
  int quantity;
} product_data;

const char *meaningful(int error_type);
void printf_info();
int add_product();
int verify_product_code_exists(FILE *f_ptr, char *code);
int verify_valid(product_data product);
void get_product_info(product_data *product);
int print_products(void (*function)(FILE *, int *));
void all(FILE *f_ptr, int *counter);
void all_by_name(FILE *f_ptr, int *counter);
void most_expensive(FILE *f_ptr, int *counter);
#endif /* FILE_H */
