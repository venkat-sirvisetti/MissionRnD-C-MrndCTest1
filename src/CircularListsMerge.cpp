/*
Given two SORTED Circular Linked Lists ,
Write a function to merge those two linked lists .
The First Linked List head should point to the final merged linked list .
The Final merged linked list should also be in SORTED order and a Circular Linked List.
You need to return the Length of Final SLL.

*********
The First linked list head should now point to the Final sorted(Ascending) Linked list First Node
*********
Ex : A: 0->3->5->10->20 (and 20 now pointing back to 0,instead of Null )
B: 1->2->6->11->21->50->70 (70 Pointing back to 1).

The Final Linked List is A:0->1->2->3->5->6->10->11->20->21->50->70 .

Note : Dont use Malloc or create any new nodes ,Only pointers need to be interchanged,
You can use temp pointers although.
Note : The Final Linked List should be  also be a circular Linked List where Last node is
pointing towards the first node.
Note : Return -1 for Invalid Inputs like NULL;

Input : head1 and head2 are Addresses of Two Circular Linked Lists heads .
Output :Return Length of New SLL .Modify the head1 value, such that it now points to 
Merged Sorted Circular SLL .

Difficulty : Medium
*/
#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
int length(struct node *ptr)
{
	struct node *temp = ptr;
	int count = 0;
	while(temp->next!=ptr){
		temp = temp->next;
		count++;
	} 
	return count+1;
}
int merge_circularlists(struct node **head1, struct node **head2){
	//Returns Length of merged Sorted circular SLL and also points *head1 to final SLL .
	//if (head1 == NULL || head2 == NULL)return -1;
	struct node *ptr1 = *head1, *ptr2 = *head2, *t1 = *head1, *t2 = *head2;
	struct node *temp1 = NULL, *temp_t = NULL;
	int first = 0, second = 0;
	if (*head1 == NULL||*head2 == NULL)
		return -1;
	while (1)
	{
		if ((first != 0 && t1 == ptr1) || (second != 0 && t2 == ptr2))
			break;
		if (t1->data < t2->data)
		{
			if (temp1 == NULL)
			{
				temp1 = t1;
				temp_t = temp1;
				t1 = t1->next;
				temp_t->next = NULL;
			}
			else
			{
				temp_t->next = t1;
				t1 = t1->next;
				temp_t = temp_t->next;
				temp_t->next = NULL;
			}
			first = 1;
		}
		else if (t1->data > t2->data)
		{
			if (temp1 == NULL)
			{
				temp1 = t2;
				temp_t = temp1;
				t2 = t2->next;
				temp_t->next = NULL;
			}
			else
			{
				temp_t->next = t2;
				t2 = t2->next;
				temp_t = temp_t->next;
				temp_t->next = NULL;
			}
			second = 1;
		}
		else
		{
			if (temp1 == NULL)
			{
				temp1 = t2;
				temp_t = temp1;
				t2 = t2->next;
				temp_t->next = t1;
				t1 = t1->next;
				temp_t = temp_t->next;
				temp_t->next = NULL;
				
			}
			else
			{
				temp_t->next = t2;
				t2 = t2->next;
				temp_t = temp_t->next;
				temp_t->next = t1;
				t1 = t1->next;
				temp_t = temp_t->next;
				temp_t->next = NULL;
			}
			first = second = 1;
		}
	} 
	while (t2 != ptr2)
	{
			if (temp1 == NULL)
			{
				temp1 = t2;
				temp_t = temp1;
				t2 = t2->next;
				temp_t->next = NULL;
			}
			else
			{
				temp_t->next = t2;
				t2 = t2->next;
				temp_t = temp_t->next;
				temp_t->next = NULL;
			}

	}
	while (t1 != ptr1)
	{
		if (temp1 == NULL)
		{
			temp1 = t1;
			temp_t = temp1;
			t1 = t1->next;
			temp_t->next = NULL;
		}
		else
		{
			temp_t->next = t1;
			t1 = t1->next;
			temp_t = temp_t->next;
			temp_t->next = NULL;
		}
	}
	temp_t->next = temp1;
	*head1 = temp1;
	return length(temp1);
	
}
