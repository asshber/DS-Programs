#include <iostream>

template <typename T>
class SinglyLinkedList
{
public:
    struct Node
    {
        T data;
        Node* next = nullptr;

        Node(T data)
            :
            data(data)
        {}
        ~Node()
        {
            delete next;
        }
    };

    SinglyLinkedList()
    {}
    ~SinglyLinkedList()
    {
        delete first;
    }
    SinglyLinkedList(const SinglyLinkedList& rhs)
    {
        *this = rhs;
    }
    SinglyLinkedList& operator=(const SinglyLinkedList& rhs)
    {
        if (this == &rhs)
        {
            return *this;
        }
        delete first;
        size = 0;

        Node* ptr = rhs.first;
        while (ptr != nullptr)
        {
            Insert(ptr->data);
            ptr = ptr->next;
        }
        return *this;
    }

    void Print() const
    {
        for (auto ptr = first; ptr != nullptr; ptr = ptr->next)
        {
            std::cout << ptr->data << ' ';
        }
        std::cout << std::endl;
    }
    void Insert(T data)
    {
        if (first == nullptr)
        {
            first = new Node(data);
            size = 1;
            return;
        }
        auto ptr = first;
        for (; ptr->next != nullptr; ptr = ptr->next)
        {
        }
        ptr->next = new Node(data);
        size++;
    }
    void Delete(int pos)
    {
        if (pos >= size)
        {
            return;
        }
        Node* ptr = first;
        Node* prev = nullptr;
        for (int i = 0; i < pos; i++)
        {
            prev = ptr;
            ptr = ptr->next;
        }
        prev->next = ptr->next;
        ptr->next = nullptr;
        delete ptr;
    }
    int GetSize() const
    {
        return size;
    }
    // interface func
    void MergeSort()
    {
        _MergeSort(&first, GetSize());
        // for a double linked list, a for loop will be needed here
        // to realign all the parent pointers
    }

private:

    // the proper merge sort implementation for linked lists
    // slightly modified to suit how i like to do things
    // but mostly the same as the one available on geeksforgeeks
    void _MergeSort(Node** start, int num)
    {
        if (num <= 1)
        {
            return;
        }

        Node* n1 = *start;
        Node* n2;

        // slpit in half
        int mid = num / 2;
        n2 = Split(n1, mid);

        _MergeSort(&n1, mid);
        _MergeSort(&n2, num - mid);

        *start = Merge(n1, n2);
    }
    // returs a ptr to the node at pos and disconnects it from the previous node
    Node* Split(Node* start, int pos)
    {
        for (int i = 0; i < pos - 1; i++)
        {
            start = start->next;
        }
        Node* temp = start;
        start = start->next;
        temp->next = nullptr;
        return start;
    }
    // merges two sub-lists together and returns poiter to the resultant list's first node
    // the originals WILL be modified
    Node* Merge(Node* l, Node* r)
    {
        // if either is empty, return the other
        if (l == nullptr)
        {
            return r;
        }
        if (r == nullptr)
        {
            return l;
        }

        // the result of merging the two sub-lists
        Node* res = nullptr;
        // initialize res with the smaller first node
        if (l->data < r->data)
        {
            res = l;
            l = l->next;
        }
        else
        {
            res = r;
            r = r->next;
        }

        // temp ptr to iterate through res
        Node* ptr = res;

        while (l != nullptr && r != nullptr)
        {
            // make the current node point to the smaller node
            if (l->data < r->data)
            {
                ptr->next = l;
                l = l->next;
            }
            else
            {
                ptr->next = r;
                r = r->next;
            }
            ptr = ptr->next;
        }

        // if either r or l is remaining, append it to res
        // it is guaranteed to be sorted
        if (l != nullptr)
            ptr->next = l;
        else if (r != nullptr)
            ptr->next = r;

        return res;
    }

private:
    Node* first = nullptr;
    int size;
};


int main(void)
{
    SinglyLinkedList<int> li;
    li.Insert(9);
    li.Insert(7);
    li.Insert(6);
    li.Insert(5);

    li.Print();
    li.MergeSort();
    li.Print();

    return 0;
}