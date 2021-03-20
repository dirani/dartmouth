/* 
https://remisharrock.fr/sysbuild/#/VM
*/

Course Unit 6.1: History of Linux and the command line Manipulating the command line interface
/* 
whoami
whoami --help
id
logname
echo hello
echo $0
hostname
uname
uname -a
history  //AND UP ARROW
clear
uptime
cal
cal --help
cal -j
date
date +"%T"
date +"%A %d %B %Y"
man
*/
/* 

Course Unit 6.1: History of Linux and the command line
Manipulating the command line interface
Interactive commands: top, htop, nano, vim, how to get back to the prompt

top --help //how to quit +
top  //q to quit
top  // ^+C to quit
htop
htop --help
htop // F1
nano // ^ = ctrl  carret (circumflex accent)
vim // :q and also escape then :q
//CTRL + C expanation (sometimes quits the program, but not always)
*/

/*
Course
Unit 6.2: The Linux file system
Discovering the file system
pwd, cd, ls, absolute path, relative path

Commands discussed in this video:

    pwd
    whoami
    ls
    cd /
    pwd
    ls
    cd
    pwd
    cd /home
    ls
    cd /
    pwd
    cd /bin
    ls
    cd /
    ls
    cd /sys
    ls
    cd
 

    //RELATIVE PATHS

    pwd
    ls -a
    cd ..
    pwd
    cd user
    pwd
    cd ../..
    pwd
    ls
    cd sys
    ls
    cd module
    cd drm
    ls
    cd parameters
    ls
    cd ../../..
    ls -a
    cd /sys/module
    cd /sys
    cd ./module
    cd
    ls
    cd program.c
 */

/* 
pwd, cd, ls, absolute path, relative path (2)



    ls
    file program.c
    nano f
    hello!   (CTRL + O then ENTER then CTRL + X)
    file f
    realpath f
    cd /
    ls
    file bin
    cd bin
    ls
    file cat
    file busybox
    realpath cat
    cd /sys/kernel
    ls
    file notes
    file fscaps
    which realpath
    which cat
    which which
    which file

*/
/* 

Course
Unit 6.2: The Linux file system
Creating and deleting files and folders
cat less



    nano file.txt
    here is a text file
    with a second line
    cat file.txt
    echo "hello world"
    echo "hello world" > file2.txt
    cat file2.txt
    cat file2.txt > file3.txt
    cat file3.txt
    cat > anotherfile.txt
    this is anotherfile
    with a new second also (CTRL + D twice!)
    cat anotherfile.txt
    cat /etc/services
    cat /etc/services > listOfServices.txt
    nano listOfServices.txt
    cat /etc/services | more
    cat /etc/services | less    (navigating: space bar, arrows or j,k, G, g)
    more anotherfile.txt
    less anotherfile.txt
    ls /usr/bin
    ls /usr/bin | less
    searching: Forward Search
    / – search for a pattern which will take you to the next occurrence.
    n – for next match in forward
    N – for previous match in backward
    Backward Search
    ? – search for a pattern which will take you to the previous occurrence.
    n – for next match in backward direction
    N – for previous match in forward direction
    less --help  (see N and M options)
    ls /usr/bin | less -NM
*/

/* 
Course
Unit 6.2: The Linux file system
Creating and deleting files and folders
mkdir, rm -r


    mkdir folder
    ls
    ls -l
    cd folder
    touch f1
    touch f2
    mkdir subfolder
    ls
    cd subfolder
    pwd
    touch f3
    touch f4
    touch f5
    cd
    pwd
    rm folder   (error: is a directory)
    rm -r folder
    mkdir folder
    cd folder
    touch f1
    touch f2
    cd
    rm -ri folder
    y y y
    mkdir folder
    cd folder
    touch f1
    touch f2
    cd
    yes   (CTR + C)
    ls
    yes | rm -ri folder
    mkdir D1/D2/D3/D4/D5
    mkdir -p D1/D2/D3/D4/D5
*/

/* 
Course
Unit 6.2: The Linux file system
Unblocking yourself in the command line
Unblock yourself in the command line



    get out of vim:
    vim
    i
    insert some text
    ESCAPE + :q or sometimes :q!
    '
    '
    '  CTRL + D
    "
    "
    "  CTRL + D
    (
    )
    cat > file.txt
    this is a file   CTRL + D twice
    cat file.txt
    cat > file2.txt
    this is a file
    CTRL + D  (only once because empty line)
    cat file2.txt

    worst case : kill a program
    rain
    open second terminal
    htop  F9  send the SIGKILL signal
*/

/* 

Course
Unit 6.2: The Linux file system
Modifying, moving and copying files and folders
mv: rename and move

touch f1
mkdir d1
mv f1 d1
mv d1/f1 .  (or mv ./d1/f1 .)
mkdir bigdir
mv d1 bigdir
cd bigdir/d1
ls
mv f1 ../..
ls ../..
mkdir ../../otherdir
mv ../../f1 ../../otherdir
pwd
mv . ../..    ERROR
cd
mv bigdir smalldir   (RENAMING)
mv otherdir/f1 f2    (MOVING AND RENAMING at the same time)
mv smalldir/d1 otherdir/d2   (MOVING AND RENANMING at the same time)
cat > f5
hello
CTRL + D
cat > f6
world
CTRL + D
cat f5
cat f6
mv f6 f5
f5 is lost ! BE CAREFUL
mv --help
mv -i   or  mv -n  TO NOT OVERWRITE! FOR MORE SECURITY
*/
/* 

Course
Unit 6.2: The Linux file system
Modifying, moving and copying files and folders
cp, cp -r



    cat > f1
    hello
    CTRL + D
    cp f1 f2
    cat f1
    cat f2
    mkdir d1
    mv f1 d1
    cp d1 d2
    cp -r d1 d2
    cp -r d1 d2
    cp -r d1 d2
    cp --help
    cp -ri d1 d2
*/
/* 

 Course
 Unit 6.2: The Linux file system
 Searching files and folders
 Find locate



    locate file
    updatedb
    echo p*
    echo /usr/bin/a*
    echo /usr/bin/a??
    echo /usr/bin/???
    find
    find /
    find .
    find . -name "program.c"
    find . -name "prog*"
    find / -name "hello"
    find / -name "hello" 2>/dev/null
    find / -name "*joe*" 2>/dev/null
    find / -iname "*joe*" 2>/dev/null
    find / -ipath "*joe*" 2>/dev/null
    find / -ipath "*joe*" 2>/dev/null | less
*/
/* 

build cmd: gcc -std=c11 -Wall -fmax-errors=10 -Wextra ctemp.c -o ctemp
exec: ./ctemp

Use the math library

Code discussed in this video:

#include <stdio.h>
#include <math.h>

int main(){
    double a = 2.5;
    double asquared = pow(a,2);
    printf("%.2lf squared = %.2lf\n",a,asquared);
    return 0;
}

Commands and changes discussed in this video:

x is raised to the power of y
a is raised to the power of 2  (squared)
look at the documentation when you click on pow

find / -name "math.h" 2>/dev/null
ls /usr/include | less
ls /usr/include > includes.txt  (open with editor)
*/
/* */

#include <stdio.h>

// insert prototype for function ftoc() here
double ctof(int);
// insert prototype for function ctof() here
double ftoc(int );

int main(void) {

	int usertemp;
	char unit;
	double convertedtemp;

	scanf("%d %c", &usertemp, &unit);
	if (unit=='C'){
		// insert function call here to convert usertemp
		/* from Celsius to Fahrenheit and store the result in convertedtemp */
		convertedtemp = ctof(usertemp);
		// complete this line to print out the conversion result
		printf("%.1lf F\n", convertedtemp);
	} else if (unit=='F'){

		// insert function call here to convert usertemp
		/* from Fahrenheit to Celsius and store the result in convertedtemp */
		convertedtemp = ftoc(usertemp);
		// complete this line to print out the conversion result
		printf("%.1lf C\n", convertedtemp);
	}

	return 0;

}

/* Function definitions below are provided for you*/

/* Conversion from Celsius to Fahrenheit: */
double ctof(int x){
	return((9.0/5)*x+32);
}

/* Conversion from Fahrenheit to Celsius: */
double ftoc(int x){
	return(5.0/9*(x-32));
}
/*
gcc -std=c11 -Wall -fmax-errors=10 -Wextra program.c -o program
*/

#include <math.h>
/*Write your C code here*/
#include <stdio.h>

int main() {
	int aninteger;
	double sqrtnum;
	double e;

	scanf("%d", &aninteger);
	sqrtnum = sqrt(aninteger);
	printf("%.8lf\n", sqrtnum);
	e = exp(1);
	printf("%.10lf\n", e);
	printf("gcc -std=c11 -Wall -fmax-errors=10 -Wextra program.c -lm -o program\n");
	return 0;
}

//Course  Unit 7.1: Libraries in C  Using multiple libraries in C  Use multiple libraries in C

#include <stdio.h>
#include <curses.h>
#include <menu.h>
#include <stdlib.h>

int main(void) {
	ITEM **my_items;
	int c;
	MENU *my_menu;
	int n_choices, i;
	char *choices[] = {
	    "Menu 1",
	    "Menu 2",
	    "Menu 3",
	    "Menu 4"
	};
	char *descriptions[] = {
		"do this",
		"do that",
		"do ....",
		"do ????"
	};

	initscr();
	cbreak();
	noecho();
	keypad(stdscr, TRUE);

	n_choices = sizeof(choices) / sizeof(choices[0]);
	my_items = (ITEM **)calloc(n_choices + 1, sizeof(ITEM *));

	for (i=0; i<n_choices; i++) {
	    my_items[i] = new_item(choices[i], descriptions[i]);
	}
	my_items[n_choices] = (ITEM *)NULL;

	my_menu = new_menu((ITEM **)my_items);
	mvprintw(LINES - 2, 0, "q to quit");
	post_menu(my_menu);
	refresh();

	while ((c = getch()) != 'q') {
	    if (c==KEY_DOWN) {
	        menu_driver(my_menu, REQ_DOWN_ITEM);
	    } else if (c==KEY_UP) {
	        menu_driver(my_menu, REQ_UP_ITEM);
	    }
	}

	for (i=0; i<=n_choices; i++) {
		free_item(my_items[i]);
	}
	free_menu(my_menu);
	endwin();
	return 0;
}

/*
gcc -std=c11 -Wall -fmax-errors=10 -Wextra myNewProgram.o program.o -o myNewProgram
gcc -std=c11 -Wall -fmax-errors=10 -Wextra myNewProgram.o program.o -o myNewProgram
 */
 
 /*

 Makefile code discussed in this video:

# define the C compiler to use
CC       = gcc
# define comipler flags
CFLAGS   = -std=c11 -Wall -fmax-errors=10 -Wextra
# define library paths in addition to /usr/lib
LFLAGS   =
# define libraries to use
LIBS     =
# define the object files that this project needs
OBJFILES = program.o weatherstats.o
# define the name of the executable file
MAIN     = program

# all of the below is generic - one typically only adjusts the above

all: $(MAIN)

$(MAIN): $(OBJFILES)
	$(CC) $(CFLAGS) -o $(MAIN) $(OBJFILES)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJFILES) $(MAIN)
_______________________________________________________________________________________________________________________
 */
/*
program.c
*/
#include <stdio.h>
#include "weatherstats.h"

int main(void) {
	double temperatures[7] = {6.9, 12.3, 9.0, 15.3, 9.8, 1.8, 0.3};
	double average = averageTemp(temperatures, 7);
	double max = maxTemp(temperatures, 7);
	printf("Average 7-day temp: %.2lf\n", average);
	printf("Highest temp: %.2lf\n", max);
	printf("Lowest temperature: %.2lf\n", minTemp(temperatures,7));
	return 0;
}
Header file weatherstats.h:

double averageTemp(double *temps, int numOfTemps);
double maxTemp(double *temps, int numOfTemps);
double minTemp(double *temps, int numOfTemps);
Source file weatherstats.c

double averageTemp(double *temps, int numOfTemps) {
	double result = 0.0;
	int i;
	for (i=0; i<numOfTemps; i++) {
		result = result + temps[i];
	}
	result = result / (double) numOfTemps;
	return result;
}

double maxTemp(double *temps, int numOfTemps) {
	double max = temps[0];
	int i;
	for (i=0; i<numOfTemps; i++) {
		if (max < temps[i]) {
			max = temps[i];
		}
	}
	return max;
}
double minTemp(double *temps, int numOfTemps) {
	double min = temps[0];
	int i;
	for (i=0; i<numOfTemps; i++) {
		if (min > temps[i]) {
			min = temps[i];
		}
	}
	return min;
}


/* */

/* Course  Unit 7.1: Libraries in C  Using the math library in C  Use the math library */
/* Code discussed in this video: */

#include <stdio.h>
#include <math.h>

int main(){
    double a = 2.5;
    double asquared = pow(a,2);
    printf("%.2lf squared = %.2lf\n",a,asquared);
    return 0;
}

/* Commands and changes discussed in this video: */

x is raised to the power of y
a is raised to the power of 2  (squared)
look at the documentation when you click on pow

find / -name "math.h" 2>/dev/null
ls /usr/include | less
ls /usr/include > includes.txt  (open with editor)

/* Course  Unit 7.1: Libraries in C  Using multiple libraries in C  Use multiple libraries in C */

/* Code discussed in this video: */

#include <stdio.h>
#include <curses.h>
#include <menu.h>
#include <stdlib.h>

int main(void) {
	ITEM **my_items;
	int c;
	MENU *my_menu;
	int n_choices, i;
	char *choices[] = {
	    "Menu 1",
	    "Menu 2",
	    "Menu 3",
	    "Menu 4"
	};
	char *descriptions[] = {
		"do this",
		"do that",
		"do ....",
		"do ????"
	};
	
	initscr();
	cbreak();
	noecho();
	keypad(stdscr, TRUE);
	
	n_choices = sizeof(choices) / sizeof(choices[0]);
	my_items = (ITEM **)calloc(n_choices + 1, sizeof(ITEM *));
	
	for (i=0; i<n_choices; i++) {
	    my_items[i] = new_item(choices[i], descriptions[i]);
	}
	my_items[n_choices] = (ITEM *)NULL;
	
	my_menu = new_menu((ITEM **)my_items);
	mvprintw(LINES - 2, 0, "q to quit");
	post_menu(my_menu);
	refresh();
	
	while ((c = getch()) != 'q') {
	    if (c==KEY_DOWN) {
	        menu_driver(my_menu, REQ_DOWN_ITEM);
	    } else if (c==KEY_UP) {
	        menu_driver(my_menu, REQ_UP_ITEM);
	    }
	}
	
	for (i=0; i<=n_choices; i++) {
		free_item(my_items[i]);
	}
	free_menu(my_menu);
	endwin();
	return 0;
}

/*  */

