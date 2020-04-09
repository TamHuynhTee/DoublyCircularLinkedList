// Done
#include<stdio.h>
#include<conio.h>

int nodeCount = 0;

struct node
{
	int data;
	struct node* next;
	struct node* prev;
};

struct List
{
	node* head;
	node* tail;
};

void Initialize(List &l)
{
	l.head = NULL;
	l.tail = NULL;

}

bool checkEmpty(List l)
{
	if (l.head == NULL)
		return true;
	return false;
}

void Display(List l)
{
	node* p = l.head;
	int i = nodeCount;
	while (i > 0)
	{
		printf("%d ", p->data);
		p = p->next;
		i--;
	}
	printf("\nNumber of nodes: %d", nodeCount);
}

void DisplayReverse(List l)
{
	node* p = l.tail;
	int i = nodeCount;
	while (i > 0)
	{
		printf("%d ", p->data);
		p = p->prev;
		i--;
	}
	printf("\nNumber of nodes: %d", nodeCount);
}

void getValue(List l, int pos)
{
	if (pos > nodeCount + 1 || pos < 1)
	{
		printf("\nInvalid node index.");
		return;
	}
	else
	{
		node* p = l.head;
		int run = 1;
		while (run < pos)
		{
			p = p->next;
			run++;
		}
		printf("\nValue get from node %d is %d.", pos, p->data);
	}
}

node* newNode(int x)
{
	node* p = new node;
	p->data = x;
	p->prev = NULL;
	p->next = NULL;
	return p;
}

void AddHead(List &l, int x)
{
	node* new_ele = newNode(x);
	if (new_ele == NULL)
	{
		printf("\nCreate node failed.");
		return;
	}
	else
	{
		if (l.head == NULL)
		{
			l.head = l.tail = new_ele;
			l.head->prev = new_ele;
			l.tail->next = new_ele;
			nodeCount++;
		}
		else
		{
			l.head->prev = new_ele;
			l.tail->next = new_ele;
			new_ele->next = l.head;
			new_ele->prev = l.tail;
			l.head = new_ele;
			nodeCount++;
		}
	}
}

void AddTail(List &l, int x)
{
	node* new_ele = newNode(x);
	if (new_ele == NULL)
	{
		printf("\nCreate node failed.");
		return;
	}
	else
	{
		if (l.head == NULL)
		{
			l.head = l.tail = new_ele;
			l.head->prev = new_ele;
			l.tail->next = new_ele;
			nodeCount++;
		}
		else
		{
			l.head->prev = new_ele;
			l.tail->next = new_ele;
			new_ele->next = l.head;
			new_ele->prev = l.tail;
			l.tail = new_ele;
			nodeCount++;
		}
	}
}

void AddNode(List &l, int pos, int x)
{
	if (pos > nodeCount + 1 || pos < 1)
	{
		printf("\nInvalid node index.");
		return;
	}
	node* new_ele = newNode(x);
	if (new_ele == NULL)
	{
		printf("\nCreate node failed.");
		return;
	}
	else
	{
		if (l.head == NULL)
		{
			l.head = l.tail = new_ele;
			l.head->prev = new_ele;
			l.tail->next = new_ele;
			nodeCount++;
		}
		else
			if (pos == 1)
			{
				AddHead(l, x);
			}
			else
				if (pos == nodeCount + 1)
				{
					AddTail(l, x);
				}
				else
				{
					node* p = l.head;
					int run = 1;
					while (run < pos - 1)
					{
						p = p->next;
						run++;
					}
					new_ele->prev = p;
					new_ele->next = p->next;
					p->next->prev = new_ele;
					p->next = new_ele;
					nodeCount++;
				}
	}
}

void DeleteHead(List &l)
{
	if (l.head == NULL)
		return;
	else
		if (nodeCount == 1)
		{
			l.head = NULL;
			l.tail = NULL;
			nodeCount = 0;
		}
		else
		{
			node* p = l.head;
			l.head = l.head->next;
			l.head->prev = l.tail;
			l.tail->next = l.head;
			delete(p);
			nodeCount--;
		}
}

void DeleteTail(List &l)
{
	if (l.head == NULL)
		return;
	else
		if (nodeCount == 1)
		{
			l.head = NULL;
			l.tail = NULL;
			nodeCount = 0;
		}
		else
		{
			node* p = l.tail;
			l.tail = l.tail->prev;
			l.head->prev = l.tail;
			l.tail->next = l.head;
			delete(p);
			nodeCount--;
		}
}

void DeleteNode(List &l, int pos)
{
	if (pos > nodeCount + 1 || pos < 1)
	{
		printf("\nInvalid node index.");
		return;
	}
	else
	{
		if (l.head == NULL)
		{
			return;
		}
		else
			if (pos == 1)
			{
				DeleteHead(l);
			}
			else
				if (pos == nodeCount)
				{
					DeleteTail(l);
				}
				else
				{
					node* p = l.head;
					int run = 1;
					while (run < pos)
					{
						p = p->next;
						run++;
					}
					p->next->prev = p->prev;
					p->prev->next = p->next;
					nodeCount--;
				}
	}
}

void DeleteData(List &l, int x)
{
	if (l.head == NULL)
	{
		return;
	}
	bool check = false;
	if (l.head->data == x)
	{
		DeleteHead(l);
		check = true;
	}
	if (l.tail->data == x)
	{
		DeleteTail(l);
		check = true;
	}
	node* p = l.head->next;
	while (p!=l.tail)
	{
		if (p->data == x)
		{
			node* p1 = p->prev;
			node* p2 = p;
			p = p->next;
			p->prev = p1;
			p1->next = p;
			delete(p2);
			nodeCount--;
			check = true;
		}
		else
		{
			p = p->next;
		}
	}
	
	if (check == false)
	{
		printf("\nNode not found.");
	}
}

void main()
{
	List l;
	Initialize(l);
	AddHead(l, 30);
	AddHead(l, 10);
	AddTail(l, 30);
	AddTail(l, 50);
	AddTail(l, 70);
	AddTail(l, 30);
	AddTail(l, 40);
	AddTail(l, 10);
	DeleteData(l, 50);
	Display(l);
	printf("\n%d %d / %d %d", l.head->data, l.head->prev->data, l.tail->data, l.tail->next->data);
	_getch();
}