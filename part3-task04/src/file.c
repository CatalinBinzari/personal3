
/* 
  Name:      file.c 

  Purpose:   File manipulation
*/

#include <stdio.h>
#include <stdlib.h>
#include "file.h"
#include <stdbool.h>
#include <string.h>
#include <sys/stat.h>

/*
  Name:        add_product

  Purpose:     Get info from user and add the product to product.dat, if
               product is valid and already do not exist.

  Params:      Nothing    

  Returns:     action code from return_code enum
*/
int add_product()
{
  int err_code = 0;
  product_data product;

  get_product_info(&product);

  err_code = verify_valid(product);

  if (err_code == 0)
  {
    FILE *f_ptr = fopen(product_file, "r");
    err_code = verify_product_code_exists(f_ptr, product.product_code);
    fclose(f_ptr);
  }

  if (err_code == 0)
  {
    FILE *f_ptr = fopen(product_file, "a");
    err_code = !fwrite(&product, sizeof(struct product_data_t), 1, f_ptr);

    fclose(f_ptr);
  }
  return err_code;
} /* add_product */

/*
  Name:        printf_info

  Purpose:     Print information about program options

  Params:      Nothing    

  Returns:     Nothing
*/
void printf_info()
{
  printf("Help support:\n"
         " h - information about the program options\n"
         " a - add a product\n"
         " w - print all products from product.dat\n"
         " b - read details about one product based on product_name\n"
         " e - print the most expensive product\n"
         " x - close the program\n");
} /* printf_info */

/*
  Name:        meaningful

  Purpose:     Describe errors

  Params:      IN error_type - error_type

  Returns:     String
*/
const char *meaningful(int error_type)
{
  switch (error_type)
  {
  case SUCCESS:
    return "Executed successful!\n";
    break;
  case FILE_DOES_NOT_EXIST:
    return "File error, location is invalid or file does not exist!\n";
    break;
  case PRODUCT_CODE_ALREADY_IN_FILE:
    return "Product is already in file!\n";
    break;
  case PARAMETERS_INVALID:
    return "Input parameters are invalid!\n";
    break;
  case PRODUCT_NOT_FOUND:
    return "Product not found!\n";
    break;
  case NO_PRODUCTS_STORED:
    return "Could not find stored products!\n";
    break;

  default:
    return "Unknown error!\n";
    break;
  }
} /* meaningful */

/*
  Name:        get_product_info

  Purpose:     Get info from user and store to product_data struct

  Params:      OUT product - product_data struct    

  Returns:     Nothing
*/
void get_product_info(product_data *product)
{
  printf("Product code: ");
  scanf("%s", product->product_code);
  printf("Product name: ");
  scanf("%s", product->product_name);
  printf("Price: ");
  scanf("%lf", &product->price);
  printf("Quantity: ");
  scanf("%d", &product->quantity);
} /* get_product_info */

/*
  Name:        verify_valid

  Purpose:     Verify input data from user

  Params:      IN product - product_data struct 

  Returns:     const PARAMETERS_INVALID if invalid data, else const SUCCESS
*/
int verify_valid(product_data product)
{
  if (strlen(product.product_code) != 5 ||
      strlen(product.product_name) == 0 ||
      strlen(product.product_name) > 60 ||
      product.price < 0 ||
      product.quantity < 0)
  {
    return PARAMETERS_INVALID;
  }

  return SUCCESS;
} /* verify_valid */

/*
  Name:        verify_product_code_exists

  Purpose:     Based on product_code, verify if product exists in file

  Params:      IN f_ptr - pointer to file where to verify
               IN code - product code from struct
               

  Returns:     0 if does not exist, -1 if file not found, -2 if student code is in file
*/
int verify_product_code_exists(FILE *f_ptr, char *code)
{
  product_data product;
  if (f_ptr == NULL)
  {
    printf("File does not exists or location is invalid.\n");
    return FILE_DOES_NOT_EXIST;
  }
  while (fread(&product, sizeof(struct product_data_t), 1, f_ptr))
  {
    if (strcmp(product.product_code, code) == 0)
    {
      return PRODUCT_CODE_ALREADY_IN_FILE;
    }
  }

  return SUCCESS;
} /* verify_product_code_exists */

/*
  Name:        print_products

  Purpose:     Print all products from product_file

  Params:      IN product_name - may be empty string, or a product name
               
  Returns:     SUCCESS const , if products were printed, else NO_PRODUCTS_STORED const
*/
int print_products(void (*function)(FILE *, int *))
{
  int counter = 0;

  FILE *f_ptr = fopen(product_file, "r");

  if (f_ptr == NULL)
  {
    printf("File does not exists or location is invalid.\n");
    exit(1);
  }

  (*function)(f_ptr, &counter);

  fclose(f_ptr);

  return ((counter == 0) ? NO_PRODUCTS_STORED : SUCCESS);
} /* print_products */

/*
  Name:        all

  Purpose:     pointer to function, to print all products from file

  Params:      IN f_ptr - input file
               IN/OUT counter - stores product index 
               
  Returns:     Nothing
*/
void all(FILE *f_ptr, int *counter)
{
  product_data product;
  while (fread(&product, sizeof(struct product_data_t), 1, f_ptr))
  {
    printf("[%d] id: %s, name: %s,  price: %.2lf, quantity: %d \n", *counter, product.product_code,
           product.product_name, product.price, product.quantity);
    ++*counter;
  }
} /* all */

/*
  Name:        all_by_name

  Purpose:     pointer to function, to print all products from file with specific name

  Params:      IN f_ptr - input file
               IN/OUT counter - stores product index 
               
  Returns:     Nothing
*/
void all_by_name(FILE *f_ptr, int *counter)
{
  product_data product;
  char name[60];
  printf("Enter the product name:");
  scanf("%s", name);

  while (fread(&product, sizeof(struct product_data_t), 1, f_ptr))
  {
    if (strcmp(product.product_name, name) == 0)
    {
      printf("[%d] id: %s, name: %s,  price: %.2lf, quantity: %d \n", *counter, product.product_code,
             product.product_name, product.price, product.quantity);
      ++*counter;
    }
  }
} /* all_by_name */

/*
  Name:        most_expensive

  Purpose:     pointer to function, to print all products from file with specific name

  Params:      IN f_ptr - input file
               IN/OUT counter - stores product index 
               
  Returns:     Nothing
*/
void most_expensive(FILE *f_ptr, int *counter)
{
  product_data most_expensive_product = {};
  product_data product;
  int product_index = -1;
  most_expensive_product.price = 0;
  while (fread(&product, sizeof(struct product_data_t), 1, f_ptr))
  {
    if (product.price > most_expensive_product.price)
    {
      most_expensive_product = product;
      product_index = *counter;
    }
    ++*counter;
  }
  if (product_index != -1)
  {
    printf("[%d] id: %s, name: %s,  price: %.2lf, quantity: %d \n", product_index, product.product_code,
           product.product_name, product.price, product.quantity);
  }
} /* most_expensive */
