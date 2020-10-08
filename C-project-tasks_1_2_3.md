1. Logging  
Create a global macro named LOG_LEVEL with the value 0, 1 or 2.  

Create a variadic function called "_log" that used for logging and takes as parameters:  
  - level    - an integer used for the message level (info, warning, error)
  - filename - a string describing the file where it took place (source file)
  - line     - an integer describing the line number
  - format   - a string describing the message format (see printf / scanf for more details)
  - variable_arguments - ...
  
If the level is less then LOG_LEVEL, this function should return immediately.  
If the value is greater equal, this function should generate a string composed of 
`<filename>`::`<line>`: `<variable_arguments><new_line>` and print it to stderr.  
Wrap this function within a variadic preprocessor macro called LOG that takes as parameters the message level, 
the message format and variable arguments (...). The macro should call the "_log" function passing in the parameters  
  - level       - received as parameter  
  - `__FILE__`    - preprocessor macro indicating the current filename  
  - `__LINE__`    - preprocessor macro indicating the current line number  
  - format      - received as parameter  
  - `__VA_ARGS__` - the variable arguments received for ...  
  
Calling: `LOG(0, "Hello World %d", 123)` from main.c::45 should print the message:  
"main.c::45: Hello World 123"  

We can controll the printed information by changing the LOG_LEVEL value  
0 - prints all information  
1 - prints warnings and errors  
2 - prints only errors  

Useful links:  
  https://www.tutorialspoint.com/cprogramming/c_variable_arguments.htm  
  https://www.gnu.org/software/libc/manual/html_node/Variable-Arguments-Output.html  
  https://gcc.gnu.org/onlinedocs/cpp/Variadic-Macros.html  
  http://www.cplusplus.com/reference/cstdio/vsnprintf/  
  http://www.cplusplus.com/reference/cstdio/fprintf/  
  
2. Config file  
Create a function called get_config_value that takes as parameters:  
  - filename - a string with the name of the file to read from  
  - key      - a string with the left hand value of the assignment  
  - value    - the output where the value will be stored  
  - length   - the maximum length of the output  
This function should return:
  - true  if the key was found  
  - false if the key wasn't found  

The config file grammar: left_value = "right_value"  
The "left_value" can be a-z, A-Z, 0-9 and _.  
The "right_value" can be any formed from any ascii characters encapsulated in quotes '"'.  
Lines that don't respect this grammar should be skipped and an warning should be posted.  
				
Example of config file:  
config.ini  
nickname="John Wayne"  
age="55"  

Based on the previous config file we should create another function called "get_server_address" that  
takes as parameters:  
  - key  - a string describing the left value  
  - ip   - an output string for the ip address part of the right value  
  - port - an unsigned short for the port part of the right value  
 This function should return 
  - true  if the key was found
  - false if the key wasn't found
							 
The server config grammar: left_value = "ip:port".  
The "left_value" can be a-z, A-Z, 0-9 and _.  
The right_value can be "XXX.XXX.XXX.XXX:XXXXX", where X is 0-9. The port address can be any  
unsigned 16 bit value between 1 and 65535
-------------------------------------------------------------------------------------------------
It is strongly recommended that you use an already existing IRC client to get better understand of
the functionality.
Recommented IRC client IRSSI. Connect to an unencrypted server (Ex: undernet) and join / create a
channel.
Create a structure for the following client information:
socket_fd   - integer for the socket file descriptor
address     - a variable of type "struct sockaddr_in" that holds the server address
address_len - sizeof(address)
nick        - a string used to store the nickname
username    - a string used to store the username
password    - a string used to store the password
channel     - a string used to store the current channel name
status      - the client status; Can be DISCONNECTED, CONNECTED, REGISTERED
Read the server name you want to connect.
Initialize the address, address_len, nick and status.
Create and connect to the server's ip and port addresses read from the "servers.ini" config file
based on the server name.
You can find the server ip and port address from the IRSSI's config file "~/.irssi/config".
All server-client interactions are made through a series of text based commands that end with a '\r' and a '\n'
and not a '\0'.
The maximum command length is 256. If a command is greater than 256 it will be split up into smaller commands.
Register the client to the IRC socket based on the messages from https://tools.ietf.org/html/rfc1459#page-13
chapter 4.1 Connection Registration.
send a NICK command with the clients nickname: NICK <nickname>
receive some output; if the output contains
if the received output contains an error
Ex: ":Miami.FL.US.Undernet.Org 433 * florin_ :Nickname is already in use." you print an error message
and exit the program; or ignore for now if no error is received.
send a USER command: USER <username> <hostname> <servername> <realname>
Ex: USER florin florin irc.undernet.org :florin
receive a PING command from the server: PING : <server>
store send back a PONG command with the same parameter as the previous PING command
join a channel: JOIN <channel_name>
send: PRIVMSG <channel_name> : <message>

