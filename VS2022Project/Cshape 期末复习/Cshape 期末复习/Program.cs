using System;
namespace Program
{
    /* 类名为 HelloWorld */
    class HelloWorld
    {
        /* main函数 */
        static void Main(string[] args)
        {
            // 输出
            Console.WriteLine("Hello World!");

            // 控制台输入 
            //string str=Console.ReadLine();


            // 装箱
            object obj = 100;
            //拆箱


            // 字符串 
            string str = "runoob.com";
            // @号字符串称作(逐字字符串) 将转义字符 当作普通字符对待
            str = @"C:\Windows";   //字符串之间的换行也会被记录
                                   //指针类型 
                                   //type* identifier;

            //char* cptr;
            //int* iptr;

            //类型转换
            //To Boolean Byte Char DataTime ...

            int i = 75;
            Console.WriteLine(i.ToString());
            //接受来自用户的值
            int num;
            num=Convert.ToInt32(Console.ReadLine()); ;
            Console.WriteLine(num.ToString());
            // sizeof() 返回数据类型的大小
            // typeof() 返回class的类型
            // ?:
            // is对象是否为某一类型
            // as强制转换 即使转换失败也不会抛出异常

            // switch 语句
            //switch (表达式)
            //{
            //    case value1:

            //        break;

            //    default:
            //        break;
            //}

            // foreach循环
            //foreach(数据类型 变量名 in 数组或集合对象)
            //{
            //    语句块;
            //}
            //foreach 会在每次循环的过程中，
            //依次从数组或集合对象中取出一个新的元素放到foreach()里定义的变量中，
            //直到所有元素都成功取出后退出循环。

            //goto
            //goto Labels;
            //语句块1;
            //Labels;
            //   语句块2;

            //函数 
            //访问修饰符 返回类型 函数名(参数列表){

            //    语句
            //    return;
            //}

            //函数调用
            //    若调用同一个类中静态函数
            //   （使用 static 修饰的函数），则可以省略实例化对象的过程，直接使用 函数名() 的形式调用。
            //类中的静态函数
            static string Output(string message)
            {
                string str = "欢迎访问:" + message;
                return str;
            }

            //封状
            //访问权限修饰符
            //public 可以从类外访问类内的成员函数
            //private 不可在类外访问
            //protected 可在类内访问 或其子类访问
            //internal 任何使用 internal 修饰的成员都可以被同一命名空间下的任何类或方法访问。
            //protected internal 可以在本类、派生类或者包含该类（使用 using 引入）的程序集中访问，在实现继承时也使用此方法。

            //C# 值传递 引用传递 输出传递
            //使用 return 语句可以从函数中返回一个值，但是使用输出传递则可以从函数中一次性返回多个值。
            //输出传递与引用传递相似，不同之处在于输出传递是将数据从函数中传输出来而不是传输到函数中。


            //nullable 可空类型
            //Null 合并运算符
            //a ?? b 中，如果 a 不为空，那么表达式的值则为 a，反之则为 b。

            //数组
            //data_type[] array_name;
            //数组赋值
            //初始化赋值
            //int[] arr2 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
            //带new(预设数组长度)赋值
            //int[] arr2 = new int[10]{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
            //可省数组长度
            //int[] arr2 = new int[]{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
            //单个赋值
            //int[] arr=new int[10];
            //arr[0]=10;
            //arr[1]=11;

            //多维数组
            //声明-在括号内添加逗号
            //int[,] arr=new int[3,3]; 声明一个二维数组
            //int[,] arr=new int[3,3,3] 声明一个三位数组
            //初始化二维数组
            //int[,] arr = new int[3,4]{
            // 第一种方式
            // int[,] arr = new int[3, 4]{
            //    {0, 1, 2, 3},
            //    {4, 5, 6, 7},
            //    {8, 9, 10, 11}
            //};
            // // 第二种方式
            // int[,] arr = new int[,]{
            //    {0, 1, 2, 3},
            //    {4, 5, 6, 7},
            //    {8, 9, 10, 11}
            //};
            // // 第三种方式
            //int[,] arr = {
            //    {0, 1, 2, 3},
            //    {4, 5, 6, 7},
            //    {8, 9, 10, 11}
            //    };
            //访问二维数组中的单个元素
            //int[,] arr = new int[3, 4]{
            //{0, 1, 2, 3},
            //{4, 5, 6, 7},
            //{8, 9, 10, 11}
            // };
            // int a = arr[1, 0];

            //交错数组
            //data_type[][] array_name;
            // 假如要声明一个具有三个元素的一维交错数组，并且数组中的每个元素都是一个一维的整型数组，示例代码如下：
            // int[][] jaggedArray = new int[3][];
            // 初始化交错数组
            // 方式1
            //int[][] jaggedArray = new int[3][]; // 定义一个交错数组
            //jaggedArray[0] = new int[5];        // 对数组的第一个元素初始化
            //jaggedArray[1] = new int[4];        // 对数组的第二个元素初始化
            //jaggedArray[2] = new int[2];        // 对数组的第三个元素初始化
            // 方式2
            //int[][] jaggedArray = new int[3][]; // 定义一个交错数组
            //jaggedArray[0] = new int[] { 1, 2, 3, 4, 5 };
            //jaggedArray[1] = new int[] { 6, 7, 8, 9 };
            //jaggedArray[2] = new int[] { 10, 11 };
            // 方式3
            //int[][] jaggedArray = new int[][]{
            // new int[] {1, 2, 3, 4, 5},
            // new int[] {6, 7, 8, 9},
            // new int[] {10, 11}
            //};
            //方式4
            //int[][] jaggedArray = {
            //new int[] {1, 2, 3, 4, 5},
            //new int[] {6, 7, 8, 9},
            //new int[] {10, 11}
            //};
            //交错数组元素访问
            //    int a = jaggedArray[0][1]    // 变量 a 的值为：2
            //    jaggedArray[2][1] = 0         // 将交错数组中第三个数组元素中的第二个元素赋值为 0

            //参数数组
            //语法格式
            //访问权限修饰符 返回值类型 函数名(params 类型名称[] 数组名称)

            //Array 类
            //属性
            //IsFixedSize 	检查数组是否具有固定大小
            //IsReadOnly 	检查数组是否为只读
            //IsSynchronized  	检查是否同步对数组的访问（线程安全）
            //Length 	获取数组中所有维度中元素的总数
            //LongLength 	获取数组中所有维数中元素的总数，并返回一个 64 位整数
            //Rank 	获取数组的秩（维数），例如一维数组返回 1，二维数组返回 2，依次类推
            //SyncRoot 	用来获取一个对象，该对象可以用于同步对数组的访问
            //方法
            //Clear(Array, Int32, Int32) 	将数组中指定范围内的元素设置为该元素所属类型的默认值
            //Copy(Array, Array, Int32) 	从第一个元素开始拷贝数组中指定长度的元素，并将其粘贴到另一个数组中（从第一个元素开始粘贴），使用 32 位整数来指定要拷贝的长度
            //CopyTo(Array, Int32) 	从指定的目标数组索引处开始，将当前一维数组的所有元素复制到指定的一维数组中，索引使用 32 位整数指定
            //GetLength 	获取数组指定维度中的元素数，并返回一个 32 位整数
            //GetLongLength 	获取数组指定维度中的元素数，并返回一个 64 位整数 
            //GetLowerBound 	获取数组中指定维度第一个元素的索引
            //GetType 	获取当前实例的类型（继承自 Object ）
            //GetUpperBound 	获取数组中指定维度最后一个元素的索引
            //GetValue(Int32) 	获取一维数组中指定位置的值
            //IndexOf(Array, Object) 	在一个一维数组中搜索指定对象，并返回其首个匹配项的索引
            //Reverse(Array) 	反转整个一维数组中元素的顺序
            //SetValue(Object, Int32) 	设置一维数组中指定元素的值
            //Sort(Array) 	对一维数组中的元素排序
            //ToString() 	返回一个表示当前对象的字符串（继承自 Object）

        }
    }
}