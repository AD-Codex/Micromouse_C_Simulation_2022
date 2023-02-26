#include <stdio.h>
#include <string.h>
#include<graphics.h>
#include<conio.h>
#include<dos.h>
#include <time.h>

///////////////////// example_1 ////////////////////////////////////////////

// X,Y,x,y start with 0

//	 _ _ _ _ _
//	| |  _   _|    ------->   13,8 ,10,2 ,12
//	| |_ _|   |    ------->   9	,5 ,12,1 ,7
//	|       | |    ------->   1	,2 ,2 ,3 ,9
//	| |_ _|_  |    ------->   9	,5 ,6 ,5 ,3
//	|_|_ _ _ _|    ------->   11,14,10,10,6

//          _
//  |= - 1,  =  -2, =|-3, _ -4
//                 _      _        
//	|_ - 5, _| -6,  |-7, | -8
//          _               _
//  | | -9, _ -10, |_| -11, _| -12,
//   _        _            _
//	| | -13, |_ -14, -15, |_| -16

//	50x50

//////////////////////////////////////////////////////////////////////////////////////////

// ---> F_X
// <--- B_X
// ^ B_Y
// v F_Y


//int x = 200;
//int y = 200;


///////////////////////////////////////////// maze examples ///////////////////////////////

int maze[10][10] = {
					{8	,7	,14	,2	,7	,14	,10	,7	,8	,12},
					{9	,1	,7	,11	,1	,10	,10	,3	,5	,7},
					{11	,9	,11	,8	,4	,10	,7	,1	,12	,9},
					{8	,6	,13	,5	,10	,7	,9	,5	,2	,6},
					{5	,7	,5	,10	,7	,1	,15	,10	,3	,13},
					{8	,4	,7	,13	,5	,6	,9	,14	,4	,3},
					{11	,8	,6	,1	,7	,14	,15	,10	,2	,3},
					{8	,6	,8	,6	,9	,8	,15	,2	,3	,9},
					{1	,10	,6	,13	,5	,6	,9	,9	,11	,9},
					{11	,14	,10	,4	,10	,10	,6	,5	,10	,6}
				};

//int maze[10][10] = {
//					{13	,8	,10	,10	,10	,10	,10	,2	,2	,7},
//					{9	,9	,13	,14	,2	,10	,7	,11	,11	,9},
//					{5	,15	,15	,2	,3	,14	,15	,12	,13	,9},
//					{14	,6	,9	,11	,9	,13	,9	,8	,6	,9},
//					{13	,8	,6	,13	,11	,5	,15	,4	,7	,9},
//					{5	,3	,13	,5	,10	,2	,15	,12	,9	,9},
//					{14	,3	,1	,12	,14	,3	,9	,13	,11	,9},
//					{8	,4	,3	,8	,7	,9	,5	,15	,12	,9},
//					{1	,12	,5	,3	,9	,9	,14	,15	,12	,9},
//					{5	,10	,12	,11	,11	,11	,14	,4	,10	,6}
//				};

//int maze[8][8] = {
//					{8	,7	,8	,2	,10	,7	,13	,13},
//					{9	,5	,6	,11	,13	,5	,3	,9},
//					{9	,8	,2	,10	,4	,10	,4	,3},
//					{9	,9	,9	,8	,7	,13	,8	,3},
//					{9	,9	,11	,5	,3	,9	,5	,3},
//					{9	,1	,10	,2	,3	,5	,10	,3},
//					{9	,11	,13	,11	,5	,10	,2	,3},
//					{11	,14	,4	,10	,10	,10	,6	,11}
//				};
				
//int maze[8][8] = {
//					{13	,8	,2	,10	,10	,2	,10	,7},
//					{9	,9	,5	,10	,7	,9	,13	,9},
//					{9	,5	,7	,13	,1	,6	,9	,9},
//					{9	,8	,3	,9	,9	,8	,4	,6},
//					{5	,6	,9	,9	,11	,1	,10	,12},
//					{14	,10	,6	,1	,10	,4	,10	,7},
//					{8	,10	,2	,6	,14	,10	,2	,3},
//					{5	,10	,4	,10	,10	,10	,6	,11}
//				};

//int maze[5][5] =  { 
//					{13,8,10,2,12},
//					{9,5,12,1,7},
//					{1,2,2,3,9},
//					{9,5,6,5,3},
//					{11,14,10,10,6},
//				};
				

int maze_size = 10; // change vaule based on maze_size

int terminal_maze[ 21][ 21]; // change vaule based on maze_size ( value = maze_size*2 +1 ) 
int edit_terminal_maze[ 20][ 21][ 21];  // change vaule based on maze_size ( value = maze_size*2 +1 ) 


int maze_lenght = maze_size*2 +1;			
				
int X_coordinate = 225 ;
int Y_coordinate= 225;
int X =0;
int Y =0;

char state[4] = "F_Y";
int count =1;

int mase(int x, int y, int num);
int sensor_check( int X_coord, int Y_coord);
int Sensor_check();
int Fill_box();
int move();
int move_back();
int mouse();



int F_sensor = 0;
int R_sensor = 0;
int L_sensor = 0;

int Path_find_1 = 0;
int maze_path = 0;
int maze_solved = 0;

int movement_count =0;

int turn_points[100][2];
int t_point = 0;
int points[100][2];
int ij =1;
int operation = 1;
int count_operation;
int y_coord;
int x_coord;

int Path_manage( int T_point, int int_x_coord, int int_y_coord);
int Path_cal( int T_point, int y, int x);
int Short_path_find( int y, int x);
	   


main()
{
	for ( int i=0; i<maze_lenght; i=i+1) {
		for ( int j=0; j<maze_lenght; j=j+1) {
			if ( i==0 || i == maze_lenght -1 || j==0 || j==maze_lenght -1 ) {
		        terminal_maze[i][j] = 101;
		    }
		    else{
			    terminal_maze[i][j] = -1;
		    }
		}
	}
	terminal_maze[ 0][ 1] = 101;
	terminal_maze[ 1][ 1] = 1;

	initwindow(800,800);
	
	Path_find_1 = 1;   
   
	while (1) {
		
		int x = 200;
		int y = 200;	
		
		for ( int i=0; i<maze_size; i=i+1) {
			for ( int j=0; j<maze_size; j=j+1) {
				mase(x,y,maze[i][j]);
				x=x+50;
			}
			x=200;
			y=y+50;		
		}		
		mouse();
		
		Sensor_check();
		Fill_box();
		
		
		printf("------------------------------------------------------------------------------------");
		printf("\n");
		for ( int i=0; i<maze_lenght; i=i+1) {
			for ( int j=0; j<maze_lenght; j=j+1) {
				printf( "%d\t",terminal_maze[i][j]);
			}
			printf("\n");
		}
		printf("-------------------------------------------------------------------------------------");
		printf("\n");
		printf("\n");
		printf("\n");
		
		delay(200); // change the frequency
		
		
//		sensor_check( X, Y);

		if ( maze_solved == 0){
			if ( Path_find_1 == 1) {
				move();
			}
			else {
				move_back();
			}
		}
		else {
			printf("maze solved----------------------\n");
			
			printf("\nmovement_count = %d\n", movement_count);
			
			
			for ( int i=0; i<=t_point; i=i+1) {
				for ( int j=0; j<maze_lenght; j=j+1) {
					for ( int k=0; k<maze_lenght; k=k+1) {
						edit_terminal_maze[i][j][k] = terminal_maze[j][k];
					}
				}
				
			}
			
			
			printf("--------------------------------0 maze -----------------------------------------------\n");
				
			for ( int j=0; j<maze_lenght; j=j+1) {
				for ( int k=0; k<maze_lenght; k=k+1) {
					printf( "%d\t",terminal_maze[j][k]);
				}
				printf("\n");
			}
			printf("-------------------------------------------------------------------------------------");
			printf("\n");
			printf("\n");
				
			
			
			for ( int i=0; i<=t_point; i=i+1) {
				printf("------------------------------- %d maze breaked by [ %d, %d] --------------------------------\n", i+1, turn_points[ i][0], turn_points[ i][1]);
				Path_manage( i, turn_points[ i][0], turn_points[ i][1]);
				
				for ( int j=0; j<maze_lenght; j=j+1) {
					for ( int k=0; k<maze_lenght; k=k+1) {
						printf( "%d\t",edit_terminal_maze[ i][j][k]);
					}
					printf("\n");
				}
				printf("-------------------------------------------------------------------------------------");
				printf("\n");
				printf("\n");
			}
			
			Short_path_find(3,2);
			
			break;
			
		}

		
		
		if ( Y == (maze_size/2)-1 && X == (maze_size/2)-1) {
			maze_path = maze_path + 1;
		}
		
		if ( X==0 && Y==0 && maze_path > 0 ) {
			maze_solved = 1;
		}
		
		printf("count number = %d \n", count);
					
		cleardevice();		
	}
	
   
   getch();
}

int move() {
	int terminalX_coord = X *2 +1;
	int terminalY_coord = Y *2 +1;
	
	if ( strcmp( state, "F_Y") == 0) {
		// turning point search
		if ( terminal_maze[ terminalY_coord +1][ terminalX_coord] == 0) {
			if ( terminal_maze[ terminalY_coord +2][ terminalX_coord] < count-1) {
			printf("terminal_maze[ terminalY_coord +2][ terminalX_coord] < count-1\n");
			turn_points[ t_point][0] = terminalY_coord +2;
			turn_points[ t_point][1] = terminalX_coord;
			t_point = t_point +1;
			}	
		}	
		if ( terminal_maze[ terminalY_coord][ terminalX_coord +1] == 0) {
			if ( terminal_maze[ terminalY_coord][ terminalX_coord +2] < count-1) {
				printf("terminal_maze[ terminalY_coord][ terminalX_coord +2] < count-1\n");
				turn_points[ t_point][0] = terminalY_coord;
				turn_points[ t_point][1] = terminalX_coord +2;
				t_point = t_point +1;
			}
		}	
		if ( terminal_maze[ terminalY_coord][ terminalX_coord -1] == 0) {
			if ( terminal_maze[ terminalY_coord][ terminalX_coord -2] < count-1) {
				printf("terminal_maze[ terminalY_coord][ terminalX_coord -2] < count-1\n");
				turn_points[ t_point][0] = terminalY_coord;
				turn_points[ t_point][1] = terminalX_coord -2;
				t_point = t_point +1;
			}
		}
	
		if ( terminal_maze[ terminalY_coord +1][ terminalX_coord] == 0 && terminal_maze[ terminalY_coord +2][ terminalX_coord] == count +1 && ( terminal_maze[ terminalY_coord +3][ terminalX_coord] == -1 || terminal_maze[ terminalY_coord +2][ terminalX_coord +1] == -1 || terminal_maze[ terminalY_coord +2][ terminalX_coord -1] == -1) ) {
			Y = Y +1;
			movement_count = movement_count +1;
			count = count +1;
			strcpy( state, "F_Y");
		} 
		else if ( terminal_maze[ terminalY_coord][ terminalX_coord -1] == 0 && terminal_maze[ terminalY_coord][ terminalX_coord -2] == count +1 && ( terminal_maze[ terminalY_coord][ terminalX_coord -3] == -1 || terminal_maze[ terminalY_coord +1][ terminalX_coord -2] == -1 || terminal_maze[ terminalY_coord -1][ terminalX_coord -2] == -1) ) {
			X = X -1;
			movement_count = movement_count +1;
			count = count +1;
			strcpy( state, "B_X");
		}
		else if ( terminal_maze[ terminalY_coord][ terminalX_coord +1] == 0 && terminal_maze[ terminalY_coord][ terminalX_coord +2] == count +1 && ( terminal_maze[ terminalY_coord][ terminalX_coord +3] == -1 || terminal_maze[ terminalY_coord +1][ terminalX_coord +2] == -1 || terminal_maze[ terminalY_coord -1][ terminalX_coord +2] == -1) ) {
			X = X +1;
			movement_count = movement_count +1;
			count = count +1;
			strcpy( state, "F_X");
		}
		else if ( terminal_maze[ terminalY_coord +1][ terminalX_coord] == 0 || terminal_maze[ terminalY_coord][ terminalX_coord -1] == 0 || terminal_maze[ terminalY_coord][ terminalX_coord +1] == 0) {
			strcpy( state, "B_Y");
			Path_find_1 = 0;
			printf("change move fn to move_back fn\n");		
		}
		else if ( terminal_maze[ terminalY_coord +1][ terminalX_coord] == 101 && terminal_maze[ terminalY_coord][ terminalX_coord -1] == 101 && terminal_maze[ terminalY_coord][ terminalX_coord +1] == 101) {
				strcpy( state, "B_Y");
				Path_find_1 = 0;
				printf("F_Y change move fn to move_back fn\n");
		}
		else {
				printf("11111111111111111\n");
		}
		
	}
	else if ( strcmp( state, "B_Y") == 0) {	
		// turning point search	
		if ( terminal_maze[ terminalY_coord -1][ terminalX_coord] == 0) {
			if ( terminal_maze[ terminalY_coord -2][ terminalX_coord] < count-1) {
				printf("terminal_maze[ terminalY_coord -2][ terminalX_coord] < count-1\n");
				turn_points[ t_point][0] = terminalY_coord -2;
				turn_points[ t_point][1] = terminalX_coord;
				t_point = t_point +1;
			}
		}	
		if ( terminal_maze[ terminalY_coord][ terminalX_coord +1] == 0) {
			if ( terminal_maze[ terminalY_coord][ terminalX_coord +2] < count-1) {
				printf("terminal_maze[ terminalY_coord][ terminalX_coord +2] < count-1\n");
				turn_points[ t_point][0] = terminalY_coord;
				turn_points[ t_point][1] = terminalX_coord +2;
				t_point = t_point +1;
			}
		}	
		if ( terminal_maze[ terminalY_coord][ terminalX_coord -1] == 0) {
			if ( terminal_maze[ terminalY_coord][ terminalX_coord -2] < count-1) {
				printf("terminal_maze[ terminalY_coord][ terminalX_coord -2] < count-1\n");
				turn_points[ t_point][0] = terminalY_coord;
				turn_points[ t_point][1] = terminalX_coord -2;
				t_point = t_point +1;
			}
		}
		
		if ( terminal_maze[ terminalY_coord -1][ terminalX_coord] == 0 && terminal_maze[ terminalY_coord -2][ terminalX_coord] == count +1 && ( terminal_maze[ terminalY_coord -3][ terminalX_coord] == -1 || terminal_maze[ terminalY_coord -2][ terminalX_coord +1] == -1 || terminal_maze[ terminalY_coord -2][ terminalX_coord -1] == -1) ) {
			Y = Y -1;
			movement_count = movement_count +1;
			count = count +1;
			strcpy( state, "B_Y");
		}
		else if ( terminal_maze[ terminalY_coord][ terminalX_coord +1] == 0 && terminal_maze[ terminalY_coord][ terminalX_coord +2] == count +1 && ( terminal_maze[ terminalY_coord][ terminalX_coord +3] == -1 || terminal_maze[ terminalY_coord +1][ terminalX_coord +2] == -1 || terminal_maze[ terminalY_coord -1][ terminalX_coord +2] == -1) ) {
			X = X +1;
			movement_count = movement_count +1;
			count = count +1;
			strcpy( state, "F_X");
		}
		else if ( terminal_maze[ terminalY_coord][ terminalX_coord -1] == 0 && terminal_maze[ terminalY_coord][ terminalX_coord -2] == count +1 && ( terminal_maze[ terminalY_coord][ terminalX_coord -3] == -1 || terminal_maze[ terminalY_coord +1][ terminalX_coord -2] == -1 || terminal_maze[ terminalY_coord -1][ terminalX_coord -2] == -1) ) {
			X = X -1;
			movement_count = movement_count +1;
			count = count +1;
			strcpy( state, "B_X");
		}
		else if ( terminal_maze[ terminalY_coord -1][ terminalX_coord] == 0 || terminal_maze[ terminalY_coord][ terminalX_coord +1] == 0 || terminal_maze[ terminalY_coord][ terminalX_coord -1] == 0 ) {
			strcpy( state, "F_Y");
			Path_find_1 = 0;
			printf("change move fn to move_back fn\n");
		}
		else if ( terminal_maze[ terminalY_coord -1][ terminalX_coord] == 101 && terminal_maze[ terminalY_coord][ terminalX_coord +1] == 101 && terminal_maze[ terminalY_coord][ terminalX_coord -1] == 101) {
			strcpy( state, "F_Y");
			Path_find_1 = 0;
			printf("B_Y change move fn to move_back fn\n");
		}
		else {
			printf("2222222222222222222\n");			
		}
				
	}
	else if ( strcmp( state, "F_X") == 0) {
		// turning point search
		if ( terminal_maze[ terminalY_coord +1][ terminalX_coord] == 0) {
			if ( terminal_maze[ terminalY_coord +2][ terminalX_coord] < count+1) {
				printf("terminal_maze[ terminalY_coord +2][ terminalX_coord] < count-1\n");
				turn_points[ t_point][0] = terminalY_coord +2;
				turn_points[ t_point][1] = terminalX_coord;
				t_point = t_point +1;
			}	
		}	
		if ( terminal_maze[ terminalY_coord -1][ terminalX_coord] == 0) {
			if ( terminal_maze[ terminalY_coord -2][ terminalX_coord] < count+1) {
				printf("terminal_maze[ terminalY_coord -2][ terminalX_coord] < count-1\n");
				turn_points[ t_point][0] = terminalY_coord -2;
				turn_points[ t_point][1] = terminalX_coord;
				t_point = t_point +1;
			}
		}	
		if ( terminal_maze[ terminalY_coord][ terminalX_coord +1] == 0) {
			if ( terminal_maze[ terminalY_coord][ terminalX_coord +2] < count+1) {
				printf("terminal_maze[ terminalY_coord][ terminalX_coord +2] < count-1\n");
				turn_points[ t_point][0] = terminalY_coord;
				turn_points[ t_point][1] = terminalX_coord +2;
				t_point = t_point +1;
			}
		}
		
		if ( terminal_maze[ terminalY_coord][ terminalX_coord +1] == 0 && terminal_maze[ terminalY_coord][ terminalX_coord +2] == count +1 && ( terminal_maze[ terminalY_coord][ terminalX_coord +3] == -1 || terminal_maze[ terminalY_coord +1][ terminalX_coord +2] == -1 || terminal_maze[ terminalY_coord -1][ terminalX_coord +2] == -1) ) {
			X = X +1;
			movement_count = movement_count +1;
			count = count +1;
			strcpy( state, "F_X");
		} 
		else if ( terminal_maze[ terminalY_coord +1][ terminalX_coord] == 0 && terminal_maze[ terminalY_coord +2][ terminalX_coord] == count +1 && ( terminal_maze[ terminalY_coord +3][ terminalX_coord] == -1 || terminal_maze[ terminalY_coord +2][ terminalX_coord +1] == -1 || terminal_maze[ terminalY_coord +2][ terminalX_coord -1] == -1) ) {
			Y = Y +1;
			movement_count = movement_count +1;
			count = count +1;
			strcpy( state, "F_Y");
		}
		else if ( terminal_maze[ terminalY_coord -1][ terminalX_coord] == 0 && terminal_maze[ terminalY_coord -2][ terminalX_coord] == count +1 && ( terminal_maze[ terminalY_coord -3][ terminalX_coord] == -1 || terminal_maze[ terminalY_coord -2][ terminalX_coord +1] == -1 || terminal_maze[ terminalY_coord -2][ terminalX_coord -1] == -1) ) {
			Y = Y -1;
			movement_count = movement_count +1;
			count = count +1;
			strcpy( state, "B_Y");
		}
		else if ( terminal_maze[ terminalY_coord][ terminalX_coord +1] == 0 || terminal_maze[ terminalY_coord +1][ terminalX_coord] == 0 || terminal_maze[ terminalY_coord -1][ terminalX_coord] == 0) {
			strcpy( state, "B_X");
			Path_find_1 = 0;
			printf("change move fn to move_back fn\n");
		}
		else if ( terminal_maze[ terminalY_coord][ terminalX_coord +1] == 101 && terminal_maze[ terminalY_coord +1][ terminalX_coord] == 101 && terminal_maze[ terminalY_coord -1][ terminalX_coord] == 101) {
			strcpy( state, "B_X");
			Path_find_1 = 0;
			printf("F_X change move fn to move_back fn\n");
		}
		else {
			printf("33333333333333333333333\n");			
		}
		
	}
	else if ( strcmp( state, "B_X") == 0) {
		// turning point search
		if ( terminal_maze[ terminalY_coord +1][ terminalX_coord] == 0) {
			if ( terminal_maze[ terminalY_coord +2][ terminalX_coord] < count-1) {
				printf("terminal_maze[ terminalY_coord +2][ terminalX_coord] < count-1\n");
				turn_points[ t_point][0] = terminalY_coord +2;
				turn_points[ t_point][1] = terminalX_coord;
				t_point = t_point +1;
			}	
		}	
		if ( terminal_maze[ terminalY_coord -1][ terminalX_coord] == 0) {
			if ( terminal_maze[ terminalY_coord -2][ terminalX_coord] < count-1) {
				printf("terminal_maze[ terminalY_coord -2][ terminalX_coord] < count-1\n");
				turn_points[ t_point][0] = terminalY_coord -2;
				turn_points[ t_point][1] = terminalX_coord;
				t_point = t_point +1;
			}
		}	
		if ( terminal_maze[ terminalY_coord][ terminalX_coord -1] == 0) {
			if ( terminal_maze[ terminalY_coord][ terminalX_coord -2] < count-1) {
				printf("terminal_maze[ terminalY_coord][ terminalX_coord -2] < count-1\n");
				turn_points[ t_point][0] = terminalY_coord;
				turn_points[ t_point][1] = terminalX_coord -2;
				t_point = t_point +1;
			}
		}
		
		if ( terminal_maze[ terminalY_coord][ terminalX_coord -1] == 0 && terminal_maze[ terminalY_coord][ terminalX_coord -2] == count +1 && ( terminal_maze[ terminalY_coord][ terminalX_coord -3] == -1 || terminal_maze[ terminalY_coord +1][ terminalX_coord -2] == -1 || terminal_maze[ terminalY_coord -1][ terminalX_coord -2] == -1) ) {
			X = X -1;
			movement_count = movement_count +1;
			count = count +1;
			strcpy( state, "B_X");
		} 
		else if ( terminal_maze[ terminalY_coord -1][ terminalX_coord] == 0 && terminal_maze[ terminalY_coord -2][ terminalX_coord] == count +1 && ( terminal_maze[ terminalY_coord -3][ terminalX_coord] == -1 || terminal_maze[ terminalY_coord -2][ terminalX_coord +1] == -1 || terminal_maze[ terminalY_coord -2][ terminalX_coord -1] == -1) ) {
			Y = Y -1;
			movement_count = movement_count +1;
			count = count +1;
			strcpy( state, "B_Y");
		}
		else if ( terminal_maze[ terminalY_coord +1][ terminalX_coord] == 0 && terminal_maze[ terminalY_coord +2][ terminalX_coord] == count +1 && ( terminal_maze[ terminalY_coord +3][ terminalX_coord] == -1 || terminal_maze[ terminalY_coord +2][ terminalX_coord +1] == -1 || terminal_maze[ terminalY_coord +2][ terminalX_coord -1] == -1) ) {
			Y = Y +1;
			movement_count = movement_count +1;
			count = count +1;
			strcpy( state, "F_Y");
		}
		else if ( terminal_maze[ terminalY_coord][ terminalX_coord -1] == 0 || terminal_maze[ terminalY_coord -1][ terminalX_coord] == 0 || terminal_maze[ terminalY_coord +1][ terminalX_coord] == 0) {
			strcpy( state, "F_X");
			Path_find_1 = 0;
			printf("change move fn to move_back fn\n");			
		}
		else if ( terminal_maze[ terminalY_coord][ terminalX_coord -1] == 101 && terminal_maze[ terminalY_coord -1][ terminalX_coord] == 101 && terminal_maze[ terminalY_coord +1][ terminalX_coord] == 101) {
			strcpy( state, "F_X");
			Path_find_1 = 0;
			printf("B_X change move fn to move_back fn\n");
		}
		else {
			printf("444444444444444444444\n");			
		}
		
	}
			
}


int move_back() {
	int terminalX_coord = X *2 +1;
	int terminalY_coord = Y *2 +1;
	
//	if ( terminal_maze[ terminalY_coord +1][ terminalX_coord] == 0) {
//		if ( terminal_maze[ terminalY_coord +2][ terminalX_coord] > count+1) {
//			printf("terminal_maze[ terminalY_coord +2][ terminalX_coord] > count+1\n");
////			Path_manage( terminalY_coord, terminalX_coord);
//			turn_points[ t_point][0] = terminalY_coord;
//			turn_points[ t_point][1] = terminalX_coord;
//			t_point = t_point +1;
//		}	
//	}	
//	if ( terminal_maze[ terminalY_coord -1][ terminalX_coord] == 0) {
//		if ( terminal_maze[ terminalY_coord -2][ terminalX_coord] > count+1) {
//			printf("terminal_maze[ terminalY_coord -2][ terminalX_coord] > count+1\n");
////			Path_manage( terminalY_coord, terminalX_coord);
//			turn_points[ t_point][0] = terminalY_coord;
//			turn_points[ t_point][1] = terminalX_coord;
//			t_point = t_point +1;
//		}
//	}	
//	if ( terminal_maze[ terminalY_coord][ terminalX_coord +1] == 0) {
//		if ( terminal_maze[ terminalY_coord][ terminalX_coord +2] > count+1) {
//			printf("terminal_maze[ terminalY_coord][ terminalX_coord +2] > count+1\n");
////			Path_manage( terminalY_coord, terminalX_coord);
//			turn_points[ t_point][0] = terminalY_coord;
//			turn_points[ t_point][1] = terminalX_coord;
//			t_point = t_point +1;
//		}
//	}	
//	if ( terminal_maze[ terminalY_coord][ terminalX_coord -1] == 0) {
//		if ( terminal_maze[ terminalY_coord][ terminalX_coord -2] > count+1) {
//			printf("terminal_maze[ terminalY_coord][ terminalX_coord -2] > count+1\n");
////			Path_manage( terminalY_coord, terminalX_coord);
//			turn_points[ t_point][0] = terminalY_coord;
//			turn_points[ t_point][1] = terminalX_coord;
//			t_point = t_point +1;
//		}
//	}
	
	
	
	if ( strcmp( state, "F_Y") == 0) {
		if ( Path_find_1 == 0 && terminal_maze[ terminalY_coord +1][ terminalX_coord] == 0 && terminal_maze[ terminalY_coord +2][ terminalX_coord] == count+1) {
			if ( terminal_maze[ terminalY_coord +3][ terminalX_coord] == -1 || terminal_maze[ terminalY_coord +2][ terminalX_coord +1] == -1 || terminal_maze[ terminalY_coord +2][ terminalX_coord -1] == -1 ) {
				count = terminal_maze[ terminalY_coord +2][ terminalX_coord] ;
				strcpy( state, "F_Y");
				Y = Y +1;
				movement_count = movement_count +1;
				Path_find_1 = 1;
				printf("1. F_Y change move_back fn to move fn\n");
			}			
		} 
		
		if ( Path_find_1 == 0 && terminal_maze[ terminalY_coord][ terminalX_coord -1] == 0 && terminal_maze[ terminalY_coord][ terminalX_coord -2] == count+1) {
			if ( terminal_maze[ terminalY_coord][ terminalX_coord -3] == -1 || terminal_maze[ terminalY_coord +1][ terminalX_coord -2] == -1 || terminal_maze[ terminalY_coord -1][ terminalX_coord -2] == -1 ) {
				count = terminal_maze[ terminalY_coord][ terminalX_coord -2];
				strcpy( state, "B_X");
				X = X -1;
				movement_count = movement_count +1;
				Path_find_1 = 1;
				printf("2. F_Y change move_back fn to move fn\n");
			}			
		}
		
		if ( Path_find_1 == 0 && terminal_maze[ terminalY_coord][ terminalX_coord +1] == 0 && terminal_maze[ terminalY_coord][ terminalX_coord +2] == count+1) {
			if ( terminal_maze[ terminalY_coord][ terminalX_coord +3] == -1 || terminal_maze[ terminalY_coord +1][ terminalX_coord +2] == -1 || terminal_maze[ terminalY_coord -1][ terminalX_coord +2] == -1) {
				count = terminal_maze[ terminalY_coord][ terminalX_coord +2];
				strcpy( state, "F_X");
				X = X +1;
				movement_count = movement_count +1;
				Path_find_1 = 1;
				printf("3. F_Y change move_back fn to move fn\n");
			}			
		}
		
		if ( Path_find_1 == 0 ) {
			if ( terminal_maze[ terminalY_coord +1][ terminalX_coord] == 0 && terminal_maze[ terminalY_coord +2][ terminalX_coord] == count -1) {
				count = terminal_maze[ terminalY_coord +2][ terminalX_coord];
				strcpy( state, "F_Y");
				Y = Y +1;
				movement_count = movement_count +1;
				printf("F_Y to F_Y moving back\n");
			}
			else if ( terminal_maze[ terminalY_coord][ terminalX_coord -1] == 0 && terminal_maze[ terminalY_coord][ terminalX_coord -2] == count -1) {
				count = terminal_maze[ terminalY_coord][ terminalX_coord -2];
				strcpy( state, "B_X");
				X = X -1;
				movement_count = movement_count +1;
				printf("F_Y to B_X moving back\n");
			}
			else if ( terminal_maze[ terminalY_coord][ terminalX_coord +1] == 0 && terminal_maze[ terminalY_coord][ terminalX_coord +2] == count -1) {
				count = terminal_maze[ terminalY_coord][ terminalX_coord +2] ;
				strcpy( state, "F_X");
				X = X +1;
				movement_count = movement_count +1;
				printf("F_Y to F_X moving back\n");
			}
			else {
				printf("------F_Y--------\n");
			}
			
		}
		
	}
	else if ( strcmp( state, "B_Y") == 0) {
		if ( Path_find_1 == 0 && terminal_maze[ terminalY_coord -1][ terminalX_coord] == 0 && terminal_maze[ terminalY_coord -2][ terminalX_coord] == count+1) {
			if ( terminal_maze[ terminalY_coord -3][ terminalX_coord] == -1 || terminal_maze[ terminalY_coord -2][ terminalX_coord +1] == -1 || terminal_maze[ terminalY_coord -2][ terminalX_coord -1] == -1) {
				count = terminal_maze[ terminalY_coord -2][ terminalX_coord] ;
				strcpy( state, "B_Y");
				Y = Y -1;
				movement_count = movement_count +1;
				Path_find_1 = 1;
				printf("1. B_Y change move_back fn to move fn\n");
			}
		}
		
		if ( Path_find_1 == 0 && terminal_maze[ terminalY_coord][ terminalX_coord +1] == 0 && terminal_maze[ terminalY_coord][ terminalX_coord +2] == count+1) {
			if ( terminal_maze[ terminalY_coord][ terminalX_coord +3] == -1 || terminal_maze[ terminalY_coord -1][ terminalX_coord +2] == -1 || terminal_maze[ terminalY_coord +1][ terminalX_coord +2] == -1) {
				count = terminal_maze[ terminalY_coord][ terminalX_coord +2];
				strcpy( state, "F_X");
				X = X +1;
				movement_count = movement_count +1;
				Path_find_1 = 1;
				printf("2. B_Y change move_back fn to move fn\n");
			}
		}
		
		if (  Path_find_1 == 0 && terminal_maze[ terminalY_coord][ terminalX_coord -1] == 0 && terminal_maze[ terminalY_coord][ terminalX_coord -2] == count+1) {
			if ( terminal_maze[ terminalY_coord][ terminalX_coord -3] == -1 || terminal_maze[ terminalY_coord -1][ terminalX_coord -2] == -1 || terminal_maze[ terminalY_coord +1][ terminalX_coord -2] == -1) {
				count = terminal_maze[ terminalY_coord][ terminalX_coord -2];				
				strcpy( state, "B_X");
				X = X -1;
				movement_count = movement_count +1;
				Path_find_1 = 1;
				printf("3. B_Y change move_back fn to move fn\n");
			}
		}
		
		if ( Path_find_1 == 0) {
			if ( terminal_maze[ terminalY_coord -1][ terminalX_coord] == 0 && terminal_maze[ terminalY_coord -2][ terminalX_coord] == count -1) {
				count = terminal_maze[ terminalY_coord -2][ terminalX_coord];
				strcpy( state, "B_Y");
				Y = Y -1;
				movement_count = movement_count +1;
				printf("B_Y to B_Y moving back\n");
			}
			else if ( terminal_maze[ terminalY_coord][ terminalX_coord +1] == 0 && terminal_maze[ terminalY_coord][ terminalX_coord +2] == count -1) {
				count = terminal_maze[ terminalY_coord][ terminalX_coord +2];
				strcpy( state, "F_X");
				X = X +1;
				movement_count = movement_count +1;
				printf("B_Y to F_X moving back\n");
			}
			else if ( terminal_maze[ terminalY_coord][ terminalX_coord -1] == 0 && terminal_maze[ terminalY_coord][ terminalX_coord -2] == count -1) {
				count = terminal_maze[ terminalY_coord][ terminalX_coord -2];
				strcpy( state, "B_X");
				X = X -1;
				movement_count = movement_count +1;
				printf("B_Y to B_X moving back\n");
			}
			else {
				printf("------B_Y--------\n");
			}
			
		}
								
	}
	else if ( strcmp( state, "F_X") == 0) {
		if ( Path_find_1 == 0 && terminal_maze[ terminalY_coord][ terminalX_coord +1] == 0 && terminal_maze[ terminalY_coord][ terminalX_coord +2] == count+1) {
			if ( terminal_maze[ terminalY_coord][ terminalX_coord +3] == -1 || terminal_maze[ terminalY_coord +1][ terminalX_coord +2] == -1 || terminal_maze[ terminalY_coord -1][ terminalX_coord +2] == -1) {
				count = terminal_maze[ terminalY_coord][ terminalX_coord +2];
				strcpy( state, "F_X");
				X = X +1;
				movement_count = movement_count +1;
				Path_find_1 = 1;
				printf("1. F_X change move_back fn to move fn\n");
			}			
		}
		
		if ( Path_find_1 == 0 && terminal_maze[ terminalY_coord +1][ terminalX_coord] == 0 && terminal_maze[ terminalY_coord +2][ terminalX_coord] == count+1) {
			if ( terminal_maze[ terminalY_coord +3][ terminalX_coord] == -1 || terminal_maze[ terminalY_coord +2][ terminalX_coord -1] == -1 || terminal_maze[ terminalY_coord +2][ terminalX_coord +1] == -1) {
				count = terminal_maze[ terminalY_coord +2][ terminalX_coord] ;
				strcpy( state, "F_Y");
				Y = Y +1;
				movement_count = movement_count +1;
				Path_find_1 = 1;
				printf("2. F_X change move_back fn to move fn\n");
			}
		}
		
		if ( Path_find_1 == 0 && terminal_maze[ terminalY_coord -1][ terminalX_coord] == 0 && terminal_maze[ terminalY_coord -2][ terminalX_coord] == count+1) {
			if ( terminal_maze[ terminalY_coord -3][ terminalX_coord] == -1 || terminal_maze[ terminalY_coord -2][ terminalX_coord +1] == -1 || terminal_maze[ terminalY_coord -2][ terminalX_coord -1] == -1) {
				count = terminal_maze[ terminalY_coord -2][ terminalX_coord];
				strcpy( state, "B_Y");
				Y = Y -1;
				movement_count = movement_count +1;
				Path_find_1 = 1;
				printf("3. F_X change move_back fn to move fn\n");
			}			
		}
		
		if ( Path_find_1 == 0) {
			if ( terminal_maze[ terminalY_coord][ terminalX_coord +1] == 0 && terminal_maze[ terminalY_coord][ terminalX_coord +2] == count -1) {
				count = terminal_maze[ terminalY_coord][ terminalX_coord +2];
				strcpy( state, "F_X");
				X = X +1;
				movement_count = movement_count +1;
				printf("F_X to F_X moving back\n");
			} 
			else if ( terminal_maze[ terminalY_coord +1][ terminalX_coord] == 0 && terminal_maze[ terminalY_coord +2][ terminalX_coord] == count -1) {
				count = terminal_maze[ terminalY_coord +2][ terminalX_coord];
				strcpy( state, "F_Y");
				Y = Y +1;
				movement_count = movement_count +1;
				printf("F_X to F_Y moving back\n");
			}
			else if ( terminal_maze[ terminalY_coord -1][ terminalX_coord] == 0 && terminal_maze[ terminalY_coord -2][ terminalX_coord] == count -1) {
				count = terminal_maze[ terminalY_coord -2][ terminalX_coord];
				strcpy( state, "B_Y");
				Y = Y -1;
				movement_count = movement_count +1;
				printf("F_X to B_Y moving back\n");
			}
			else {
				printf("------F_X--------\n");
			}
			
		}
		
	}
	else if ( strcmp( state, "B_X") == 0) {
		if ( Path_find_1 == 0 && terminal_maze[ terminalY_coord][ terminalX_coord -1] == 0 && terminal_maze[ terminalY_coord][ terminalX_coord -2] == count+1) {
			if ( terminal_maze[ terminalY_coord][ terminalX_coord -3] == -1 || terminal_maze[ terminalY_coord -1][ terminalX_coord -2] == -1 || terminal_maze[ terminalY_coord +1][ terminalX_coord -2] == -1) {
				count = terminal_maze[ terminalY_coord][ terminalX_coord -2];
				strcpy( state, "B_X");
				X = X -1;
				movement_count = movement_count +1;
				Path_find_1 = 1;
				printf("1. B_X change move_back fn to move fn\n");
			}			
		} 
		
		if ( Path_find_1 == 0 && terminal_maze[ terminalY_coord -1][ terminalX_coord] == 0 && terminal_maze[ terminalY_coord -2][ terminalX_coord] == count+1) {
			if ( terminal_maze[ terminalY_coord -3][ terminalX_coord] == -1 || terminal_maze[ terminalY_coord -2][ terminalX_coord +1] == -1 || terminal_maze[ terminalY_coord -2][ terminalX_coord -1] == -1) {
				count = terminal_maze[ terminalY_coord -2][ terminalX_coord];
				strcpy( state, "B_Y");
				Y = Y -1;
				movement_count = movement_count +1;
				Path_find_1 = 1;
				printf("2. B_X change move_back fn to move fn\n");
			}			
		}
		
		if ( Path_find_1 == 0 && terminal_maze[ terminalY_coord +1][ terminalX_coord] == 0 && terminal_maze[ terminalY_coord +2][ terminalX_coord] == count+1) {
			if ( terminal_maze[ terminalY_coord +3][ terminalX_coord] == -1 || terminal_maze[ terminalY_coord +2][ terminalX_coord -1] == -1 || terminal_maze[ terminalY_coord +2][ terminalX_coord +1] == -1) {
				count = terminal_maze[ terminalY_coord +2][ terminalX_coord];
				strcpy( state, "F_Y");
				Y = Y +1;
				movement_count = movement_count +1;
				Path_find_1 = 1;
				printf("3. B_X change move_back fn to move fn\n");
			}			
		}
		
		if ( Path_find_1 == 0) {
			if ( terminal_maze[ terminalY_coord][ terminalX_coord -1] == 0 && terminal_maze[ terminalY_coord][ terminalX_coord -2] == count -1) {
				count = terminal_maze[ terminalY_coord][ terminalX_coord -2];
				strcpy( state, "B_X");
				X = X -1;
				movement_count = movement_count +1;
				printf("B_X to B_X moving back\n");
			} 
			else if ( terminal_maze[ terminalY_coord -1][ terminalX_coord] == 0 && terminal_maze[ terminalY_coord -2][ terminalX_coord] == count -1) {
				count = terminal_maze[ terminalY_coord -2][ terminalX_coord];
				strcpy( state, "B_Y");
				Y = Y -1;
				movement_count = movement_count +1;
				printf("B_X to B_Y moving back\n");
			}
			else if ( terminal_maze[ terminalY_coord +1][ terminalX_coord] == 0 && terminal_maze[ terminalY_coord +2][ terminalX_coord] == count -1) {
				count = terminal_maze[ terminalY_coord +2][ terminalX_coord];
				strcpy( state, "F_Y");
				Y = Y +1;
				movement_count = movement_count +1;
				printf("B_X to F_Y moving back\n");
			}
			else {
				printf("------B_X--------\n");
			}
			
		}
				
	}
	
	
}


int Sensor_check() {
	int Y_coord = Y;
	int X_coord = X;
	
	if ( strcmp( state, "F_Y") == 0) {
		if ( maze[ Y_coord][ X_coord] == 1) {
			F_sensor = 0;
			R_sensor = 1;
			L_sensor = 0;
		}
		else if ( maze[ Y_coord][ X_coord] == 2) {
			F_sensor = 0;
			R_sensor = 0;
			L_sensor = 0;
		}
		else if ( maze[ Y_coord][ X_coord] == 3) {
			F_sensor = 0;
			R_sensor = 0;
			L_sensor = 1;
		}
		else if ( maze[ Y_coord][ X_coord] == 4) {
			F_sensor = 1;
			R_sensor = 0;
			L_sensor = 0;
		}
		else if ( maze[ Y_coord][ X_coord] == 5) {
			F_sensor = 1;
			R_sensor = 1;
			L_sensor = 0;
		}
		else if ( maze[ Y_coord][ X_coord] == 6) {
			F_sensor = 1;
			R_sensor = 0;
			L_sensor = 1;
		}
		else if ( maze[ Y_coord][ X_coord] == 7) {
			F_sensor = 0;
			R_sensor = 0;
			L_sensor = 1;
		}
		else if ( maze[ Y_coord][ X_coord] == 8) {
			F_sensor = 0;
			R_sensor = 1;
			L_sensor = 0;
		}
		else if ( maze[ Y_coord][ X_coord] == 9) {
			F_sensor = 0;
			R_sensor = 1;
			L_sensor = 1;
		}
		else if ( maze[ Y_coord][ X_coord] == 10) {
			F_sensor = 1;
			R_sensor = 0;
			L_sensor = 0;
		}
		else if ( maze[ Y_coord][ X_coord] == 11) {
			F_sensor = 1;
			R_sensor = 1;
			L_sensor = 1;
		}
		else if ( maze[ Y_coord][ X_coord] == 12) {
			F_sensor = 1;
			R_sensor = 0;
			L_sensor = 1;
		}
		else if ( maze[ Y_coord][ X_coord] == 13) {
			F_sensor = 0;
			R_sensor = 1;
			L_sensor = 1;
		}
		else if ( maze[ Y_coord][ X_coord] == 14) {
			F_sensor = 1;
			R_sensor = 1;
			L_sensor = 0;
		}
		else if ( maze[ Y_coord][ X_coord] == 15) {
			F_sensor = 0;
			R_sensor = 0;
			L_sensor = 0;
		}
		else if ( maze[ Y_coord][ X_coord] == 16) {
			F_sensor = 1;
			R_sensor = 1;
			L_sensor = 1;
		}
		
	}
	else if ( strcmp( state, "B_Y") == 0) {
		if ( maze[ Y_coord][ X_coord] == 1) {
			F_sensor = 0;
			R_sensor = 0;
			L_sensor = 1;
		}
		else if ( maze[ Y_coord][ X_coord] == 2) {
			F_sensor = 1;
			R_sensor = 0;
			L_sensor = 0;
		}
		else if ( maze[ Y_coord][ X_coord] == 3) {
			F_sensor = 0;
			R_sensor = 1;
			L_sensor = 0;
		}
		else if ( maze[ Y_coord][ X_coord] == 4) {
			F_sensor = 0;
			R_sensor = 0;
			L_sensor = 0;
		}
		else if ( maze[ Y_coord][ X_coord] == 5) {
			F_sensor = 0;
			R_sensor = 0;
			L_sensor = 1;
		}
		else if ( maze[ Y_coord][ X_coord] == 6) {
			F_sensor = 0;
			R_sensor = 1;
			L_sensor = 0;
		}
		else if ( maze[ Y_coord][ X_coord] == 7) {
			F_sensor = 1;
			R_sensor = 1;
			L_sensor = 0;
		}
		else if ( maze[ Y_coord][ X_coord] == 8) {
			F_sensor = 1;
			R_sensor = 0;
			L_sensor = 1;
		}
		else if ( maze[ Y_coord][ X_coord] == 9) {
			F_sensor = 0;
			R_sensor = 1;
			L_sensor = 1;
		}
		else if ( maze[ Y_coord][ X_coord] == 10) {
			F_sensor = 1;
			R_sensor = 0;
			L_sensor = 0;
		}
		else if ( maze[ Y_coord][ X_coord] == 11) {
			F_sensor = 0;
			R_sensor = 1;
			L_sensor = 1;
		}
		else if ( maze[ Y_coord][ X_coord] == 12) {
			F_sensor = 1;
			R_sensor = 1;
			L_sensor = 0;
		}
		else if ( maze[ Y_coord][ X_coord] == 13) {
			F_sensor = 1;
			R_sensor = 1;
			L_sensor = 1;
		}
		else if ( maze[ Y_coord][ X_coord] == 14) {
			F_sensor = 1;
			R_sensor = 0;
			L_sensor = 1;
		}
		else if ( maze[ Y_coord][ X_coord] == 15) {
			F_sensor = 0;
			R_sensor = 0;
			L_sensor = 0;
		}
		else if ( maze[ Y_coord][ X_coord] == 16) {
			F_sensor = 1;
			R_sensor = 1;
			L_sensor = 1;
		}
		
	}
	else if ( strcmp( state, "F_X") == 0) {
		if ( maze[ Y_coord][ X_coord] == 1) {
			F_sensor = 0;
			R_sensor = 0;
			L_sensor = 0;
		}
		else if ( maze[ Y_coord][ X_coord] == 2) {
			F_sensor = 0;
			R_sensor = 0;
			L_sensor = 1;
		}
		else if ( maze[ Y_coord][ X_coord] == 3) {
			F_sensor = 1;
			R_sensor = 0;
			L_sensor = 0;
		}
		else if ( maze[ Y_coord][ X_coord] == 4) {
			F_sensor = 0;
			R_sensor = 1;
			L_sensor = 0;
		}
		else if ( maze[ Y_coord][ X_coord] == 5) {
			F_sensor = 0;
			R_sensor = 1;
			L_sensor = 0;
		}
		else if ( maze[ Y_coord][ X_coord] == 6) {
			F_sensor = 1;
			R_sensor = 1;
			L_sensor = 0;
		}
		else if ( maze[ Y_coord][ X_coord] == 7) {
			F_sensor = 1;
			R_sensor = 0;
			L_sensor = 1;
		}
		else if ( maze[ Y_coord][ X_coord] == 8) {
			F_sensor = 0;
			R_sensor = 0;
			L_sensor = 1;
		}
		else if ( maze[ Y_coord][ X_coord] == 9) {
			F_sensor = 1;
			R_sensor = 0;
			L_sensor = 0;
		}
		else if ( maze[ Y_coord][ X_coord] == 10) {
			F_sensor = 0;
			R_sensor = 1;
			L_sensor = 1;
		}
		else if ( maze[ Y_coord][ X_coord] == 11) {
			F_sensor = 1;
			R_sensor = 1;
			L_sensor = 0;
		}
		else if ( maze[ Y_coord][ X_coord] == 12) {
			F_sensor = 1;
			R_sensor = 1;
			L_sensor = 1;
		}
		else if ( maze[ Y_coord][ X_coord] == 13) {
			F_sensor = 1;
			R_sensor = 0;
			L_sensor = 1;
		}
		else if ( maze[ Y_coord][ X_coord] == 14) {
			F_sensor = 0;
			R_sensor = 1;
			L_sensor = 1;
		}
		else if ( maze[ Y_coord][ X_coord] == 15) {
			F_sensor = 0;
			R_sensor = 0;
			L_sensor = 0;
		}
		else if ( maze[ Y_coord][ X_coord] == 16) {
			F_sensor = 1;
			R_sensor = 1;
			L_sensor = 1;
		}
		
	}
	else if ( strcmp( state, "B_X") == 0) {
		if ( maze[ Y_coord][ X_coord] == 1) {
			F_sensor = 1;
			R_sensor = 0;
			L_sensor = 0;
		}
		else if ( maze[ Y_coord][ X_coord] == 2) {
			F_sensor = 0;
			R_sensor = 1;
			L_sensor = 0;
		}
		else if ( maze[ Y_coord][ X_coord] == 3) {
			F_sensor = 0;
			R_sensor = 0;
			L_sensor = 0;
		}
		else if ( maze[ Y_coord][ X_coord] == 4) {
			F_sensor = 0;
			R_sensor = 0;
			L_sensor = 1;
		}
		else if ( maze[ Y_coord][ X_coord] == 5) {
			F_sensor = 1;
			R_sensor = 0;
			L_sensor = 1;
		}
		else if ( maze[ Y_coord][ X_coord] == 6) {
			F_sensor = 0;
			R_sensor = 0;
			L_sensor = 1;
		}
		else if ( maze[ Y_coord][ X_coord] == 7) {
			F_sensor = 0;
			R_sensor = 1;
			L_sensor = 0;
		}
		else if ( maze[ Y_coord][ X_coord] == 8) {
			F_sensor = 1;
			R_sensor = 1;
			L_sensor = 0;
		}
		else if ( maze[ Y_coord][ X_coord] == 9) {
			F_sensor = 1;
			R_sensor = 0;
			L_sensor = 0;
		}
		else if ( maze[ Y_coord][ X_coord] == 10) {
			F_sensor = 0;
			R_sensor = 1;
			L_sensor = 1;
		}
		else if ( maze[ Y_coord][ X_coord] == 11) {
			F_sensor = 1;
			R_sensor = 0;
			L_sensor = 1;
		}
		else if ( maze[ Y_coord][ X_coord] == 12) {
			F_sensor = 0;
			R_sensor = 1;
			L_sensor = 1;
		}
		else if ( maze[ Y_coord][ X_coord] == 13) {
			F_sensor = 1;
			R_sensor = 1;
			L_sensor = 0;
		}
		else if ( maze[ Y_coord][ X_coord] == 14) {
			F_sensor = 1;
			R_sensor = 1;
			L_sensor = 1;
		}
		else if ( maze[ Y_coord][ X_coord] == 15) {
			F_sensor = 0;
			R_sensor = 0;
			L_sensor = 0;
		}
		else if ( maze[ Y_coord][ X_coord] == 16) {
			F_sensor = 1;
			R_sensor = 1;
			L_sensor = 1;
		}
		
	}
	
}

int Fill_box() {
	int terminalX_coord = X*2 +1;
	int terminalY_coord = Y*2 +1;
	
	if ( strcmp( state, "F_Y") == 0) {	
		if ( F_sensor == 0 ) {
			terminal_maze[ terminalY_coord +1][ terminalX_coord] = 0;
			if ( terminal_maze[ terminalY_coord +2][ terminalX_coord] == -1) {
				terminal_maze[ terminalY_coord +2][ terminalX_coord] = count +1;
			}			
		}
		else terminal_maze[ terminalY_coord +1][ terminalX_coord] = 101;
		
		if ( R_sensor == 0 ) {
			terminal_maze[ terminalY_coord][ terminalX_coord -1] = 0;
			if ( terminal_maze[ terminalY_coord][ terminalX_coord -2] == -1) {
				terminal_maze[ terminalY_coord][ terminalX_coord -2] = count +1;
			}			
		}
		else terminal_maze[ terminalY_coord][ terminalX_coord -1] = 101;
		
		if ( L_sensor == 0 ) {
			terminal_maze[ terminalY_coord][ terminalX_coord +1] = 0;
			if ( terminal_maze[ terminalY_coord][ terminalX_coord +2] == -1) {
				terminal_maze[ terminalY_coord][ terminalX_coord +2] = count +1;
			}			
		}
		else terminal_maze[ terminalY_coord][ terminalX_coord +1] = 101;
		
	}
	else if ( strcmp( state, "B_Y") == 0) {
		if ( F_sensor == 0 ) {
			terminal_maze[ terminalY_coord -1][ terminalX_coord] = 0;
			if ( terminal_maze[ terminalY_coord -2][ terminalX_coord] == -1) {
				terminal_maze[ terminalY_coord -2][ terminalX_coord] = count +1;
			}			
		}
		else terminal_maze[ terminalY_coord -1][ terminalX_coord] = 101;
		
		if ( R_sensor == 0 ) {
			terminal_maze[ terminalY_coord][ terminalX_coord +1] = 0;
			if ( terminal_maze[ terminalY_coord][ terminalX_coord +2] == -1) {
				terminal_maze[ terminalY_coord][ terminalX_coord +2] = count +1;
			}			
		}
		else terminal_maze[ terminalY_coord][ terminalX_coord +1] = 101;
		
		if ( L_sensor == 0 ) {
			terminal_maze[ terminalY_coord][ terminalX_coord -1] = 0;
			if ( terminal_maze[ terminalY_coord][ terminalX_coord -2] == -1) {
				terminal_maze[ terminalY_coord][ terminalX_coord -2] = count +1;
			}			
		}
		else terminal_maze[ terminalY_coord][ terminalX_coord -1] = 101;
		
	}
	else if ( strcmp( state, "F_X") == 0) {
		if ( F_sensor == 0 ) {
			terminal_maze[ terminalY_coord][ terminalX_coord +1] = 0;
			if ( terminal_maze[ terminalY_coord][ terminalX_coord +2] == -1) {
				terminal_maze[ terminalY_coord][ terminalX_coord +2] = count +1;
			}			
		}
		else terminal_maze[ terminalY_coord][ terminalX_coord +1] = 101;
		
		if ( R_sensor == 0 ) {
			terminal_maze[ terminalY_coord +1][ terminalX_coord] = 0;
			if ( terminal_maze[ terminalY_coord +2][ terminalX_coord] == -1) {
				terminal_maze[ terminalY_coord +2][ terminalX_coord] = count +1;
			}			
		}
		else terminal_maze[ terminalY_coord +1][ terminalX_coord] = 101;
		
		if ( L_sensor == 0 ) {
			terminal_maze[ terminalY_coord -1][ terminalX_coord] = 0;
			if ( terminal_maze[ terminalY_coord -2][ terminalX_coord] == -1) {
				terminal_maze[ terminalY_coord -2][ terminalX_coord] = count +1;
			}			
		}
		else terminal_maze[ terminalY_coord -1][ terminalX_coord] = 101;
		
	}
	else if ( strcmp( state, "B_X") == 0) {
		if ( F_sensor == 0 ) {
			terminal_maze[ terminalY_coord][ terminalX_coord -1] = 0;
			if ( terminal_maze[ terminalY_coord][ terminalX_coord -2] == -1) {
				terminal_maze[ terminalY_coord][ terminalX_coord -2] = count +1;
			}			
		}
		else terminal_maze[ terminalY_coord][ terminalX_coord -1] = 101;
		
		if ( R_sensor == 0 ) {
			terminal_maze[ terminalY_coord -1][ terminalX_coord] = 0;
			if ( terminal_maze[ terminalY_coord -2][ terminalX_coord] == -1) {
				terminal_maze[ terminalY_coord -2][ terminalX_coord] = count +1;
			}			
		}
		else terminal_maze[ terminalY_coord -1][ terminalX_coord] = 101;
		
		if ( L_sensor == 0 ) {
			terminal_maze[ terminalY_coord +1][ terminalX_coord] = 0;
			if ( terminal_maze[ terminalY_coord +2][ terminalX_coord] == -1) {
				terminal_maze[ terminalY_coord +2][ terminalX_coord] = count +1;
			}			
		}
		else terminal_maze[ terminalY_coord +1][ terminalX_coord] = 101;
		
	}
	
}



int Path_manage( int T_poinit, int int_y_coord, int int_x_coord) {
		
	points[0][0] = int_y_coord;
	points[0][1] = int_x_coord;

	count_operation =0;

	while (1) {
		
		if ( count_operation >= ij) {
//			printf("break\n");
			break;
		}
		
		y_coord = points[count_operation][0];
		x_coord = points[count_operation][1];
		
//		printf("%d,%d\n", y_coord, x_coord );
	
		operation = 1;
	
		while ( operation == 1) {
			operation =0;
			Path_cal( T_poinit, y_coord, x_coord);
//			printf("\n");
		}
		
		count_operation = count_operation +1;
		
	}
	
	printf("path break points, ");
	for ( int i=0; i<=ij; i=i+1) {		
		printf("%d-[%d , %d] ", i, points[i][0], points[i][1]);
	}
	printf("\n");
	
}

int Path_cal( int T_point, int y, int x) {
	int count_points =0;

	int count_number = edit_terminal_maze[T_point][y][x];

	if ( edit_terminal_maze[T_point][y +1][x] == 0 && edit_terminal_maze[T_point][y +2][x] > count_number +1) {
//		printf( "maze[y +1][x] == 0 and maze[y +2][x] > count_number\n" );
		if ( count_points ==0) {
//			printf( "%d , %d \n", y_coord, x_coord);
			edit_terminal_maze[T_point][y +2][x] = count_number +1;
			y_coord = y +2;
			operation = 1;
			count_points = 1;
		}
		else {
			points[ij][0] = y;
			points[ij][1] = x;
			ij = ij +1;
		}
	}

	if ( edit_terminal_maze[T_point][y -1][x] == 0 && edit_terminal_maze[T_point][y -2][x] > count_number +1) {
//		printf( "maze[y -1][x] == 0 and maze[y -2][x] > count_number\n" );
		if ( count_points ==0) {
//			printf( "%d , %d \n", y_coord, x_coord);
			edit_terminal_maze[T_point][y -2][x] = count_number +1;
			y_coord = y -2;
			operation = 1;
			count_points = 1;
		}
		else {
			points[ij][0] = y;
			points[ij][1] = x;
			ij = ij +1;
		}
	}

	if ( edit_terminal_maze[T_point][y][x +1] == 0 && edit_terminal_maze[T_point][y][x +2] > count_number +1) {
//		printf( "maze[y][x -1] == 0 and maze[y][x -2] > count_number\n" );
		if ( count_points ==0) {
//			printf( "%d , %d \n", y_coord, x_coord);
			edit_terminal_maze[T_point][y][x +2] = count_number +1;
			x_coord = x +2;
			operation = 1;
			count_points = 1;
		}
		else {
			points[ij][0] = y;
			points[ij][1] = x;
			ij = ij +1;
		}
	}

	if ( edit_terminal_maze[T_point][y][x -1] == 0 && edit_terminal_maze[T_point][y][x -2] > count_number +1) {
//		printf( "maze[y][x -1] == 0 and maze[y][x -2] > count_number\n" );
		if ( count_points ==0) {
//			printf( "%d , %d \n", y_coord, x_coord);
			edit_terminal_maze[T_point][y][x -2] = count_number +1;
			x_coord = x -2;
			operation = 1;
			count_points = 1;
		}
		else {
			points[ij][0] = y;
			points[ij][1] = x;
			ij = ij +1;
		}
	}
}

int Short_path_find( int y, int x) {
	int given_Xpoint = x;
	int given_Ypoint = y;
	int Mnum = 2000;
	int Mint =0;
	
	int given_T_Xpoint = given_Xpoint *2 +1;
	int given_T_Ypoint = given_Ypoint *2 +1;
	
	int Short_path_points[40][2];
	
	for ( int i=0; i<=t_point; i=i+1) {
		if ( edit_terminal_maze[ i][ given_T_Ypoint][ given_T_Xpoint] < Mnum) {
			Mnum = edit_terminal_maze[ i][ given_T_Ypoint][ given_T_Xpoint];
			Mint = i;
		}
	}
	
	Short_path_points[0][0] = given_T_Ypoint;
	Short_path_points[0][1] = given_T_Xpoint;
	
	int current_Xpoint = given_T_Xpoint;
	int current_Ypoint = given_T_Ypoint;
	int current_count = Mnum;
	int current_i = 0;
	
	while ( current_count > 1) {
//		printf("%d\n", current_count);
		current_i = current_i +1;
		
		if ( edit_terminal_maze[ Mint][ current_Ypoint -1][ current_Xpoint] ==0 && edit_terminal_maze[ Mint][ current_Ypoint -2][ current_Xpoint] == current_count-1) {
			Short_path_points[current_i][0] = current_Ypoint;	
			Short_path_points[current_i][1] = current_Xpoint;		
			current_Ypoint = current_Ypoint -2;
			current_count = current_count -1;			
		}
		else if ( edit_terminal_maze[ Mint][ current_Ypoint +1][ current_Xpoint] ==0 && edit_terminal_maze[ Mint][ current_Ypoint +2][ current_Xpoint] == current_count-1) {
			Short_path_points[current_i][0] = current_Ypoint;	
			Short_path_points[current_i][1] = current_Xpoint;
			current_Ypoint = current_Ypoint +2;
			current_count = current_count -1;
		}
		else if ( edit_terminal_maze[ Mint][ current_Ypoint][ current_Xpoint -1] ==0 && edit_terminal_maze[ Mint][ current_Ypoint][ current_Xpoint -2] == current_count-1) {
			Short_path_points[current_i][0] = current_Ypoint;	
			Short_path_points[current_i][1] = current_Xpoint;
			current_Xpoint = current_Xpoint -2;
			current_count = current_count -1;
		}
		else if ( edit_terminal_maze[ Mint][ current_Ypoint][ current_Xpoint +1] ==0 && edit_terminal_maze[ Mint][ current_Ypoint][ current_Xpoint +2] == current_count-1) {
			Short_path_points[current_i][0] = current_Ypoint;	
			Short_path_points[current_i][1] = current_Xpoint;
			current_Xpoint = current_Xpoint +2;
			current_count = current_count -1;
		}
				
	}
	
	printf("Short path to run - [ %d, %d] \n", y, x);
	for ( int i=1; i<Mnum; i=i+1) {
		printf("%d-[ %d, %d], ", i, (Short_path_points[i][0] -1)/2, (Short_path_points[i][1] -1)/2);
	}
		
	

}


int sensor_check( int X_coord, int Y_coord) {
	int terminalX_coord = X_coord *2 +1;
	int terminalY_coord = Y_coord *2 +1;
	
	if ( maze[ Y_coord][ X_coord] == 1) {
		terminal_maze[ terminalY_coord][ terminalX_coord] = count;
		terminal_maze[ terminalY_coord][ terminalX_coord -1] = 101;
		terminal_maze[ terminalY_coord -1][ terminalX_coord] = 0;
		terminal_maze[ terminalY_coord][ terminalX_coord +1] = 0;
		terminal_maze[ terminalY_coord +1][ terminalX_coord] = 0;
	}
	else if ( maze[ Y_coord][ X_coord] == 2) {
		terminal_maze[ terminalY_coord][ terminalX_coord] = count;
		terminal_maze[ terminalY_coord][ terminalX_coord -1] = 0;
		terminal_maze[ terminalY_coord -1][ terminalX_coord] = 101;
		terminal_maze[ terminalY_coord][ terminalX_coord +1] = 0;
		terminal_maze[ terminalY_coord +1][ terminalX_coord] = 0;
		
	}
	else if ( maze[ Y_coord][ X_coord] == 3) {
		terminal_maze[ terminalY_coord][ terminalX_coord] = count;
		terminal_maze[ terminalY_coord][ terminalX_coord -1] = 0;
		terminal_maze[ terminalY_coord -1][ terminalX_coord] = 0;
		terminal_maze[ terminalY_coord][ terminalX_coord +1] = 101;
		terminal_maze[ terminalY_coord +1][ terminalX_coord] = 0;
		
	}
	else if ( maze[ Y_coord][ X_coord] == 4) {
		terminal_maze[ terminalY_coord][ terminalX_coord] = count;
		terminal_maze[ terminalY_coord][ terminalX_coord -1] = 0;
		terminal_maze[ terminalY_coord -1][ terminalX_coord] = 0;
		terminal_maze[ terminalY_coord][ terminalX_coord +1] = 0;
		terminal_maze[ terminalY_coord +1][ terminalX_coord] = 101;
		
	}
	else if ( maze[ Y_coord][ X_coord] == 5) {
		terminal_maze[ terminalY_coord][ terminalX_coord] = count;
		terminal_maze[ terminalY_coord][ terminalX_coord -1] = 101;
		terminal_maze[ terminalY_coord -1][ terminalX_coord] = 0;
		terminal_maze[ terminalY_coord][ terminalX_coord +1] = 0;
		terminal_maze[ terminalY_coord +1][ terminalX_coord] = 101;
		
	}
	else if ( maze[ Y_coord][ X_coord] == 6) {
		terminal_maze[ terminalY_coord][ terminalX_coord] = count;
		terminal_maze[ terminalY_coord][ terminalX_coord -1] = 0;
		terminal_maze[ terminalY_coord -1][ terminalX_coord] = 0;
		terminal_maze[ terminalY_coord][ terminalX_coord +1] = 101;
		terminal_maze[ terminalY_coord +1][ terminalX_coord] = 101;
		
	}
	else if ( maze[ Y_coord][ X_coord] == 7) {
		terminal_maze[ terminalY_coord][ terminalX_coord] = count;
		terminal_maze[ terminalY_coord][ terminalX_coord -1] = 0;
		terminal_maze[ terminalY_coord -1][ terminalX_coord] = 101;
		terminal_maze[ terminalY_coord][ terminalX_coord +1] = 101;
		terminal_maze[ terminalY_coord +1][ terminalX_coord] = 0;
		
	}
	else if ( maze[ Y_coord][ X_coord] == 8) {
		terminal_maze[ terminalY_coord][ terminalX_coord] = count;
		terminal_maze[ terminalY_coord][ terminalX_coord -1] = 101;
		terminal_maze[ terminalY_coord -1][ terminalX_coord] = 101;
		terminal_maze[ terminalY_coord][ terminalX_coord +1] = 0;
		terminal_maze[ terminalY_coord +1][ terminalX_coord] = 0;
		
	}	
	else if ( maze[ Y_coord][ X_coord] == 9) {
		terminal_maze[ terminalY_coord][ terminalX_coord] = count;
		terminal_maze[ terminalY_coord][ terminalX_coord -1] = 101;
		terminal_maze[ terminalY_coord -1][ terminalX_coord] = 0;
		terminal_maze[ terminalY_coord][ terminalX_coord +1] = 101;
		terminal_maze[ terminalY_coord +1][ terminalX_coord] = 0;
		
	}
	else if ( maze[ Y_coord][ X_coord] == 10) {
		terminal_maze[ terminalY_coord][ terminalX_coord] = count;
		terminal_maze[ terminalY_coord][ terminalX_coord -1] = 0;
		terminal_maze[ terminalY_coord -1][ terminalX_coord] = 101;
		terminal_maze[ terminalY_coord][ terminalX_coord +1] = 0;
		terminal_maze[ terminalY_coord +1][ terminalX_coord] = 101;
		
	}
	else if ( maze[ Y_coord][ X_coord] == 11) {
		terminal_maze[ terminalY_coord][ terminalX_coord] = count;
		terminal_maze[ terminalY_coord][ terminalX_coord -1] = 101;
		terminal_maze[ terminalY_coord -1][ terminalX_coord] = 0;
		terminal_maze[ terminalY_coord][ terminalX_coord +1] = 101;
		terminal_maze[ terminalY_coord +1][ terminalX_coord] = 101;
		
	}
	else if ( maze[ Y_coord][ X_coord] == 12) {
		terminal_maze[ terminalY_coord][ terminalX_coord] = count;
		terminal_maze[ terminalY_coord][ terminalX_coord -1] = 0;
		terminal_maze[ terminalY_coord -1][ terminalX_coord] = 101;
		terminal_maze[ terminalY_coord][ terminalX_coord +1] = 101;
		terminal_maze[ terminalY_coord +1][ terminalX_coord] = 101;
		
	}
	else if ( maze[ Y_coord][ X_coord] == 13) {
		terminal_maze[ terminalY_coord][ terminalX_coord] = count;
		terminal_maze[ terminalY_coord][ terminalX_coord -1] = 101;
		terminal_maze[ terminalY_coord -1][ terminalX_coord] = 101;
		terminal_maze[ terminalY_coord][ terminalX_coord +1] = 101;
		terminal_maze[ terminalY_coord +1][ terminalX_coord] = 0;
		
	}
	else if ( maze[ Y_coord][ X_coord] == 14) {
		terminal_maze[ terminalY_coord][ terminalX_coord] = count;
		terminal_maze[ terminalY_coord][ terminalX_coord -1] = 101;
		terminal_maze[ terminalY_coord -1][ terminalX_coord] = 101;
		terminal_maze[ terminalY_coord][ terminalX_coord +1] = 0;
		terminal_maze[ terminalY_coord +1][ terminalX_coord] = 101;
		
	}
	else if ( maze[ Y_coord][ X_coord] == 15) {
		terminal_maze[ terminalY_coord][ terminalX_coord] = count;
		terminal_maze[ terminalY_coord][ terminalX_coord -1] = 0;
		terminal_maze[ terminalY_coord -1][ terminalX_coord] = 0;
		terminal_maze[ terminalY_coord][ terminalX_coord +1] = 0;
		terminal_maze[ terminalY_coord +1][ terminalX_coord] = 0;
		
	}
	else if ( maze[ Y_coord][ X_coord] == 16) {
		terminal_maze[ terminalY_coord][ terminalX_coord] = count;
		terminal_maze[ terminalY_coord][ terminalX_coord -1] = 101;
		terminal_maze[ terminalY_coord -1][ terminalX_coord] = 101;
		terminal_maze[ terminalY_coord][ terminalX_coord +1] = 101;
		terminal_maze[ terminalY_coord +1][ terminalX_coord] = 101;
		
	}
	
}



int mouse() {
	X_coordinate = 225 + X*50;
	Y_coordinate = 225 + Y*50;
	circle( X_coordinate, Y_coordinate, 10);
}

int mase(int x, int y, int num) {
	
	if ( num == 1 ) {
		line( x, y, x, y+50);
	}
	else if (num == 2) {
		line( x, y, x+50, y);
	}
	else if (num == 3) {
		line( x+50, y, x+50, y+50);
	}
	else if (num == 4) {
		line( x, y+50, x+50, y+50);
	}
	else if (num == 5) {
		line( x, y, x, y+50);
		line( x, y+50, x+50, y+50);
	}
	else if (num == 6) {
		line( x+50, y, x+50, y+50);
		line( x, y+50, x+50, y+50);
	}
	else if (num == 7) {
		line( x, y, x+50, y);
		line( x+50, y, x+50, y+50);
	}
	else if (num == 8) {
		line( x, y, x+50, y);
		line( x, y, x, y+50);
	}
	else if (num == 9) {
		line( x, y, x, y+50);
		line( x+50, y, x+50, y+50);
	}
	else if (num == 10) {
		line( x, y, x+50, y);
		line( x, y+50, x+50, y+50);
	}
	else if (num == 11) {
		line( x, y, x, y+50);
		line( x, y+50, x+50, y+50);
		line( x+50, y, x+50, y+50);
	}
	else if (num == 12) {
		line( x, y, x+50, y);
		line( x+50, y, x+50, y+50);
		line( x, y+50, x+50, y+50);
	}
	else if (num == 13) {
		line( x, y, x, y+50);
		line( x, y, x+50, y);
		line( x+50, y, x+50, y+50);
	}
	else if (num == 14) {
		line( x, y, x+50, y);
		line( x, y, x, y+50);
		line( x, y+50, x+50, y+50);
	}
	else if (num == 15) {
		
	}
	else if (num == 16) {
		line( x, y, x, y+50);
		line( x, y, x+50, y);
		line( x+50, y, x+50, y+50);
		line( x, y+50, x+50, y+50);
	}
	
}



