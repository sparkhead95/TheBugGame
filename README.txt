The files being handed in are within the /src/ and /Debug/ folders. They contain all the files necessary to compile the program using gdb.
The user is advised to navigate to the /Debug/ folder and attempt to run the *.o file within gdb to get the program running.
If this still doesn't work, the config files (in the previous directory) must be copied in.
The program runs off the Main class/method, thus the user is advised to locate this within the Debug/ folder.
The program also uses the thread(sleep) function, which requires the c++2011 standard.
Required libraries:

#include <string>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <sstream>
#include <stdexcept>
#include <vector>
#include <fstream>
#include <chrono>
#include <thread>
#include <cstdlib>
#include <ctime>

My program has been designed so that it is cross-platform.
