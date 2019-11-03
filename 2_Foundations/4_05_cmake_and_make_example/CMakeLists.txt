# CMake Step 1

# These lines set the minimum cmake version required to 3.5.1 
# and set the environment variable CMAKE_CXX_STANDARD 
# so CMake uses C++ 14. On your own computer, if you have a 
# recent g++ compiler, you could use C++ 17 instead.
cmake_minimum_required(VERSION 3.5.1)
set(CMAKE_CXX_STANDARD 14)

# CMake Step 2

# CMake requires that we name the project, so you should 
# choose a name for the project and then add the following 
# line to CMakeLists.txt:

project(ExampleProject)

# You can choose any name you want, but be sure to 
# change <your_project_name> to the actual name of the project!

# CMake Step 3

# Next, we want to add an executable to this project. 
# You can do that with the add_executable command by specifying 
# the executable name, along with the locations of all the 
# source files that you will need. CMake has the ability 
# to automatically find source files in a directory, 
# but for now, you can just specify each file needed:

# add_executable(your_executable_name  path_to_file_1  path_to_file_2 ...)
add_executable(example src/main.cpp src/vect_add_one.cpp src/increment_and_sum.cpp)

# Hint: The source files you need are the three .cpp files in 
# the src/ directory. You can specify the path relative to 
# the CMakeLists.txt file, so src/main.cpp would work, for example.

# CMake Step 4

# A typical CMake project will have a build directory in the 
# same place as the top-level CMakeLists.txt. Make a build 
# directory in the /home/workspace/cmake_example folder:

## root@abc123defg:/home/workspace/cmake_example# mkdir build
## root@abc123defg:/home/workspace/cmake_example# cd build

# From within the build directory, you can now run CMake as follows:

## root@abc123defg:/home/workspace/cmake_example/build# cmake ..
## root@abc123defg:/home/workspace/cmake_example/build# make

# The first line directs the cmake command at the 
# top-level CMakeLists.txt file with ... This command uses 
# the CMakeLists.txt to configure the project and create a 
# Makefile in the build directory.

# In the second line, make finds the Makefile and uses 
# the instructions in the Makefile to build the project.

# If CMake and Make are successful, you should see something 
# like the following output in the terminal:

# CMake Step 5

# If everything has worked correctly, you should now be able 
# to run your executable from the build folder:

## root@abc123defg:/home/workspace/cmake_example/build#  ./your_executable_name
# This executable should print:

## The total is: 14

# just as it did in the previous workspace.

# If you don't remember the name of your executable, the last 
# line of the make output should tell you:


## [100%] Built target <your_executable_name>

# CMake Step 6

# Now that your project builds correctly, try modifying one of 
# the files. When you are ready to run the project again, 
# you'll only need to run the make command from the build 
# folder, and only that file will be compiled again. Try it now!

# In general, CMake only needs to be run once for a project, 
# unless you are changing build options (e.g. using different 
# build flags or changing where you store your files).

# Make will be able to keep track of which files have changed 
# and compile only those that need to be compiled before building.

# Note: If you do re-run CMake, or if you are having problems 
# with your build, it can be helpful to delete your build 
# directory and start from scratch. Otherwise, some 
# environment variables may not be reset correctly.


# CMake Review

# Excellent work! You've now written a basic CMakeLists.txt file 
# that builds a small project for you.

# CMake is a build system that uses text files named CMakeLists.txt 
# to configure and build your project. Once the CMakeLists.txt 
# is written, you only need the cmake and make commands to build 
# your project again and again, so it is very convenient to use!

# Coming up, we will provide the CMakeLists.txt for your course 
# project, and as you will see, it creates two executables and 
# links several external libraries, so it will be a bit longer 
# than the one you've just created. However, you should now have 
# a better understanding of the mechanics of CMake, and you are 
# ready to start experimenting with CMake on your own projects.





