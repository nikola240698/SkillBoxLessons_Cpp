#include <iostream>
#include <vector>
#include <ctime>

#define TREE_COUNT 5        // кол-во деревьев

class Branch {

    Branch* parent = nullptr;
    std::vector<Branch*> children;
    std::string nameElf;

public:

    // инициализация поелй класса, по умолчанию родитель nullptr
    Branch(Branch* parentBranch = nullptr)
        : parent(parentBranch), nameElf("None") {}


    // метод добавления дочерних веток
    void addChildren(Branch* child) {
        children.push_back(child);
    }

    // метод получения старшей ветки
    Branch* getParent() const {
        return parent;
    }

    // метод получения дочерний ветки
    std::vector<Branch*> getChildren() const {
        return children;
    }

    // метод назначения имени эльфа
    void setNameElf(const std::string &name) {
        nameElf = name;
    }

    // метод получения имени эльфа
    std::string getNameElf() const {
        return nameElf;
    }

    // получение указателя на самую старшую ветку
    Branch* getTopBranch() {
        // метод из подсказки
        //Если это дерево
        if (parent == nullptr) return nullptr;
        //Если это средняя ветка
        if (parent->parent == nullptr) return this;
        //Если это маленькая ветка
        return parent->getTopBranch();
    }

    // метод поиска эльфа
    Branch* findElf(const std::string &name) {
        // если искомый эльф на этой ветке
        if (nameElf == name) {
            return this;
        }
        // перебираем все дочерни ветки
        for (int i = 0; i < children.size(); ++i) {
            // определяем результат поиска последующей ветки
            Branch* result = children[i]->findElf(name);
            // если успешно нашли, то останавливаемся
            if (result != nullptr) {
                return result;
            }

        }
        // иначе возвращаем нулевой указатель
        return nullptr;
    }

    // метод определения наличия эльфа в доме
    bool haveElf() const {
        return nameElf != "None";
    }

    // метод подсчета эльфов на ветках
    int elfCountOnBranch() const {
        // смотрим есть ли эльф в текущем доме
        int count = haveElf() ? 1 : 0;
        // пробегаемся по остальным веткам рекурсивно
        for (int i = 0; i < children.size(); ++i) {
            count += children[i]->elfCountOnBranch();
        }
        return count;
    }

    // метод заселения эльфов рекурсивный
    void setElfOnBranch(int numberTree, int &numberHouse) {
        // проверяем, что находимся на ветке
        if (parent != nullptr) {
            std::string name;
            std::cout << "Tree " << numberTree << ", house " << numberHouse
                << ". Inout the Elf name -> ";
            std::getline(std::cin, name);

            setNameElf(name);
            // следующий дом
            ++numberHouse;
        }
        for (int i = 0; i < children.size(); ++i) {
            children[i]->setElfOnBranch(numberTree, numberHouse);
        }

    }
};

// функция рандомного значения по границам
int randomRange(const int min,const int max) {
    return min + std::rand() % (max - min + 1);
}

int main() {

    std::srand(std::time(nullptr));

    // создаем вектор деревьев
    std::vector<Branch*> trees;

    for (int i = 0; i < TREE_COUNT; ++i) {
        // создаем указатель на дерево
        Branch* tree = new Branch(nullptr);
        // рандомно определяем кол-во больших веток
        int bigBranchCount = randomRange(3, 5);
        // создаем большие ветки
        for (int j = 0; j < bigBranchCount; ++j) {
            Branch* bigBranch = new Branch(tree);
            // добавляем большие ветки в дочерние дерева
            tree->addChildren(bigBranch);
            // рандомно определяем кол-во средних веток
            int childBranchCount = randomRange(2, 3);
            // создаем средние ветки
            for (int k = 0; k < childBranchCount; ++k) {
                Branch* childBranch = new Branch(bigBranch);
                // добавляем средние ветки в дочерние к большим
                bigBranch->addChildren(childBranch);
            }
        }
        // заполняем вектор деревьев
        trees.push_back(tree);
    }

    // заселяем эльфов
    for (int i = 0; i < TREE_COUNT; ++i) {
        // начинаем с первого дома
        int numberHouse = 1;
        std::cout << i + 1 << " tree colonization" << std::endl;
        trees[i]->setElfOnBranch(i + 1, numberHouse);
    }

    // ищем эльфа по имени
    std::string nameFind;
    std::cout << "Input the name of the elf you are looking for ->";
    std::getline(std::cin, nameFind);

    // ветка для поиска
    Branch* findElfBranch = nullptr;

    // проверяем по всем деревьям
    for (int i = 0; i < trees.size(); ++i) {
        findElfBranch = trees[i]->findElf(nameFind);
        // условие нахождения на этом дереве
        if (findElfBranch != nullptr) {
            break;
        }
    }
    // если не нашлось совсем его
    if (findElfBranch == nullptr) {
        std::cout << "An elf named " << nameFind << " wasn't found" << std::endl;
    } else {
        // получив указатель ветки, на которой живет эльф,
        // получаем указатель на самую большую ветку
        Branch* bigBranch = findElfBranch->getTopBranch();
        // считаем всех эльфов на ветке
        int elfCount = bigBranch->elfCountOnBranch();
        // вычитаем самого эльфа для отображения кол-ва соседей
        int neighboursCount = elfCount - 1;
        // выводим резуьтат
        std::cout << "Number of elf neighbors " << nameFind << " - "
            << neighboursCount << std::endl;
    }
    // очищаем память
    for (int i = 0; i < trees.size(); ++i) {
        delete trees[i];
    }
  
    return 0;
}










