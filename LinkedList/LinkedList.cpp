#include "Header.h"
#include <iostream>
#include <stdexcept>
#include <vector>
#include <cstddef>


using namespace std;

template <typename ItemType>
class LinkedList
{
public:
    LinkedList();
    ~LinkedList();

    void Add(const ItemType& item);
    void MultiAdd(const vector<ItemType>& items);
    ItemType Get(uint32_t index) const;
    void Set(uint32_t index, const ItemType& item);
    ItemType Remove(const ItemType& item);
    void Clear();
    uint32_t Count() const;
    bool Contains(const ItemType& item) const;
    uint32_t IndexOf(const ItemType& item) const; // declaration of IndexOf function


private:
    struct Node
    {
        Node* next{ nullptr };
        Node* previous{ nullptr };
        ItemType data{};

        Node(const ItemType& item, Node* nextNode = nullptr, Node* previousNode = nullptr)
            : next(nextNode), previous(previousNode), data(item)
        {
        }
    };


    Node* firstNode{ nullptr };
    Node* lastNode{ nullptr };

    Node* makeNode(const ItemType& item);
    Node* getNodeAt(uint32_t index) const;
};


template <typename ItemType>
LinkedList<ItemType>::LinkedList() : firstNode(nullptr), lastNode(nullptr) {}

template <typename ItemType>
LinkedList<ItemType>::~LinkedList()
{
    Clear();
}


template <typename ItemType>
typename LinkedList<ItemType>::Node* LinkedList<ItemType>::makeNode(const ItemType& item)
{
    Node* node = new Node{ item, nullptr, nullptr };
    return node;
}

template <typename ItemType>
void LinkedList<ItemType>::Add(const ItemType& item)
{
    Node* node = makeNode(item);

    if (firstNode == nullptr)
    {
        firstNode = node;
        lastNode = node;
    }
    else
    {
        lastNode->next = node;
        node->previous = lastNode;
        lastNode = node;
    }
}

template <typename ItemType>
void LinkedList<ItemType>::MultiAdd(const vector<ItemType>& items)
{
    for (const ItemType& item : items)
    {
        Add(item);
    }
}

template <typename ItemType>
typename LinkedList<ItemType>::Node* LinkedList<ItemType>::getNodeAt(uint32_t index) const
{
    Node* current = firstNode;
    for (uint32_t i = 0; i < index; i++)
    {
        if (current == nullptr)
        {
            throw out_of_range("Index out of range");
        }
        current = current->next;
    }
    return current;
}

template <typename ItemType>
ItemType LinkedList<ItemType>::Get(uint32_t index) const
{
    Node* node = getNodeAt(index);
    return node->data;
}

template <typename ItemType>
void LinkedList<ItemType>::Set(uint32_t index, const ItemType& item)
{
    Node* node = getNodeAt(index);
    node->data = item;
}

template <typename ItemType>
ItemType LinkedList<ItemType>::Remove(const ItemType& item)
{
    Node* current = firstNode;
    while (current != nullptr)
    {
        if (current->data == item)
        {
            (current == firstNode ? firstNode : current->previous->next) = current->next;
            (current == lastNode ? lastNode : current->next->previous) = current->previous;

            ItemType removedItem = current->data;
            delete current;
            current = nullptr;
            return removedItem;
        }
        current = current->next;
    }

    // item not found
    return ItemType{};
}

template <typename ItemType>
void LinkedList<ItemType>::Clear()
{
    Node* current = firstNode;
    while (current != nullptr)
    {
        Node* next = current->next;
        delete current;
        current = next;
    }
    firstNode = nullptr;
    lastNode = nullptr;
}

template <typename ItemType>
uint32_t LinkedList<ItemType>::IndexOf(const ItemType& item) const

{
    Node* current = firstNode;
    int index = 0;
    while (current != nullptr)
    {
        if (current->data == item) return index;
        current = current->next;
        ++index;
    }
    return -1;
}


template <typename ItemType>
bool LinkedList<ItemType>::Contains(const ItemType& item) const
{
    Node* current = firstNode;
    while (current != nullptr)
    {
        if (current->data == item) return true;

        current = current->next;
    }
    return false;
}

template <typename ItemType>
uint32_t LinkedList<ItemType>::Count() const
{
    uint32_t count = 0;
    Node* current = firstNode;
    while (current != nullptr)
    {
        count++;
        current = current->next;
    }
    return count;
}


int main()
{
    LinkedList<int> myLinkedList;
    myLinkedList.Add(1);
    myLinkedList.Add(2);
    myLinkedList.Add(3);
    cout << "Linked List contains: " << myLinkedList.Count() << " elements." << endl;

    int firstItem = myLinkedList.Get(0);
    cout << "First Item: " << firstItem << endl;

    int removedItem = myLinkedList.Remove(2);
    cout << "Removed Item: " << removedItem << endl;

    myLinkedList.Set(1, 4);

    int index = myLinkedList.IndexOf(4);
    if (index != -1) {
        cout << "Item found at index: " << index << endl;
    }

    bool containsItem = myLinkedList.Contains(3);
    if (containsItem) {
        cout << "Linked List contains the item 3." << endl;
    }

    myLinkedList.Clear();
    cout << "Linked List cleared." << endl;

    return 0;
}