/*******************************
 * Topic:多线程下的单例模式C++实现
 * Author:Sliverchen
 * Create file date : 2021 / 5 / 26
 * *****************************/

//返回一个reference指向local static 对象
//多线程可能存在不确定性
//任何一种non-const static对象，不论它是local或non-local,在多线程环境下“等待某事发生”都会有麻烦
//解决的方法：在程序的单线程启动阶段手工调用所有reference-returning函数

class Singleton
{
public:
    static Singleton &getInstance();

private:
    Singleton() {}
    Singleton(const Singleton &) = delete;
    Singleton &operator=(const Singleton &) = delete;
};

Singleton &Singleton::getInstance()
{
    static Singleton singleton;
    return singleton;
}
