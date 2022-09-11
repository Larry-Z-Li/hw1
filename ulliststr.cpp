#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

using namespace std;


ULListStr::ULListStr()
{
    head_ = NULL;
    tail_ = NULL;
    size_ = 0;
}

ULListStr::~ULListStr()
{
    clear();
}

bool ULListStr::empty() const
{
    return size_ == 0;
}

size_t ULListStr::size() const
{
    return size_;
}

// WRITE YOUR CODE HERE

void ULListStr::push_back(const std::string& val)
{
    if(head_ == NULL)                                   //If val is first element inserted
    {
        Item* newItem = new Item();
        head_ = newItem;
        tail_ = newItem;
        newItem->val[0] = val;
        newItem->last = 1;
    }
    else if (tail_->last == 10)                         //If there is an attempt to inserted val into an Item with full array.
    {                                                   //Create new element after tail element.
        Item* newItem = new Item();
        newItem->prev = tail_;
        tail_->next = newItem;
        tail_ = newItem;
        newItem->val[0] = val;
        newItem->last++;
    }
    else                                                //Else case, existing Item array is not full.
    {
        tail_->val[tail_->last] = val;
        tail_->last++;
    }
    size_++;
    return;
}

void ULListStr::pop_back()
{
    if(size_ == 1)                                      //If only one val left in List, removing the last Item.
    {
        Item *temp = NULL;
        delete head_;
        head_ = temp;
        tail_ = temp;
    }
    else if(tail_->last == 1)                           //If element popped is last in Item, delete Item and move tail.
    {
        Item *temp = tail_->prev;
        delete(tail_);
        tail_ = temp;
    }
    else                                                //Else case, existing val in tail array.
    {
        tail_->val[tail_->last-1] = "";
        tail_->last--;
    }

    size_--;

    return;
}

void ULListStr::push_front(const std::string& val)
{
    if(head_ == NULL)                                   //If val is first element inserted
    {
        Item* newItem = new Item();
        head_ = newItem;
        tail_ = newItem;
        newItem->first = 9;
        newItem->last = 10;
        newItem->val[newItem->first] = val;
    }
    else if (head_->first == 0)                         //If there is an attempt to inserted val into an Item with full array.
    {                                                   //Create new element before head_ element.
        Item* newItem = new Item();
        newItem->next = head_;
        head_->prev = newItem;
        head_ = newItem;
        newItem->val[9] = val;
        newItem->first = 9;
        newItem->last = 10;
    }
    else                                                //Else case, existing Item array is not full.
    {
        head_->first--;
        head_->val[head_->first] = val;
    }
    size_++;
    return;
}

void ULListStr::pop_front()
{
    if(size_ == 1)                                      //If only one val left in List, removing the last Item
    {
        Item *temp = NULL;
        delete head_;
        head_ = temp;
        tail_ = temp;
    }
    else if(head_->first == 9)                          //If element popped is last in Item, delete Item and move head.
    {
        Item *temp = head_->next;
        delete head_;
        head_ = temp;
    }
    else                                                //Else case, existing val in head array.
    {
        head_->val[head_->first] = "";
        head_->first++;
    }

    size_--;

    return;
}

std::string const & ULListStr::back() const             //Return reference of back element
{
    return tail_->val[tail_->last-1];
}

std::string const & ULListStr::front() const            //Return reference of front element
{
    return head_->val[head_->first];
}

string* ULListStr::getValAtLoc(size_t loc) const        //Used by get() and set(), returns pointer to val at loc
{
    if(size_ == 0)
    {
        return NULL;
    }
    Item* temp = head_;
    if (loc < 10 && temp->first + loc < 10)             //Counting from index 0, supposedly from array in head.
    {
        return &temp->val[temp->first + loc];           //If loc is in head array, return the loc-th item initialized.
    }
    else if (temp->next == NULL)                        //If loc is out of bounds.
    {
        return NULL;
    }
    loc = loc-(temp->last - temp->first);               //loc index past head array.
    temp = temp->next;                                  //beginning at index 0 of array in next Item.

    int itemLoc = loc/10;                               //Calculating how many Items needs to be jumped.
    int valLoc = loc%10;                                //Calculating index at target Item's array.
    for(int i = 0; i < itemLoc; i++)                    //Jumping.
    {
        if(temp->next == NULL)
            return NULL;
        temp=temp->next;
    }
    if (temp->val[valLoc] == "")                        //Finally arrived at original loc!
        return NULL;
    return &temp->val[valLoc];

}



void ULListStr::set(size_t loc, const std::string& val) //Setting using loc and pointer from getValAtLoc();
{
    std::string* ptr = getValAtLoc(loc);
    if(ptr == NULL){
        throw std::invalid_argument("Bad location");
    }
    *ptr = val;
}

std::string& ULListStr::get(size_t loc)                 //Getting using loc and pointer from getValAtLoc();
{
    std::string* ptr = getValAtLoc(loc);
    if(ptr == NULL){
        throw std::invalid_argument("Bad location");
    }
    return *ptr;
}

std::string const & ULListStr::get(size_t loc) const    //Overloading function for reference instead of value;
{
    std::string* ptr = getValAtLoc(loc);
    if(ptr == NULL){
        throw std::invalid_argument("Bad location");
    }
    return *ptr;
}

void ULListStr::clear()                                 //Refreshes the List
{
    while(head_ != NULL){
        Item *temp = head_->next;
        delete head_;
        head_ = temp;
    }
    tail_ = NULL;
    size_ = 0;
}
