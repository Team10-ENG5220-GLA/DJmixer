#include <iostream>
#include <cstdlib>
#include <pthread.h>

using namespace std;

#define NUM_THREADS     5

void *PrintHello(void *threadid)
{
   // 对传入的参数进行强制类型转换，由无类型指针变为整形数指针，然后再读取
   int tid = *((int*)threadid);

   system("./alsaDemo.o < MoodyLoop.wav");

   cout << "Hello Runoob! 线程 ID, " << tid << endl;
   pthread_exit(NULL);
}

void *PrintHello1(void *threadid)
{
   // 对传入的参数进行强制类型转换，由无类型指针变为整形数指针，然后再读取
   int tid = *((int*)threadid);
   system("amixer set Master 20%");
   system("./alsaDemo.o < DesiJourney.wav");
   cout << "Hello Runoob! 线程 ID, " << tid << endl;
   pthread_exit(NULL);
}


int main ()
{
   pthread_t threads[NUM_THREADS];
   int indexes[NUM_THREADS];// 用数组来保存i的值
   int rc;
   int rc1;
   int i;
   // for( i=0; i < NUM_THREADS; i++ ){
   //    cout << "main() : 创建线程, " << i << endl;
   //    indexes[i] = i; //先保存i的值
   //    // 传入的时候必须强制转换为void* 类型，即无类型指针
   //    rc = pthread_create(&threads[i], NULL,
   //                        PrintHello, (void *)&(indexes[i]));
   //    if (rc){
   //       cout << "Error:无法创建线程," << rc << endl;
   //       exit(-1);
   //    }
   // }

      indexes[0] = 0; //先保存i的值
      // 传入的时候必须强制转换为void* 类型，即无类型指针
      rc = pthread_create(&threads[0], NULL,
                          PrintHello, (void *)&(indexes[0]));
      if (rc){
         cout << "Error:无法创建线程," << rc << endl;
         exit(-1);
      }

         indexes[1] = 1; //先保存i的值
         // 传入的时候必须强制转换为void* 类型，即无类型指针
         rc1 = pthread_create(&threads[1], NULL,
                             PrintHello1, (void *)&(indexes[1]));
         if (rc1){
            cout << "Error:无法创建线程," << rc << endl;
            exit(-1);
         }

   pthread_exit(NULL);
}
