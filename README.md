TuringMachine
=============

Implementation of a Turing Machine in C++

Contains:
1.	Solution – TuringMachine.sln created with Visual Studio 2010 and source code inside TuringMachine folder
2.	Classes reference – ClassReference.docx  describes all files, classes and class members
3.	Program workflow – ProgramWorkflow.docx describes how the program work and how the classes interact between each other
4.	Tests – in Release folder
a.	execute_file.bat – runs the machine with input and output files
b.	In_file.txt – define which files will be used
i.	 in.txt
3 blank x y
4 A B C F
1 F
6
A x B y R
A y F x R
B x C y L
B y C x S
C x A y R
C y A x S
1 x
Result:
4 x x y x

ii.	in_1.txt
3 blank x y
5 A B C D F
1 F
9
A x B blank R
A y F x R
B x C y L
B y C x S
B blank D y R
C x A y R
C y F x S
D y B x L
D x A y L
4 x blank blank y
Result:
4 y x x y
