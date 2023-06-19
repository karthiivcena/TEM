#include <stdio.h>
#include <stdlib.h>

#define STATE_A ('A')
#define STATE_B ('B')
#define STATE_C ('C')
#define STATE_D ('D')
#define STATE_E ('E')

int c;

int transition(char state,int c);

int main()
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

int transition(char state,int c)
{
    char next_state;
    switch(c)
    {
	case 0:
            if (state == 'A')
	    {
                next_state = STATE_B;
	    }
	    break;
        case 1:
	    if (state == 'E')
	        next_state = STATE_A;
	    break;
	case 2:
	    if (state == 'C')
		    next_state = STATE_E;
	    break;
	case 3:
	    if (state == 'D')
		    next_state = STATE_C;
	    break;
	case 4:
	    if (state == 'B')
		    next_state = STATE_D;
	    break;
	default:
	    printf("\n Invalid Input\n");
	    exit(0);
    }
    return next_state;
}
