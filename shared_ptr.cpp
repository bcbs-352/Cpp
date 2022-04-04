#include <memory>
// shared_ptr与weak_ptr的关系类似于unique_ptr与原始指针C*
/*或是
shared_ptr<C> m_child;
C* m_parent
->m_child=child;
->m_parent=parent.get();//get函数，父类在释放时,子类自然无法get到父类
*/
struct C
{
    std::shared_ptr<C> m_child;
    // std::shared_ptr<C> m_parent;
    std::weak_ptr<C> m_parent;
    ~C()
    {
        printf("freePTR");
    }
};
//逻辑上是:父xx拥有子xx，而子xx并不拥有父xx
int main()
{
    std::shared_ptr<C> child = std::make_shared<C>();
    // auto child = std::make_shared<C>();
    auto parent = std::make_shared<C>();
    // std::unique_ptr::released();
    child->m_parent = parent;
    parent->m_child = child;

    return 1;
}
