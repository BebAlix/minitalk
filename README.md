# minitalk

This project make communicate two separate processes using unix signals.

## How to launch the game

1. To compile the program :

   ```sh
   $ make
   ```

   With bonus :

   ```sh
   $ make bonus
   ```
   
2. To start the program :

    In a terminal :
  
    ```sh
     $ ./server
    ```
   
    Copy the ID of the process.
   
    In a second terminal :
   
    ```sh
    $ ./client [ID_server_process] [character string of your choice]
    ```
   
3.  Remove all :

	  ```sh
	  $ make fclean
	  ```
