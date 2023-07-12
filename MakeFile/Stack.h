#ifndef _STACK_H_
#define _STACK_H_

#include <iostream>
#include <cstring>

using namespace std;

/* User-defined Data types */
enum StackDataType
{
    StackDataTypeNone,
    StackDataTypeVoid,
    StackDataTypeInt,
    StackDataTypeFloat,
    StackDataTypeChar,
    StackDataTypeDouble,
    StackDataTypeString,
    StackDataTypeMax
};

/* Different types of Errors */
enum StackStatus
{
    StackStatusSuccess,
    StackStatusError,
    StackStatusEmpty,
    StackStatusAllocFail,
    StackStatusAddNodeSuccess,
    StackStatusDeleteNodeSuccess,
    StackStatusPushSuccess,
    StackStatusPopSuccess,
    StackStatusMemoryError
};

class StackNode
{
private:
    StackNode* next;
    StackDataType type;
    void* data;
    int dataSize;
    
public:
    StackNode();
    ~StackNode();
    
    void setType(StackDataType type);
    StackDataType getType();
    void setData(void* data);
    void* getData();
    void setNext(StackNode* ptr);
    StackNode* getNext();
    void displayData();
    void display();
    const char* getDataTypeStr();
    int getTypeSize();
    
};
    
class Stack
{
private:
    
    StackNode *top = NULL;   
    StackStatus addStackNode(StackNode *nodeptr);
    StackNode* detachStackNode();
    
public:
    int nodeCount;
    //Stack();
    //~Stack();
    StackStatus push(float data);
    StackStatus push(int data);
    StackStatus pop(char* nodeptr,  int &size, StackDataType &type);
    void display();
    int displayNodeCount();
    
};


#endif
     
