#include <QCoreApplication>
#include <QtCore>
#include <iostream>

const int DataSize = 10;
const int BufferSize = 4;
char buffer[BufferSize];
//c的线程：pthread_t pt->pthread_creat;   aem_t    sem_init->sem_wait->sem_post
QSemaphore freeSpace(BufferSize);//空闲资源最开始有4个
QSemaphore usedSpace(0);

class Producer : public QThread
{
public:
    void run();
};

void Producer::run()
{
    for (int i = 0; i < DataSize; ++i) {
        freeSpace.acquire();// Tries to acquire n resources guarded by the semaphore. If n > available(), this call will block until enough resources are available.
        buffer[i % BufferSize] = "ACGT"[356 % 4];
std::cerr <<"1";// https://blog.csdn.net/liuhhaiffeng/article/details/52628561
std::cerr << buffer[i % BufferSize];
        usedSpace.release();
    }
}

class Consumer : public QThread
{
public:
    void run();
};

void Consumer::run()
{
    for (int i = 0; i < DataSize; ++i) {
        usedSpace.acquire();//used-1
std::cerr <<"2";
        std::cerr << buffer[i % BufferSize];
        freeSpace.release();//free+1
    }
    std::cerr << std::endl;
}
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Producer producer;
    Consumer consumer;
    producer.start();//start会自动调用线程里面的run函数
    consumer.start();
    producer.wait();//阻止线程执行，直到线程结束（run函数返回）
    consumer.wait();
    return 0;

}
/*
 * 阻塞线程，直到满足以下任一条件:
与此QThread对象关联的线程已经完成执行(即当它从run()返回时)。如果线程已经完成，这个函数将返回true。如果线程尚未启动，则返回true。
时间毫秒已经过去。如果时间是ULONG_MAX(默认值)，那么等待将永远不会超时(线程必须从run()返回)。如果等待超时，这个函数将返回false。
*/
