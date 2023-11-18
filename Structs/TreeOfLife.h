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

    void treeInformation(){
        printTreeBase();
        printTreeNodeAmmount();
        printTreeDepth();
    }

    void printTreeBase() {
        printTreeBase(root);
    }

    void printTreeBase(HumanNode* _node) {
        if (_node == NULL) {
            return;
        }
        if (_node->isLeaf()) {
            _node->getHuman()->printHuman();
            return;
        }
        printTreeBase(_node->getLeft());
        printTreeBase(_node->getRight());
    }

    void printTreeDepth() {
        cout << "Niveles del arbol: " << printTreeDepth(root) << endl;
    }

    int printTreeDepth(HumanNode* _node) {
        if (_node == NULL)
            return 0;
        if (_node->isLeaf())
            return 1;
        else
            return 1 + max(printTreeDepth(_node->getLeft()), printTreeDepth(_node->getRight()));
    }

    void printTreeNodeAmmount() {
        cout << "Cantidad de nodos: " << printTreeNodeAmmount(root) << endl;
    }

    int printTreeNodeAmmount(HumanNode* _node) {
        if (_node == NULL)
            return 0;
        if (_node->isLeaf())
            return 1;
        else
            return 1 + printTreeNodeAmmount(_node->getLeft()) + printTreeNodeAmmount(_node->getRight());
    }
};