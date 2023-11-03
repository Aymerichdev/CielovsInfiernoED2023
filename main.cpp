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
    // cout << "Maxheap" << endl;
    // Maxheap heap;
    // heap.insert(1);
    // heap.insert(4);
    // heap.insert(6);
    // heap.insert(2);
    // heap.insert(8);
    // heap.print();

    HumanSinHeap* sinHeap = new HumanSinHeap(0);
    Human* h1 = new Human(1);
    Human* h2 = new Human(2);
    Human* h3 = new Human(3);
    h1->sins[0] = 5;
    h2->sins[0] = 3;
    h3->sins[0] = 1;
    sinHeap->insert(h1);
    sinHeap->insert(h2);
    sinHeap->insert(h3);
    sinHeap->print();
    TreeOfLife* tree2 = new TreeOfLife();
    HumanWorld* mundo = new HumanWorld(tree2);
    inferno* infierno = new inferno(mundo);
    mundo->generateRandomHumans(1000);
    for (int i = 0; i < 30; i++) {
        mundo->humans[i]->addSin(0, 50);
    }
    mundo->humans[15]->sins[0] = 80;
    infierno->condenation(0);
    cout << infierno->getsinners(0) << endl;
    cout << infierno->getaverage(0) << endl;
    cout << infierno->getminsin(0) << endl;
    cout << infierno->getmaxsin(0) << endl;
    infierno->print();
    cout << endl << endl;


    // Test for HumanWorld Struct
    cout << "HumanWorld" << endl;
    HumanWorld* world = new HumanWorld(tree);
    world->generateRandomHumans(300);
    // world->printHumans();
    tree->getRoot()->getHuman()->setState(1);
    tree->inOrder();
    // Test for state validation
    world->humans[149]->setState(1);
    world->humans[149]->printHuman();
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

    // Test for names, surnames, jobs, beliefs, countries
    cout << "Names, surnames, jobs, beliefs, countries" << endl;
    vector<string>* names = world->names;
    vector<string>* surnames = world->surnames;
    vector<string>* jobs = world->jobs;
    vector<string>* beliefs = world->beliefs;
    vector<string>* countries = world->countries;
    cout << "Names: " << endl;
    for (int i = 0; i < names->size(); i++) {
        cout << i << ": " << names->at(i) << endl;
    }

    cout << "Surnames: " << endl;
    for (int i = 0; i < surnames->size(); i++) {
        cout << i << ": " << surnames->at(i) << endl;
    }

    cout << "Jobs: " << endl;
    for (int i = 0; i < jobs->size(); i++) {
        cout << i << ": " << jobs->at(i) << endl;
    }

    cout << "Beliefs: " << endl;
    for (int i = 0; i < beliefs->size(); i++) {
        cout << i << ": " << beliefs->at(i) << endl;
    }

    cout << "Countries: " << endl;
    for (int i = 0; i < countries->size(); i++) {
        cout << i << ": " << countries->at(i) << endl;
    }

    cout << endl << endl;
    
    cout << "Dates" << endl;
    for (int i = 0; i < 10; i++) {
        cout << randomBirthdate() << endl;
    }
}
