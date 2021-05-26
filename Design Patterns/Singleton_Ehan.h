/**********************************
 * Topic：饿汉式的单例模式的C++实现
 * Author:Sliverchen
 * Create file date : 2021 / 5 / 26
 * ********************************/

//懒汉式一般实现：非线程安全，getInstance返回的实例指针需要delete
/*
    通俗定义:第一次调用该类实例的时候才产生一个新的该类实例，并在以后仅返回此实例
    饿汉式特点:
    1、具有私有的构造函数
    2、具有私有的静态属性，维护自身的实例，在初始化的时候就创建实例
    3、具有共有的服务函数

    非线程安全的说明：
        多个线程可能进入判断是否已经存在实例的if语句，
        进而会导致多个线程先后产生一个新的该类实例
        导致实例不唯一
    解决方法：
        使用mutex头文件的互斥锁，具体看Singleton_Other
*/
class Singleton
{
public:
    static Singleton *getInstance();
    ~Singleton();

private:
    static Singleton *m_pSingleton;
    Singleton() {} //私有构造函数
    Singleton(const Singleton &obj) = delete;
    Singleton &operator=(const Singleton &obj) = delete;
};

//静态数据成员需要在类外初始化
Singleton *Singleton::m_pSingleton = nullptr;

Singleton *Singleton::getInstance()
{
    if (m_pSingleton == nullptr) //如果没有一个单例对象指针，则创建它
        m_pSingleton = new Singleton;
    return m_pSingleton; //如果已经存在单例对象指针，则指向它
}
