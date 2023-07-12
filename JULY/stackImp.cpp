/* Program to create node and delete nodes in the stack  */

#include "Stack.h"

/* Constructor for class StackNode */
StackNode::StackNode()
{
    next = NULL;
    type = StackDataTypeNone;
    data = NULL;
    dataSize = 0;
}

/* Destructor for the constructor StackNode */
StackNode:: ~StackNode()
{
    if(this->data)
        free(data);
    type = StackDataTypeNone;
}       
       
/* Constructor for class Stack 
Stack::Stack()
{
    top = NULL;
    nodeCount = 0;
}

/* Destructor for the constructor Stack 
Stack:: ~Stack()
{
    if(top == NULL)
        StackStatusEmpty;
    else
    {
        
}*/

/* Function setNext to set the next node to the pointer of top */
void StackNode::setNext(StackNode* ptr)
{
    this->next = ptr;
} 

/* Function to get the pointer of nextnode */
StackNode* StackNode::getNext()
{
    return next;
}

/* Function to set the data type */
void StackNode::setType(StackDataType t)
{
    this->type = t;
    this->dataSize = sizeof(this->type);
}

/* Function to get the data type */
StackDataType StackNode::getType()
{
    return type;
}   

/* Function to get the data size */
int StackNode::getTypeSize()
{
    return dataSize;
}

/* Function to set the data to the size */
void StackNode::setData(void* d)
{
    this->data = d;
}

/* Function to get the data */
void* StackNode::getData()
{
    return data;
}

/* Display Function to display the Datatype and the data */
void StackNode::display()
{
    cout <<"Nodes NEXT: " << getNext() << endl;
    cout <<"Data Type: " << getDataTypeStr() << endl;
    cout <<"Data Type Size: " << getTypeSize() << endl;
    displayData();
    printf("\n");
    
}

void Stack::display()
{
    StackNode *t = top;
    if(!t)
    {
        cout << "Stack is Empty" << endl;
        return;
    }
    while(t != NULL)
    {
        printf("\n");
        t->display();
        printf("\n");
        t = t->getNext();
        printf("\n");
    }
}

/* Function to siaply the count of nodes in the stack */
int Stack::displayNodeCount()
{
    return nodeCount;
}

/* Function to get the data type in the string format */
const char* StackNode::getDataTypeStr()
{
    switch(this->type)
    {
        case StackDataTypeInt: 
            return "Type Integer ";
        case StackDataTypeFloat:
            return " Type Float ";
        case StackDataTypeChar :
            return " Type Character ";
        case StackDataTypeString:
            return " Type String ";
        case StackDataTypeDouble:
            return " Type Double ";
        case StackDataTypeVoid:
            return " Type Void ";
        default:
            return " Unknown Type ";
     }   
}

void StackNode::displayData()
{
    if(!(this->data))
    {
        printf("\n No Data ");
        return ;
    }
   
    switch(this->type)
    {
        case StackDataTypeInt:
            int *iptr;
            iptr = (int *) this->data;
            printf(" Integer Type : %d ", *iptr);
            break;
        
        case StackDataTypeFloat:
            float *fptr;
            fptr = (float *) this->data;
            printf(" Floating Type : %f ", *fptr);
            break;
           
        case StackDataTypeChar:
            char *cptr;
            cptr = (char *) this->data;
            printf(" Character Type : %c ", *cptr);
            break;
            
        case StackDataTypeDouble:
            double *dptr;
            dptr = (double *) this->data;
            printf(" Double Type Data : %f ", *dptr);
            break;
        
        case StackDataTypeString:
            char *sptr;
            sptr = (char *) this->data;
            while(*(sptr++) != '\0')
            {
                printf(" Character String Data : %c ", *sptr);
            }
            break;
            
        case StackDataTypeVoid:
            void *vptr;
            vptr = (void *) this->data;
            printf(" Void Data ");
            break;
            
        default:
            printf(" Unknown Data "); 
        
    }
    printf("\n");
}

/* Function to add the stack */
StackStatus Stack::addStackNode(StackNode *nodeptr)
{ 
    if(!nodeptr)
        return StackStatusError;
    if(!top)
    {
        nodeptr->setNext(NULL);
        top = nodeptr;
    }
    else
    {
        nodeptr->setNext(top);
        top = nodeptr;
    }
    nodeCount += 1;
    return StackStatusAddNodeSuccess;
}

/* Function to push float value into the stack */
StackStatus Stack::push(int data)
{
    StackNode* st = new StackNode;
    
    st->setType(StackDataTypeInt);
    int *dataPtr = (int*) malloc(sizeof(int));
    *dataPtr = data;
    st->setData((void *)dataPtr);
    addStackNode(st);
    return StackStatusSuccess;   
} 

/* Function to push float value into the stack */
StackStatus Stack::push(float data)
{
    StackNode* st = new StackNode;
    
    st->setType(StackDataTypeFloat);
    float *dataPtr = (float*) malloc(sizeof(float));
    *dataPtr = data;
    st->setData((void *)dataPtr);
    st->setNext(0);
    addStackNode(st);
    return StackStatusSuccess;   
} 

/* Function to delete the node of the stack */
StackNode* Stack::detachStackNode()
{
    StackNode* st;
    
    if(!top || !st)
        return NULL;
    st = top;
    top = top->getNext();  
    nodeCount -= 1;
    return st;
}

/* Function to pop the value from the stack */
StackStatus Stack::pop(char* dataBuffer, int &size, StackDataType &type)
{
    StackNode* stNode;
    stNode = detachStackNode();
    
    if(!stNode)
    {
        size = 0;
        type = StackDataTypeNone;
        return StackStatusEmpty;
    }
    
    if(stNode->getTypeSize() >= size)
    {
        size = 0;
        type = StackDataTypeNone;
        return StackStatusMemoryError;
    }
    memcpy(dataBuffer,(char*) stNode->getData(), stNode->getTypeSize());
    
    delete stNode;
    return StackStatusSuccess;
}

/* Main Function */
int main(int argc, char** argv)
{
    Stack myStack;
    int SIZE = 15;
    char buffer[SIZE];
    StackDataType t;
    /*
    node.push('K');
    node.push('V');*/
    
    myStack.push(30);
    myStack.push(40);  
    
    myStack.display();
    
    myStack.pop(buffer, SIZE, t);
    myStack.pop(buffer, SIZE, t);
    
    myStack.display();
    
    myStack.push(40); 
    
    myStack.display();
    
    return 0;
}    
                 
    
