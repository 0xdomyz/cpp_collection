#ifndef GUARD_STRING_LIST_H
#define GUARD_STRING_LIST_H

#include <string>
#include <vector>

// type definitions
typedef std::string &reference;
typedef const std::string &const_reference;

struct String_list_node
{
    std::string data;
    String_list_node *prev;
    String_list_node *next;
};

class String_list_iterator
{
public:
    String_list_iterator(String_list_node *p) : ptr{p} {}
    ~String_list_iterator() {}
    String_list_iterator(const String_list_iterator &rhs) : ptr{rhs.ptr} {} // copy constructor
    String_list_iterator &operator=(const String_list_iterator &rhs)        // copy assignment
    {
        ptr = rhs.ptr;
        return *this;
    }
    String_list_iterator &operator++()
    {
        ptr = ptr->next;
        return *this;
    }
    String_list_iterator operator++(int)
    {
        String_list_iterator tmp = *this;
        ++*this;
        return tmp;
    }
    String_list_iterator &operator--()
    {
        ptr = ptr->prev;
        return *this;
    }
    String_list_iterator operator--(int)
    {
        String_list_iterator tmp = *this;
        --*this;
        return tmp;
    }
    reference operator*() const
    {
        return ptr->data;
    }
    bool operator==(const String_list_iterator &rhs) const
    {
        return ptr == rhs.ptr;
    }
    bool operator!=(const String_list_iterator &rhs) const
    {
        return ptr != rhs.ptr;
    }

private:
    String_list_node *ptr;
};

// String_list which is a linked list of strings
class String_list
{
public:
    // type definitions
    typedef String_list_iterator iterator;
    typedef const String_list_iterator const_iterator;
    typedef std::string value_type;
    typedef std::string &reference;
    typedef const std::string &const_reference;

    // constructors
    String_list();
    String_list(const std::vector<std::string> &);
    ~String_list();

    // iterators
    String_list_iterator begin();
    String_list_iterator end();
    String_list_iterator rbegin();
    String_list_iterator rend();

    // capacity

    // modifiers
    void push_back(const_reference);

    // friends
    friend std::ostream &operator<<(std::ostream &, const String_list &);

private:
    // data members
    String_list_node *head;
    String_list_node *tail;
};

String_list::String_list() : head{nullptr}, tail{nullptr} {}

String_list::String_list(const std::vector<std::string> &v) : head{nullptr}, tail{nullptr}
{
    for (auto it = v.begin(); it != v.end(); ++it)
    {
        push_back(*it);
    }
}

String_list::~String_list()
{
    String_list_node *ptr = head;
    while (ptr != nullptr)
    {
        String_list_node *next = ptr->next;
        delete ptr;
        ptr = next;
    }
}

void String_list::push_back(const_reference s)
{
    String_list_node *node = new String_list_node{s, nullptr, nullptr};
    if (head == nullptr)
    {
        head = node;
        tail = node;
    }
    else
    {
        tail->next = node;
        node->prev = tail;
        tail = node;
    }
}

String_list_iterator String_list::begin()
{
    return String_list_iterator(head);
}

String_list_iterator String_list::end()
{
    return String_list_iterator(nullptr);
}

String_list_iterator String_list::rbegin()
{
    return String_list_iterator(tail);
}

String_list_iterator String_list::rend()
{
    return String_list_iterator(nullptr);
}

std::ostream &operator<<(std::ostream &out, const String_list &sl)
{
    String_list_node *ptr = sl.head;
    while (ptr != nullptr)
    {
        out << ptr->data << std::string{" "};
        ptr = ptr->next;
    };
    return out;
}

#endif //
