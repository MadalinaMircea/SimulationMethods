
//  main.cpp
//  softplot
//  Simulation Methods course, 2018
//  First Assignment: Molecular Dynamics (Brownian Dynamics) Simulation
//  Visualization part (needs the movie file copid into its directory)

// The OpenGL libraries, make sure to include the GLUT and OpenGL frameworks

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "globaldata.h"
#include "drawing.h"


int main(int argc, char **argv)
{

    initialize_global_data();

    read_moviefile_data();

    init_glut();
    init_OpenGl();

    start_main_loop_glut();

    return 0;
}


//
//#include <stdlib.h>
//#include <stdio.h>
//#define NUM_POINTS 5
//#define NUM_COMMANDS 4
//
//int main()
//{
//    char * commandsForGnuplot[] = {"set title \"Simulation Graph\"", "set style fill solid", "set boxwidth 0.5", "plot 'data.temp' with boxes"};
//    double xvals[NUM_POINTS] = {1.0, 2.0, 3.0, 4.0, 5.0};
//    double yvals[NUM_POINTS] = {5.0 ,3.0, 1.0, 3.0, 5.0};
//    FILE * temp = fopen("data.temp", "w");
//    /*Opens an interface that one can use to send commands as if they were typing into the
//     *     gnuplot command line.  "The -persistent" keeps the plot open even after your
//     *     C program terminates.
//     */
//    FILE * gnuplotPipe = popen ("gnuplot -persistent", "w");
//    int i;
//    for (i=0; i < NUM_POINTS; i++)
//    {
//    fprintf(temp, "%lf %lf \n", xvals[i], yvals[i]); //Write the data to a temporary file
//    }
//
//    for (i=0; i < NUM_COMMANDS; i++)
//    {
//    fprintf(gnuplotPipe, "%s \n", commandsForGnuplot[i]); //Send commands to gnuplot one by one.
//    }
//    return 0;
//}
//
