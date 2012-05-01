/*=================================================
 * glutapp2d
 * IGN Code Foo
 * Francisco S Velazquez
 *=================================================*/

// Ensure the header file is included only once in multi-file projects
// Pragma once is a non-standard but widely supported preprocessor directive
# pragma once

// Include GLUT (OpenGL Graphics Utility Library) header files.
// In Windows we include our own included GLUT header file, but
// in Linux, the GLUT header file should be already installed.
#if defined WIN32 
#include <glut/glut.h> 
#elif defined __APPLE__
#include <GLUT/glut.h>
#else
#include <GLUT/glut.h>
#endif

// The application state is stored in the AppState structure defined
// below. A single instance of this structure is initialized in
// glutapp.cpp and is accessible by pointer App. This will allow
// your application data to be visible by all source files including
// this header file and this will be very usefull when your project
// grows and becomes multi-file project.
struct AppState
 { double markx, marky;
 };
extern AppState* App; // Pointer to the single instance

// The following functions are callbacks that GLUT will call to
// run your application. They are passed to GLUT in glutdemo.cpp.
// See in glut.h additional callbacks to interface your program with GLUT.
// For extensive documentation, just google GLUT and OpenGL
void appKeyboardFunc ( unsigned char key, int x, int y );
void appKeyboardFunc ( int key, int x, int y );
void appDrawScene ();
void appResizeWindow ( int w, int h );

