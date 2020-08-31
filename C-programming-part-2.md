# C Programming Part 2
  * Array; Strings; 
  * Structures; Unions; Bitfields
  * Pointers
  * Dynamic memory allocation
  * Detect memory leaks using Valgrind
  * Modular programming
   
   
# Tasks

1. Write a C program that reads an array of integers and do the following (defined as separate functions):
    - find the largest element of the array;
    - display all array elements using recursion;
    - find maximum and minimum elements in array;
    - return True if the array contains a 3 next to another 3 somewhere;
    - print all unique elements in the array;
    
2. Write a C program to convert a lowercase string to uppercase.

3. Write a C program to find the total number of alphabets, digits or special characters in a string.

4. Define a new data structure, named `person`, which contains a string (pointer to char) called name, and an integer called age. 
     Read the data for two persons and output the person with the greater age.

5. Using structures, write a C program to add two fractions and display the resulting fraction.

6. The input is a list of students who have passed the exam. For each student we know: name, surname, grade. 
     It is required to order the students after the grade and display the promoted students. 
     Calculate the arithmetic mean obtained.

7. The input is a list of cars from a car park. The information for each car in the car park will be read from keyboard. For each car we store: 
   - number of seats (number between 2 and 8);
   - power (number greater than 0);
   - brand (string with max 20 characters);
   - color (string with max 20 characters);
   - the year of manufacture (number that is not greater than current year).   
   
   The cars are stored into an array of structures (with max 100 elements) and a variable is used to keep track of the number of cars in array (both defined in `main`).  

   Display a menu (define a small function to print the menu) where the user select one of the following operations (each operation is identified by a number that the user enters):  
   - **Add new car**. When selecting this option the user inputs all details of a car (seats, power, brand, color, year) as strings.  Then calls the function `int add_cars(...)` that receives as parameters the car array, the number of cars in array and the input read from user (seats, power, brand, color, year). If input from user is valid and the array of cars is not full the car is added to car array and the number of cars in array is incremented;  The function shoule return 0 if car was successfuly added and a non o valeu in case of error: 1 - when car array is full, 2 - seats param is invalid, etc; Define the returned value from `add_cars` as an `enum`: `typedef enum {ADD_SUCCESS=0,....} car_add_result`
   - **Display cars ordered by power**. The sorting of cars should be done by a function `void order_by_power(input_array, int car_num, output_array)` which receives in input the car array an the number of cars and return on `output_array` the cars sorted by power;  
   - **Displays cars from year (year read from keyboard)**. Cars are filtered by a function `void filter_by_year(input_array, int input_car_num, output_array, int output_car_num, int year)` which receives in input the car array an the number of cars and return on `output_array` and `output_car_num` the cars and their number after filtering only cars from `year`;   
   - **Exit**  

   The 3 functions that adds, sorts and filter cars can be tested individually. In your test functions define the variables for the array of cars and number of cars  and call the function you want to test.

8. Skipped (duplicate with 9)
  
9. String manipulation using pointer arithmetics:
For the following functions you are not allowed to use array accessor `[]`. Use pointer arithmetics instead:  
    - find the length of the string using pointers. Create a function `int s_len(const char* string)` that returns the length of the `NULL` terminated string.
    - char lookup in a string using pointers. Create function `char* find_char(const char* letter, const char* string)` that returns the address of the first occurrence of `letter` in `string`.
    - remove vowels from a string. Create a function `void trim_vowel(const char* input, char* out)` that puts in `out` string all that characters from `input` string that are not vowels.
    - check if string is palindrome. Create a function `int is_palindrome(const char* input)` that return true if the string is palindrome, use the previously `s_len` implementation.  
    
10. Change the car park exercise to to work as follows.  

   The new data model for a car is: 
   - license plate (string with max 10 characters). This fiels uniquely identify the car;   
   - power (number greater than 0);
   - brand (string with max 20 characters);
   - model (string with max 20 characters);
   - color (enum with possible values: WHITE, YELLOW, RED, BLUE, GREEN, BROWN, GREY, BLACK);
   - the year of manufacture (number that is not greater than current year).  

   The user interacts with the programs by passing commands with the follosing format: `command parameters`. The following commands are supported:
   - **add a car**: `add license_plate|horse_power|brand|model|color|year`. Example: `add AUD 1023|125|Audi|A6|red|2016`;  
   - **list cars**: `list -filter filter_field filter_value -sort sort_field`. Both `-filter` and `-sort` parameters are optional, `filter_field` and `sort_field` are names of car fields. Filtering on strings should be case insensitive. Sorting shall be decending and should be done using `qsort` function from C standard library. Example: `list -filter brand bmw -sort year` (prints only the BMW cars sorted by year descending);  
   - **delete cars**: `delete -filter filter_field`. The parameter `-filter` is optional, `filter_field` is the name of a car field. Example: `delete -filter year 2012` (deletes all cars from 2012); 
   - **exit**: close the program; 

   Implementation details.
   - **store a car**, in a structure (`struct car {}`) that has separate fields for all car's parametes (see car's data model above for details); **Hint**: use a `typedef` definition to not have to write `struct` each time you use `car` structure.    
   - **a user command is stored** in a structure (`struct car_command {}`) that has fields to store the following info:
     - a command id defined as a enum: `typedef enum {ADD_COMMAND = 1, LIST_COMMAND, DELETE_COMMNAD}`;
     - a car structure to store parsed car details when command is add;
     - fields to store the `filter_field`, `filter_value`, `sort_field`. For `filter_field`, `sort_field` use an enumeration of car's fields (`typedef enum {LICENSE_PLATE = 1,...}`);
   - **the cars managed by the program are stored** in a structure (`struct car_list {}`) which has 2 fields:  
     - a dynamically allocated array of pointers to `car` structures;
     - an int field which stores the number of cars from the array;  
   - **parse the user's command**, define a function that receives the user input and a command structure where is stores that parsed information: `int parse_command(char *user_input, car_command *command);`. **Hint**: use a separate module (`commands.c/h`) for functions that parses user input. The module should expose only the `parse_command` function, all other helper function should be available only inside the module;
   - **adding a car**, the function that adds a car receives as paramaters the car list and the car command  (`int add_car(car_list* cars, car_command *add_command)`) and returns an enumerated value indicating the result of add the car to the list (see task 7 for details):      
     - check that a car with the same license plate is not already in the car list;
     - allocate a new `car` structure to store the new car;
     - allocate / re-allocate the car list to make room for the new car and add the new car to the car list;
   - **listing cars**, the function that list cars receives as paramaters the car list, the car command, and a empty car list (`int add_car(car_list* cars, car_command *list_command, car_list *listed_cars)`) and returns an enumerated value indicating the result of filter and sort operations. If function executes successfully the `listed_cars` parameter should contain filterd and sorted cars. **Hints**: 
     - create separate modules for sorting and filtering logic; the filtering module is reponsible to allocate the memory to store the array of pointers in `listed_cars`. 
     - the array of pointers in `listed_cars` should reference entries from the `cars` parameter (the main list of cars managed by the program);  
   - **delete cars**, similar implementation to listing cars; **Hint**: when a car is deleted, the car list array should shifted to left (shoudl not contain gaps) and the memory re-allocated to a smaller size.

11. Implement a program that does the following:
- Reads a list of integer values:
    - first it gets  the number of elements to be added by the user  
    - dynamically allocates the needed memory for a integer list to store the needed number of integers  
    - gets each integer from the user and stores it in the list
        
- list every integer from the list in the order that they were stored<br>
   - use a pointer as cursor  to iterate through each element
   
- list every integer from the list in reversed order<br>
   - use a pointer as cursor  to iterate through each element in reversed order<br>

- list the integer from the list in ascending order without modifing the intial list:
   - create a list of integer pointers with the same number of elements as the list which stores the values
   - sort this new list
   - print the sorting result using this new list
   
Expected ouput:  
./int_list  
Enters the number of elements: 4  
Enter element 1: 4  
Enter element 2: 3  
Enter element 3: 7    
Enter element 4: 5  

Integer list: 4 3 7 5  
Integer list(reversed): 5 7 3 4  
Integer list(sorted): 3 4 5 7  
