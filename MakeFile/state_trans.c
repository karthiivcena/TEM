#include "utility.h"

int c;

int transition(char state,int c);


/* Main function for state transition */
int state_trans_main()
{
    
    char state = 'A';
     
    while (1)
    {
        printf("\n Enter the number to go to that state \n A --> 1 \n B --> 0 \n C --> 3 \n D --> 4 \n E --> 2 \n Exit --> 5\n");
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
                break;
	    }
	    break;
        case 1:
	    if (state == 'E')
	    {
	        next_state = STATE_A;
	        break;
	    }
	    break;
	case 2:
	    if (state == 'C')
	    {
		    next_state = STATE_E;
		    break;
            }
	    break;
	case 3:
	    if (state == 'D')
	    {
		    next_state = STATE_C;
		    break;
	    }
	    break;
	case 4:
	    if (state == 'B')
	    {
		    next_state = STATE_D;
		    break;
            }
	    break;
	case 5:
	    exit(0);
	default:
	    printf("\n Invalid Input\n");
	    break;
    }
    return next_state;
}

#ifndef RELOCATABLE_OBJ
int main()
{
    state_trans_main();
}
#endif   /* Ending the Relocatable OBJECTS*/



