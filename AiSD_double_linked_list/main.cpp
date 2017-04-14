#include <iostream>
using namespace std;

//*************************************************************************************************************************
                                                                                            
struct node;

void insertNodeFromRight(node * &Head, int x);
void deleteNode(node * &Head);
void bubbleSortWithTwoBumpers(node * &Head);
void show(node *Head);

//*************************************************************************************************************************

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                                                                                                              
struct node
{
	node *prev;
	int val;
	node *next;
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//*************************************************************************************************************************
                                                                                                                     
int main()
{
	int x;
	node *Head = NULL;

	int wybor;
	int wybor2;
	do
	{
		cout << "1. Show menu" << endl
			 << "2. Show functions ";
		cin >> wybor;
		switch (wybor)
		{
		case 1:
			cout << "1. Enter node from right" << endl
				<< "2. Delete" << endl
				<< "3. Bubble Sort with two bumpers" << endl
				<< "4. Show list" << endl
				<< "0. Exit" << endl;
			break;

		case 2:
			cout << "Choose function: ";
			cin >> wybor2;
			switch (wybor2)
			{
			case 1:
				cout << "Enter element value: ";
				cin >> x;
				insertNodeFromRight(Head, x);                                  
				break;

			case 2:
				deleteNode(Head);                                                              
				break;

			case 3:
				bubbleSortWithTwoBumpers(Head);                       
				break;

			case 4:
				show(Head);                                                                    
				break;
			}
		}			                                 

	} while (wybor != 0);
}

//*************************************************************************************************************************
                                                                                                   
void insertNodeFromRight(node * &Head, int x)
{
	node *tmp = new node;
	tmp->val = x;
	tmp->next = Head;
	Head = tmp;
	Head->prev = NULL;
	if (Head->next != NULL)
	{
		Head->next->prev = Head;
	}
}

//*************************************************************************************************************************
                                                                                                           
void deleteNode(node * &Head)
{
	node *tmp = Head;

	if (tmp != NULL)
	{
		Head = Head->next;
		Head->prev = NULL;
		delete tmp;
		cout << "Node has been deleted" << endl;
	}
	else
		cout << "An error occurred during deleting a node" << endl;
}

//*************************************************************************************************************************
                                                                                                       
void show(node *Head)
{
	node *tmp = Head;
	cout << "Head->";
	while (tmp != NULL)
	{
		cout << tmp->val << "->";
		tmp = tmp->next;
	}

	cout << "NULL" << endl;
}

//*************************************************************************************************************************
                                                                                  
void bubbleSortWithTwoBumpers(node * &Head)
{
	node *rear_bumper = NULL;
	node *front_bumper = NULL;
	node *tmp_prev = NULL;
	node *tmp = NULL;
	node *tmp_next = NULL;

	if (Head != NULL && Head->next != NULL)
	{
		tmp = Head;

		while (tmp->prev != rear_bumper || tmp->next != front_bumper)
		{
			while (tmp != front_bumper)
			{
				if (tmp->val > tmp->next->val)
				{
					if (tmp == Head)
					{
						Head = Head->next;
						tmp->next = Head->next;
						Head->next = tmp;
						tmp->prev = Head;
						Head->prev = NULL;
						tmp->next->prev = tmp;
					}

					else
					{
						tmp->next = tmp_next->next;
						tmp_next->next = tmp;
						tmp_prev->next = tmp_next;

						if(tmp->next != NULL)
							tmp->next->prev = tmp;

						tmp->prev = tmp_next;
						tmp_next->prev = tmp_prev;
					}
				}

				else
				{
					tmp = tmp->next;
				}

				tmp_prev = tmp->prev;
				tmp_next = tmp->next;

				if (tmp->next == front_bumper)
				{
					front_bumper = tmp;
				}
			}

			tmp = tmp_prev;
			tmp_prev = tmp->prev;
			tmp_next = tmp->next;

			while (tmp != rear_bumper)
			{
				if (tmp->prev->val > tmp->val)
				{
					tmp->prev = tmp_prev->prev;
					tmp_prev->prev = tmp;
					tmp_next->prev = tmp_prev;
					
					if (tmp->prev != NULL)
						tmp->prev->next = tmp;

					tmp->next = tmp_prev;
					tmp_prev->next = tmp_next;

					if (tmp->prev == NULL)
						Head = Head->prev;
				}

				else
				{
					tmp = tmp->prev;
				}

				tmp_prev = tmp->prev;
				tmp_next = tmp->next;

				if (tmp->prev == rear_bumper)
				{
					rear_bumper = tmp;
				}
			}

			tmp = tmp->next;
			tmp_prev = tmp->prev;
			tmp_next = tmp->next;
		}
	}
}

