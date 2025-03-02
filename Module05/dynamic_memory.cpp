#include <iostream>
#include <memory>

int main()
{
    int* ptr = nullptr;

    std::cout << "Valor de ptr: " << ptr << "\n";

    ptr = new int(42);

    std::cout << "Valor de ptr: " << ptr << "\n";
    std::cout << "Valor apuntado ptr: " << *ptr << "\n";

    delete ptr;
    ptr = nullptr;

    // unique_ptr, shared_ptr y weak_ptr

    std::unique_ptr<int> uptr = std::make_unique<int>(45);

    std::cout << "Valor de uptr: " << uptr.get() << "\n";
    std::cout << "Valor apuntado uptr: " << *uptr << "\n";

    std::shared_ptr<int> sptr = std::make_shared<int>(50);
    std::shared_ptr<int> sptrcpy = sptr;

    std::weak_ptr<int> wptr = sptr;

    return 0;
}