#include "./linkedlist.h"
#include "./hashing.h"

char *GetString()
{
  char *s;
  s = (char *)malloc(sizeof(char) * 100);
  scanf("%s", s);
  return s;
}

int main()
{
  char ch;
  while (1)
  {
    node *city;
    node *head = NULL;
    printf("Enter the year: ");
    int year;
    scanf("%d", &year);
    int flag = 0;

    printf("Available Choices: \n");
    printf("1. Enter next City \n");
    printf("2. Enter next Places of the city \n");

    while (flag == 0)
    {

      int n;
      printf("Choice: ");
      scanf("%d", &n);

      switch (n)
      {
      case 1:
        printf("Enter the City: ");
        city = insertLL(&head, GetString());
        printf("Enter the no of places visited in the city: ");
        int nplaces;
        scanf("%d", &nplaces);
        link_stack(city, nplaces);
        break;

      case 2:
        printf("Enter the Place: ");

        push(city->link, GetString());
        break;

      default:
        flag = 1;
        break;
      }
    }
    insertHT(year, head);
    displayHT();

    printf("You want to continue? ");
    fflush(stdin);
    scanf("%c", &ch);
    if (ch == 'n')
      break;
  }
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