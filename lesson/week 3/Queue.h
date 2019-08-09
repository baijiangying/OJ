#ifndef QUEUE_H
#define QUEUE_H

template <typename T> struct Node {
	T data = 0;
	Node* succ = nullptr;
	Node* pred = nullptr;
	Node ( T e = 0, Node* p = nullptr, Node* s = nullptr ) 
	: data ( e ), pred ( p ), succ ( s ) {}
};

template <typename T> class Queue {
private:
	Node<T>* head;
	Node<T>* trail;
	void init();
	int _size;

public:
	Queue() { init(); }
	~Queue();
	int size() { return _size; }
	void enqueue ( const T& e );
	T dequeue ( const bool& front = true );
	T front();
	T rear();
};

template <typename T> Queue<T>::~Queue() {
	while ( 0 < _size-- ) dequeue ( true );
	delete head, delete trail;
}

template <typename T> void Queue<T>::init() {
	head = new Node<T>;
	trail = new Node<T>;
	head -> succ = trail;
	trail -> pred = head;
	_size = 0;
}

template <typename T> void Queue<T>::enqueue ( const T& e ) {
	Node<T>* p = new Node<T> ( e, trail -> pred, trail );
	trail -> pred -> succ = p;
	trail -> pred = p;
	++_size;
}

template <typename T> T Queue<T>::dequeue ( const bool& front ) {
	if ( _size ) {
		if ( front ) {
			T e = head -> succ -> data;
			Node<T>* p = head -> succ;
			head -> succ = p -> succ;
			p -> succ -> pred = head;

			delete p;
			--_size;
			return e; 
		}
		else {
			T e = trail -> pred -> data;
			Node<T>* p = trail -> pred;
			trail -> pred = p -> pred;
			p -> pred -> succ = trail;

			delete p;
			--_size;
			return e;
		}
	}

	return 0;
}

template <typename T> T Queue<T>::front() { return head -> succ -> data; }
template <typename T> T Queue<T>::rear() { return trail -> pred -> data; }


#endif