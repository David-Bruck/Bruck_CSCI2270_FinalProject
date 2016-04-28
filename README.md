# Bruck_CSCI2270_FinalProject

To set up, clone repository onto a computer running Ubuntu (or VM) and open FinalProject.cbp in Codeblocks.

For this project, I will be working alone.

I will be programming a virtual marble machine that allows the user to build a 
marble machine and tracks every marble that enters the machine over time.
Each component will have a certain length, and that length determines the size of the fifo
inside the component, and every tick, the program will move the marble one space along. The
program will allow one or multiple marbles to be put in one after another and will display
when each marble enters and leaves a component.

###Track Types

* Straight - The generic, straight track. Marbles roll right through.
* Buffer - Will fill up with marbles (The small buffer's max is 5, the large's is 10) and once full, marbles will be allowed to pass until the buffer has emptied.
* Splitter - Has a left and right track that marbles will alternately follow

