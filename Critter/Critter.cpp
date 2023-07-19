// Тамогочи
// Имитирует заботу о вертуальном питомце

#include <iostream>
using namespace std;

class Critter
{
public:
    Critter(int hunger = 0, int boredom = 0);
    void Talk();
    void Eat(int food = 4);
    void Play(int fun = 4);
private:
    int m_Hunger; // голод
    int m_Boredom; // скука
    int GetMood() const; // настроение
    void PassTime(int time = 1); // ход времени
};

Critter::Critter(int hunger, int boredom) : // инициализируем в конструкторе члены голод и скука
    m_Hunger(hunger),
    m_Boredom(boredom)
{}

inline int Critter::GetMood() const /* настроение зависит от двух показателей:
голод и скука, оно ухудшается по мере возрастания этих значений. Функция закрыта, так как инициировать её может 
только другая функция этого же класса.
*/
{
    return (m_Hunger + m_Boredom);
}

void Critter::PassTime(int time) /* закрытая фукнкция-член, увеличивающая уровни голода и скуки тамагочи, также инициировать её может
только другая функция член из того же класса.
*/
{
    m_Hunger += time;
    m_Boredom += time;
}

void Critter::Talk() // фунцкия Talk(), полностью зависит от mood и его возвращаемого значения 
{
    cout << "I'm a critter and I feel ";
    int mood = GetMood();
    if (mood > 15)
    {
        cout << "mad.\n";
    }
    else if (mood > 10)
    {
        cout << "frustrated.\n";
    }
    else if (mood > 5)
    {
        cout << "okay.\n";
    }
    else 
    {
        cout << "happy.\n";
    }
    PassTime();
}

void Critter::Eat(int food)
{
    cout << "Brruup.\n";
    m_Hunger -= food;
    if (m_Hunger < 0)
    {
        m_Hunger = 0;
    }
    PassTime(); // функция PassTime моделирует ход времени
}

void Critter::Play(int fun) // снижает уровень скуки тамагочи на величину, передаваемую в параметре fun. 
{
    cout << "Wheee!\n";
    m_Boredom -= fun;
    if (m_Boredom)
    {
        m_Boredom = 0;
    }
    PassTime();
}

int main()
{
    Critter crit;
    crit.Talk();
    int choice;
    do
    {
        cout << "\nCritter Caretaker\n\n";
        cout << "0 - Quit\n";
        cout << "1 - Listen to your critter\n";
        cout << "2 - Feed your critter\n";
        cout << "3 - Play with you critter\n\n";
        cout << "Choice: ";
        cin >> choice;
        switch (choice)
        {
        case 0:
            cout << "GoodBye.\n";
            break;
        case 1:
            crit.Talk();
            break;
        case 2:
            crit.Eat();
            break;
        case 3:
            crit.Play();
            break;
        default:
            cout << "\nSorry, but " << choice << " isn't a valid choice.\n";
        }
    } while (choice != 0);
    return 0;
}
