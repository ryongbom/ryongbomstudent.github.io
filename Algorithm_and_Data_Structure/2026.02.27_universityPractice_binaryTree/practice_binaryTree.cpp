// practice.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <queue>

using namespace std;

struct Data {
    int key;
    string name;
};

struct BTreeNode {
    Data myData;
    BTreeNode* left = nullptr; // левый потомок
    BTreeNode* right = nullptr; // правый потомок
};

BTreeNode* find(int theKey, BTreeNode* tree) {
    if (tree == nullptr)
        return nullptr;
    if (theKey < tree->myData.key)
        return find(theKey, tree->left);
    if (theKey > tree->myData.key)
        return find(theKey, tree->right);
    return tree;
}

BTreeNode* addNodeRecursively(Data theData, BTreeNode* tree) {
    if (tree == nullptr) { // Если дерева нет, то формируем корень
        tree = new BTreeNode(); // память под узел
        tree->myData = theData;
        return tree;
    }

    else if (theData.key < tree->myData.key) // условие добавление левого потомка
        tree->left = addNodeRecursively(theData, tree->left);
    else // условие добавление правого потомка
        tree->right = addNodeRecursively(theData, tree->right);
    return tree;
}

BTreeNode* findWithParent(int theKey, BTreeNode* tree, BTreeNode** outParent) {
    if (tree == nullptr)
        return nullptr;
    if (theKey < tree->myData.key)
    {
        (*outParent) = tree;
        return findWithParent(theKey, tree->left, outParent);
    }
    if (theKey > tree->myData.key)
    {
        (*outParent) = tree;
        return findWithParent(theKey, tree->right, outParent);
    }
    return tree;
}

BTreeNode* deleteNode(int x, BTreeNode* tree) {
    BTreeNode** parent = &tree;
    BTreeNode* node2Del = findWithParent(x, tree, parent); // поиск узла для удаления и его родителя
    if (!node2Del)   return tree;


    BTreeNode* tempNode;
    // 0. У удаляемого узла нет потомков        
    if (node2Del->right == nullptr && node2Del->left == nullptr) {
        if (*parent == node2Del)//если дерево из одного корня
        {
            delete node2Del;
            return nullptr;
        }
        if ((*parent)->myData.key < node2Del->myData.key)
        {
            (*parent)->right = nullptr;
        }
        else {
            (*parent)->left = nullptr;
        }
        delete node2Del;
        return tree;
    }
    // 1. У удаляемого узла нет правого потомка
    if (node2Del->right == nullptr) {
        tempNode = node2Del->left;
        //копируем данные левого потомка на место удаляемого узла, других потомков у
        //него всё равно нет
        node2Del->myData.key = tempNode->myData.key;
        node2Del->left = tempNode->left;
        node2Del->right = tempNode->right;
        //удалеям остатки от левого потомка
        delete tempNode;
        return tree;
    }
    // 2. У удаляемого узла есть правый потомок, у которого нет левого потомка
    if (node2Del->right->left == nullptr) {
        tempNode = node2Del->right;
        //копируем данные из правого потомка
        node2Del->myData.key = tempNode->myData.key;
        node2Del->right = tempNode->right;
        //левый нас не интересует: 1) у tempNode его и так нет; 2) у node2Del может
        //и быть, но он заведомо меньше всех с правой стороны
        delete tempNode;
        return tree;
    }
    // 3. У удаляемого узла есть правый потомок, у которого есть левый потомок
    //Так как все значения справа от удаляемого элемента больше или равны значению
    //самого узла, то ...
    //... мы должны поместить на место удаляемого узел,  значения которых меньше
    //или равны любому узлу справа от него. Для этого нам необходимо найти
    //наименьшее значение в правом поддереве. Поэтому мы берем крайний левый узел
    //правого поддерева
    BTreeNode* tempNodeParent = node2Del->right;
    tempNode = node2Del->right->left;
    while (tempNode->left != nullptr) {
        tempNodeParent = tempNode;
        tempNode = tempNode->left;
    }
    //Теперь в tempNode элемент с минимальным значением, и копируем значение
    node2Del->myData.key = tempNode->myData.key;
    //перед удалением tempNode необходимо позаботится о его правом потомке, левого
    //у него и так нет: правый потомок займёт место удаляемого
    tempNodeParent->left = tempNode->right;
    delete tempNode;
    return tree;
}

// Функция для обхода дерева в ширину

void BFS(BTreeNode* root) {
    if (root == nullptr) return;
    std::queue<BTreeNode*> queue;
    queue.push(root);
    while (!queue.empty()) {
        BTreeNode* current = queue.front();
        queue.pop();
        cout << current->myData.key << " ";
        if (current->left != nullptr) {
            queue.push(current->left);
        }
        if (current->right != nullptr) {
            queue.push(current->right);
        }
    }
}

int main() {

    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
