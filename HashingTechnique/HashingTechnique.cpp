
#include <iostream>
#include "Header.h"
#define SIZE 10
int Hash(int key)
{
    return key % SIZE;
}
// Chaining
void Insert(struct Node* H[], int key)
{
    int index = Hash(key);
    SortedInsert(&H[index], key);
}
//////////////////////////////////////////////

// Linear Probing
void Insert(int H[], int key)
{
    int index = Hash(key);
    if (H[index] != 0)
        index = Probe(H,key);
    H[index] = key;
}
//Probe function will find out the next free space
int Probe(int H[], int key)
{
    int index = Hash(key);
    int i = 0;
    while (H[(index + i) % 10] != 0)
        i++;
    return (index + i) % SIZE;
}
int Search(int H[], int key)
{
    int index = Hash(key);
    int i = 0;
    while (H[(index + i) % 10] != key)
        i++;
    return (index + i) % SIZE;
}
////////////////////////////////////////////

//Quadratic Probing
void Insert(int H[], int key)
{
    int index = Hash(key);
    if (H[index] != 0)
        index = Probe(H, key);
    H[index] = key;
}
int Probe(int H[], int key)
{
    int index = Hash(key);
    int i = 0;
    while (H[(index + i*i) % 10] != 0)
        i++;
    return (index + i*i) % SIZE;
}
int Search(int H[], int key)
{
    int index = Hash(key);
    int i = 0;
    while (H[(index + i*i) % 10] != key)
        i++;
    return (index + i*i) % SIZE;
}
int main()
{
    std::cout << "Hello World!\n";
}