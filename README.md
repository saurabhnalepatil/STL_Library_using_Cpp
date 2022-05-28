# STL_Library_using_Cpp
CustomizedVirtualFileSystem
The aim of this project is to understand the actual implementation of FileSystems in Operating Systems and how things work under the hood.
In this project we emulate all data structures which are used by operating system to manage File system oriented tasks.
About
In this project we create all data structures which are required for File Subsystems such as Inode Table, File Table, UAREA, User File Descriptor Table, Super block, Disk Inode List Block, Data Block, Boot Block etc.
As the name suggest its virtual because we maintain all records in Primary storage.
We provide all implementations of necessary system calls and commands of File subsystem such as Open, Close, Read, Write, Lseek, Create, rm, ls, Stat, Fstat etc.
While providing the implementations of all above functionality we use our own data structures by referring Algorithms of UNIX operating system.
By using this project we can get overview of UFS (UNIX File System) on any platform.
Build the project:
First clone the repository on your system.
Open terminal in the project directory and compile project using below command.
	g++ cvfs.cpp main.cpp -o Main
Once you compile all the necessary files, Run the project using below command.
	./Main
