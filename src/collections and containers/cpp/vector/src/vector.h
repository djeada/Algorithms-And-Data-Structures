
template <class T> class Vector {

public:
  Vector();
  Vector(const Vector<T> &v);
  ~Vector();

  typedef T *iterator;
  int size();
  bool empty();
  iterator begin();
  iterator end();
  T &front();
  T &back();
  void push_back(const T &value);
  T pop_back();

  void resize(unsigned int size);
  T &operator[](unsigned int index);
  Vector<T> &operator=(const Vector<T> &);
  void clear();

private:
  int n;
  int capacity;
  void reserve(unsigned int size);
  T *data;
};
