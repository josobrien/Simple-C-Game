# Simple-C-Game
Around 2017 I wrote a simple game in my spare time which involved collecting rings while moving around a 2D array.

There is a randomly generated layout of walls that cannot be moved through and rings to be collected in a 38x18 grid.
There are two different modes as well as some other options and features. 

There are some problems with the implementation since the code has not been changed since experimenting with it in 2017. 
When anything on the screen changes, everything is removed and re-written which, ignoring inefficency, makes the screen flicker after any input.
Sometimes a specific layout of the walls and rings makes the game impossible, so there is an option to regenerate the grid (not a good solution).
Also, only unicode characters were used, limiting the graphics.
