#include <iostream>

void showArray(int arr[][6]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 6; j++) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void packGuest(int arr[][6], int pack[][6]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 6; j++) {
            arr[i][j] += pack[i][j];
        }
    }
    showArray(arr);
}

int main() {

    // создаем "массив" гостей
    // по типу (V - VIP):
    // V V G G G G
    // G G G G G G
    int guests[2][6] = {{0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}};
    std::cout << "Places for guests:" << std::endl;
    showArray(guests);

    // добавляем столовые приборы
    std::cout << "Let's add cutlery" << std::endl;
    int cutlery[2][6] = {{3, 3, 3, 3, 3, 3}, {3, 3, 3, 3, 3, 3}};
    packGuest(guests, cutlery);

    // не забудем про маленькие ложечки для ВИП персон
    std::cout << "Special attention to VIPs" << std::endl;
    int spoon[2][6] = {{1, 1, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}};
    packGuest(guests, spoon);

    // добавляем тарелки
    std::cout << "Let's add a plate to everyone" << std::endl;
    int plate[2][6] = {{2, 2, 2, 2, 2, 2}, {2, 2, 2, 2, 2, 2}};
    packGuest(guests, plate);

    // десертные тарелочки ВИП-персонам
    std::cout << "Dessert plates for the \"special\"" << std::endl;
    int dessert[2][6] = {{1, 1, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}};
    packGuest(guests, dessert);

    // и, наконец, стулья
    std::cout << "Let's add a chair to everyone" << std::endl;
    int chairs[2][6] = {{1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1}};
    packGuest(guests, chairs);

    std::cout << "Everything is ready for the celebration" << std::endl;
    std::cout << "Oh, no, the lady in seat number 5 came with a child" << std::endl;
    std::cout << "They also need a chair" << std::endl;
    guests[0][4] += 1;
    showArray(guests);

    std::cout << "Someone stole a spoon from seat 3 of row 2" << std::endl;
    guests[1][2] -= 1;
    showArray(guests);

    std::cout << "A VIP shared his spoon" << std::endl;
    guests[0][1] -= 1;
    guests[1][2] += 1;
    showArray(guests);

    std::cout << "Because of this, the waiter took the dessert plate away from" << std::endl;
    guests[0][1] -= 1;
    showArray(guests);

    std::cout << "The evening of celebration was a success" << std::endl;

    return 0;
}
