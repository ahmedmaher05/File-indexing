/*
 * inord_list.cpp
 *
 *  Created on: ??‏/??‏/????
 *      Author: fox
 */
#include"inord_list.h"
inord_list::inord_list()
{
    head=NULL;
    tail=NULL;
    currentpos=NULL;
    predessor=NULL;
}

bool inord_list::insert(const listelemtype& e,int& linenum)
{
    link added_node;
    added_node=new node;
    if(added_node==NULL)
    	return false;
    added_node->elem=e;
    added_node->elemline=linenum;

    if(head==NULL || e<=(head->elem))
    {
        added_node->next=head;
        head=added_node;
    }

    else
    {
        predessor=head;
    	while(head->next!=NULL && e>predessor->next->elem)
    	{
    		predessor=predessor->next;
             if(predessor->next==NULL)
                break;
    	}

added_node->next = predessor->next;
predessor->next=added_node;
    }
    return true;

}
bool inord_list::first(listelemtype& e, int& linenum)
{
	if(head==NULL)
		return false;
	else
	{
		e=head->elem;
		currentpos=head;
		linenum=head->elemline;
	return true;
	}
}

bool inord_list::next(listelemtype& e,int& linenum)
{
	if(currentpos==NULL||currentpos->next==NULL)
	return false;
	else

	{
	    linenum=currentpos->next->elemline;
		e=currentpos->next->elem;
	    currentpos=currentpos->next;

	    return true;
	}



}

