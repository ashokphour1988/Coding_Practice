#include <iostream>
#include <vector>
using namespace std;

class ListNode
{
	public:
	int val;
	ListNode* next;
};

void MoveNode(ListNode** destRef, ListNode** sourceRef)
{
	ListNode* newListNode = *sourceRef;
	//assert(newListNode != NULL);

	/* Advance the source pointer */
	*sourceRef = newListNode->next;
	
	/* Link the old dest off the new ListNode */
	newListNode->next = *destRef;

	/* Move dest to point to the new ListNode */
	*destRef = newListNode;
}

void push(ListNode** head_ref, int new_data)
{
	/* allocate ListNode */
	ListNode* new_ListNode = new ListNode();

	/* put in the val */
	new_ListNode->val = new_data;

	/* link the old list off the new ListNode */
	new_ListNode->next = (*head_ref);

	/* move the head to point to the new ListNode */
	(*head_ref) = new_ListNode;
}

void printList(ListNode *ListNode)
{
	while (ListNode!=NULL)
	{
		cout<<ListNode->val<<" ";
		ListNode = ListNode->next;
	}
}


class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
		
		ListNode dummy;
		ListNode *tail = &dummy;
		ListNode* a,*b;
		tail->next  = NULL;
		int i=0,j=1,n=0;
		n = lists.size();
		
		if(lists.empty() ){
            return NULL;
        }
        
        if(n == 1){
            return lists[0];
        }
		
		while (j<n){
			if(i==0){
				a = lists[i];
			}
			else{
				a = dummy.next;
				tail  =&dummy;
				tail->next = NULL;
			}
				
			b = lists[j];
			while(1){
			
			if (a == NULL)
			{
				/* if either list runs out, use the
				other list */
				tail->next = b;
				break;
			}
			else if (b == NULL)
			{
				tail->next = a;
				break;
			}
			
			if (a->val <= b->val)
				MoveNode(&(tail->next), &a);
			else
				MoveNode(&(tail->next), &b);
	
			tail = tail->next;
			
			}
			
			i++;
			j++;
		}
		
		return (dummy.next);
    }
};



int main() {
	// your code goes here
	ListNode *a = NULL;
	ListNode *b = NULL;
	ListNode *c = NULL;
	
	push(&a,7);
	push(&a,4);
	push(&a,1);
	
	push(&b,5);
	push(&b,2);
	
	push(&c,8);
	push(&c,6);
	push(&c,3);
	
	vector<ListNode*> vec;
	ListNode *ListNode = NULL;
	vec.push_back(a);
	vec.push_back(b);
	vec.push_back(c);
	
	Solution sol;
	
	ListNode = sol.mergeKLists(vec);
	cout<<"print after merge\n";
	printList(ListNode);
	
	return 0;
}