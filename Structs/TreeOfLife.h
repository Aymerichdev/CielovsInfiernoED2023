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