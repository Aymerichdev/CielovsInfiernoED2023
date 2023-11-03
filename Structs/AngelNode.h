struct AngelNode{
    // Node for the HeavenTree, which is a 3-ary tree
    
    // Attributes
    Angel* angel;
    AngelNode* left;
    AngelNode* center;
    AngelNode* right;

    AngelNode(){
        angel = NULL;
        left = NULL;
        center = NULL;
        right = NULL;
    }

    AngelNode(Angel* _angel){
        angel = _angel;
        left = NULL;
        center = NULL;
        right = NULL;
    }

    AngelNode(Angel* _angel, AngelNode* _left, AngelNode* _center, AngelNode* _right){
        angel = _angel;
        left = _left;
        center = _center;
        right = _right;
    }

    bool hasSpace(){
        return left == NULL || center == NULL || right == NULL;
    }

    bool insertEmpty(Angel* _angel){
        if (hasSpace()){
            if (left == NULL) left = new AngelNode(_angel);
            else if (center == NULL) center = new AngelNode(_angel);
            else if (right == NULL) right = new AngelNode(_angel);
            return true;
        }
        return false;
    }

    AngelNode* getLatestNode(){
        if (left != NULL) return left;
        else if (center != NULL) return center;
        else if (right != NULL) return right;
        else return NULL;
    }

    string getName(){
        return angel->name + " " + to_string(angel->version) + " " + to_string(angel->version);
    }

    Angel* getAngel(){
        return angel;
    }

    AngelNode* getLeft(){
        return left;
    }

    AngelNode* getCenter(){
        return center;
    }

    AngelNode* getRight(){
        return right;
    }

    void setAngel(Angel* _angel){
        angel = _angel;
    }

    void setLeft(AngelNode* _left){
        left = _left;
    }

    void setCenter(AngelNode* _center){
        center = _center;
    }

    void setRight(AngelNode* _right){
        right = _right;
    }
};