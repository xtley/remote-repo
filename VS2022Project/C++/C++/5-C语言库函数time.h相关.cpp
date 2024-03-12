//#include <stdio.h>
//#include <time.h>
//#include <stdint.h>
//
//#include <wchar.h>
//#include <locale.h>
//
//#include <iostream>
//
//#define my _5_
//#define _POSIX_C_SOURCE 200112L // 为 GCC 的 setenv
//using namespace std;
////类型
//
//    //time_t 从纪元开始的日历时间类型 
//    // time_t实际上是长整型
//    // time_t 这种类型就是用来存储从1970年到现在经过了多少秒，要想更精确一点，
//    // 可以用结构struct timeval，它精确到微妙。而直接存储年月日的是一个结构：
//    //#ifndef __TIME_T
//    //#define __TIME_T     /* 避免重复定义 time_t */
//    //    typedef long     time_t;    /* 时间值time_t 为长整型的别名*/
//    //#endif
//
//
//    //struct tm 日历时间类型
//    //{
//    //    int tm_sec;  /*秒，正常范围0-59， 但允许至61*/
//    //    int tm_min;  /*分钟，0-59*/
//    //    int tm_hour; /*小时， 0-23*/
//    //    int tm_mday; /*日，即一个月中的第几天，1-31*/
//    //    int tm_mon;  /*月， 从一月算起，0-11 1+p->tm_mon;  */
//    //    int tm_year;  /*年， 从1900至今已经多少年 1900＋ p->tm_year;  */
//    //    int tm_wday; /*星期，一周中的第几天， 从星期日算起，0-6*/
//    //    int tm_yday; /*从今年1月1日到目前的天数，范围0-365*/
//    //    int tm_isdst; /*日光节约时间的旗标*/
//    //};
//   //struct tm 日历时间类型
//    //{int tm_sec	分后之秒 –[0, 61](C99 前)[0, 60](C99 起)[注 1]
//    //    int tm_min	时后之分 –[0, 59]
//    //    int tm_hour	自午夜起的小时 –[0, 23]
//    //    int tm_mday	月之日 –[1, 31]
//    //    int tm_mon	自 1 月起的月 –[0, 11]
//    //    int tm_year	自 1900 年起的年
//    //    int tm_wday	自星期日起的星期 –[0, 6]
//    //    int tm_yday	从 1 月 1 日起的日 –[0, 365]
//    //    int tm_isdst	夏时令标签。若夏时令有效则此值为正，若无效则为零，若无可用信息则为负。
//    //}
//
//    //clock_t 从时点开始的处理器时间类型
//
//    //timespec  (C11)
//    //单位为秒和纳秒的时间 (结构体)
//    //在标头 <time.h> 定义
//    //struct timespec; (C11 起)
//    //保有时间间隔的结构体，将其拆分成秒数和纳秒数。
//    //成员对象
//    //time_t tv_sec	整秒数（合法值 >= 0）
//    //long tv_nsec	纳秒数（合法值为[0, 999999999] ）
//
//
//     //常量 
//    //定义于头文件 <time.h>
//    // CLOCKS_PER_SEC   处理器每秒的时间计数(宏常量)
//    //在标头 <time.h> 定义
//    //#define CLOCKS_PER_SEC /*implementation defined*/
//    //    展开成一个 clock_t 类型的表达式（不必是编译时常量），等于每秒计次数，如 clock() 所返回者。
//    //
//    //    注意
//    //    POSIX 定义 CLOCKS_PER_SEC 为一百万，无关乎 clock 的实际精度。
//    //
//    //    在 C89 中被标准为 CLOCKS_PER_SEC 之前，此宏有时会以其 IEEE std 1003.1 - 1988 名称 CLK_TCK 为人所用：
//    //    该名称未包含于 C89 ，并为 POSIX 自身于 1996 年移除，
//    //    因为它和 times() 函数所用的给出每秒时钟数的宏 _SC_CLK_TCK 有歧义。
//
//void mytest01() {
//    //函数
//    //difftime 函数 double difftime( time_t time_end, time_t time_beg );
//    //以秒数计算二个作为 time_t 对象的日历时间的差（ time_end - time_beg ）。
//    //若 time_end 代表先于 time_beg 的时间点，则结果为负。
//
//    //计算从月初开始经过的秒数
//
//    time_t now; //声明一个时间戳now
//    time(&now); //将时间戳给对象now
//
//    struct tm beg; //定义一个日历类型 beg
//    beg = *localtime(&now);  //跟进当前时间
//    // 设 beg 为月初
//    beg.tm_hour = 0;     
//    beg.tm_min = 0;
//    beg.tm_sec = 0;
//    beg.tm_mday = 1; //令其为一个月的第一天
//
//    double seconds = difftime(now, mktime(&beg)); //计算现在时间和月初的时间差  
//                                                  //mktime 将日历时间转换成纪元开始经过的时间
//
//    printf("%.f seconds have passed since the beginning of the month.\n", seconds);
//    //自本月初以来，已过去  秒。
//}
//void mytest02() {
//    //函数
//    //time 函数 time_t time( time_t *arg );
//    // 返回纪元开始经过的当前系统日历时间
//    // 返回编码成 time_t 对象的当前日历时间，并将其存储于 arg 指向的 time_t 对象（除非 arg 为空指针）。
//    //成功时返回编码成 time_t 对象的当前日历时间。错误时返回 (time_t)(-1) 。
//    //若arg不是空指针，则返回值也会存储于 arg 所指向的对象。
//    //time_t 为32位有符号整数的实现（许多历史上的实现）会在 2038 年出错。
//
//    //asctime 函数 将 struct tm 对象转换成文本表示 
//    //gmtime 将从纪元开始的时间转换成以协调世界时（UTC）表示的日历时间
//    time_t result = time(NULL);
//    if (result != (time_t)(-1))
//        printf("The current time is %s(%jd seconds since the Epoch)\n",
//            asctime(gmtime(&result)), (intmax_t)result); // intmax_t 扩展整数类型 %jd 他的特殊控制符
//
//    //当前时间为2015年4月24日星期五15:05:25
//    //（大纪元以来1429887925秒）
//}
//void mytest03() {
//    //函数
//    //clock 函数
//    //返回未加工的程序启动时开始经过的处理器时间
//}
//void mytest04() {
//    //函数
//    //timespec_get 函数
//    //	返回基于给定时间基底的日历时间
//}
//void mytest05() {
//     //函数
//     //timespec_getres 函数
//     //返回基于给定时间基底的日历时间的分辨率
//  
// 
//
//
//}
//void mytest06() {
//    //函数
//    //asctime 函数 
//    //将 struct tm 对象转换成文本表示
//    //char* asctime(const struct tm* time_ptr);(C23 前)
//    //[[deprecated]] char* asctime(const struct tm* time_ptr);(C23 起)
//    //1) 转换日历时间 tm 为以下固定的 25 字符表示形式： Www Mmm dd hh : mm:ss yyyy\n
//    //Www ——来自 time_ptr->tm_wday 的星期之日的三字母英文缩写， Mon、 Tue、 Wed、 Thu、 Fri、 Sat、 Sun 之一。
//     //   Mmm ——来自 time_ptr->tm_mon 的月名的三字母英文缩写， Jan、 Feb、 Mar、 Apr、 May、 Jun、 Jul、 Aug、 Sep、 Oct、 Nov、 Dec 之一。
//     //   dd ——来自 timeptr->tm_mday 的 2 位月之日，如同由 sprintf 以 % 2d 打印
//     //   hh ——来自 timeptr->tm_hour 的 2 位时，如同由 sprintf 以 % .2d 打印
//     //   mm ——来自 timeptr->tm_min 的 2 位分，如同由 sprintf 以 % .2d 打印
//     //   ss ——来自 timeptr->tm_sec 的 2 位秒，如同由 sprintf 以 % .2d 打印
//     //   yyyy ——来自 timeptr->tm_year + 1900 的 4 位年，如同由 sprintf 以 % 4d 打印
//     //   若 * time_ptr 的任何成员在其正常范围外则行为未定义
//     //   若 time_ptr->tm_year 所指示的历年拥有多于 4 位数或小于 1000 年则行为未定义。
//     //   函数不支持本地化，且不能移除换行符。
//     //   函数修改静态存储且非线程安全。
//     //   此函数被弃用且不应被用于新的代码。  (C23 起)
//     //   2) 同(1) ，除了写入消息到用户提供的存储 buf 中，保证它是空终止的。且在运行是检测下列错误并调用当前安装的制约处理函数：
//     //   buf 或 time_ptr 为空指针
//     //   bufsz 小于 26 或大于 RSIZE_MAX
//     //   不是所有 * time_ptr 的成员都在其正常范围内
//     //   time_ptr->tm_year 所指示的年小于 0 或大于 9999
//     //   同所有边界检查函数， asctime_s 仅若实现定义 __STDC_LIB_EXT1__ 且用户在包含 time.h 前定义 __STDC_WANT_LIB_EXT1__ 为整数常量 1 才保证可用。
//    time_t now = time(NULL);
//    struct tm tm = *localtime( &now); //localtime 将从纪元开始的时间转换成以本地时间表示的日历时间
//    printf("%s", asctime(&tm));  //将日历时间转换为文本表示
//}
//void mytest07() {
//      //函数
//      //asctime_s 函数 (C11) errno_t asctime_s( char* buf, rsize_t bufsz, const struct tm* time_ptr ); (C11 起)
//      //将 struct tm 对象转换成文本表示
//
//
//}
//void mytest08() {
//    //函数
//    //ctime 函数 (C23 中弃用) 
//    //char*                ctime( const time_t* timer ); (C23 前)
//    //[[deprecated]] char* ctime(const time_t * timer);  (C23 起)
//    //将 struct time_t 对象转换成文本表示
//    //结果字符串拥有下列格式：
//        //Www Mmm dd hh : mm:ss yyyy\n
//    time_t result = time(NULL);
//    printf("%s", ctime(&result));
//}
//void mytest09() {
//    //函数
//     //ctime_s 函数 (C11) errno_t ctime_s( char *buf, rsize_t bufsz, const time_t* timer ); (C11 起)
//     //将 struct time_t 对象转换成文本表示
//}
//void mytest10() {
//    //函数
//    //strftime 函数
//    // size_t strftime( char *         str, size_t count,const char* format, const struct tm* time );(C99 前)
//    // size_t strftime(char* restrict str, size_t count,const char* restrict format, const struct tm* restrict time);(C99 起)
//    // 按照格式字符串 format ，转换来自给定的日历时间 time 的日期和时间信息，为空终止多字节字符串 str 。最多写入 count 字节。
//    //将 struct tm 对象转换成自定义文本表示
//    // *****定义于头文件 <wchar.h>*****
//    // 参数
//    //str - 指向待输出 char 数组首元素的指针
//    //count - 最大写入字节数
//    //format - 指向指定转换格式的空终止多字节字符串指针。
//    // 格式字符串由零或更多个说明符和通常字符（除 % ）构成。
//    // 所有通常字符，包括空终止字符，都会被复制到输出字符串而不加修改。
//    // 每个转换说明符都始于 % 字符，可选地跟随 E 或 O 修饰符（若本地环境不支持则忽略），
//    // 后随决定修饰符行为的字符。下列修饰符格式可用：
//    // 返回值
//    //  成功时，返回写入 str 所指向的字符数组的字节数，不包含终止 '\0' 。
//    // 若在能存储整个字符串前抵达 count ，则返回 ​0​ ，写入内容是未定义的。
//    //详解 https://zh.cppreference.com/w/c/chrono/strftime
//
//    //struct tm my_time = { .tm_year = 112, // = 2012年 //结构体的.号乱序初始化方式 c风格
//    //                      .tm_mon = 9,    // = 10月
//    //                      .tm_mday = 9,   // = 9日
//    //                      .tm_hour = 8,   // = 8时
//    //                      .tm_min = 10,   // = 10分
//    //                      .tm_sec = 20    // = 20秒
//    //};
//
//    //struct tm my_time = {tm_year : 112, // = 2012年 //结构体的:号乱序初始化方式 c++风格
//    //                     tm_mon : 9,    // = 10月
//    //                     tm_mday : 9,   // = 9日
//    //                     tm_hour : 8,   // = 8时
//    //                     tm_min : 10,   // = 10分
//    //                     tm_sec : 20    // = 20秒
//    //};
//    
//    // 但是上面两种方式不知道为什么不能在VS2022中使用
//    
//    char buff[70];
//    struct tm my_time;
//    my_time.tm_year = 2012; // = 2012年 
//    my_time.tm_mon  = 10;    // = 10月
//    my_time.tm_mday = 9;   // = 9日
//    my_time.tm_hour = 8;   // = 8时
//    my_time.tm_min  = 10;   // = 10分
//    my_time.tm_sec  =20;   // = 20秒
//
//   // if (strftime(buff, sizeof buff, "%A %c", &my_time)) {
//        puts(buff);
//    //}
//   // else {
//        puts("strftime failed");
//  //  }
//
//    setlocale(LC_TIME, "el_GR.utf8");
//
//    //char* setlocale(int category, const char* locale);
//    //setlocale位于头文件locale.h，
//    //setlocale() 函数既可以用来对当前程序进行地域设置（本地设置、区域设置），
//    //也可以用来获取当前程序的地域设置信息，使用setlocale需要两个参数
//
//    if (strftime(buff, sizeof buff, "%A %c", &my_time)) {
//        puts(buff);
//    }
//    else {
//        puts("strftime failed");
//    }
//
//
//
//}
//void mytest11() {
//    //函数
//    //wcsftime 函数 在标头 <wchar.h> 定义
//    //size_t wcsftime(wchar_t* str, size_t count, const wchar_t* format, tm * time);
//    //将来自给定的日历时间 time 的日期和时间信息，按照格式字符串 format ，转换成空终止宽字符串 str 。最多写入 count 个宽字符。
//    //将 struct tm 对象转换成自定义宽字符文本表示
//}
//void mytest12() {
//    //函数
//    //gmtime
//    //gmtime_r (C23)
//    //gmtime_s (C11)
//    //将从纪元开始的时间转换成以协调世界时（UTC）表示的日历时间
//    //在标头 <time.h> 定义
//    //struct tm* gmtime(const time_t * timer);
//    //(1)
//    //    struct tm* gmtime_r(const time_t * timer, struct tm* buf);
//    //(2)	(C23 起)
//    //    struct tm* gmtime_s(const time_t * restrict timer, struct tm* restrict buf);
//    //(3)	(C11 起)
//    //    1) 转换从纪元开始的给定时间（ time 所指向的 time_t 的值），以 struct tm 格式表示成协调世界时（ UTC ）。存储结果于静态存储，并返回指向静态存储的指针。
//    //    2) 同(1) ，除了函数使用用户为结果提供的存储 buf 。
//    //    3) 同(1) ，除了函数使用用户为结果提供的存储 buf ，还在运行时检测下列错误，并调用当前安装的约束处理函数：
//    //    timer 或 buf 是空指针
//    //    同所有边界检查函数， gmtime_s 仅若实现定义 __STDC_LIB_EXT1__ 且用户在包含 time.h 前定义 __STDC_WANT_LIB_EXT1__ 为整数常量 1 才保证可用。
//    //    参数
//    //    timer - 指向要转换的 time_t 对象的指针
//    //    buf - 指向要存储结果的 struct tm 对象的指针
//    //    返回值
//    //    1) 成功时返回指向静态的内部 struct tm 对象的指针，失败时返回空指针。该结构体可能会为 gmtime 、 localtime 以及 ctime 所共享，并于每次调用时被覆盖。
//    //    2 - 3) 成功时返回 buf 指针的副本，错误时返回空指针（可能是一个运行时制约违规或对指定时间到 UTC 的转换失败）。
//
//    //将从纪元开始的时间转换成以协调世界时（UTC）表示的日历时间
//
//    time_t t = time(NULL);
//    printf("UTC:   %s", asctime(gmtime(&t)));
//    printf("local: %s", asctime(localtime(&t)));
//
//    #ifdef __STDC_LIB_EXT1__
//        struct tm buf;
//        char str[26];
//        asctime_s(str, sizeof str, gmtime_s(&t, &buf));
//        printf("UTC:   %s", str);
//        asctime_s(str, sizeof str, localtime_s(&t, &buf)));
//        printf("local: %s", str);
//    #endif
//
//    //UTC:   Sun Dec 11 13:02:06 2022
//    //local: Sun Dec 11 21 : 02 : 06 2022
//}
//void mytest13() {
//    //函数
//    //localtime 
//    //localtime_r (C23)
//    //localtime_s (C11)
//    //将从纪元开始的时间转换成以本地时间表示的日历时间
//
//    //在标头 <time.h> 定义
//    //    struct tm* localtime(const time_t * timer);  (1)
//    //    struct tm* localtime_r(const time_t * timer, struct tm* buf); (2)(C23 起)
//    //    error_t    localtime_s(const time_t * restrict timer, struct tm* restrict buf); (3)(C11 起)
//    //    1) 转换给定的纪元起的时间（ timer 所指向的 time_t 值）为以 struct tm 格式表达为本地时间的日历时间。存储结果于静态存储中并返回指向该静态存储的指针。
//    //    2) 同(1) ，除了函数对结果使用用户提供的存储 buf 。
//    //    3) 同(1) ，除了函数对结果使用用户提供的存储 buf 。并且在运行时检测下列错误并调用当前安装的制约处理函数：
//    //    timer 或 buf 为空指针
//    //    同所有边界检查函数， localtime_s 仅若实现定义 __STDC_LIB_EXT1__ 且用户在包含 time.h 前定义 __STDC_WANT_LIB_EXT1__ 为整数常量 1 才保证可用。
//    //    参数
//    //    timer - 指向待转换的 time_t 对象的指针
//    //    buf - 指向待存储结果的 struct tm 对象的的指针
//    //    返回值
//    //    1) 成功时为指向静态内部 tm 对象的指针，否则为空指针。该结构体可能在 gmtime 、 localtime 及 ctime 间共享并可能在每次调用时被重写。
//    //    2 - 3) buf 指针的副本，或在错误（可能为运行时制约违规或转换指定时间为日历时间失败）时为空指针
//
//    time_t t = time(NULL);
//    printf("UTC:   %s", asctime(gmtime(&t)));
//    printf("local: %s", asctime(localtime(&t)));
//
//    #ifdef __STDC_LIB_EXT1__
//        struct tm buf;
//        char str[26];
//        asctime_s(str, sizeof str, gmtime_s(&t, &buf));
//        printf("UTC:   %s", str);
//        asctime_s(str, sizeof str, localtime_s(&t, &buf)));
//        printf("local: %s", str);
//    #endif
//
//    //UTC:   Sun Dec 11 13 : 06 : 15 2022
//    //local : Sun Dec 11 21 : 06 : 15 2022
//}
//void mytest14() {
//    //mktime 函数 
//    //将日历时间转换成纪元开始经过的时间
//
//    //在标头 <time.h> 定义
//    //    time_t mktime(struct tm* time);
//    // 
//    //重整化表示成 struct tm 的本地日历时间，并将其转化成从纪元开始经过时间的 time_t 对象格式。忽略 time->tm_wday 与 time->tm_yday 。容许 time 中的值在其正常范围外。
//    //    time->tm_isdst 的负值会导致 mktime 尝试确定在指定时间夏时令是否有效。
//    //
//    //    若转换到 time_t 成功，则修改 time 会被修改。更新 time 的所有域为符合其正确范围的值。用可用于其他域的信息重新计算 time->tm_wday 与 time->tm_yday 。
//    //
//    //    参数
//    //    time - 指向 struct tm 对象的指针，它指定要转换的本地日历时间
//    //    返回值
//    //    成功时返回表示从纪元开始时间的 time_t 对象，若 time 不能表示成 time_t 对象则返回 - 1 （ POSIX 亦要求此情况下存储 EOVERFLOW 于 errno 中）。
//    //
//    //    注意
//    //    若 struct tm 对象是由 POSIX strptime 或等价的函数取得的，则 tm_isdst 的值不确定，并需要在调用 mktime 前显式设置。
//
//    //setenv("TZ", "/usr/share/zoneinfo/America/New_York", 1); // POSIX 限定
//
//    time_t now = time(NULL);
//    struct tm tm = *localtime(&now);
//    printf("Today is           %s", asctime(&tm));
//    printf("(DST is %s)\n", tm.tm_isdst ? "in effect" : "not in effect");
//    tm.tm_mon -= 100;  // tm_mon 落在正常范围外
//    mktime(&tm);       // tm_dst 不被设为 -1 ；使用今日的 DST 状态
//    printf("100 months ago was %s", asctime(&tm));
//    printf("(DST was %s)\n", tm.tm_isdst ? "in effect" : "not in effect");
//
//    //Today is           Sun Dec 11 21:09 : 28 2022
//    //    (DST is not in effect)
//    //    100 months ago was Mon Aug 11 21 : 09 : 28 2014
//    //    (DST was not in effect)
//
//
//    //今天是2022年12月11日星期日21:09 : 28
//    //（DST未生效）
//    //100个月前是2014年8月11日星期一21 : 09 : 28
//    //（DST未生效）
//
//}
//
//
//
////int main(){
////   
////
////    return 0;
////}