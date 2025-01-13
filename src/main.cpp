#include <engine/engine.hpp>

// keep track of allocated memory and freed memory
#ifndef NDEBUG

size_t allocatedBytes = 0;
size_t countAllocation = 0;

void* operator new(size_t size){
    void* heapm = std::malloc(size);
    allocatedBytes += size;
    countAllocation++;
    if (!heapm) {
        std::cerr << "allocation failed";
        throw std::bad_alloc();
    }

    return heapm;
}

void operator delete(void* ptr, size_t size) {
    std::free(ptr);
    allocatedBytes -= size;
    countAllocation--;
}

void* operator new[](size_t size) {
    void* heapm = std::malloc(size);
    if (!heapm) {
        std::cerr << "Memory allocation failed for array\n";
        throw std::bad_alloc();
    }
    allocatedBytes += size;
    countAllocation++;
    return heapm;
}

void operator delete[](void* ptr, size_t size) noexcept {
    std::free(ptr);
    allocatedBytes -= size;
    countAllocation--;
}

#endif

int main(int argc, char** argv){
    Engine e(argc, argv);

    // keep track of allocated memory and freed memory
    #ifndef NDEBUG

    std::cout << "unfreed memory in bytes: " << allocatedBytes << "\n"
    << "allocations that didnt got freed: " << countAllocation << "\n";

    #endif
    return 0;
}
