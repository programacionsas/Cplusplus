#include <iostream>

enum Suit
{
    Spades,
    Clubs,
    Diamonds,
    Hearts
};

enum class SemaphoreColor
{
    Green,
    Yellow,
    Red
};

enum class RGBColor
{
    Red,
    Green,
    Blue
};

int main()
{
    Suit suit = Spades;

    std::cout << suit << "\n";

    std::cout << Spades << "\n";
    std::cout << Clubs << "\n";
    std::cout << Diamonds << "\n";
    std::cout << Hearts << "\n";

    RGBColor color = RGBColor::Green;

    std::cout << static_cast<int>(color) << "\n";

    return 0;
}