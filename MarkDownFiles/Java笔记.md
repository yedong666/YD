# 														Java笔记

## 类



## 多线程与并发

### 线程

- 进程与线程：进程是程序的一次执行过程，线程就是程序中独立执行的路径，一个程序中会有多个线程，因此一个进程中包含多个线程。

- 线程实现：

  1. 继承Thread类，重写其run方法
  2. 实现Runable接口
  3. 实现Callable接口

- 线程状态：新建---就绪---运行---死亡。新建一个线程，该线程就进入新建状态，当该线程对象调用start()方法时线程进入就绪状态，等待cpu为之分配资源，当该线程获取到cpu的使用权时，即进入运行，此时可调用某些函数使线程进入阻塞态（即线程让出cpu资源），该线程任务执行结束即死亡。

  阻塞状态：

  1. 等待阻塞：运行状态中的线程执行 wait() 方法，使线程进入到等待阻塞状态。

  2. 同步阻塞：线程在获取 synchronized 同步锁失败(因为同步锁被其他线程占用)。

  3. 其他阻塞：通过调用线程的 sleep() 或 join() 发出了 I/O 请求时，线程就会进入到阻塞状态。当sleep() 状态超时，join() 等待线程终止或超时，或者 I/O 处理完毕，线程重新转入就绪状态。

     - 注意调用sleep()总是需要捕获异常，因此其使用方法为：

       ```java
       try{
           Thread.sleep(100);
       } catch (InterruptedException e){
           e.printStackTrace();
       }
       ```

       

- 线程的优先级：每一个 Java 线程都有一个优先级，这样有助于操作系统确定线程的调度顺序。

  Java 线程的优先级是一个整数，其取值范围是 1 （Thread.MIN_PRIORITY ） - 10 （Thread.MAX_PRIORITY ）。

  默认情况下，每一个线程都会分配一个优先级 NORM_PRIORITY（5）。

  具有较高优先级的线程对程序更重要，并且应该在低优先级的线程之前分配处理器资源。但是，线程优先级不能保证线程执行的顺序，而且非常依赖于平台。

- 函数异同：

  1. sleep()与wait():
     - 所属对象不同，sleep是Thread 上的方法，而wait是Object上的方法
     - sleep方法不会释放锁，而wait会释放锁
     - sleep不依赖于synchronized，而wait必须在synchronized包住的代码块中执行，如果不是，则会报错
     - sleep不需要被唤醒，休眠之后会从阻塞状态转为就绪状态，而wait在某些情况下会仍然处于阻塞状态，需要手动唤醒
  2. yield() 与 join():
     - Thread.yield()：一定是当前线程调用此方法，**当前线程放弃获取CPU的时间片，由运行态转变为就绪态，**让操作系统中再次选择线程执行。作用：让相同优先级的线程轮流执行，但并不能保证轮流执行，根据解释我们了解到，转成就绪态的的线程还有可能再次选中执行。Thread.yield()方法不会导致阻塞。
     - t.join()/t.join(long millis)：当前线程调用t2.join()方法，**当前线程阻塞但是不会释放对象锁，直到t2线程执行完毕或者millis时间到，则当前的线程恢复就绪状态。**作用：让优先级比较高的线程优先执行。

### 锁 (对象监视器)

#### synchronized

- 修饰方法

  - ```java
    public synchronized void fun();
    //此时锁对象默认为this
    ```

- 修饰代码块

  - ```java
    synchronized(Object obj) {
        //内容
    }
    //obj为锁对象
    ```

- 作用：同步线程，防止出现线程不安全的情况，常在并发编程中用到

#### Lock

- 用法：

  - ```java
    class Test implements Runnable{
        //属性......
        
        //声明Lock锁
        private final ReetrantLock lock = new ReetrantLock();
        
        @Override
        public void run(){
            try{
                //上锁
                lock.lock();
                
                //执行内容....
            } finally{
                //解锁
                lock.unlock()
            }
        }
    }
    ```

    

  







### 线程池





## IO流

- 分类：按流的内容可分为字节流与字符流，按流向可分为输出流与输入流
- 

## 网络编程



##  反射

- 定义：将类的各个部分（方法、属性、构造器）封装为其他对象
- 框架：半成品软件，可以在框架的基础上进行软件开发，简化编码
- 优点：

  1. 可以在程序运行过程中操作这些对象
  2. 可以解耦（根据类名创建实例，而类名可以从配置文件中获取，不用new），提高程序可扩展性。
3. 用Method.invoke执行方法
- 获取Class对象的方式：
  1. Class.forName("全类名即包名加类名")：将字节码文件加载进内存，返回Class对象
  2. 类名.class：通过类名的class属性获取
  3. 对象.getClass()：getClass()方法在Object类中定义	
- 结论：
  1. 同一个字节码文件（*.class）在一次程序运行过程中，只会被加载一次，不论是通过哪一种方式获取的

- 作用：

## 注解

- 作用分类：
  1. 编写文档：通过代码里标识的注解生成文档（使用javadoc命令）
  2. 代码分析：通过代码里标识的注解对代码进行分析（使用反射）
  3. 编译检查：通过代码里标识的注解让编译器能够实现基本的编译检查

- JDK中预定义的一些注解：
  1. @Override：检测被该注解标注的方法是否是继承自父类或接口的
  2. @Deprecated：该注解标注的类容，表示已过时
  3. @SuppressWarnning：压制警告
     - 一般传递参数all @SuppressWarnning("all")

- 自定义注解:

  1. 格式：

     - 元注解：用于描述注解的注解（JDK已定义好）
       1. @Target：描述注解能够作用的位置
       2. @Retention：描述注解被保留的阶段
       3. @Doucumented：描述注解是否被抽取到api文档中
       4. @Inherited：描述注解是否被子类继承
     - public @interface 注解名称 {}

  2. 本质：注解本质是一个接口，其默认 继承Annotation接口

  3. 属性：接口（注解）中的抽象方法

     - 要求：要求返回值类型为基本数据类型、String、枚举、注解的数组

     
