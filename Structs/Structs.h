// Includes all necessary libraries, this will be "inherit" by all files that include this file or files included in this file.
#include <iostream>
#include <vector>
#include <cmath>

// Declare namespace
using namespace std;

// Global variables (if needed)

// Struct headers
struct Human;
struct HumanNode;
struct TreeOfLife;
struct Maxheap;
struct HumanWorld;

// Function headers

// Structs
struct Human{
    // Attributes
    int id, generation, arrayPosition, state; // State has three values: 0 = alive, 1 = hell, 2 = heaven
    // TODO: check if it would be better to use an int index for country, belief and job
    string name, surname, country, belief, job, email, birthdate;
    int sins[7];
    vector<Human*> friends;
    int socialNetworks[7];

    // Constructors
    Human(){
        id = 0;
        generation = 0;
        arrayPosition = 0;
        state = 0;
        name = "";
        surname = "";
        country = "";
        belief = "";
        job = "";
        email = "";
        birthdate = "";
        for(int i = 0; i < 7; i++){
            sins[i] = 0;
            socialNetworks[i] = 0;
        }
    }

    // For testing purposes
    Human(int _id){
        id = _id;
        generation = 0;
        arrayPosition = 0;
        state = 0; // 1 dead 2 saved 
        name = "";
        surname = "";
        country = "";
        belief = "";
        job = "";
        email = "";
        birthdate = "";
        for(int i = 0; i < 7; i++){
            sins[i] = 0;
            socialNetworks[i] = 0;
        }
    }

    Human(int _id, int _generation, string _name, string _surname, string _country, string _belief, string _job, string _email, string _birthdate, vector<Human*> _friends){
        // TODO: check if int _friends is correct or if it should be filled within this struct (in other words, it should recieve the human vector and randomize it here)
        id = _id;
        generation = _generation;
        arrayPosition = 0;
        state = 0;
        name = _name;
        surname = _surname;
        country = _country;
        belief = _belief;
        job = _job;
        email = _email;
        birthdate = _birthdate;
        for(int i = 0; i < 7; i++){
            sins[i] = 0;
            socialNetworks[i] = 0;
        }
        friends = _friends;
    }

    // Getters & Setters
    int getId(){
        return id;
    }

    int getGeneration(){
        return generation;
    }

    int getArrayPosition(){
        return arrayPosition;
    }

    int getState(){
        return state;
    }

    void setState(int _state){
        state = _state;
    }

    void setArrayPosition(int _arrayPosition){
        arrayPosition = _arrayPosition;
    }

    string getName(){
        return name;
    }

    string getSurname(){
        return surname;
    }

    string getCountry(){
        return country;
    }

    string getBelief(){
        return belief;
    }

    string getJob(){
        return job;
    }

    string getEmail(){
        return email;
    }

    string getBirthdate(){
        return birthdate;
    }

    int getSin(int index){
        return sins[index];
    }

    int getSocialNetwork(int index){
        return socialNetworks[index];
    }

    vector<Human*> getFriends(){
        return friends;
    }

    void addSin(int index, int value){
        sins[index] += value;
    }

    void addSocialNetwork(int index, int value){
        socialNetworks[index] += value;
    }

    void addFriend(Human * friendToAdd){
        friends.push_back(friendToAdd);
    }
};

struct HumanNode{
    Human* human;
    HumanNode* left;
    HumanNode* right;

    HumanNode(){
        human = NULL;
        left = NULL;
        right = NULL;
    }

    HumanNode(Human* _human){
        human = _human;
        left = NULL;
        right = NULL;
    }

    HumanNode(Human* _human, HumanNode* _left, HumanNode* _right){
        human = _human;
        left = _left;
        right = _right;
    }

    int getId(){
        return human -> getId();
    }

    Human* getHuman(){
        return human;
    }

    HumanNode* getLeft(){
        return left;
    }

    HumanNode* getRight(){
        return right;
    }

    void setHuman(Human* _human){
        human = _human;
    }

    void setLeft(HumanNode* _left){
        left = _left;
    }

    void setRight(HumanNode* _right){
        right = _right;
    }
};

struct TreeOfLife{
    HumanNode* root;

    TreeOfLife(){
        root = NULL;
    }

    TreeOfLife(HumanNode* _root){
        root = _root;
    }

    HumanNode* getRoot(){
        return root;
    }

    void insert(Human* _human){
        root = insert(_human, root);
    }

    HumanNode* insert(Human* _human, HumanNode* _node){
        if (_node == NULL)
            return new HumanNode(_human);
        else if (_node -> getId() < _human -> getId())
            _node -> setRight(insert(_human, _node -> getRight()));
        else if (_node -> getId() >= _human -> getId())
            _node -> setLeft(insert(_human, _node -> getLeft()));
        return _node;
    }

    int sizeTree(HumanNode* _human){
        if (_human == NULL || _human -> getHuman() == NULL)
            return 0;
        else
            return 1 + sizeTree(_human -> getLeft()) + sizeTree(_human -> getRight());
    }

    int sizeTree(){
        return sizeTree(root);
    }

    void inOrder(){
        inOrder(root);
    }

    void preOrder(){
        preOrder(root);
    }

    void inOrder(HumanNode* _node){
        if (_node != NULL){
            inOrder(_node -> getLeft());
            cout << _node -> getId() << ",";
            inOrder(_node -> getRight());
        }
    }

    void preOrder(HumanNode* _node){
        if (_node != NULL){
            cout << _node -> getId() << "  ";
            preOrder(_node -> getLeft());
            preOrder(_node -> getRight());
        }
    }

    void emptyTree(HumanNode* _node){
        if (_node != NULL){
            emptyTree(_node -> getLeft());
            emptyTree(_node -> getRight());
            _node->setRight(NULL);
            _node->setLeft(NULL);
            delete _node;
        }
    }

    void emptyTree(){
        emptyTree(root);
        root = NULL;
    }
};

struct HumanSinHeap {
    std::vector<Human*> heap;
    int choosenSin;

    // Constructor
    HumanSinHeap() {
        heap = {};
        choosenSin = 0;
    }

    HumanSinHeap(int _choosenSin) {
        heap = {};
        choosenSin = _choosenSin;
    }


    void heapifyUp(int index) {
        int parentIndex = (index - 1) / 2;
        while (index > 0 && heap[index]->getSin(choosenSin) > heap[parentIndex]->getSin(choosenSin)) {
            std::swap(heap[index], heap[parentIndex]);
            index = parentIndex;
            parentIndex = (index - 1) / 2;
        }
    }

    void heapifyDown(int index) {
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int largest = index;

        if (leftChild < heap.size() && heap[leftChild]->getSin(choosenSin)> heap[largest]->getSin(choosenSin)) {
            largest = leftChild;
        }
        if (rightChild < heap.size() && heap[rightChild]->getSin(choosenSin) > heap[largest]->getSin(choosenSin)) {
            largest = rightChild;
        }

        if (largest != index) {
            std::swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }

    void insert(Human* human) {
        heap.push_back(human);
        heapifyUp(heap.size() - 1);
    }

    Human* extractMax() {
        if (heap.empty()) {
            throw std::out_of_range("Heap is empty");
        }

        Human* maxValue = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);

        return maxValue;
    }

    bool isEmpty() const {
        return heap.empty();
    }

    void print() const {
        for (int i = 0; i < heap.size(); ++i) {
            std::cout << heap[i]->getId() << " ";

        }
        std::cout << std::endl;
    }
};

struct HumanWorld{
    // Attributes
    // Sorted by id
    Human* humans[100000];
    vector<int> humansIds;
    int humansCount;
    TreeOfLife* treeOfLife;

    HumanWorld(){
        humansCount = 0;
        srand(time(0));
        for (int i = 0; i < 100000; i++){
            humans[i] = NULL;
            humansIds.push_back(i);
        }
        treeOfLife = new TreeOfLife();
    }

    HumanWorld(TreeOfLife* _treeOfLife){
        humansCount = 0;
        srand(time(0));
        for (int i = 0; i < 100000; i++){
            humans[i] = NULL;
            humansIds.push_back(i);
        }
        treeOfLife = _treeOfLife;
    }

    void addHuman(Human* humanToAdd){
        if (humansCount == 0){
            humans[0] = humanToAdd;
            humanToAdd -> setArrayPosition(0);
            humansCount++;
            return;
        }
        int id = humanToAdd -> getId();
        for (int i = 0; i < humansCount; i++){
            if (humans[i]->getId() < id){
                continue;
            }else if (humans[i]->getId() > id){
                for (int j = humansCount; j > i; j--){
                    humans[j] = humans[j - 1];
                    humans[j] -> setArrayPosition(j);
                }
                humans[i] = humanToAdd;
                humanToAdd -> setArrayPosition(i);
                humansCount++;
                return;
            }
        }
        humans[humansCount++] = humanToAdd;
    }

    Human* getHuman(int id){
        for (int i = 0; i < humansCount; i++){
            if (humans[i]->getId() == id){
                return humans[i];
            }
        }
        return NULL;
    }

    Human* generateRandomHuman(){
        // TODO: has to be changed to generate a random human, including all attributes
        int id = rand() % humansIds.size();
        int idHuman = humansIds[id];
        humansIds.erase(humansIds.begin() + id);
        return new Human(idHuman);
    }

    int getTreeSize(){
        int treeSize = humansCount * 0.01;
        while (!(treeSize && (0 == (treeSize & (treeSize - 1)))))
            treeSize++;
        if (treeSize != 1) treeSize--;
        cout << "Tree size: " << treeSize << endl;
        return treeSize;
    }

    void insertTree(Human* humanArray[], int start, int end, int size, int levelMax, int level = 0){
        if (start >= end || level >= levelMax)
            return;
        int middle = (start + end) / 2;
        // Check if the middle is a valid human, in other words, if it is not in hell or heaven
        while (humanArray[middle]->getState() != 0){
            middle--;
            if (middle < start){
                return;
            }
        }
        treeOfLife->insert(humanArray[middle]);
        level++;
        insertTree(humanArray, start, middle, size, levelMax, level);
        insertTree(humanArray, middle + 1, end, size, levelMax, level);
    }

    void buildTree(){
        treeOfLife->emptyTree();
        int treeSize = getTreeSize();
        insertTree(humans, 0, humansCount - 1, treeSize, (int)log2(treeSize + 1));
    }

    void generateRandomHumans(int amount){
        if (amount + humansCount > 100000){
            cout << "Not enough space for " << amount << " humans" << endl;
            return;
        }
        for (int i = 0; i < amount; i++){
            addHuman(generateRandomHuman());
        }
        buildTree();
    }

    void printHumans(){
        for (int i = 0; i < humansCount; i++){
            if (humans[i] == NULL){
                break;
            }else{
                // cout << i << " - " << humans[i]->getId() << endl;
                cout << humans[i]->getId() <<  ",";
            }
        }
        cout << endl;
    }
};

// Includes of structs that use this one as sort of a "base struct"
#include "Inferno.h"
// Includes of structs that use this one as sort of a "base struct"

// Function logic
