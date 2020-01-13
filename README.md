# iots_task3

Internet of Things Security Task Three.  
UFCF8P-15-M

## Files  
1. [Source Files](https://gitlab.uwe.ac.uk/jj6-williams/iots_task3/tree/master/source)  
    * [main.cpp](https://gitlab.uwe.ac.uk/jj6-williams/iots_task3/blob/master/source/main.cpp)  
    * [main.hpp](https://gitlab.uwe.ac.uk/jj6-williams/iots_task3/blob/master/source/main.hpp)  
    * [sha2.cpp](https://gitlab.uwe.ac.uk/jj6-williams/iots_task3/blob/master/source/sha2.cpp)  
2. [Documentation](https://gitlab.uwe.ac.uk/jj6-williams/iots_task3/tree/master/documentation)  
    * [Task Specification](https://gitlab.uwe.ac.uk/jj6-williams/iots_task3/blob/master/documentation/Task%203%20Specification.pdf)  
    * [System Specification](https://gitlab.uwe.ac.uk/jj6-williams/iots_task3/blob/master/documentation/System%20specification.pdf)  
    * [19041865 - Luke Murray Reflective Statement](https://gitlab.uwe.ac.uk/jj6-williams/iots_task3/blob/master/documentation/LUKE_MURRAY_REFLECTIVE_STATEMENT.pdf)  
    * [15008632 - Jacob Williams Reflective Statement](https://gitlab.uwe.ac.uk/jj6-williams/iots_task3/blob/master/documentation/JACOB_WILLIAMS_REFLECTIVE_STATEMENT.pdf)  

## Flashing  
1. In order to run this project, you will have to install yotta and all of its
dependencies, details of which can be found [here](http://docs.yottabuild.org/#installing).  
    * After this, the project contains a Makefile that will perform most of the
actions for you.  
2. Input "make init" to set the yotta target to bbc-microbit.  
3. Input "make" to build the project.  
4. This project will require you to have atleast two Micro:bits, one for sending
and one or more for receiving. The Makefile is only formatted for two micro:bits
however.  
5. Then you can input "make m1" and "make m2" to flash your Micro:bits with the
software. You may encounter an error if your connected Micro:bits are called
anything other than "MICROBIT" and "MICROBIT1".

## Run-Time  
1. The Micro:bits will prompt you to selected Send Mode (A) or Recieve Mode (B)
2. The Micro:bits will then both prompt for the entry of the pin, make sure
these match.  
3. After both pins have been entered, press (A) on the sending Micro:bit to
initiate Saltshaking. You will know this has finished when the Micro:bits scroll
"MESSAGE MODE".
4. On the sending device you can then select one of four commands, pressing (B)
to cycle commands, and (A) to send commands.  

## Testing  
The implementation has been tested fairly comprehensively, mostly with
variations to the pin code and using non matching pin codes to test for
collision. As expected, the non-matching pin codes always produce the fail
state. The matching pins works reliably, long winded testing has revealed that
there does appear to be a small margin of error, mostly like occuring during the
command passing stages, the root cause of this could be any number of things,
and will require much more extensive testing than time permits.  
