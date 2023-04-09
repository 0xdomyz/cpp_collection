// compile and run: g++ non_intrusive_list.cpp -o non_intrusive_list && ./non_intrusive_list

#include <iostream>

template <class T>
class List
{
public:
    void insert(T); // insert a value at the head of the allocated list
    T get();        // get the value at the head of the allocated list
    List() : allocated(0), free(0), head(0){};
    ~List()
    {
        // ... free all the allocated chunks ...
        while (allocated)
        {
            Chunk *p = allocated;
            allocated = allocated->next;
            delete p;
        }
    };
    friend std::ostream &operator<<(std::ostream &os, const List<T> &lst)
    {
        // ... print the list ...
        // each line has chunk::chunk_size elements, use modulo to print the elements
        os << "List: ";
        int row_size = Chunk::chunk_size;
        int i = 0;
        for (Link *p = lst.head; p; p = p->next)
        {
            os << p->val << " ";
            if (++i % row_size == 0)
                os << std::endl;
        }
        os << std::endl;
        return os;
    }

private:
    struct Link // a Link is a node in the list
    {
        T val;
        Link *next;
    };
    struct Chunk // a chunk is a list of Links
    {
        enum
        {
            chunk_size = 15
        };
        Link v[chunk_size];
        Chunk *next;
    };
    Chunk *allocated; // allocated list, a list of Chunks that have been allocated
    Link *free;       // free list, a list of Links that are not in use
    Link *get_free(); // get a free Link
    Link *head;       // head of what is in use
};

// if thrown, give a message
class Underflow
{

public:
    Underflow()
    {
        std::cout << "Underflow" << std::endl;
    }
};

template <class T>
void List<T>::insert(T val)
{
    Link *lnk = get_free(); // get a free link

    lnk->val = val;
    // insert at the head of the list
    lnk->next = head;
    head = lnk;
}

template <class T>
T List<T>::get()
{
    if (head == 0)
        throw Underflow{}; // Underflow is my exception class

    Link *p = head; // get the first element
    head = p->next; // remove it from the list
    p->next = free; // put it on the free list
    free = p;       // return the value
    return p->val;  // return the value
}

template <class T>
typename List<T>::Link *List<T>::get_free()
// typename List<T>::Link * is the same as List<T>::Link *
{
    if (free == 0)
    {
        // ... allocate a new chunk and place its Links on the free list ...
        Chunk *p = new Chunk;
        p->next = allocated;
        allocated = p;
        for (int i = 0; i < Chunk::chunk_size; ++i)
        // the first iteration has i = 0
        {
            p->v[i].next = free;
            free = &p->v[i];
        }
    }
    Link *p = free;
    free = free->next;
    return p;
}

int main(void)
{
    List<int> lst;

    for (int i = 0; i < 31; ++i)
        lst.insert(i);

    std::cout << lst << std::endl;

    for (int i = 0; i < 31; ++i)
        std::cout << lst.get() << " ";
    std::cout << std::endl;

    return 0;
}
