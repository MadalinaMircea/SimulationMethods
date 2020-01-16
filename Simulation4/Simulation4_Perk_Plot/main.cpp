
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

#include<iostream>
using namespace std;

#define NUM_COMMANDS 4

void plotGraph()
{
    char * commandsForGnuplot[] = {"set title \"Simulation Graph\"",
    "set grid", "set term x11 solid lw 4",
    "plot '../perk_p_10.in' with linespoints lc rgb 'orange', '../perk_p_30.in' with linespoints lc rgb 'blue',\
    '../perk_p_50.in' with linespoints lc rgb 'green','../perk_p_60.in' with linespoints lc rgb 'red',\
    '../perk_p_70.in' with linespoints lc rgb 'black', '../perk_p_90.in' with linespoints lc rgb 'purple'"};
    FILE * gnuplotPipe = popen ("gnuplot -persistent", "w");

    int i;
    for (i=0; i < NUM_COMMANDS; i++)
    {
      fprintf(gnuplotPipe, "%s \n", commandsForGnuplot[i]); //Send commands to gnuplot one by one.
    }
}

void plotSpanningGraph()
{
    char * commandsForGnuplot[] = {"set title \"Simulation Graph\"",
    "set grid", "set term x11 solid lw 4",
    "plot '../spanning_p_10.in' with linespoints lc rgb 'orange',\
    '../spanning_p_50.in' with linespoints lc rgb 'green',\
    '../spanning_p_60.in' with linespoints lc rgb 'black',\
    '../spanning_p_70.in' with linespoints lc rgb 'red'"};
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
    cout << "Give movie file\n\t'0'-p=0.1\n\t'1'-p=0.3\n\t'2'-p=0.5\n\t'3'-p=0.6\n\t'4'-p=0.7\n\t'5'-p=0.9\nFile: ";
    cin >> file;

    initialize_global_data(file);

    read_moviefile_data();

    init_glut();
    init_OpenGl();

    start_main_loop_glut();
}


int main(int argc, char **argv)
{

//    initialize_global_data();
//
//    read_moviefile_data();
//
//    init_glut();
//    init_OpenGl();
//
//    start_main_loop_glut();

    char input;
        cout << "Give input: \n\t'0'-exit\n\t'1'-plot max cluster graph\n\t'2'-plot spanning cluster probability\n\t'3'-play movie\nInput:";

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
                plotSpanningGraph();
                break;
            case '3':
                playMovie();
                break;
        }

    return 0;
}
