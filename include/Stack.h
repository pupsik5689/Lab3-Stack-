#pragma once

const int MaxStackSize = 128;

template <class T>
class TStack
{
protected:
  T* pMem;
  int size;
  int start;

public:
  TStack(size_t sz = MaxStackSize);
  TStack(const TStack<T>& st);
  TStack(TStack<T>&& st);
  ~TStack();

  int GetSize();
  int GetStart();

  bool IsFull();
  bool IsEmpty();

  void Push(T elem);
  T Top();
  T Pop();
};

template<class T>
inline TStack<T>::TStack(size_t sz)
{
  if (sz <= 0)
    throw "Error";

  size = sz;
  start = -1;
  pMem = new T[sz];

  for (int i = 0; i < sz; i++)
    pMem[i] = {};
}

template<class T>
inline TStack<T>::TStack(const TStack<T>& st)
{
  if (st.pMem == nullptr)
    throw "Error";

  size = st.size;
  start = st.start;
  pMem = new T[size];

  for (int i = 0; i < size; i++)
    pMem[i] = st.pMem[i];
}

template<class T>
inline TStack<T>::TStack(TStack<T>&& st)
{
  size = st.size;
  start = st.start;
  pMem = st.pMem;

  st.size = 0;
  st.start = 0;
  st.pMem = nullptr;
}

template<class T>
inline TStack<T>::~TStack()
{
  if (pMem != nullptr)
  {
    delete[] pMem;
    pMem = 0;
    size = 0;
    start = 0;
  }
}

template<class T>
inline int TStack<T>::GetSize()
{
  return size;
}

template<class T>
inline int TStack<T>::GetStart()
{
  return start;
}

template<class T>
inline bool TStack<T>::IsFull()
{
  return (start == size - 1);
}

template<class T>
inline bool TStack<T>::IsEmpty()
{
  return (start == -1);
}

template<class T>
inline void TStack<T>::Push(T elem)
{
  if (IsFull())
    throw "Error";

  pMem[++start] = elem;
}

template<class T>
inline T TStack<T>::Top()
{
  return T();
}

template<class T>
inline T TStack<T>::Pop()
{
  if (IsEmpty())
    throw "Error";

  return pMem[start--];
}
