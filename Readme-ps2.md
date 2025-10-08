# PS2: Pythagorean Tree

## Contact
Name: Juan Fernando Ruiz
Section: 204
Time to Complete: ~7 hours


## Description
Use a recursive function to draw rectangles in such a way that draws a tree using a specified formula

### Features
I made PTree an obect that recursively calls on its parent functions to draw new smaller instances of new rectangle PTree objects. I felt this was the most intuitive way to go about things
since recursion as well as using 'parent' nodes is something used commonly in actual trees so using some level of parent rectangles to call upon was the easiest way I could conceptualize it.

### Issues
It was really difficult at first to really work out how to properly change the angles and a lesson I learned throughout was to remember that functions can have the same name if I overload them and the compiler is aware of which they are based on the context if done right. This allowed me to create two functions called drawTree that took in different arguments and both helped in the actual task of drawing the Pythagoras tree.

### Extra Credit
Simply went ahead and set a fill color


## Acknowledgements
Geeksforgeeks, help from Kathryn the classmate on some ideas for how to make things in the program work with regards to window sizing, looked up references to different functions in SFML using the SFML documentation

