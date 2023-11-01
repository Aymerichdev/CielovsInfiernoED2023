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

    Maxheap heap;
    heap.insert(1);
    heap.insert(4);
    heap.insert(6);
    heap.insert(2);
    heap.insert(8);
    heap.print();

    HumanSinHeap sinHeap = HumanSinHeap(0);
    Human* h1 = new Human(1);
    Human* h2 = new Human(2);
    Human* h3 = new Human(3);
    h1->sins[0] = 5;
    h2->sins[0] = 3;
    h3->sins[0] = 1;
    sinHeap.insert(h1);
    sinHeap.insert(h2);
    sinHeap.insert(h3);
    sinHeap.print();
    inferno inferno;
    inferno.Demons[0]->push_back(sinHeap);
    inferno.Demons[4]->push_back(sinHeap);
    inferno.print();


}
