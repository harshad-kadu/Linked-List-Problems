#include <stdlib.h>
#include <iostream>
#include <conio.h>
using namespace std;

struct node {
	int data;
	struct node* next;
};

void Push (struct node** headRef, int newData);
struct node* BuildOneTwoThree();
int Length (struct node* head);
int Count (struct node* head, int searchFor);
int GetNth (struct node* head, int index);
void DeleteList (struct node** headRef);
int Pop (struct node** headRef);
void InsertNth (struct node** headRef, int index, int data);
void SortedInsert (struct node** headRef, struct node* newNode);
void InsertSort (struct node ** headRef);
void Append (struct node** aRef, struct node** bRef);
void PrintList (struct node* head);
void FrontBackSplit (struct node* source, struct node** frontRef, struct node** backRef);
void RemoveDuplicates (struct node* head);
void MoveNode (struct node** destRef, struct node** sourceRef);
void AlternatingSplit (struct node* source, struct node** aRef, struct node** bRef);
struct node* ShuffleMerge(struct node* a, struct node* b);
struct node* SortedMerge (struct node* a, struct node* b);
void MergeSort (struct node** headRef);
struct node* SortedIntersect (struct node* a, struct node* b);
void Reverse (struct node** headRef);
void RecursiveReverse (struct node** headRef);

int main () {
	struct node* head = NULL;
	//int len, count, lastNode;
	
	struct node* a = NULL;
	struct node* b = BuildOneTwoThree();
	
	
	InsertNth (&a, 0, 10);
	InsertNth (&a, 1, 42);
	InsertNth (&a, 0, 5);
	InsertNth (&a, 3, 53);
	InsertNth (&a, 4, 78);
	
	/*
	b = BuildOneTwoThree();

	count = Count(head, 2);
	cout << "# of occurances is: " << count <<endl;
	
	lastNode = GetNth(head, 1);
	cout << "Value of last node is: " << lastNode <<endl;

	DeleteList(&head);
	cout << "Popped value is: " << Pop(&head) << endl;
	cout << "Length is: " << Length(head) << endl;

	InsertNth (&head, 0, 13);
	InsertNth (&head, 1, 42);
	InsertNth (&head, 1, 5);
	cout << "Popped value is: " << Pop(&head) << endl;
	
	struct node* newNode = (struct node*) malloc (sizeof (struct node));
	newNode->data = 0;
	newNode->next = NULL;
	SortedInsert (&head, newNode); 
	len = Length(head);
	cout << "Length of linked list is: " << len <<endl;
	InsertSort (&head);
	
	Append ( &a, &b);
	PrintList (a);
	
	FrontBackSplit (head, &a, &b);
	cout<< "List is: "<< endl;
	PrintList (a);

	RemoveDuplicates (head);
	cout<< "List is: "<< endl;
	PrintList (head);

	MoveNode (&a, &b);
	AlternatingSplit (head, &a, &b);
	head = ShuffleMerge (a, b);
	head = SortedMerge (a, b);
	MergeSort (&b);
	head = SortedIntersect(a, b);
	*/
	
	cout<< "B List is: "<< endl;
	PrintList (b);

	RecursiveReverse(&b);
	cout<< "Reverse B List is: "<< endl;
	PrintList (b);
	int ch = _getch();

}
void Push (struct node** headRef, int newData) {
	struct node* newNode = (struct node*) malloc (sizeof (struct node));
	newNode->data = newData;
	newNode->next = (*headRef);
	(*headRef) = newNode;
}

struct node* BuildOneTwoThree() {
	struct node* head = NULL;
	Push(&head, 78);
	Push(&head, 73);
	Push(&head, 63);
	Push(&head, 53);
	Push(&head, 13);
	Push(&head, 10);
	Push(&head, 5);
	Push(&head, 3);

	return (head);
}

void PrintList (struct node* head) {
	struct node* current = head;

	while (current != NULL) {
		cout << current->data << endl; 
		current = current->next;
	}

}

int Length (struct node* head) {
	int count = 0;
	struct node* current = head;

	while (current != NULL) {
		count++;
		current = current->next;
	}
	return(count);
}

int Count (struct node* head, int searchFor) {
	int count = 0;
	struct node* current = head;

	while (current != NULL) {
		if (current->data == searchFor)
			count++;
		current = current->next;
	}
	return(count);
}

int GetNth (struct node* head, int index) {
	struct node* current = head;
	int count = 0;

	while (current != NULL) {
		if (count == index) 
			return(current->data);
		count++;
		current = current->next;
	}
	cout << "Index out of bounds"<<endl;
	return(0);
}

void DeleteList (struct node** headRef) {
	struct node* current = (*headRef);
	struct node* nextNode;
	int count = 0;

	while (current != NULL) {
		nextNode = current->next;
		free (current);
		current = nextNode;
		cout << ++count << endl;
	}
	(*headRef) = NULL;
}

int Pop (struct node** headRef) {
	struct node* current = (*headRef);
	int retVal;

	if (current == NULL) {
		cout << "No node to pop! " << endl;
		return (0);
	}

	(*headRef) = current->next;
	retVal = current->data;
	free (current);

	return (retVal);

}

void InsertNth (struct node** headRef, int index, int data) {
	struct node* current = (*headRef);
	struct node* nextNode;
	int count = 0;

	if (index == 0) {
		Push (headRef, data);
	}else {
		struct node* newNode = (struct node*) malloc (sizeof(struct node));
		newNode->data = data;

		while (current != NULL) {
			if (count == index-1) { 
				nextNode = current->next;
				current->next = newNode;
				newNode->next = nextNode;
				break;
			}
			count++;
			current = current->next;
		}

		if (current == NULL)
			cout << "Index out of bounds" << endl;

	}

}

void SortedInsert (struct node** headRef, struct node* newNode) {
	struct node* current;

	if ((*headRef) == NULL || newNode->data <= (*headRef)->data) {
		newNode->next = (*headRef);
		(*headRef) = newNode;
	}else {
		current = (*headRef);
		while (current->next != NULL && newNode->data > current->next->data) {
			current = current->next;
		}
		newNode->next = current->next;
		current->next = newNode;
	}
		
}

void InsertSort (struct node ** headRef) {
	struct node* result = NULL;
	struct node* current = (*headRef);
	struct node* nextNode;

	while (current != NULL) {
		nextNode = current->next;
		SortedInsert (&result, current);
		current = nextNode;
	}
	(*headRef) = result;
}

void Append (struct node** aRef, struct node** bRef) {
	struct node* current = (*aRef);

	if (current == NULL) {
		(*aRef) = (*bRef);
	}else {
		while (current->next != NULL) {
			current = current->next;
		}
		current->next = (*bRef);
	}
	(*bRef) = NULL;
}

void FrontBackSplit (struct node* source, struct node** frontRef, struct node** backRef) {
	int len = Length (source);
	int cutoff = (len-1)/2;
	struct node* current = source;
	struct node* nextNode = NULL;

	*frontRef = source;
	if (len < 2) {
		backRef = &nextNode;
	}else {
		for (int count = 0; count < cutoff; count++) {
			current = current->next;
		}
		nextNode = current->next;
		*backRef = nextNode;
		current->next = NULL;
	}
}

void RemoveDuplicates (struct node* head) {
	struct node* current = head;
	struct node* nextNode;

	if (current == NULL) return;
	while (current->next != NULL) {
		nextNode = current->next;
		if (current->data == nextNode->data) {
			current->next = nextNode->next;
			free (nextNode);
		}else {
			current = current->next;
		}
	}
}

void MoveNode (struct node** destRef, struct node** sourceRef) {
	struct node* destHead = (*destRef);
	struct node* sourceHead = (*sourceRef);

	if (sourceHead == NULL) {
		cout<< "The source list is empty!" << endl;
		return;
	}else {
		(*sourceRef) = sourceHead->next;
		sourceHead->next = destHead;

		(*destRef) = sourceHead;
	}

}

void AlternatingSplit (struct node* source, struct node** aRef, struct node** bRef) {
	struct node* aHead = NULL;
	struct node* bHead = NULL;
	int count = 0;

	while (source != NULL) {
		switch (count%2) {
			case 0:
				MoveNode(&aHead, &source);
				break;
			default:
				MoveNode(&bHead, &source);
		}
		count++;
	}
	(*aRef) = aHead;
	(*bRef) = bHead;

}

struct node* ShuffleMerge(struct node* a, struct node* b) {
	struct node dummy;
	struct node* tail = &dummy;

	dummy.next = NULL;
	
	while (a != NULL || b != NULL) {
		if (a != NULL) {
			MoveNode(&(tail->next), &a);
			tail = tail->next;
		}
		if (b != NULL) {
			MoveNode(&(tail->next), &b);
			tail = tail->next;
		}
	}
	return (dummy.next);
}

struct node* SortedMerge (struct node* a, struct node* b) {
	struct node dummy;
	struct node* tail = &dummy;
	dummy.next = NULL;
	
	while (true) {
		if (a == NULL) {
			tail->next = b;
			break;
		}else if (b == NULL) {
			tail->next = a;
			break;
		}else {
			if (a->data <= b->data) 
				MoveNode(&(tail->next), &a);
			else 
				MoveNode(&(tail->next), &b);
			tail = tail->next;
		}
	}
	return (dummy.next);

}

void MergeSort (struct node** headRef) {
	struct node* a = NULL;
	struct node* b = NULL;
	struct node* head = (*headRef);

	if (head == NULL || head->next == NULL) return;

	FrontBackSplit (head, &a, &b);
	MergeSort (&a);
	MergeSort (&b);
	(*headRef) = SortedMerge (a, b);
}

struct node* SortedIntersect (struct node* a, struct node* b) {
	struct node dummy;
	struct node* tail = &dummy;
	struct node* aCurr = a;
	struct node* bCurr = b;
	dummy.next = NULL;

	while (aCurr != NULL && bCurr != NULL) {
		if (aCurr->data == bCurr->data) {
			Push(&(tail->next), aCurr->data);
			aCurr = aCurr->next;
			bCurr = bCurr->next;
			tail = tail->next;
		}
		else {
			if (aCurr->data > bCurr->data) {
				bCurr = bCurr->next;
			}else {
				aCurr = aCurr->next;
			}
		}
	}
	return (dummy.next);
}

void Reverse (struct node** headRef) {
	struct node* result = NULL;
	struct node* head = (*headRef);

	while (head != NULL) {
		MoveNode (&result, &head);
	}
	(*headRef) = result;
}

void RecursiveReverse (struct node** headRef) {
	struct node* first;
	struct node* rest;

	if (*headRef == NULL) return;

	first = (*headRef);
	rest = first->next;

	if (rest == NULL) return;
	
	RecursiveReverse (&rest);

	first->next->next = first;
	first->next = NULL;

	(*headRef) = rest;
}