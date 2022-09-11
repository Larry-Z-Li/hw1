/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"
#include <cstddef>

/* Add a prototype for a helper function here if you need */

void split(Node*& in, Node*& odds, Node*& evens)
{
    if(in == NULL)
    {
        return;
    }
    Node* temp = new Node(in->value, NULL);                  //Makes new Node, deallocates in later

    if(in->value % 2 == 0)                                      //Case if EVEN
    {
        if(evens == NULL)                                       //Case that value is the first even
        {
            evens = temp;
            if(in->next != NULL)                                //Triggers when there are more nodes
                split(in->next, odds, evens);
        }
        else
        {
            evens->next = temp;
            if(in->next != NULL)                                //Triggers when there are more nodes
                split(in->next,odds,evens->next);
        }
    }
    else                                                        //Case if ODD
    {
        if(odds == NULL)                                        //Case that value is the first odd
        {
            odds = temp;
            if(in->next != NULL)                                //Triggers when there are more nodes
                split(in->next, odds, evens);
        }
        else
        {
            odds->next = temp;
            if(in->next != NULL)                                //Triggers when there are more nodes
                split(in->next,odds->next,evens);
        }
    }

    delete(in);                                                 //Deallocate in nodes
    in=NULL;
    return;
}

/* If you needed a helper function, write it here */

// WRITE YOUR CODE HERE