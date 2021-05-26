/***************************
 * Topic:懒汉式单例模式的C++实现
 * Author:Sliverchen
 * Create file date : 2021 / 5 / 26
 * *************************/

//懒汉式：加lock，线程安全
/*
    懒汉式与饿汉式的区别：
        懒汉式不会在类初始化的时候就实例化对象
        而是在外部调用共有服务函数时才判断是否需要进行创建
    使用次数较多的原因：
        在初始化的过程中，它的系统少
        并且在系统运行时，会有选择地进行实例化工作
*/
#include <mutex>
std::mutex mt; //声明互斥量的锁类型

//静态成员实例的懒汉模式：
class Singleton
{
public:
    static Singleton *getInstance();

private:
    static Singleton *m_pSingleton;
    Singleton() {}
};

Singleton *Singleton::getInstance()
{
    if (nullptr == m_pSingleton)
    {
        mt.lock();
        m_pSingleton = new Singleton();
        mt.unlock();
    }
    return m_pSingleton;
}

//内部静态实例的懒汉模式
class SingletonInside
{
public:
    static SingletonInside *getInstance()
    {
        mt.lock(); //no needed after C++0x
        static SingletonInside instance;
        mt.unlock(); //no needed after C++0x
        return &instance;
    }
};