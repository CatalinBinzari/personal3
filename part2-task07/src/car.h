
/*
  Header:  car.h

  Purpose: TODO
*/

#ifndef CAR_H
#define CAR_H
#include "car_struct.h"

enum car_add_result
{
  ADD_INSUCCESS = -1,
  ADD_SUCCESS = 0,
  ARRAY_FULL = 1,
  PARAMS_INVALID = 2
};

int user_selection();
struct cars new_car();
int add_cars(struct cars *car, int *number_of_cars, struct cars car_to_add, int max_size);
void order_by_power(struct cars *car, int number_of_cars, struct cars *cars_sorted);

#endif /* CAR_H */
