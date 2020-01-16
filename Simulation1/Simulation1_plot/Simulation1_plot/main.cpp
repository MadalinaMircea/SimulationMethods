
//  main.cpp
//  softplot
//  Simulation Methods course, 2018
//  First Assignment: Molecular Dynamics (Brownian Dynamics) Simulation
//  Visualization part (needs the movie file copid into its directory)

// The OpenGL libraries, make sure to include the GLUT and OpenGL frameworks

//#include <math.h>
//#include <stdio.h>
//#include <stdlib.h>
//
//#include "globaldata.h"
//#include "drawing.h"
//
//
//int main(int argc, char **argv)
//{
//
//    initialize_global_data();
//
//    read_moviefile_data();
//
//    init_glut();
//    init_OpenGl();
//
//    start_main_loop_glut();
//
//    return 0;
//}

#include <stdlib.h>
#include <iostream>
#include "globaldata.h"
#include "drawing.h"
#define NUM_COMMANDS 4

void plotGraph()
{
    char * commandsForGnuplot[] = {"set title \"Simulation Graph\"",
    "set grid", "set term x11 solid lw 4",
 //   "plot '../../verlet.in' with linespoints lc rgb 'blue', '../../tabulated.in' with linespoints lc rgb 'green'"};
    "plot '../../unoptimized.in' with linespoints lc rgb 'orange', '../../verlet.in' with linespoints lc rgb 'blue', '../../tabulated.in' with linespoints lc rgb 'green'"};
    FILE * gnuplotPipe = popen ("gnuplot -persistent", "w");

    int i;
    for (i=0; i < NUM_COMMANDS; i++)
    {
      fprintf(gnuplotPipe, "%s \n", commandsForGnuplot[i]); //Send commands to gnuplot one by one.
    }
}

void playMovie()
{
    int file = -1;
    cout << "Give movie file\n\t'0'-unoptimized\n\t'1'-verlet\n\t'2'-tabulated\nFile: ";
    cin >> file;

    initialize_global_data(file);

    read_moviefile_data();

    init_glut();
    init_OpenGl();

    start_main_loop_glut();
}


int main()
{
//    bool keepGoing = true;
//
//    while(keepGoing)
//    {
        char input;
        cout << "Give input: \n\t'0'-exit\n\t'1'-plot graph\n\t'2'-play movie\nInput:";

        cin >> input;

        switch(input)
        {
            case '0':
                //keepGoing = false;
                break;
            case '1':
                plotGraph();
                break;
            case '2':
                playMovie();
                break;
        }
//    }

    return 0;
}

