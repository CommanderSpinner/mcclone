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


#ifndef _WIN32

int main(int argc, char** argv){
    Engine e(argc, argv);

    // keep track of allocated memory and freed memory
    #ifndef NDEBUG

    std::cout << "unfreed memory in bytes: " << allocatedBytes << "\n"
    << "allocations that didnt got freed: " << countAllocation << "\n";

    #endif
    return 0;
}

#else

// Windows-specific WinMain entry point
int WINAPI WinMain(
    HINSTANCE hInstance,      // Handle to the current instance of the application
    HINSTANCE hPrevInstance,  // Handle to the previous instance (always NULL in modern Windows)
    LPSTR lpCmdLine,          // Command-line arguments as a single string
    int nCmdShow              // Controls how the window is to be shown
) {
    // Parse command-line arguments into argc and argv
    int argc = 0;
    char** argv = nullptr;

    LPSTR* argvWide = CommandLineToArgvW(GetCommandLineW(), &argc);
    if (argvWide) {
        argv = new char*[argc];
        for (int i = 0; i < argc; i++) {
            size_t size = wcslen(argvWide[i]) + 1;
            argv[i] = new char[size];
            wcstombs(argv[i], argvWide[i], size);
        }
        LocalFree(argvWide);
    }

    // Instantiate Engine with command-line arguments
    Engine e(argc, argv);

    // Free allocated argv memory
    for (int i = 0; i < argc; i++) {
        delete[] argv[i];
    }
    delete[] argv;

    // Keep track of allocated memory and freed memory
    #ifndef NDEBUG
    std::string debugMessage = "unfreed memory in bytes: " + std::to_string(allocatedBytes) + "\n" +
                                "allocations that didn't get freed: " + std::to_string(countAllocation) + "\n";
    OutputDebugString(debugMessage.c_str());
    #endif

    return 0;
}
#endif
