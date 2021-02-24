#include <string>

const std::string invalidSizeMsg = "Invalid Size";
const int defaultInitSize = 10;

template<class T>
class Queue {

public:
	Queue();
	Queue(const Queue& other);
	~Queue();
	void enqueue(T element);
	T dequeue();
	T peek();
	int size();
	bool isEmpty();
	Queue& operator=(const Queue& other);

private:
	T *data;
	int head;
	int tail;
	int n;
	int maxSize;
	void copy(const Queue& other);
	void expand();
       
};

