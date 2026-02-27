// practice.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>

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





void addNode(int x, BTreeNode* root) {

    //заменеям вызов функции, на переприсвивание корневого узла



    BTreeNode** cur = &root; //указатель на указатель на узел



    while (*cur) {

        BTreeNode& node = **cur; //ссылка, чтобы не делать "->"

        if (x < node.field) {

            cur = &node.left;

        }

        else if (x > node.field) {

            cur = &node.right;

        }

        else {

            return;

        }

    }

    *cur = new BTreeNode();

    (*cur)->field = x;

    (*cur)->left = NULL;

    (*cur)->right = NULL;

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



void treePrintRecursively(BTreeNode* tree, string move) {



    if (tree != NULL) { //Пока не встретится пустой узел



        cout << move << "my val is " << tree->field

            << endl; //Отображаем корень дерева



        move += "\t";



        cout << move << " left: " << endl;



        treePrintRecursively(tree->left,

            move); //Рекурсивная функция для левого поддерева



        cout << move << " right: " << endl;



        treePrintRecursively(tree->right,

            move); //Рекурсивная функция для правого поддерева

    }

}



#endif

-------------------------------------------------- -

#include <iostream>

#include "BTree.h"

using namespace std;



void deleteSingleRootTree()

{

    BTreeNode* root = addNodeRecursively(8, NULL);

    treePrintRecursively(root, "");

    cout << "\n After  delete: ";



    root = deleteNode(8, root);

    treePrintRecursively(root, "");

}





void deleteRootElementTree()

{

    BTreeNode* root = addNodeRecursively(8, NULL);

    addNodeRecursively(5, root);

    addNodeRecursively(10, root);

    treePrintRecursively(root, "");

    cout << "\n After  delete: ";



    root = deleteNode(8, root);

    treePrintRecursively(root, "");

}



void deleteNodeInTree()

{

    BTreeNode* root = addNodeRecursively(8, NULL);



    addNodeRecursively(5, root);

    addNodeRecursively(10, root);

    addNodeRecursively(11, root);

    addNodeRecursively(2, root);

    addNodeRecursively(7, root);



    treePrintRecursively(root, "");



    BTreeNode* resNode = find(5, root);



    root = deleteNode(5, root);



    treePrintRecursively(root, "");

}



void findWithParentTest()

{

    BTreeNode* root = addNodeRecursively(8, NULL);

    addNodeRecursively(10, root);

    addNodeRecursively(2, root);

    addNodeRecursively(7, root);

    addNode(140, root);

    addNodeRecursively(6, root);





    BTreeNode* nullPtr(0);

    BTreeNode** parent = &nullPtr;



    BTreeNode* resNode2 = findWithParent(5, root, parent);



    if (resNode2)

    {

        cout << "\n Node: " << resNode2->field;

        if (!(*parent))

        {

            cout << "\n Parent is absent ";

        }

        else

        {

            cout << "\n Parent: " << (*parent)->field;

        }

    }

    else

    {

        cout << "\n Node not found ";

    }

}



int main()

{

    cout << "\n deleteNodeInTree TEST\n";

    // deleteNodeInTree();



    cout << "\n deleteSingleRootTree TEST\n";

    // deleteSingleRootTree();



    cout << "\n delete RootTree TEST\n";

    deleteRootElementTree();

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
