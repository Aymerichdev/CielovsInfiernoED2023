#include "Structs/Structs.h"

int main() {
    cout << "Hello, world!" << endl;

    // Test for TreeOfLife Struct
    cout << "TreeOfLife" << endl;
    TreeOfLife* tree = new TreeOfLife();
    tree->insert(new Human(1));
    tree->insert(new Human(4));
    tree->insert(new Human(6));
    tree->insert(new Human(2));
    tree->inOrder();
    cout << endl;
    tree->preOrder();
    cout << endl;
    tree->emptyTree();
    tree->inOrder();
    cout << endl << endl;

    // Test for Maxheap Struct
    cout << "Maxheap" << endl;
    Maxheap heap;
    heap.insert(1);
    heap.insert(4);
    heap.insert(6);
    heap.insert(2);
    heap.insert(8);
    heap.print();
    cout << endl << endl;


    // Test for HumanWorld Struct
    cout << "HumanWorld" << endl;
    HumanWorld* world = new HumanWorld(tree);
    world->generateRandomHumans(300);
    tree->getRoot()->getHuman()->setState(1);
    tree->inOrder();
    // Test for state validation
    world->humans[149]->setState(1);
    world->humans[150]->setState(1);
    world->humans[151]->setState(1);
    world->humans[152]->setState(1);
    cout << endl << "IDS: ";
    cout << world->humans[149]->getId() << ", " << world->humans[150]->getId() << ", " << world->humans[151]->getId() << ", " << world->humans[152]->getId() << endl;
    world->generateRandomHumans(1);
    cout << "Root: " << tree->getRoot()->getId() << endl;
    cout << world->humans[(world->humansCount - 1) / 2]->getId() << endl; // humans[50]
    cout << tree->getRoot()->getId() << endl;
    tree->inOrder();
    // world->printHumans();
    cout << endl;
    world->generateRandomHumans(300);
    tree->inOrder();
    cout << endl;
    world->generateRandomHumans(500);
    tree->inOrder();
    cout << endl << endl;
}
