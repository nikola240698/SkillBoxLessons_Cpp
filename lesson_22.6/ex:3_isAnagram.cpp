#include <iostream>
#include <string>
#include <map>

// разбиваем строку на словарь, где
// ключ - буква, значение - количество букв в слове
std::map<char, int> stringToMap(std::string &str) {
    // создаем словарь
    std::map<char, int> dict;
    // читаем строку посимвольно
    for (int i = 0; i < str.length(); ++i) {
        //опускаем заглавные в прописные, так как сравниваем буквы, а не их размер
        if (std::isupper(str[i])) {
            str[i] = str[i] + 32;
        }        
        // если у нас пустой словарь
        if (dict.empty()) {
            dict.insert(std::pair<char, int>(str[i], 1));
        } else {
            // если есть уже такая буква, то увеличиваем значение на один
            if (dict.find(str[i]) != dict.end()) {
                dict[str[i]] = dict.find(str[i])->second + 1;
            } else {
                // если первый раз такой ключ, то просто добавляем его
                dict.insert(std::pair<char, int>(str[i], 1));
            }
        }
    }
    // возвращаем наш словарь
    return dict;
}

// функция проверки двух строк на аннограмму
bool isAnagram(std::string &word, std::string &anagram) {
    // создаем два словаря
    std::map<char, int> wordMap = stringToMap(word);
    std::map<char, int> anagramMap = stringToMap(anagram);
    // создаем два итератора на словари для сравнения их
    std::map<char, int>::iterator wordIt = wordMap.begin();
    std::map<char, int>::iterator anagramIt = anagramMap.begin();
    // флаг схожести ключа и значения
    bool similar = false;
    // читаем словари по порядку
    for (; wordIt != wordMap.end();) {
        // если совпадают и ключ и значение, то поднимаем флаг
        if (wordIt->first == anagramIt->first
                && wordIt->second == anagramIt->second ) {
            similar = true;
        } else {
            // если не совпали - опускаем
            similar = false;
        }
        // если уже флаг опущен, дальше нет смысла искать
        if (!similar) {
            return similar;
        }
        // переходим на следующий ключ
        ++wordIt;
        ++anagramIt;
    }
    // возвращаем успех
    return similar;
}

int main() {
    // приветствие
    std::cout << "A Program for comparing two words" << std::endl;
    std::cout << "returning TRUE if the words are anagrams," << std::endl;
    std::cout << "or FALSE if they are not" << std::endl << std::endl;

    // строки для ввода данных
    std::string word, anagram;

    // гоняем по кругу программу
    while (true) {
        // вводим первую строку
        std::cout << "First word ->";
        std::getline(std::cin, word);
        // вводим вторую строку
        std::cout << "Second word ->";
        std::getline(std::cin, anagram);
        // сразу в консоль выводим результат в булевом виде
        std::cout << std::boolalpha << isAnagram(word, anagram) << std::endl;
    }

    return 0;
}
