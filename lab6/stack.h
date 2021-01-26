#ifndef OOP_LAB5_STACK_H
#define OOP_LAB5_STACK_H

#include <memory>
#include <exception>

template<class T,class ALLOCATOR>
class stack {
private:

    struct item {

        using allocator_type = typename ALLOCATOR::template rebind<item>::other;

        T value;
        std::unique_ptr<item> next = nullptr;

        item() = default;

        item(T val) : value(val) {}

        item &operator=(item const &other) noexcept {
            value = other.value;
            next = std::move(other.next);
            return *this;
        }

        bool operator!=(item &other) {
            return &value != &other.value;
        }

        // singleton allocator
        static allocator_type& get_allocator() {
            static allocator_type allocator;
            return allocator;
        }

        void* operator new(size_t size) {
            return get_allocator().allocate();
        }

        void operator delete(void* p) {
            get_allocator().destroy((item*)p);
            get_allocator().deallocate((item*)p);
        }
    };

    std::unique_ptr<item> head;

public:
    class iterator {
    private:
        item* ptr;

        friend class stack;

    public:

        // iterator traits
        using difference_type = ptrdiff_t;
        using value_type = T;
        using reference = T &;
        using pointer = T*;
        using iterator_category = std::forward_iterator_tag;

        iterator() {
            ptr = nullptr;
        }

        iterator(item* node) {
            ptr = node;
        }

        iterator &operator++() {
            if (ptr != nullptr) {
                ptr = ptr->next.get();
            }
            else {
                ptr = nullptr;
            }
            return *this;
        }

        reference operator*() {
            return ptr->value;
        }

        pointer operator->() {
            return &(ptr->value);
        }

        iterator& operator=(iterator const& other) {
            ptr = other.ptr;
        }

        bool operator!=(iterator &other) {
            return ptr != other.ptr;
        }

        bool operator!=(iterator &&other) {
            return ptr != other.ptr;
        }

        bool operator==(iterator &other) {
            return ptr == other.ptr;
        }

        bool operator==(iterator &&other) {
            return ptr == other.ptr;
        }
    };

    T top() {
        if (head) {
            return head->value;
        }
        throw std::runtime_error("Stack is empty");
    }

    void pop() {
        if (head) {
            std::unique_ptr<item> tmp = std::move(head);
            head = std::move(tmp->next);
        } else {
            throw std::runtime_error("Stack is empty");
        }
    }

    void push(T val) {
        std::unique_ptr<item> new_head = std::make_unique<item>(val);
        if (head) {
            new_head->next = std::move(head);
            head = std::move(new_head);
        }
        else {
            head = std::move(new_head);
        }
    }

    // iterator to the top
    iterator begin() const {
        if (head == nullptr) {
            return nullptr;
        }
        return head.get();
    }

    // iterator to the last element
    iterator end() const {
        return iterator();
    }

    // insert to iterator's pos
    void insert(iterator &it, T val) {
        if (it == begin()) {
            push(val);
        }
        else {
            std::unique_ptr<item> new_node = std::make_unique<item>(*it);
            new_node->next = std::move(it.ptr->next);
            *it = val;
            it.ptr->next = std::move(new_node);

        }
    }

    // erase from iterator's pos
    void erase(iterator &it) {
        if (it == begin()) {
            pop();
        }
        else if (it.ptr->next == nullptr) {
            auto iter = begin();
            while (iter.ptr->next->next != nullptr) {
                ++iter;
            }
            iter.ptr->next = nullptr;
        }
        else {
            *it = it.ptr->next->value;
            it.ptr->next = std::move(it.ptr->next->next);
        }
    }
};


#endif //OOP_LAB5_STACK_H
