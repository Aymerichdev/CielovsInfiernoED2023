#include "Structs/Structs.h"

int main() {
    cout << "Hello, world!" << endl;

    // Test for TreeOfLife Struct
    TreeOfLife* tree = new TreeOfLife();
    tree->insert(new Human(1));
    tree->insert(new Human(4));
    tree->insert(new Human(6));
    tree->insert(new Human(2));
    tree->inOrder();
    cout << endl;
    tree->preOrder();

    // Test for Maxheap Struct
    Maxheap heap;
    heap.insert(1);
    heap.insert(4);
    heap.insert(6);
    heap.insert(2);
    heap.insert(8);
    heap.print();

    // Test for HumanWorld Struct
    HumanWorld* world = new HumanWorld();
    world->generateRandomHumans(10000);
    world->generateRandomHumans(1);
    world->generateRandomHumans(1);
    world->printHumans();

}
