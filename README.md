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


