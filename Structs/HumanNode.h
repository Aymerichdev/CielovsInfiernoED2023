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