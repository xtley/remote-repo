/**
 * @version v1.0
 * @Date:2023-10-06
 * @Description: TODO(一句话描述该类的功能)
 * @Author: x.t.
 */
public class VariableTest2 {
    public static void main(String[] args) {
        /*
           测试字符类型和布尔类型的使用
        */

        /*
           字符类型： char(2字节)
           Java中所有字符类型都使用Unicode编码，
           故一个字符可以存储一个字母，一个汉字，或其他
           书面语的一个字符。
           字符型常量的三种表现形式：
             形式1：使用单引号('')括起来的单个字符
                例如：char c1 = 'a'; char c2 = '中'; char c3 = '9';
             形式2：直接使用Unicode值来表示字符型常量:'\(u)XXXX'。其中XXXX代表一个16进制数
                例如：\u0023表示'#'。
             形式3：Java中还允许使用转义字符'\'来将其后的字符转变为特殊字符型的常量
                例如：char c3 = '\n'; // ‘\n’表示换行符
             形式4: 使用具体字符对应的数值 如ASCII码
                例如：char c4 = 97; a
        */

        // 1.字符类型：char(2字节)

        // 表现形式1: 使用一对''表示，内有且只有一个字符。

        char c1 = 'a';
        char c2 = '中';
        char c3 = '1';
        char c4 = '\u0002';
        char c5 = 97; // a
        System.out.println(c5);
        // 2.boolean类型：
        // 只有两个取值：true / false
        // 不可以使用0或非0的整数代替false和ture,这点和c语言不同。
        boolean bo1 = true;
        boolean bo2 = false;

        // 编译不通过
        // boolean bo3 = 0;
        // 常使用在流程控制语句中。比如：条件判断，循环结构
        // 拓展：Java虚拟机中没有任何供boolean值专用的字节码指令，
        // Java语言表达所操作的boolean值，在编译之后都使用Java
        // 虚拟机中的int数据类型来代替：true用1表示，false用0表示。
        // 《java虚拟机规范 8版》
        boolean isMarried = true;
        if(isMarried) {
            System.out.println("很抱歉，不能参加单身派对了");
        }else {
            System.out.println("可以多谈几个女朋友或男朋友");
        }
        // 了解：我们不谈boolean类型占用的空间大小。但是，真正内存中
        // 分配的话是4个字节。
    }

}
