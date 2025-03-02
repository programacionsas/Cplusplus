#include <iostream>

struct Student
{
    int card_number;
    const char* full_name;
    float avg_grade;
};

enum class Suit
{
    Spades,
    Clubs,
    Diamonds,
    Hearts
};

enum class Rank
{
    Ace, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten,
    Jack, Queen, King
};

struct Card
{
    Suit suit;
    Rank rank;
    bool visible;
};

int main()
{
    Student student;

    student.card_number = 12345;
    student.full_name = "Alejandro Mujica";
    student.avg_grade = 14.0f;

    std::cout << "Estudiante:\n";
    std::cout << "Card number: " << student.card_number << "\n";
    std::cout << "Full name: " << student.full_name << "\n";
    std::cout << "Avg grade: " << student.avg_grade << "\n";

    Card hearts_queen;
    hearts_queen.suit = Suit::Hearts;
    hearts_queen.rank = Rank::Queen;
    hearts_queen.visible = true;

    std::cout << std::boolalpha << "(" << int(hearts_queen.suit);
    std::cout << ", " << int(hearts_queen.rank);
    std::cout << ", " << hearts_queen.visible << ")\n";

    return 0;
}