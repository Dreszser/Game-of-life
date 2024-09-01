# Game-of-life

Conway's Game Of Life realisation written in C using ncurses library as part of School21 project. Only the ASCII characters used to display the graphics, with output to terminal. The option to control the speed of the "game" is supported.

## How to run?

- Clone repository to your machine
- Run ``` make all ``` or ``` make ``` target
- Than you can use any of the txt files from 'input-files', simply run command in your terminal: ``` ./game < input-files/"FILENAME" ```(pick any of the files in the directory)
- EXAMPLE: ``` ./game < cat.txt ```
- You should see moving cells in your terminal window, use number keys(from 1 to 9) or UP(faster)/DOWN(slower) to control the speed of the game, also you can press "p" to pause(any input after pausing will continue the game) and "ESC" to close the game
- Have fun :)
