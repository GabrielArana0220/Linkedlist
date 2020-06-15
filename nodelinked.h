#include <iostream>
#include <string>

class Node
{
    int element;
    Node *next;
public:
    Node(int element);
    friend class LinkedList;
};

class LinkedList
{
    int sizee;
    Node *head;
public:
    LinkedList();
    void show();
    void add(int);
    void del(int);
    ~LinkedList();
};


