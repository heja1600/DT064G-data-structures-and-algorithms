#include <vector>



template <typename T>
class BinaryTree {

public:
	class Position {
	private:
		int key;
	public:
		Position(int k) : key(k) {}
		friend class BinaryTree;
	};


protected:

	vector<T> *array;

public:
	BinaryTree() {
		array = new vector<T>;
		array->push_back(T());
	}

	int size() {
		return int(array->size()) - 1;
	}

	~BinaryTree() {
		delete[] array;
	}

	BinaryTree<T>& operator=(const BinaryTree<T>& t) {
		if (this != &t) {
			copyFrom(t);
		}
		return *this;
	}

	BinaryTree(const BinaryTree<T>& t) {
		array = new vector<T>;
		copyFrom(t);
	}

	void print() {
		cout << "size is: " << size() << endl;
		for (int i = 1; i <= size(); i++) {
			cout << array->at(i) << "\t";
		}
		cout << endl;
	}

protected:
	void copyFrom(const BinaryTree& t) {
		for (int i = 1; i <= t.size(); i++) {
			array->push_back(t[i]);
		}
	}


public:

	void swapElements(const Position& p1, const Position& p2) {
		T element = array[p1.key];
		array[p2.key] = array[p1.key];
		array[p1.key] = element;
	}

	void replaceElement(const Position& p, const T& e) {
		array[p.key] = e;
	}

	Position root() {
		return Position(array[1]);
	}

	bool isRoot(const Position& p) {
		return p.key == 1;
	}

	bool isLeft(const Position& p) {
		return p.key % 2 == 0;
	}



	Position parent(const Position& p) {
		return Position(array->at(p.key / 2));

	}

	Position leftChild(const Position& p) {
		return Position(array->at(p.key * 2));
	}
	Position rightChild(const Position& p) {
		return Position(array->at(p.key * 2 + 1));
	}

	Position sibling(const Position& p) {
		if (isLeft(p)) {
			return Position(array->at(p.key + 1));
		}
		return Position(array->at(p.key - 1));
	}

	bool isExternal(const Position& p) {
		return p.key * 2 > size();
	}
	bool isInternal(const Position& p) {
		return !isExternal(p);
	}

	Position insert(const T& e) {
		array->push_back(e);
		return
			(size());
	}


	T elementOf(const Position& p) {
		return array->at(p.key);
	}

};
