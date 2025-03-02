#include <iostream>

int main()
{
    const int min_age = 18;
    constexpr int max_age = 60;
    
    int age;

    std::cout << "La edad mínima es: " << min_age << '\n';
    std::cout << "La edad máxima es: " << max_age << '\n';
    std::cout << "Introduzca su edad: ";
    std::cin >> age;
    std::cout << "La edad introducida es: " << age << '\n';

    int& age_ref = age;

    std::cout << "La referencia a edad es: " << age_ref << '\n';

    age_ref = 30;

    std::cout << "La nueva referencia a edad es: " << age_ref << '\n';
    std::cout << "La nueva edad es: " << age << '\n';
    
    return 0;
}