struct HumanSinHeap {
    std::vector<Human*> heap;
    int choosenSin;
    string country;
    string surname;
    // Constructor
    HumanSinHeap() {
        heap = {};
        choosenSin = 0;
        country = "";
        surname = "";
    }

    HumanSinHeap(int _choosenSin, string _country, string _surname) {
        heap = {};
        choosenSin = _choosenSin;
        country = _country;
        surname = _surname;
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
    
    int getMax() const {
        if (heap.empty()) {
            return 0;
        }

        return heap[0]->getSin(choosenSin);
    }

    int getSize() const {
        return heap.size();
    }

    Human* getmin() const {
        if (heap.empty()) {
            throw std::out_of_range("Heap is empty");
        }
        int cont = 999999999;
        Human * res = nullptr;
        for (int i = 0; i < heap.size(); i++) {
            if (heap[i]->getSin(choosenSin) < cont) {
                cont = heap[i]->getSin(choosenSin);
                res = heap[i];
            }        
        }
        return res;
    }

    int getallints() const {
        int res = 0;
        for (int i = 0; i < heap.size(); i++) {
            res += heap[i]->getSin(choosenSin);
        }
        return res;
    }

    bool isEmpty() const {
        return heap.empty();
    }

    void deleteHuman(Human* human) {
    // Find the index of the human to delete
    int indexToDelete = -1;
    for (int i = 0; i < heap.size(); i++) {
        if (heap[i] == human) {
            indexToDelete = i;
            break;
        }
    }

    if (indexToDelete == -1) {
        // The specified human is not in the heap
        return;
    }

    // Replace the element to delete with the last element
    heap[indexToDelete] = heap.back();
    heap.pop_back();

    // Check if we need to heapify down
    if (indexToDelete < heap.size()) {
        // If the element was not the last one, and it's less than its parent, heapify down.
        if (indexToDelete > 0 && heap[indexToDelete]->getSin(choosenSin) > heap[(indexToDelete - 1) / 2]->getSin(choosenSin)) {
            heapifyUp(indexToDelete);
        } else {
            heapifyDown(indexToDelete);
        }
    }
}
    int addallints() const {
        if (heap.empty()) {
            return 0;
        }
        int res = 0;
        for (int i = 0; i < heap.size(); i++) {
            res += heap[i]->getSin(choosenSin);
        }
        return res;
    }

    void print() const {
        if (heap.empty()) {
            std::cout << "Heap is empty" << std::endl;
            return;
        }
        for (int i = 0; i < heap.size(); ++i) {
            //imprime los int
            std::cout << heap[i]->getSin(choosenSin) << " ";

        }
        std::cout << std::endl;
    }

    Human * maxsinnerhuman(){
        int cont = 0;
        Human* res = nullptr; // Initialize to nullptr
        if (heap.empty()) {
            return nullptr;
        }
        for(int i = 0; i < heap.size(); i++) {
            if (heap[i]->totalsins > cont) {
               res = heap[i];
               cont = heap[i]->totalsins; // Update the max sin count
            }
        }
        return res; // Return the human with the max sin count
    }
};