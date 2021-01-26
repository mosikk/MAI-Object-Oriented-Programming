#ifndef OOP_LAB5_STACK_H
#define OOP_LAB5_STACK_H

#include <memory>
#include <exception>

template<class T>
class stack {
private:

    struct item {
        T value;
        std::shared_ptr<item> next = nullptr;

        item() = default;

        item(T val) : value(val) {}

        item &operator=(item const &other) {
            value = other.value;
            next = other.next;
            return *this;
        }

        bool operator!=(item &other) {
            if (value == other.value) {
                if (next == nullptr && other.next == nullptr) {
                    return false;
                }
                return next != other.next;
            }
            return value != other.value;
        }
    };

    item head;
    item tail = head;
public:
    class iterator {
    private:
        std::shared_ptr<item> node;

        friend class stack;

    public:

        // iterator traits
        using difference_type = ptrdiff_t;
        using value_type = T;
        using reference = T &;
        using pointer = std::shared_ptr<T>;
        using iterator_category = std::forward_iterator_tag;

        iterator(item node_) {
            node = std::make_shared<item>(node_);
        }

        iterator &operator++() {
            node = node->next;
            return *this;
        }

        reference operator*() {
            return node->value;
        }

        pointer operator->() {
            return &node->value;
        }

        iterator& operator=(iterator& other) {
            node = other.node;
        }

        bool operator!=(iterator &other) {
            return *node != *(other.node);
        }

        bool operator!=(iterator &&other) {
            return *node != *(other.node);
        }

        bool operator==(iterator &other) {
            return !(*this != other);
        }

        bool operator==(iterator &&other) {
            return !(*this != other);
        }
    };

    T &top() {
        if (head != tail) {
            return head.value;
        }
        throw std::runtime_error("Stack is empty");
    }

    void pop() {
        if (head != tail) {
            head = *head.next;
        } else {
            throw std::runtime_error("Stack is empty");
        }
    }

    void push(T val) {
        item new_head(val);
        new_head.value = val;
        new_head.next = std::make_shared<item>(head);
        head = new_head;
    }

    // iterator to the top
    iterator begin() const {
        return iterator(head);
    }

    // iterator to the last element
    iterator end() const {
        return iterator(tail);
    }

    // insert to iterator's pos
    void insert(iterator &it, T val) {
        if (it == begin()) {
            push(val);
        }
        else {
            item new_node(*it);
            new_node.next = it.node->next;
            *it = val;
            it.node->next = std::make_shared<item>(new_node);
        }
    }

    // erase from iterator's pos
    void erase(iterator &it) {
        if (it == begin()) {
            pop();
        }
        else if (it == end()) {
            tail = *it;
        }
        else {
            *it = it.node->next->value;
            it.node->next = it.node->next->next;
        }
    }
};


#endif //OOP_LAB5_STACK_H
