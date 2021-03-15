#include <stdio.h>
int main(void){
    int i,n,height, weight, enginePower, resistance;
    scanf("%d",&n);
    for (i=0;i<n;i++){
        scanf("%d %d %d %d\n",height,weight,enginePower,resistance);
    }
}

//(enginePower + resistance) * (weight - height)
// numberOfRobots
// height, weight, enginePower, resistance



/*
Course
Unit 5.3: Linked lists
Sorting a linked list using Insertion Sort
Create a sorted copy of a linked list
*/
#include <stdio.h>
#include <stdlib.h>

struct digit {
    int num;
    struct digit *next;
};

struct digit * createDigit(int);
struct digit * append(struct digit * end, struct digit * newDigptr);
void printNumber(struct digit *);
void freeNumber(struct digit *);
struct digit * readNumber(void);
struct digit * searchNumber(struct digit * start, int number);
struct digit * insertAtFront(struct digit * start, struct digit * newptr);
struct digit * reverseNumber(struct digit * start);
struct digit * sortedCopy(struct digit * start);
struct digit * insertIntoSorted(struct digit *start, struct digit *newDig);

int main(void) {
    //! showMemory(start=65520)
    struct digit *start, *backwards, *sorted;
    printf("Please enter a number: ");
    start = readNumber();
    printf("You entered: ");
    printNumber(start);
    printf("Backwards: ");
    backwards = reverseNumber(start);
    printNumber(backwards);
    printf("Sorted by digit:");
    sorted = sortedCopy(start);
    printNumber(sorted);
    freeNumber(start);
    freeNumber(backwards);
    freeNumber(sorted);
    return 0;
}

struct digit *createDigit(int dig) {
    struct digit *ptr;
    ptr = (struct digit *) malloc(sizeof(struct digit));
    ptr->num = dig;
    ptr->next = NULL;
    return ptr;
}

struct digit * append(struct digit * end, struct digit * newDigptr) {
    end->next = newDigptr;
    return(end->next);
}

void printNumber(struct digit *start) {
    struct digit * ptr = start;
    while (ptr!=NULL) {
        printf("%d", ptr->num);
        ptr = ptr->next;
    }
    printf("\n");
}

void freeNumber(struct digit *start) {
    struct digit * ptr = start;
    struct digit * tmp;
    while (ptr!=NULL) {
        tmp = ptr->next;
        free(ptr);
        ptr = tmp;
    }
}

struct digit * readNumber(void) {
    char c;
    int d;
    struct digit *start, *end, *newptr;
    start = NULL;
    scanf("%c", &c);
    while (c != '\n') {
        d = c-48;
        newptr = createDigit(d);
        if (start == NULL) {
            start = newptr;
            end = start;
        } else {
            end = append(end, newptr);
        }
        scanf("%c", &c);
    }
    return(start);
}

struct digit * searchNumber(struct digit * start, int number) {
    struct digit * ptr = start;
    while ((ptr!=NULL) && (ptr->num!=number)) {
        ptr = ptr->next;
    }
    return(ptr);
}

struct digit * insertAtFront(struct digit * start, struct digit * newptr) {
    newptr->next = start;
    return(newptr);
}

struct digit * reverseNumber(struct digit * start) {
    struct digit *ptr = start;
    struct digit *bstart = start;
    struct digit *newdigit;

    if (start!=NULL) {
        bstart = createDigit(start->num);
        ptr = ptr->next;
    }
    while (ptr != NULL) {
        newdigit = createDigit(ptr->num);
        bstart = insertAtFront(bstart, newdigit);
        ptr = ptr->next;
    }
    return(bstart);
}

struct digit * insertIntoSorted(struct digit *start, struct digit *newDig) {
    struct digit *ptr = start;
    struct digit *prev = NULL;
    while ((ptr!=NULL) && (ptr->num < newDig->num)) {
        prev = ptr;
        ptr = ptr->next;
    }
    if (prev == NULL) {
        start = insertAtFront(start, newDig);
    } else {
        prev->next = newDig;
        newDig->next = ptr;
    }
    return(start);
}

struct digit * sortedCopy(struct digit * start) {
    //! heap1=showMemory(start=348, cursors=[start, ptr, sortedStart, newDigit])
    //! heap2=showMemory(start=519, cursors=[start, newDigit, ptr, prev])
    struct digit *ptr = start;
    struct digit *sortedStart = NULL;
    struct digit *newDigit;

    if (start!=NULL) {
        sortedStart = createDigit(start->num);
        ptr = ptr->next;
    }
    while (ptr!=NULL) {
        newDigit = createDigit(ptr->num);
        sortedStart = insertIntoSorted(sortedStart, newDigit);
        ptr = ptr->next;
    }
    return(sortedStart);
}



/*
Activity: count redundancies in number
*/

#include <stdio.h>
#include <stdlib.h>

struct digit {
    int num;
    struct digit *next;
};


// Add a prototype for countRedun() here
struct digit * createDigit(int);
struct digit * append(struct digit * end, struct digit * newDigptr);
void printNumber(struct digit *);
void freeNumber(struct digit *);
struct digit *readNumber(void);
int divisibleByThree(struct digit * start);
int changeThrees(struct digit * start);


// Do not modify this main() function
int main(void) {
    struct digit *start;
    start = readNumber();

    printf("The number ");
    printNumber(start);
    printf("contains %d redundancies.\n", countRedun(start));

    freeNumber(start);

    return 0;
}

struct digit *createDigit(int dig) {
    struct digit *ptr;
    ptr = (struct digit *) malloc(sizeof(struct digit));
    ptr->num = dig;
    ptr->next = NULL;
    return ptr;
}

struct digit * append(struct digit * end, struct digit * newDigptr) {
    end->next = newDigptr;
    return(end->next);
}

void printNumber(struct digit *start) {
    struct digit * ptr = start;
    while (ptr!=NULL) {
        printf("%d", ptr->num);
        ptr = ptr->next;
    }
    printf("\n");
}

void freeNumber(struct digit *start) {
    struct digit * ptr = start;
    struct digit * tmp;
    while (ptr!=NULL) {
        tmp = ptr->next;
        free(ptr);
        ptr = tmp;
    }
}

struct digit *readNumber(void) {
    char c;
    int d;
    struct digit *start, *end, *newptr;
    start = NULL;
    scanf("%c", &c);
    while (c != '\n') {
        d = c-48;
        newptr = createDigit(d);
        if (start == NULL) {
            start = newptr;
            end = start;
        } else {
            end = append(end, newptr);
        }
        scanf("%c", &c);
    }
    return(start);
}

int divisibleByThree(struct digit * start) {
    struct digit * ptr = start;
    int qsum = 0;
    while (ptr!=NULL) {
        qsum += ptr->num;
        ptr = ptr->next;
    }
    if (qsum%3==0) return 1;
    else return 0;
}

int changeThrees(struct digit * start) {
    struct digit * ptr = start;
    int sum = 0;
    while (ptr!=NULL) {
        if (ptr->num == 3) {
            ptr->num = 9;
            sum++;
        }
        ptr = ptr->next;
    }
    return(sum);
}

// Write your countRedun() function here



/*
In this task you will work with the linked list of digits we have created in the lessons up to this point. As before you are provided with some code that you should not modify:

    A structure definition for the storage of each digit's information.
    A main() function to test your code.
    The functions createDigit(), append(), printNumber(), freeNumber(), readNumber() and divisibleByThree() (although you may not need to use all of these).

Your task is to write a new function changeThrees() which takes as input a pointer that holds the address of the start of a linked list of digits. Your function should change all of those digits in this linked list that equal 3 to the digit 9, and count how many replacements were made. The function should return this number of replacements.









Examples
Input:

5243

Output:

The number 5243
contains 0 redundancies.

Input:

5256202

Output:

The number 5256202
contains 3 redundancies.

Input:

7777

Output:

The number 7777
contains 3 redundancies.

**************

In this task you will again work with the linked list of digits we created during the lessons up to this point.

You are provided with (but are not required to use) the functions and prototypes we have written so far. You are also provided with a main() function to test your code. Please do not modify this main() function.

Your task is to write a new function countRedun() which takes as input a pointer that holds the address of the start of a linked list of digits. Your function should count how many redundancies can be observed in the number stored in this list and return this count of redundancies. A redundancy is a digit which has previously already occurred in the number. For example, in the number 39534, the second '3' is a redundancy.

**************

Hint 1 :

One way to solve this problem is to create a sorted copy of the linked list and count redundancies in this copy - it's easier in a sorted list. Just remember to free your sorted copy after its use.

Hint 2 :

In a sorted linked list of digits, a redundancy occurrs for each digit that equals the previous digit.




*/












/*
In this task you will again work with the linked list of digits we created during the lessons up to this point.

You are provided with (but are not required to use) the functions and prototypes we have written so far. You are also provided with a main() function to test your code. Please do not modify this main() function.

Your task is to write a new function countRedun() which takes as input a pointer that holds the address of the start of a linked list of digits. Your function should count how many redundancies can be observed in the number stored in this list and return this count of redundancies. A redundancy is a digit which has previously already occurred in the number. For example, in the number 39534, the second '3' is a redundancy.

*/

#include <stdio.h>
#include <stdlib.h>

struct digit {
    int num;
    struct digit *next;
};


// Add a prototype for countRedun() here
struct digit * createDigit(int);
struct digit * append(struct digit * end, struct digit * newDigptr);
void printNumber(struct digit *);
void freeNumber(struct digit *);
struct digit *readNumber(void);
int divisibleByThree(struct digit * start);
int changeThrees(struct digit * start);


// Do not modify this main() function
int main(void) {
    struct digit *start;
    start = readNumber();

    printf("The number ");
    printNumber(start);
    printf("contains %d redundancies.\n", countRedun(start));

    freeNumber(start);

    return 0;
}

struct digit *createDigit(int dig) {
    struct digit *ptr;
    ptr = (struct digit *) malloc(sizeof(struct digit));
    ptr->num = dig;
    ptr->next = NULL;
    return ptr;
}

struct digit * append(struct digit * end, struct digit * newDigptr) {
    end->next = newDigptr;
    return(end->next);
}

void printNumber(struct digit *start) {
    struct digit * ptr = start;
    while (ptr!=NULL) {
        printf("%d", ptr->num);
        ptr = ptr->next;
    }
    printf("\n");
}

void freeNumber(struct digit *start) {
    struct digit * ptr = start;
    struct digit * tmp;
    while (ptr!=NULL) {
        tmp = ptr->next;
        free(ptr);
        ptr = tmp;
    }
}

struct digit *readNumber(void) {
    char c;
    int d;
    struct digit *start, *end, *newptr;
    start = NULL;
    scanf("%c", &c);
    while (c != '\n') {
        d = c-48;
        newptr = createDigit(d);
        if (start == NULL) {
            start = newptr;
            end = start;
        } else {
            end = append(end, newptr);
        }
        scanf("%c", &c);
    }
    return(start);
}

int divisibleByThree(struct digit * start) {
    struct digit * ptr = start;
    int qsum = 0;
    while (ptr!=NULL) {
        qsum += ptr->num;
        ptr = ptr->next;
    }
    if (qsum%3==0) return 1;
    else return 0;
}

int changeThrees(struct digit * start) {
    struct digit * ptr = start;
    int sum = 0;
    while (ptr!=NULL) {
        if (ptr->num == 3) {
            ptr->num = 9;
            sum++;
        }
        ptr = ptr->next;
    }
    return(sum);
}

// Write your countRedun() function here


/*
Examples
Input:

5243

Output:

The number 5243
contains 0 redundancies.

Input:

5256202

Output:

The number 5256202
contains 3 redundancies.

Input:

7777

Output:

The number 7777
contains 3 redundancies.

This task offers 2 hints :

Hint 1 :

One way to solve this problem is to create a sorted copy of the linked list and count redundancies in this copy - it's easier in a sorted list. Just remember to free your sorted copy after its use.

Hint 2 :

In a sorted linked list of digits, a redundancy occurrs for each digit that equals the previous digit.

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

//



//Course Unit 7.1: Libraries in C Declaring and defining functions Activity: function declaration versus definition

#include <stdio.h>
// insert prototype for function ftoc() here
double ftoc(int x);
// insert prototype for function ctof() here
double ctof(int x);

int main(void) {
    int usertemp;
    char unit;
    double convertedtemp;

    scanf("%d %c", &usertemp, &unit);
    if (unit=='C'){
        // insert function call here to convert usertemp
        // from Celsius to Fahrenheit and store the result in convertedtemp
        convertedtemp=ctof(usertemp);
        // complete this line to print out the conversion result
        printf("%.1lf F", convertedtemp);
    } else if (unit=='F'){
        // insert function call here to convert usertemp
        // from Fahrenheit to Celsius and store the result in convertedtemp
        convertedtemp=ftoc(usertemp);
        // complete this line to print out the conversion result
        printf("%.1lf C", convertedtemp);
    }
    return 0;
}

/* Function definitions below */

/* Conversion from Celsius to Fahrenheit: */
double ctof(int x){
    return((9.0/5)*x+32);
}

/* Conversion from Fahrenheit to Celsius: */
double ftoc(int x){
    return(5.0/9*(x-32));
}



// Course Unit 7.1: Libraries in C Using the math library in C Use the math library

//Code discussed in this video:

    #include <stdio.h>
    #include <math.h>

    int main(){
        double a = 2.5;
        double asquared = pow(a,2);
        printf("%.2lf squared = %.2lf\n",a,asquared);
        return 0;
    }

//Commands and changes discussed in this video:
/*
    x is raised to the power of y
    a is raised to the power of 2  (squared)
    look at the documentation when you click on pow

    find / -name "math.h" 2>/dev/null
    ls /usr/include | less
    ls /usr/include > includes.txt  (open with editor)

*/

/*
Course Unit 7.1: Libraries in C Using multiple libraries in C Use multiple libraries in C
*/

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


/*Write your C code here*/
#include <stdio.h>


int main(void){
	printf("gcc -std=c11 -Wall -fmax-errors=10 -Wextra vizplus.c -ljpeg -o program");

}

//<!-- -->
