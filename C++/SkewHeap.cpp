#include <functional>
using std::less;

template<typename T, typename cmp=less<T> >
class SkewHeap{
private:
    struct SkewNode{
        T x;
        SkewNode *lc, *rc;
        SkewNode(T a=0):x(a), lc(nullptr), rc(nullptr){}
    } *root;
    cmp CMP_;
    size_t count;
    SkewNode* Merge(SkewNode* a, SkewNode* b){
        if(!a or !b) return a?a:b;
        if(CMP_(a->x, b->x)) swap(a, b);
        a->rc = Merge(a->rc, b);
        swap(a->lc, a->rc);
        return a;
    }
    void clear(SkewNode*& a){
        if(!a) return;
        clear(a->lc); clear(a->rc);
        delete a; a = nullptr;
    }
public:
    SkewHeap(): root(nullptr), count(0){}
    bool empty(){return count==0;}
    size_t size(){return count;}
    T top(){return root->x;}
    void clear(){clear(root);count = 0;}
    void push(const T& x){
        SkewNode* a = new SkewNode(x);
        count += 1;
        root = Merge(root, a);
    }
    void join(SkewHeap& a){
        count += a.count; a.count = 0;
        root = Merge(root, a.root);
    }
    void pop(){
        count -= 1;
        SkewNode* rt = Merge(root->lc, root->rc);
        delete root; root = rt;
    }
    friend void swap(SkewHeap& a, SkewHeap& b){
        swap(a.root, b.root);
    }
};
