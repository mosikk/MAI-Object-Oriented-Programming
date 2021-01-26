#ifndef OOP_LAB6_ALLOCATOR_H
#define OOP_LAB6_ALLOCATOR_H


#include <vector>

template<class T, size_t BLOCKS_AMOUNT>
class allocator {
private:
    T* buffer;
    std::vector<T*> free_blocks;

public:

    // allocator traits
    using value_type = T;
    using pointer = T *;
    using const_pointer = const T *;
    using size_type = size_t;

    allocator() noexcept {
        std::cout << "Allocator's constructor" << std::endl;
        buffer = nullptr;
    }

    ~allocator() {
        std::cout << "Allocator's destructor" << std::endl;
        free(buffer);
    }

    // allocator type conversion
    template<class U>
    struct rebind {
        using other = allocator<U, BLOCKS_AMOUNT>;
    };

    pointer allocate() {
        // at first we should allocate memory for buffer
        if (!buffer) {
            std::cout << "Allocating buffer" << std::endl;
            buffer = (pointer)malloc(BLOCKS_AMOUNT * sizeof(T));
            for (int i = 0; i < BLOCKS_AMOUNT; ++i) {
                free_blocks.push_back(buffer + i);
            }
        }

        if (free_blocks.empty()) {
            throw std::bad_alloc();
        }

        pointer p = free_blocks[free_blocks.size() - 1];
        free_blocks.pop_back();
        std::cout << "Allocating " << p << std::endl;
        return p;

    }

    void deallocate(pointer p) {
        std::cout << "Deallocating " << p << std::endl;
        free_blocks.push_back(p);
    }

    template<typename U, typename... Args>
    void construct(U* p, Args&&... args) {
        new (p) U(std::forward<Args>(args)...);
    }

    void destroy(pointer p) {
        p->~T();
    }
};


#endif //OOP_LAB6_ALLOCATOR_H
