#include "Byte.h"


/* setBit Function */
int Byte::setBit(unsigned int pos, unsigned int value)
{   
    switch(pos)
    {
        case 0: 
            this->bit_0 = value ? 1:0;
            return bit_0;
            break;
            
        case 1:
            this->bit_1 = value ? 1:0;
            return bit_1;
            break;
            
        case 2:
            this->bit_2 = value ? 1:0; 
            return bit_2;   
            break;
            
        case 3:
            this->bit_3 = value ? 1:0;
            return bit_3;
            break;
            
        case 4:
            this->bit_4 = value ? 1:0;
            return bit_4;
            break;
            
        case 5:
            this->bit_5 = value ? 1:0;
            return bit_5;
            break;
            
        case 6:
            this->bit_6 = value ? 1:0;
            return bit_6;
            break;
            
        case 7:
            this->bit_7 = value ? 1:0;
            return bit_7;
            break;
            
        default:
            printf("\n Error : Value of of Bounds \n");
            return STATUS_FAILURE;
             
    }  
    
}
    
char* Byte::display()
{
    /*if(buffer)
    {
        sprintf(buffer, " %d%d%d%d%d%d%d ", this->bit_7, this->bit_6, this->bit_5, 
                                           this->bit_4, this->bit_3, this->bit_2, 
                                           this->bit_1, this->bit_0 );
    } */
    
    printf(" %d%d%d%d%d%d%d%d ",this->bit_7, this->bit_6, this->bit_5,  
                   this->bit_4, this->bit_3, this->bit_2, 
                   this->bit_1, this->bit_0);
}
    
/* Main Function */
int main()
{
    /*
    unsigned int number;
    printf("\n Enter the 8-bit binary number : \n");
    scanf("%d", &number); */
    Byte b;
    
    b.setBit(2, 10);
    
    b.display();
    return 0;   
}
    
    
