struct HeavenHashTable {
    
    HeavenHashTable() : table_size(1000), table(1000, nullptr) {

        for (int i = 0; i < 1000; i++) {
            table[i] = new AVLNode();
        }
    }

    
    // Función de hash personalizada que utiliza el ID del humano
    int hash(int id) {
        return id / 100;
    }

    void insert(Human* human) {
        int index = hash(human->id);
        table[index] = insert(table[index], human);
        int ahpapi = table[index]->key;
        if (ahpapi == 0)
        deleteNode(table[index], 0);
    }

    int search(int id) {
        int index = id % table_size;
        return search(table[index], id);
    }

    void print() {
        for (int i = 0; i < table_size; i++) {
            std::cout << i << ": ";
            if (table[i] != nullptr)
                inOrderTraversal(table[i]);
            std::cout << std::endl;
        }
    }

    // Funcion que da la cantidad de elementos en el arbol
    int size(AVLNode* root) {
        if (root == nullptr) return 0;
        return size(root->left) + size(root->right) + 1;
    }

    AVLNode* insert(AVLNode* root, Human* human) {
        if (root == nullptr) return new AVLNode(human);

        if (human->id < root->key)
            root->left = insert(root->left, human);
        else if (human->id > root->key)
            root->right = insert(root->right, human);
        return root;
    }

    int search(AVLNode* root, int id) {
        if (root == nullptr) return -1;

        if (id == root->key)
            return root->key;
        else if (id < root->key)
            return search(root->left, id);
        else
            return search(root->right, id);
    }

    int table_size;
    std::vector<AVLNode*> table;
};