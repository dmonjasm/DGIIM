#include<stack>

using namespace std;

template <class T>
class cola {
    private:
        stack<T> normal;
        stack<T> reversa;
    public:    
        cola(){ };
        cola(const cola<T> & c);
        bool empty() const;
        void clear();
        T & front();
        const T & front() const;
        void push_back(const T & elem);
        void pop_front();
        unsigned int size() const;
        void swap(cola <T> & c);
        ~cola(){};
};