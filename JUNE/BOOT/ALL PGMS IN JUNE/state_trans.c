extern "C"
{
#include <stdio.h>
#include <stdlib.h>
#include "utility.h"

int transition(char state,int c);

int c;

/* Main function for state transition */
int state_trans_main()
{
    char state = 'A';
    printf("\n Enter the number to go to that state \n A --> 1 \n B --> 0 \n C --> 3 \n D --> 4 \n E --> 2 \n");
     
    while (1)
    {
    	scanf("%d", &c);
        state = transition(state, c);
        printf("\n Final state : %c \n",state);   
    }
     
}

/* Transition Function */
int transition(char state,int c)
{
    char next_state;
    switch(c)
    {
	case 0:
            if (state == 'A')
                next_state = STATE_B;
            else
                printf("\n Previous state is not A \n");
	    break;
        case 1:
	    if (state == 'E')
	        next_state = STATE_A;
	    else
	        printf("\n Previous state is not E \n");;
	    break;
	case 2:
	    if (state == 'C')
		next_state = STATE_E;
	    else
	        printf("\n Previous state is not C \n");;
	    break;
	case 3:
	    if (state == 'D')
		next_state = STATE_C;
	    else
	        printf("\n Previous state is not D \n");;
	    break;
	case 4:
	    if (state == 'B')
		next_state = STATE_D;
	    else
	        printf("\n Previous state is not B \n");;
	    break;
	default:
	    printf("\n Invalid Input\n");
	    exit(0);
    }
    return next_state;
}

#ifndef RELOCATABLE_OBJ
int main()
{
    state_trans_main();
}
#endif  /* Ended DRELOCATE */
}

