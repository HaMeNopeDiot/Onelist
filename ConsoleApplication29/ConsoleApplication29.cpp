#include "Header.h"
#include <iostream>

const int exitNumber = 10;

int main()
{
    setlocale(LC_ALL, "Russian");
    Tlist userList;
    init(userList);
    int c;
    do
    {
        std::cout << "Меню:" << '\n';
        std::cout << "1. Добавление элемента в начало списка." << '\n';
        std::cout << "2. Добавление элемента в конец списка." << '\n';
        std::cout << "3. Добавление элемента после заданного звена (по значению)." << '\n';
        std::cout << "4. Удаление элемента из начала списка." << '\n';
        std::cout << "5. Удаление элемента из конца списка." << '\n';
        std::cout << "6. Удаление элемента после звена (по значению)." << '\n';
        std::cout << "7. Очистка списка." << '\n';
        std::cout << "8. Печать списка." << '\n';
        std::cout << "9. Текст задания." << '\n';
        std::cout << "10. Выход." << '\n';
        std::cout << "11. Задачи на дом" << '\n';
        std::cin >> c;
        int numb, fnumb;
        switch (c)
        {
        case 1:
            std::cout << "| Напишите число, которое нужно добавить:";
            std::cin >> numb;
            addToHead(userList, numb);
            break;
        case 2:
            std::cout << "| Напишите число, которое нужно добавить:";
            std::cin >> numb;
            addToTail(userList, numb);
            break;
        case 3:
            std::cout << "| Напишите число, которое нужно добавить и первое число, после которого нужно поставить новое число:";
            std::cin >> numb >> fnumb;
            AddAfterNumber(userList, fnumb, numb);
            break;
        case 4:
            deletefromHead(userList);
            break;
        case 5:
            deletefromTail(userList);
            break;
        case 6:
            std::cout << "| Напишите число, после которого нужно удалить:";
            std::cin >> fnumb;
            deleteAfterNumber(userList, fnumb);
            break;
        case 7:
            clear(userList);
            break;
        case 8:
            printList(userList);
            break;
        case 9:
            deleteTwoZeroes(userList);
            std::cout << "Введите число которое нужно добавить:";
            std::cin >> numb;
            TwoPositiveNumbers(userList, numb);
            break;
        case 10:
            std::cout << "Завершение работы.";
            break;
        case 11:
            std::cout << "Введите число e:";
            int e;
            std::cin >> e;
            DoubleE(userList, e);
        default:
            std::cout << "Некорректный ввод!";
            break;
        }
    } while (c != exitNumber);
    clear(userList);
    return 0;
}

//ya caheli
