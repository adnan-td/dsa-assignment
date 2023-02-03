#include <stdio.h>
#include <stdlib.h>

#define srange(i, start, end) for (int i = start; i < end; i++)
#define range(i, end) srange(i, 0, end)

typedef struct node
{
  char data;
  struct node *next;
} node;

node *newNode(int data)
{
  node *temp = (node *)malloc(sizeof(node));
  temp->data = data;
}

void isEmptyLL(node *head)
{
  if (head == NULL)
    printf("SLL is empty!!!\n");
}

int lengthLL(node *head)
{
  int count = 0;
  node *temp = head;
  while (temp != NULL)
  {
    count++;
    temp = temp->next;
  }
  return count;
}

int searchLL(node *head, char key)
{
  int flag, count1;
  flag = count1 = 0;
  node *temp = head;
  while (temp != NULL)
  {
    count1++;
    if (temp->data == key)
    {
      flag = 1;
      break;
    }
    temp = temp->next;
  }
  if (flag == 1)
    printf("Element is found at position %d\n .", count1);
  else
    printf("Element is not present in the linked list.\n");
  return count1;
}

void insertLL(node **head, char item)
{
  node *ptr = newNode(item), *temp;
  if (ptr == NULL)
  {
    printf("OVERFLOW\n");
  }
  else
  {
    ptr->data = item;
    if (*head == NULL)
    {
      ptr->next = NULL;
      *head = ptr;
    }
    else
    {
      temp = *head;
      while (temp->next != NULL)
      {
        temp = temp->next;
      }
      temp->next = ptr;
      ptr->next = NULL;
    }
  }
}

void deleteAtBeginingLL(node *head)
{
  node *temp = head;
  if (temp->next == NULL)
    head = NULL;
  else
  {
    head = temp->next;
    free(temp);
  }
}

void deleteAtEndLL(node *head)
{
  node *temp = head, *previous_node;
  if (temp->next == NULL)
    head = NULL;
  else
  {
    while (temp->next != 0)
    {
      previous_node = temp;
      temp = temp->next;
    }
    previous_node->next = NULL;
    free(temp);
  }
}

void displayLL(node *head)
{
  node *temp = head;
  if (temp == NULL)
    printf("SLL is empty!!!\n");
  else
  {
    while (temp != NULL)
    {
      printf("%c ", temp->data);
      temp = temp->next;
    }
  }
}
