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
/* General approach: creating only one new node for odds and even for the first elements, pointing to subsequent
 * existing nodes in "in" as the function progresses. This is because odds and even cannot contain the first
 * node of "in" while "in" has to be set to NULL at the end of the program, and references cannot be redirected,
 * causing the inevitable deletion of the first node.
 */

{
    if(in == NULL)
    {
        return;                                                 // duh
    }

    if(evens == NULL && odds == NULL)                           // Setting up deletion of the first node of "in."
    {
        if(in->value % 2 == 0)
        {
            evens = new Node(in->value, NULL);
            if(in->next == NULL)
            {
                delete(in);
                in = NULL;
                return;                                                 // There exists only one node in "in.
            }
            else
            {
                split(in->next, odds, evens);                // Function recurses, but in this instance, "in" is deleted after it exits.
                delete(in);
                in = NULL;
            }
        }
        else                                                            // In the case of odd number, same approach as above.
        {
            odds = new Node(in->value, NULL);
            if(in->next == NULL)
            {
                delete(in);
                in = NULL;
                return;
            }
            else
            {
                split(in->next, odds, evens);
                delete(in);
                in = NULL;
            }
        }
    }

    else if(in->value % 2 == 0)
    {
        if(evens == NULL)                                       // In the case that the first node has already been created, just not in "evens."
        {
            evens = in;
            if(in->next == NULL)                                // There exists only 2 node in "in."
            {
                if(odds == NULL)
                {
                    return;
                }
                else
                {
                    odds->next = nullptr;
                    return;
                }
            }
            else
            {
                split(in->next, odds, evens);         // Function recurses on the first evens node
            }
        }
        else                                                    // There exists node in evens, so function recurses on next "evens" node, set to current "in" node
        {
            evens->next = in;
            if(in->next == NULL)
            {
                if(odds == NULL)                                // Recallibrating the last pointers .
                {
                    return;
                }
                else
                {
                    odds->next = nullptr;
                    return;
                }
            }
            else
            {
                split(in->next, odds, evens->next);
            }
        }
    }
    else                                                          // Same as above, but in the case that val is odd.
    {
        if(odds == NULL)                                          // In the case that the first node has already been created, just not in "odds."
        {
            odds = in;
            if(in->next == NULL)
            {
                if(evens == NULL)
                {
                    return;
                }
                else
                {
                    evens->next = nullptr;
                    return;
                }
            }
            else
            {
                split(in->next,odds,evens);
            }
        }
        else                                                       // In the case that odds contain at least 1 node.
        {
            odds->next = in;
            if(in->next == NULL)
            {
                if(evens == NULL)
                {
                    return;
                }
                else
                {
                    evens->next = nullptr;
                    return;
                }
            }
            else
            {
                split(in->next, odds->next, evens);
            }
        }
    }
    return;
}

/* If you needed a helper function, write it here */

// WRITE YOUR CODE HERE