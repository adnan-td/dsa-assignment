#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 11

typedef struct dataitems
{
  node *data;
  int key;
} hashitem;

hashitem *hashArray[SIZE];
hashitem *dummyItem;
hashitem *item;

int hashfunction(int key)
{
  return key % SIZE;
}

hashitem *searchHT(int key)
{
  int hashIndex = hashfunction(key);
  while (hashArray[hashIndex] != NULL)
  {

    if (hashArray[hashIndex]->key == key)
      return hashArray[hashIndex];
    ++hashIndex;
    hashIndex %= SIZE;
  }

  return NULL;
}

void insertHT(int key, node *data)
{

  hashitem *item = (hashitem *)malloc(sizeof(hashitem));
  item->data = data;
  item->key = key;
  int hashIndex = hashfunction(key);
  while (hashArray[hashIndex] != NULL && hashArray[hashIndex]->key != -1)
  {
    ++hashIndex;
    hashIndex %= SIZE;
  }

  hashArray[hashIndex] = item;
}

hashitem *deleteHT(hashitem *item)
{
  int key = item->key;
  int hashIndex = hashfunction(key);
  while (hashArray[hashIndex] != NULL)
  {
    if (hashArray[hashIndex]->key == key)
    {
      hashitem *temp = hashArray[hashIndex];
      hashArray[hashIndex] = dummyItem;
      return temp;
    }
    ++hashIndex;
    hashIndex %= SIZE;
  }

  return NULL;
}

void displayHT()
{
  int i = 0;
  for (i = 0; i < SIZE; i++)
  {
    if (hashArray[i] != NULL)
    {
      printf("(%d -> ", hashArray[i]->key);
      displayLL(hashArray[i]->data);
      printf(")\n");
    }
    else
      printf(" ~\n");
  }
  printf("\n");
}
