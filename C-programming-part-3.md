# C Programming Part 3
  * File I/O 
  * Network I/O (Sockets), IPC 
  * C standard library
  * Multithreading and concurrency
  
   
# Tasks

1. Given a file containing some text, write program to find and replace a word in the file by another given word.
If the word does't exist, add the following sentence on a new line at the end of file: `<'new_word' added at the end of file.>`

2. Given a text file, display the following statistical information: 
    - number of words in the file
    - number of characters
    - number of lines
    - number of digits.

3. Considering the following files:
    - `student.txt` contains on each line:
      student_code, fisrt_name, last_name, age
    -  `grades.txt` contains on each line:
      student_code grade1, grade2, grade3
  Create a program with following menu:
    - h - Information about the program options
    - s - add one student in `student.txt`
        If student_code already exist, print a specific message and don't add duplicates.
    - g - add grades in `grades.txt` for one student
        If student_code already exist, print a specific message and don't add duplicates.
    - a - create a file `graduate.txt` for students with average > 5 with following information:
      student_code, fisrt_name, last_name, average.
	  If this file already exist, add only students which does not exist.
    - x - close the program


4. Create a program that allows the management of the following information about products in a store: product_code, product_name, price, quantity
The data will be stored in a binary file (with structures), called `product.dat`. The program will have the following menu:
    - h - information about the program options
    - a - add a product
    - w - print all products from product.dat
    - b - read details about one product based on product_name
    - e - print the most expensive product
    - x - close the program

5. Create three programs, two of which are clients to a single server. 
    - Client1 will send a text to the server process. The server will convert the characters to uppercase
 and send the result to Client1.Client1 prints the text it receives and then the process terminates.
    - Client2 will send a number to the server process. The server will double the number and send the result to Client2.Client2 prints the number it receives and then the process terminates.


TODO
