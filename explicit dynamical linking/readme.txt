
how to dynamically link the libm-2.19-so 


./dl /lib/i386-linux-gnu/libm-2.19.so



显式运行时链接
动态链接还有一种更加灵活的模块加载方式，称为显式运行时链接（Explicit Run-time Linking），也叫运行时加载。就是让程序自己在运行时控制加载指定的模块，并且可以在不需要该模块时将其卸载。一般的共享对象不需要进行任何修改就可以进行运行时加载，称为动态装载库（Dynamic Loading Library）。

动态库的装载通过以下一系列的动态链接器API完成：


dlopen：打开一个动态库，加载到进程的地址空间，完成初始化过程。

dlsym： 通过指定的动态库句柄找到指定的符号的地址。

dlerror：每次调用dlopen()、dlsym()或dlclose()以后，可以调用dlerror()来判断上一次调用是否成功。

dlclose：将一个已经加载的模块卸载。系统会维持一个加载引用计数器，每次使用dlopen()加载时，计数器加一；每次使用dlclose()卸载时，计数器减一。当计数器减到0时，模块才真正地卸载。