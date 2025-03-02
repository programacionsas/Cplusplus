#include <iostream>

union StudentId
{
    int card_number;
    const char* full_name;
};

union DummyType
{
    char letter;
    int int_number;
    float float_number;
};

int main()
{
    StudentId student_id;

    student_id.card_number = 12345;

    std::cout << student_id.card_number << "\n";

    student_id.full_name = "Alejandro Mujica";

    std::cout << student_id.card_number << "\n";
    std::cout << student_id.full_name << "\n";

    std::cout << "Tamaño de un char: " << sizeof(char) << "\n";
    std::cout << "Tamaño de un int: " << sizeof(int) << "\n";
    std::cout << "Tamaño de un float: " << sizeof(float) << "\n";
    std::cout << "Tamaño de un DummyType: " << sizeof(DummyType) << "\n";


    return 0;
}