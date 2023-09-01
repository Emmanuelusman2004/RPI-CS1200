#ifndef priority_queue_h_
#define priority_queue_h_

#include <iostream>
#include <vector>
#include <cassert>


template <class T>
class priority_queue {
private:
  std::vector<T> m_heap;

public:
  priority_queue() {}

  priority_queue( std::vector<T> const& values )
  {
    for (unsigned int i = 0; i < values.size(); i++) {
      this->push(values[i]);
    }
  }

  const T& top() const 
  {
    assert( !m_heap.empty() );
    return m_heap[0]; 
  }

  void push( const T& entry )
  {
    T temp;
    int swap;
    m_heap.push_back(entry);
    
    
    int p = m_heap.size()-1;
    while (p != 0 && m_heap[p-1/2]) {
      if (m_heap[p]<m_heap[(p)/2]){
        swap = floor((p)/2);
        temp = m_heap[swap];
        m_heap[swap] = m_heap[p];
        m_heap[p] = temp;

        }
        p = floor(p-1)/2;
    }
  }

  void pop() 
  {
    assert( !m_heap.empty() );
    T temp;
    unsigned int p = 0;
    int swap = 0;
    temp = m_heap[m_heap.size()-1];
    m_heap[m_heap.size()-1] = m_heap[0];
    m_heap[0] = temp;
    m_heap.pop_back();
    while (p < m_heap.size()) {
      if (2*p+2<=m_heap.size() && m_heap[2*p+2] < m_heap[p]) {
        swap = 2*p+2;
        if (m_heap[2*p+1] < m_heap[2*p+2]) {
          swap = 2*p+1;
        }
      }
      else if (2*p+1 < m_heap.size() && m_heap[2*p+1] < m_heap[p]) {
        swap = 2*p+1;
      }
      if (m_heap[swap] < m_heap[p]) {
        temp = m_heap[swap];
        m_heap[swap] = m_heap[p];
        m_heap[p] = temp;
        p = swap;
      }
      else {
        break;
      }
    }
  }

  int size() { return m_heap.size(); }
  bool empty() { return m_heap.empty(); }


  //  The following three functions are used for debugging.

  //  Check to see that internally the heap property is realized.
  bool check_heap( )
  {
    return this->check_heap( this->m_heap );
  }

  //  Check an external vector to see that the heap property is realized.
  bool check_heap( const std::vector<T>& heap )
  {
    for(unsigned int i = 0;  i < heap.size()/2;i++) {
      if (2*i+2 <= heap.size()) {
        if (heap[2*i+1]+heap[2*i+2] < heap[i]) {
          return false;
        }
      }
      else {
        if (heap[2*i+1] < heap[i]) {
          return false;
        }
      }
    }
    return true;
  }

  //  A utility to print the contents of the heap.  Use it for debugging.
  void print_heap( std::ostream & ostr )
  {
    for ( unsigned int i=0; i<m_heap.size(); ++i )
      ostr << i << ": " << m_heap[i] << std::endl;
  }
  
};


template <class T>
void heap_sort( std::vector<T> & v )
{
}

#endif
