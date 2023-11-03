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