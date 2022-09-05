template <typename T>
class ForwardList
{
public:
  ForwardList();

  ~ForwardList();

  void push(T);
  T drop();

  void print(std::ostream&) const;
  bool isEmpty();

private:

  struct node_t
  {
    T data;
    node_t* next = nullptr;
  };


  node_t* head_;
};

template <typename T>
ForwardList<T>::ForwardList() :
  head_(nullptr)
{}

template <typename T>
ForwardList<T>::~ForwardList()
{
  while (head_)
  {
    node_t* temp = head_;
    head_ = head_->next;

    delete temp;
  }
}

template <typename T>
void ForwardList<T>::print(std::ostream& stream) const
{
  node_t* temp = head_;
  while (temp)
  {
    stream << temp->data;
    temp = temp->next;
    if (temp != nullptr) {
      stream << " ";
    }
  }
}

template <typename T>
bool ForwardList<T>::isEmpty() {
  return head_ == nullptr;
}

template <typename T>
T ForwardList<T>::drop()
{
  if (!head_)
  {
    throw std::logic_error("ForwardList is empty");
  }
  T res = head_->data;
  node_t* temp = head_;
  head_ = head_->next;
  delete temp;
  return res;
}

template <typename T>
void ForwardList<T>::push(T val)
{
  node_t* newNode = new node_t;
  newNode->data = val;
  newNode->next = head_;
  head_ = newNode;
}
