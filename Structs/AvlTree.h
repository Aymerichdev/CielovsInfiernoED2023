// Definición de un nodo AVL
struct AVLNode {
    Human* human;
    int key;
    int height;
    AVLNode* left;
    AVLNode* right;

    AVLNode(){
        human = nullptr;
        key = 0;
        height = 0;
        left = nullptr;
        right = nullptr;
    }

    AVLNode(Human* human_) : human(human_) , key(human->id), height(1), left(nullptr), right(nullptr) {}
};
//Funcion que cuenta la cantidad de elementos en el arbol
int sizeavl(AVLNode* root) {
    if (root == nullptr) return 0;
    return sizeavl(root->left) + sizeavl(root->right) + 1;
}
// Función para calcular la altura de un nodo
int getHeight(AVLNode* node) {
    return (node != nullptr) ? node->height : 0;
}

// Función para calcular el factor de equilibrio de un nodo
int getBalance(AVLNode* node) {
    if (node == nullptr) return 0;
    return getHeight(node->left) - getHeight(node->right);
}

// Función para rotar a la derecha
AVLNode* rotateRight(AVLNode* y) {
    AVLNode* x = y->left;
    AVLNode* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = std::max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = std::max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

// Función para rotar a la izquierda
AVLNode* rotateLeft(AVLNode* x) {
    AVLNode* y = x->right;
    AVLNode* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = std::max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = std::max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

// Función para insertar un nodo en el árbol AVL
AVLNode* insertavl(AVLNode* root, Human* human) {
    int key = human->id;
    if (root == nullptr) return new AVLNode(human);

    if (key < root->key)
        root->left = insertavl(root->left, human);
    else if (key > root->key)
        root->right = insertavl(root->right, human);
    else
        return root;  // No se permiten claves duplicadas

    root->height = 1 + std::max(getHeight(root->left), getHeight(root->right));

    // Calcula el factor de equilibrio del nodo y realiza rotaciones si es necesario
    int balance = getBalance(root);

    if (balance > 1 && key < root->left->key)  // Desequilibrio izquierda-izquierda
        return rotateRight(root);

    if (balance < -1 && key > root->right->key)  // Desequilibrio derecha-derecha
        return rotateLeft(root);

    if (balance > 1 && key > root->left->key) {  // Desequilibrio izquierda-derecha
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

    if (balance < -1 && key < root->right->key) {  // Desequilibrio derecha-izquierda
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}

// Función para encontrar el nodo con el valor mínimo en un árbol AVL
AVLNode* findMinValueNode(AVLNode* node) {
    AVLNode* current = node;
    while (current->left != nullptr)
        current = current->left;
    return current;
}

// Función para eliminar un nodo en el árbol AVL
AVLNode* deleteNode(AVLNode* root, int key) {
    if (root == nullptr) return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == nullptr || root->right == nullptr) {
            AVLNode* temp = root->left ? root->left : root->right;
            if (temp == nullptr) {
                temp = root;
                root = nullptr;
            } else
                *root = *temp;
            delete temp;
        } else {
            AVLNode* temp = findMinValueNode(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }

    if (root == nullptr) return root;

    root->height = 1 + std::max(getHeight(root->left), getHeight(root->right));

    int balance = getBalance(root);

    if (balance > 1 && getBalance(root->left) >= 0)  // Desequilibrio izquierda-izquierda
        return rotateRight(root);

    if (balance < -1 && getBalance(root->right) <= 0)  // Desequilibrio derecha-derecha
        return rotateLeft(root);

    if (balance > 1 && getBalance(root->left) < 0) {  // Desequilibrio izquierda-derecha
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

    if (balance < -1 && getBalance(root->right) > 0) {  // Desequilibrio derecha-izquierda
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}

// Función para buscar un valor en el árbol AVL
AVLNode* search(AVLNode* root, int key) {
    if (root == nullptr || root->key == key)
        return root;

    if (key < root->key)
        return search(root->left, key);
    return search(root->right, key);
}

// Función para imprimir el árbol en orden
void inOrderTraversal(AVLNode* root) {
    if (root != nullptr) {
        inOrderTraversal(root->left);
        std::cout << root->key << " ";
        inOrderTraversal(root->right);
    }
}



string stringforarchive(AVLNode* root) {
    // Función para guardar en str lo que contiene el arbol
    string res = "";
    if (root != nullptr) {
        res += stringforarchive(root->left);
        res += root->human->getinfo() + "\n";
        for (int i = 0; i < root->human->friends.size(); i++)
            res += to_string(root->human->friends[i]->id) + " ";
        res += "\n\n";
        res += stringforarchive(root->right);
    }

    return res;
}




 