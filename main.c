#include "./linkedlist.h"
#include "./hashing.h"

int main()
{
  for (int i = 2018; i < 2024; i++)
  {
    node *head = NULL;
    insertLL(&head, 'A');
    insertLL(&head, 'D');
    insertLL(&head, 'N');
    insertLL(&head, 'A');
    insertLL(&head, 'N');
    insertHT(i, head);
  }

  displayHT();
  // item = searchHT(37);

  // if (item != NULL)
  // {
  //   printf("Element found: %d\n", item->data);
  // }
  // else
  // {
  //   printf("Element not found\n");
  // }

  // deleteHT(item);
  // item = searchHT(37);

  // if (item != NULL)
  // {
  //   printf("Element found: %d\n", item->data);
  // }
  // else
  // {
  //   printf("Element not found\n");
  // }
}