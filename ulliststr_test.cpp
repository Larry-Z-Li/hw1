/* Write your test code for the ULListStr in this file */

#include <iostream>
#include "ulliststr.h"
using namespace std;


int main(int argc, char* argv[])
{

    ULListStr testList;    //Test list construction

    //Begin test
    cout << "Item array max: " << ARRSIZE << ", begin test, inserting 11 ordered numbers through push_back()" << endl;
    for(int i = 12; i < 23; i++)             //Insert 11 elements through push_back()
    {
        testList.push_back(to_string(i));
    }
    cout << "Testing size(): " << testList.size() << ", result should be 11." << endl;

    cout << "Testing front(): " << testList.front() << ", result should be 12." << endl;

    cout << "Testing back(): " << testList.back() << ", result should be 22." << endl;

    cout << "Inserting 11 ordered numbers through push_front()" << endl;
    for(int i = 11; i > 0; i--)
    {
        testList.push_front(to_string(i));
    }
    cout << "Testing size(): " << testList.size() << ", result should be 22." << endl;

    cout << "Testing front(): " << testList.front() << ", result should be 1." << endl;

    cout << "Testing back(): " << testList.back() << ", result should still be 22." << endl;

    cout << "Test printing all odd numbers with get():";

    int temp;
    for(int i = 0; i < testList.size(); i++)
    {
        temp = stoi(testList.get(i));
        if (temp % 2 == 1)
        {
            cout << " " << temp;
        }
    }

    cout << ", result should range from 1-21 with 11 elements." << endl;

    cout << "Testing set() by setting the 1st, 11th, and 22th element to strings of breeds of dogs, then access with get(): ";

    testList.set(0, "Labradoodle");
    testList.set(10, "Terrier");
    testList.set(20, "Pomeranian");

    cout << testList.get(0) << ", " << testList.get(10) << ", " << testList.get(20);
    cout << ", results should be Labradoodle, Terrier, and Pomeranian, respectively." << endl;

    cout << "Testing pop_back() by removing 11 elements, then calling size(): ";
    for(int i = 0; i< 11; i++)
    {
        testList.pop_back();
    }

    cout << testList.size() << ", result should be 11." << endl;

    cout << "Testing pop_front() by removing 11 elements, then calling size(): ";
    for(int i = 0; i< 11; i++)
    {
        testList.pop_front();
    }

    cout << testList.size() << ", result should be 0." << endl;

    cout << "Testing creating the first Item using push_front(), then calling size(), and get(0): ";
    testList.push_front("Poodles");
    cout << testList.size() << ", " << testList.get(0) << ", result should be 1, Poodles." << endl;

    cout << "Testing removing the first Item using pop_back(), then calling size(): ",
    testList.pop_back();
    cout << testList.size() << ", should now be 0." << endl;

    cout << "Test complete!" << endl;

    return 0;
}