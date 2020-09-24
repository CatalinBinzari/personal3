# C Programming Part 1
  * Variables and data types
  * Variable scope, static and global variables, constants
  * Operators
  * Flow Control
  * Functions 
 

# Tasks
1. Write a C program to enter the length and width of a rectangle and compute the area and perimeter. This task is just a small extension of the example project: add a new `rectangle_perimeter` function and relevant UTs.
2. Write a C program to check whether a triangle can be formed with the given value for the angles: 
   - the program accepts 3 integers representing the angles in degrees;
   - write a function (`triangle_angles`) which receives 3 integers as parameters and returns `1` if the 3 values can represent the angles of a triangle and `0` otherwise;
   - write UTs for the following combination of values: 
     - `test_triangle_angles_sum_180` calls angles validation function with values: 60, 45, 75;
     - `test_triangle_angles_sum_lt_180` calls angles validation function with values: 45, 45, 80;
     - `test_triangle_angles_sum_gt_180` calls angles validation function with values: 60, 90, 80;
     - `test_triangle_angles_zero_angle` calls angles validation function with values: 120, 60, 0;
     - `test_triangle_angles_negative_angle` calls angles validation function with values: 90, 120, -30;
3. Write a C program to enter temperature in Fahrenheit and convert to Celsius.
4. Write a C program to enter two numbers and print the result of the following operations (define each operation as a separate function): sum, difference, product, division, modulus, average, minimum, maximum.
5. Write a C program that accepts three integers and prints the maximum and the minimum.
6. Write a C program that accepts a number of minutes and convert them to years (years have 365 days) and days.
7. Write a program in C that reads a long and prints the sum of its digits.
8. Write a C program that accepts a number and determines whether the number is positive, negative or zero using:
   - a function that uses `if` statements; 
   - a function that uses `switch` statements;
9. Write a C program to print the name for the day (the user inputs the day number and the 1st day is Monday) of the week using `switch` statement (hint: define and use an `enum` for day number).
10. Write a C program to that accepts a number `N` :
    - compute the sum of the first `N` natural numbers using `for`; 
    - compute the sum of the first `N` natural numbers using `while`
    - compute the sum of the first `N` natural even numbers using `for`;
    - compute the sum of the first `N` natural odd numbers using `while`;
11. Write a C program to find the eligibility of admission for a professional course based on the following criteria:
    - Marks in Maths >= 65
    - Marks in Phy >= 55
    - Marks in Chem >= 50
    - Total Maths + Phy + Chem >=180 or total in Math and Phy >=140.
12. Write a program that accepts 1 integer representing number of minutes used by an user and computes the total amount (in cents) to pay. in case of invalie input (negative number of minutes) the function should return -1. 
The charged is determined as follows:
    - the first 50 minutes are free of charge;
    - from  51 up to 199 the user pays 20 cents per minute;
    - from 200 up to 399 the user pays 15 cents per minute;
    - from 400 up to 499 the user pays 10 cents per minute;
    - from 500 the user pays 5 cents per minute;  
**Write unit tests for the following values:**
    - test_charge_value_41_min expects the function to return 0;
    - test_charge_value_50_min expects the function to return 0;
    - test_charge_value_76_min expects the function to return 520;
    - test_charge_value_199_min expects the function to return 2980;
    - test_charge_value_282_min expects the function to return 4225;
    - test_charge_value_399_min expects the function to return 5980;
    - test_charge_value_420_min expects the function to return 6190;
    - test_charge_value_499_min expects the function to return 6980;
    - test_charge_value_500_min expects the function to return 6985;
    - test_charge_value_510_min expects the function to return 7035;
    - test_charge_value_negative_min expects the function to return -1;