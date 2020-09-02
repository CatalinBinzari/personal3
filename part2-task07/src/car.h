
/*
  Header:  car.h

  Purpose: Contains declaration from car.c file and structs/enum
*/

#ifndef CAR_H
#define CAR_H

enum car_add_result
{
  ADD_INSUCCESS = -1,
  ADD_SUCCESS = 0,
  ARRAY_FULL = 1,
  PARAMS_INVALID = 2
};

struct cars
{
    int number_of_seats;
    unsigned int power;
    char brand[20];
    char color[20];
    int year;
};


int user_selection();
struct cars new_car();
int add_cars(struct cars *car, int *number_of_cars, struct cars car_to_add, int max_size);
void order_by_power(struct cars *car, int number_of_cars, struct cars *cars_sorted);
int comparePowerDesc(const void *pa, const void *pb);
void display(struct cars *car, int n);
void filter_by_year(struct cars *car, int input_car_num, struct cars *output_array, int *output_car_num, int given_year);

#endif /* CAR_H */
