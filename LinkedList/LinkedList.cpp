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
    uint32_t IndexOf(const ItemType& item) const;
    bool Contains(const ItemType& item) const;
    uint32_t Count() const;
    void RemoveAt(uint32_t index);

private:
    struct Node
    {
        Node* next{ nullptr };
        Node* previous{ nullptr };
        ItemType data{};

        Node(const ItemType& item, Node* nextNode = nullptr, Node* previousNode = nullptr)
            : next(nextNode), previous(previousNode), data(item)
        {}
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
    auto* node = makeNode(item);

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
    auto* current = firstNode;
    for (uint32_t i = 0; i < index && current != nullptr; i++)
    {
        current = current->next;
    }
    return (current != nullptr ? current : throw out_of_range("Index out of range"));
}

template <typename ItemType>
ItemType LinkedList<ItemType>::Get(uint32_t index) const
{
    auto* node = getNodeAt(index);
    return node->data;
}

template <typename ItemType>
void LinkedList<ItemType>::Set(uint32_t index, const ItemType& item)
{
    auto* node = getNodeAt(index);
    node->data = item;
}

template <typename ItemType>
ItemType LinkedList<ItemType>::Remove(const ItemType& item)
{
    auto* current = firstNode;
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
    return ItemType{};
}

template <typename ItemType>
void LinkedList<ItemType>::Clear()
{
    auto* current = firstNode;
    while (current != nullptr)
    {
        auto* next = current->next;
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
    auto index = 0;
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
    auto* current = firstNode;
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
    auto* current = firstNode;
    while (current != nullptr)
    {
        count++;
        current = current->next;
    }
    return count;
}

template <typename ItemType>
void LinkedList<ItemType>::RemoveAt(uint32_t index)
{
    if (index >= Count()) return;

    auto* nodeToRemove = getNodeAt(index);
    auto* prevNode = nodeToRemove->previous;
    auto* nextNode = nodeToRemove->next;

    prevNode ? prevNode->next = nextNode : firstNode = nextNode;
    nextNode ? nextNode->previous = prevNode : lastNode = prevNode;

    delete nodeToRemove;
}

int main()
{
    return 0;
}