/*=================================================
 * glutapp2d 1.0
 * Example program illustrating OpenGL and GLUT
 * IGN Code Foo
 * Francisco S Velazquez
 *=================================================*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "glutapp.h"

//==========================================================================
// Use a global pointer to maintain the a single instance of the 
// state of our application, see comments in glutapp.h
//==========================================================================
AppState* App;
double speed = 0.002;
float xr, yr, zr;
// idle function
void idle(void)
{
	App->markx = App->markx + speed;
	if (App->markx > 7) {
		App->markx = -7;
	}
	if (App->markx < -7) {
		App->markx = 7;
	}
	glRotatef(5, xr, yr, zr);
	glutPostRedisplay();
}

//==========================================================================
// appKeyboardFunc is called every time a "normal" ascii key is pressed
//==========================================================================
void appKeyboardFunc ( unsigned char key, int x, int y )
 {
   switch ( key )
    { case ' ': // space bar
	   printf ( "Space pressed.\n" );
       App->markx = 3;
       App->marky = 3;
       glutPostRedisplay();
	   break;

	  case 27: // Esc was pressed
	   exit(1);
	}
}


//==========================================================================
// This appKeyboardFunc is for handling special keys. Note that this is 
// C++ and the parameter list differs from the other appKeyboardFunc
//==========================================================================
void appKeyboardFunc ( int key, int x, int y )
 {
   const double incx=0.002;
   const double incy=0.2;
   switch ( key )
    { case GLUT_KEY_LEFT:  speed-=incx; break;
      case GLUT_KEY_RIGHT: speed+=incx; break;
      case GLUT_KEY_UP:    App->marky+=incy; break;
      case GLUT_KEY_DOWN:  App->marky-=incy; break;
      default: return; // return without rendering
	}

   // at this point the mark position changed and so we render the scene again:
   glutPostRedisplay();
}

//==========================================================================
// Called every time the window is resized
// Parameters w, h are the width and height of the window in pixels
//==========================================================================
void appResizeWindow ( int w, int h )
 {
   double scale, center;
   double winXmin, winXmax, winYmin, winYmax;

   const double appXmin = 0.0;
   const double appXmax = 15.0;
   const double appYmin = 0.0;
   const double appYmax = 15.0;

   // Define that OpenGL should use the whole window for rendering
   glViewport( 0, 0, w, h );	

   // Set up the projection matrix using a orthographic projection that will
   // maintain the aspect ratio of the scene no matter the aspect ratio of
   // the window, and also set the min/max coordinates to be the disered ones
   w = (w==0) ? 1 : w;
   h = (h==0) ? 1 : h;
   if ( (appXmax-appXmin)/w < (appYmax-appYmin)/h )
    {
      scale = ((appYmax-appYmin)/h)/((appXmax-appXmin)/w);
	  center = (appXmax+appXmin)/2;
	  winXmin = center - (center-appXmin)*scale;
	  winXmax = center + (appXmax-center)*scale;
	  winYmin = appYmin;
	  winYmax = appYmax;
	}
   else
    {
      scale = ((appXmax-appXmin)/w)/((appYmax-appYmin)/h);
	  center = (appYmax+appYmin)/2;
	  winYmin = center - (center-appYmin)*scale;
	  winYmax = center + (appYmax-center)*scale;
	  winXmin = appXmin;
	  winXmax = appXmax;
    }
	
   // Now we use glOrtho to set up our viewing frustum
   glMatrixMode ( GL_PROJECTION );
   glLoadIdentity ();
   glOrtho ( winXmin, winXmax, winYmin, winYmax, -1, 1 );
}


//==========================================================================
// appDrawScene() will redraw the scene accodring to the current state of
// the application. For more complex scenes, display lists should be used.
//==========================================================================
void appDrawScene ()
 {
   // Clear the rendering window
   glClear ( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

   // Clear the trasnformation stack
   glMatrixMode( GL_MODELVIEW );
   glLoadIdentity();

   // Set drawing color to GREEN
   glColor3f ( 0.2, 1.0, 0.0 );
	 //glClearColor(0,255,255,0);
	 
	 float rad = 0.0174532925;
	 
	 // Head
	 glBegin(GL_TRIANGLE_FAN);
	 
	 for (int i = 270; i < 455; i = i + 5) {
		 glVertex2f(App->markx + sin(i*rad)*1 + 5, App->marky + cos(i*rad)*1 + 5);
		 
	 }
	 glEnd();
	 
	 // Body
	 glBegin(GL_QUADS);
	 glVertex3f( App->markx + 4.0f , App->marky + 4.8f , 0.0f);
	 glVertex3f( App->markx + 6.0f , App->marky + 4.8f , 0.0f);
	 glVertex3f( App->markx + 6.0f , App->marky + 2.8f , 0.0f);
	 glVertex3f( App->markx + 4.0f , App->marky + 2.8f , 0.0f);
	 glEnd();
	 
	 // Left Arm
	 glBegin(GL_LINE_LOOP);
	 
	 for (int i = 0; i < 360; i = i + 5) {
		 glVertex2f(App->markx + sin(i*rad)*.2 + 3.7, App->marky + cos(i*rad)*.9 + 3.9);
		 
	 }
	 glEnd();
	 
	 // Right Arm
	 glBegin(GL_LINE_LOOP);
	 
	 for (int i = 0; i < 360; i = i + 5) {
		 glVertex2f(App->markx + sin(i*rad)*.2 + 6.3, App->marky + cos(i*rad)*.9 + 3.9);
		 
	 }
	 glEnd();
	 
	 // left leg
	 glBegin(GL_LINE_LOOP);
	 
	 for (int i = 0; i < 360; i = i + 5) {
		 glVertex2f(App->markx + sin(i*rad)*.29 + 4.5, App->marky + cos(i*rad)*.9 + 3);
		 
	 }
	 glEnd();
	 
	 // right leg
	 glBegin(GL_LINE_LOOP);
	 
	 for (int i = 0; i < 360; i = i + 5) {
		 glVertex2f(App->markx + sin(i*rad)*.29 + 5.5, App->marky + cos(i*rad)*.9 + 3);
		 
	 }
	 glEnd();
	 
	 glColor3f ( 1.0, 1.0, 1.0 );
	 // left eye
	 glBegin(GL_LINE_LOOP);
	 
	 for (int i = 0; i < 360; i = i + 5) {
		 glVertex3f(App->markx + sin(i*rad)*.1 + 4.6, App->marky + cos(i*rad)*.1 + 5.4, 1);
		 
	 }
	 glEnd();
	 
	 // right eye
	 glBegin(GL_LINE_LOOP);
	 
	 for (int i = 0; i < 360; i = i + 5) {
		 glVertex3f(App->markx + sin(i*rad)*.1 + 5.4, App->marky + cos(i*rad)*.1 + 5.4, 1);
		 
	 }
	 glEnd();
	 
	 // Little triangle
	 glBegin(GL_TRIANGLES);
	 glColor3f(1.0f, 0.0f, 0.0f);
	 glVertex3f(11.0f, 3.0f, 0.0f);
	 glVertex3f(12.0f, 3.0f, 0.0f);
	 glColor3f(0.0f, 0.0f, 1.0f);
	 glVertex3f(11.5f, 3.7f, 0.0f);
	 glEnd();
	 
	 // Nexus
	 glBegin(GL_LINE_STRIP);
	 glVertex3f(9.0f, 3.0f, 0.0f);
	 glVertex3f(9.0f, 12.0f, 0.0f);
	 glVertex3f(14.0f, 12.0f, 0.0f);
	 glVertex3f(14.0f, 3.0f, 0.0f);
	 glVertex3f(9.0f, 3.0f, 0.0f);
	 glEnd();
	 
	 //Screen
	 glBegin(GL_QUADS);
	 glColor3f(1.0f, 1.0f, 1.0f);
	 glVertex3f(9.3f, 3.7f, 0.0f);
	 glVertex3f(9.3f, 11.3f, 0.0f);
	 glVertex3f(13.7f, 11.3f, 0.0f);
	 glVertex3f(13.7f, 3.7f, 0.0f);
	 glVertex3f(9.3f, 3.7f, 0.0f);
	 glEnd();
	 
	 // Gmail
	 glBegin(GL_LINE_STRIP);
	 glColor3f(1.0f, 0.0f, 1.0f);
	 glVertex3f(xr + 3.0f,yr + 9.6f, 1.0f);
	 glVertex3f(xr + 3.0f,yr + 11.0f, 1.0f);
	 glVertex3f(xr + 4.0f,yr + 10.0f, 1.0f);
	 glVertex3f(xr + 5.0f,yr + 11.0f, 1.0f);
	 glVertex3f(xr + 5.0f,yr + 9.6f, 1.0f);
	 glEnd();
	 
	 glBegin(GL_QUADS);
	 glColor3f(xr + 1.0,yr + 1.0, 1.0f);
	 glVertex3f(xr + 3.01f,yr + 9.59f, 0.2f);
	 glVertex3f(xr + 3.01f,yr + 10.99f, 0.2f);
	 glVertex3f(xr + 4.99f,yr + 10.99f, 0.2f);
	 glVertex3f(xr + 4.99f,yr + 9.59f, 0.2f);
	 glEnd();
	 
	 
   glFlush();         // flush the pipeline (usually not necessary)
   glutSwapBuffers(); // we were drawing to the back buffer, now bring it to the front
}

//==========================================================================
// Main routine
//==========================================================================
int main ( int argc, char** argv )
 {
   // First thing to do is to create a single application state instance
   // and init here each state variable of our application:
   App = new AppState;
   App->markx = 1.5;
   App->marky = 1.5;

   // Init GLUT:
   glutInit ( &argc,argv );
   glutInitDisplayMode ( GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH );

   // Window position (from top corner), and size (width and height)
   glutInitWindowPosition( 20, 60 );
   glutInitWindowSize( 360, 360 );
   glutCreateWindow( "Android *GO* Home" );
	 

   // Initialize OpenGL settings as we want
   glEnable ( GL_DEPTH_TEST );
   glEnable ( GL_POINT_SMOOTH );
   glEnable ( GL_LINE_SMOOTH );
   glHint ( GL_LINE_SMOOTH_HINT, GL_NICEST );
   glHint ( GL_POINT_SMOOTH_HINT, GL_NICEST );
   glPointSize ( 6 );
   glLineWidth ( 2 );
	 
	 // orage r 255, g 204, b 102 
	 glClearColor(0.42,0.48,0.54,0.0);

   // Set up GLUT callback functions for key presses
   glutKeyboardFunc ( appKeyboardFunc );
   glutSpecialFunc ( appKeyboardFunc );

   // Set up GLUT callback function for resizing windows
   glutReshapeFunc( appResizeWindow );

   // Set up GLUT callback for drawing the scene
   glutDisplayFunc( appDrawScene );

   // Set up idle callback for background processing if needed
   // glutIdleFunc( myIdleFunction );

   // Print some info
   printf ( "Try keys: <space>, <up>, <down>, <left>, <right>\n" );
   printf ( "Press escape button to quit.\n");
	
	 // initiate idle
	 glutIdleFunc(idle);
	 
   // Finally start the main loop
   // Note that glutMainLoop never returns so your program is entirely event-driven
   glutMainLoop ();
}
