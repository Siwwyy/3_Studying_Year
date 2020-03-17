przewodnik DLL stworzony przez
inz. Igora Wadowskiego
(wadowski.igor@gmail.com)

------------------------------------------------------------------
dumpbin /EXPORTS

------------------------------------------------------------------
https://msdn.microsoft.com/en-us/library/ms235636(v=vs.80).aspx

To use the functionality from the class library in the console application

    After you create a new Console Application, an empty program is created for you. The name for the source file will be the same as the name you chose for the project above. In this example, it is named MyExecRefsDll.cpp.

    To use the math routines that were created in the dynamic link library, you must reference it. To do this, select References… from the Project menu. From the Property Pages dialog, expand the Common Properties node and select References. Then select the Add New Reference… button. For more information on the References… dialog, see References, Common Properties, <Projectname> Property Pages Dialog Box.

    The Add Reference dialog is displayed. This dialog lists all the libraries that you can reference. The Project tab lists all the projects in the current solution and any libraries they contain. From the Projects tab, select MathFuncsDll. Then select OK. For more information on the Add Reference dialog, see Add Reference Dialog Box.

    To reference the header files of the dynamic link library, you must modify the include directories path. To do this, from the Property Pages dialog, expand the Configuration Properties node, then the C/C++ node, and select General. Next to Additional Include Directories, type in the path to the location of the MathFuncsDll.h header file.

    Dynamic link libraries are not loaded by the executable until runtime. You must tell the system where to locate MathFuncsDll.dll. This is done using the PATH environment variable. To do this, from the Property Pages dialog, expand the Configuration Properties node and select Debugging. Next to Environment, type in the following: PATH=<path to MathFuncsDll.dll file>, where <path to MathFuncsDll.dll file> is replaced with the actual location of MathFuncsDll.dll. Press OK to save all the changes made.