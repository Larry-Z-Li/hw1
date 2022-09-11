#include "split.h"
#include <cstddef>
#include <iostream>
using namespace std;

void printAllVals(Node*& node)
{
    if(node == NULL)
    {
        cout << "NULL";
        return;
    }
    cout << node->value << " ";

    while(node->next != NULL)
    {
        node = node->next;
        cout << node->value << " ";
    }
    return;
}

void deallocateNodes(Node*& node)
{
    if(node->next == NULL)
    {
        delete(node);
        return;
    }
    while(node->next!= NULL)
    {
        Node* temp = node->next;
        delete(node);
        node = temp;
    }
    delete(node);
    return;
}
int main()
{
    cout << "Beginning test." << endl;
    cout << "Creating 6 nodes from 1-6, as well as beginner nodes for odds and even, both initialized NULL" << endl;
    Node* temp6 = new Node(6, NULL);
    Node* temp5 = new Node(5, temp6);
    Node* temp4 = new Node(4, temp5);
    Node* temp3 = new Node(3, temp4);
    Node* temp2 = new Node(2, temp3);
    Node* temp1 = new Node(1, temp2);           //in
    Node* odds = NULL;
    Node* evens = NULL;
    split(temp1,odds,evens);
    cout << "Calling split(), in: ";
    printAllVals(temp1);
    cout << ", odds: ";
    printAllVals(odds);
    cout << ", evens: ";
    printAllVals(evens);
    cout << "." << endl;
    cout << "Result should be in: NULL, odds: 1 3 5 , evens: 2 4 6 ." << endl;

    deallocateNodes(evens);deallocateNodes(odds);

    cout << "Creating 6 nodes of 2,2,2,3,3,3 for in and NULL for odds and evens." <<endl;
    temp6 = new Node(3, NULL);
    temp5 = new Node(3, temp6);
    temp4 = new Node(3, temp5);
    temp3 = new Node(2, temp4);
    temp2 = new Node(2, temp3);
    temp1 = new Node(2, temp2);           // in1
    odds = NULL;
    evens = NULL;
    cout << "Calling split(), in: ";
    split(temp1, odds, evens);
    printAllVals(temp1);
    cout << ", odds: ";
    printAllVals(odds);
    cout << ", evens: ";
    printAllVals(evens);
    cout << "." << endl;
    cout << "Result should be in: NULL, odds: 3 3 3 , evens: 2 2 2 ." << endl;

    delete(evens);delete(odds);

    cout << "Creating 2 nodes of 2, 2 for in and NULL for odds and evens." <<endl;
    temp2 = new Node(2, NULL);
    temp1 = new Node(2, temp2);           // in2
    odds = NULL;
    evens = NULL;
    cout << "Calling split(), in: ";
    split(temp2, odds, evens);
    printAllVals(temp1);
    cout << ", odds: ";
    printAllVals(odds);
    cout << ", evens: ";
    printAllVals(evens);
    cout << "." << endl;
    cout << "Result should be in: NULL, odds: NULL, evens: 2 2 ." << endl;

    deallocateNodes(evens);

    cout << "Creating 2 nodes of 3, 3 for in and NULL for odds and evens." <<endl;
    temp2 = new Node(3, NULL);
    temp1 = new Node(3, temp2);           //in3
    odds = NULL;
    evens = NULL;
    cout << "Calling split(), in: ";
    split(temp1, odds, evens);
    printAllVals(temp1);
    cout << ", odds: ";
    printAllVals(odds);
    cout << ", evens: ";
    printAllVals(evens);
    cout << "." << endl;
    cout << "Result should be in: NULL, odds: 3 3 , evens: NULL." << endl;

    deallocateNodes(odds);

    cout << "Creating 1 node of 2 for in and NULL for odds and evens." <<endl;
    temp1 = new Node(2, NULL);          //in4
    odds = NULL;
    evens = NULL;
    cout << "Calling split(), in: ";
    split(temp1, odds, evens);
    printAllVals(temp1);
    cout << ", odds: ";
    printAllVals(odds);
    cout << ", evens: ";
    printAllVals(evens);
    cout << "." << endl;
    cout << "Result should be in: NULL, odds: NULL, evens: 2 ." << endl;

    deallocateNodes(evens);

    cout << "Creating 1 node of 3 for in and NULL for odds and evens." << endl;
    temp1 = new Node(3, NULL);          //in4
    odds = NULL;
    evens = NULL;
    cout << "Calling split(), in: ";
    split(temp1, odds, evens);
    printAllVals(temp1);
    cout << ", odds: ";
    printAllVals(odds);
    cout << ", evens: ";
    printAllVals(evens);
    cout << "." << endl;
    cout << "Result should be in: NULL, odds: 3 , evens: NULL." << endl;

    deallocateNodes(odds);
    cout << "Testing complete!" << endl;

    return 0;
}
