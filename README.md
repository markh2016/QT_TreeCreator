The code provided is a console application written in C++ using the Qt framework. 
MD HARRINGTON 22/02/2023
Please note this is written for Debian12  Distributions of linux 


Its purpose is to generate a tree-like representation of the folder structure starting from a specified folder name and display the folder structure both in the console and as an image using Qt's graphical capabilities.

Here's a step-by-step explanation of how the code works:

    TreeCreator class: This is a static class that contains various static functions 
    for generating and displaying the folder tree structure.

    listFiles function: 
    This function takes a folder path as input and recursively traverses the folder structure. 
    It prints the folder structure with proper indentation to represent the tree-like hierarchy. 
    It also writes the folder structure to a file (if a file pointer is provided).

    generateTree function: 
    This function is the entry point of the program. 
    It creates a Qt QApplication instance to enable the GUI components and interactions. 
    It prompts the user to input a folder name through a dialog box. 
    Then it searches for the specified folder name in the user's home directory and sets the current directory to the found folder.

    createImage function: 
    This function takes the folder structure as input text and converts it into an image using Qt's graphical capabilities. 
    It uses a fixed font size and line spacing to draw the text on the image.

    displayImage function: This function displays the generated image in a Qt QGraphicsView. 
    It uses Qt's graphics scene to hold the image and then creates a view to display the scene. 
    The view is shown in a new window, and the Qt application's event loop is started to handle user interactions and keep the window open until the user closes it.

    typewriterPrint function: 
    This function is responsible for printing text with typewriter-like animation in the console. 
    It uses ANSI escape codes to change text colors and introduces a small delay between printing each character to create the typewriter effect.

    main function: 
    This is the main entry point of the console application. 
    It calls the generateTree function to start the process of generating and displaying the folder tree structure.

The generated tree structure is displayed in both the console (using qDebug) 
and as an image in a graphical window. 
The font size and line spacing used for drawing the image can be adjusted to control the appearance of the generated image.

The user interacts with the application by providing a folder name through the input dialog box, 
and the program then generates the folder structure starting from that folder and displays it both in the console and as an image.

Note: The provided code assumes that the necessary Qt libraries are installed and that the font file Lato-Medium.ttf is present in the specified path
 (/usr/share/fonts/truetype/lato/). 
 
Make sure you have the required dependencies and font file installed before running the application.

Instructions 

1: To compile  you must have  QT5 / QT 6 installed and relative paths set up 
2: Also required is CMAKE

To Compile for scratch 
Open a terminal in the build  folder
Cd into build  directory once downloaded 

run command   cmake .. 
then run make 

The  compiled output  will be placed in  the same  build directory  named TreeCreator

To run 

Open a terminal in the build  folder if you have closed this 

Type the following ./TreeCreator

You will prompted  via window to search for 
Wait for all  tree structure to be printed to stdio  
When this completes  you will be presented with and Imageviewer window that shows the tree structure 

Both image and  textfiles relating to this tree will be placed in the folder that  you searched on

How the make file  works 


The provided CMakeLists.txt file is used to configure the build process for a C++ project called "TreeCreator" that depends on the Qt library.

Break down  of  file step by step:

   1:  cmake_minimum_required(VERSION 3.12): This line sets the minimum required version of CMake to 3.12. It ensures that the CMake version used to build the project is at least 3.12.

   2:  project(TreeCreator): This line sets the name of the project to "TreeCreator." The project name is used in various CMake variables and commands.

   3:  set(CMAKE_CXX_STANDARD 17): This line sets the C++ standard to C++17. It indicates that the project's C++ code should adhere to the C++17 standard.

   4 : find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Gui Widgets): 

This line attempts to find the required Qt packages. The find_package command is used to locate and configure the Qt libraries for the project. The NAMES keyword specifies the possible names of the Qt version, which can be either "Qt6" or "Qt5." The REQUIRED keyword indicates that these packages are mandatory for building the project. The COMPONENTS keyword lists the specific Qt modules needed for the project, which are Core, Gui, and Widgets in this case.

   5:  find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Gui Widgets): This line is similar to the previous one, but it uses the value of the QT_VERSION_MAJOR variable (derived from the earlier find_package command) to specify the version of Qt to be used.

   6: add_executable(${PROJECT_NAME} source/main.cpp): This line adds an executable target to the project. The target is named after the value of the PROJECT_NAME variable, which is "TreeCreator" in this case. The source file source/main.cpp is specified as the source file for the target. The add_executable command informs CMake to build an executable from the given source file(s).

   7 : target_link_libraries(${PROJECT_NAME} PRIVATE Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Gui Qt${QT_VERSION_MAJOR}::Widgets): 

This line links the executable target against the Qt libraries. The target_link_libraries command specifies that the target "TreeCreator" depends on the Qt Core, Gui, and Widgets modules (determined by Qt${QT_VERSION_MAJOR}::Core, Qt${QT_VERSION_MAJOR}::Gui, and Qt${QT_VERSION_MAJOR}::Widgets). 

The PRIVATE keyword indicates that the target is using these libraries for internal purposes, not to be exposed as part of the target's interface.
