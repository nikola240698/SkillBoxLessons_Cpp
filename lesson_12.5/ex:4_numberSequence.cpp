#include <iostream>

int main() {

    int numbers[] = {114, 111, 106, 107, 108, 105, 115, 108, 110, 109, 112, 113, 116, 117, 118};

    std::cout << "Program find start and repeating numbers in sequence of number" << std::endl;
    std::cout << std::endl;

    /* 
     * для решения будем сравнивать ожидаемую сумму последовательности
     * и получившуюся со всеми числами
     * при этом необходимо найти минимальное значение
     */
    
    int sumAll = 0;
    int min = numbers[0];
  
    // ищем минимальное значение в последовательности
    for (int i = 0; i < 15; i++ ) {
        if (min > numbers[i]) {
            min = numbers[i];
        }
        // не теряя лишнего времени сразу суммируем все числа
        sumAll += numbers[i];
    }

    std::cout << "The sequence starts with a number " << min << std::endl;

    /* 
     * ищем сумму алгебраической последовательности по известной формуле:
     * (полусумма первого и последнего члена отрезка последовательности на кол-во членов)
     *          (min + (min + 13))  
     *   sum =  ------------------ * 14
     *                   2
     * приводим все к упрощенной формуле                 
     */
    int sum = (2 * min + 13) * 7;

    // разницей м/у получившимися суммами и будет дублирующееся число
    int dublicateNum = sumAll - sum;

    std::cout << "Repeating number is " << dublicateNum << std::endl;    
    
    return 0;

}
