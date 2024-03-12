/**
 * @version v1.0
 * @Date:2023-10-09
 * @Description: TODO(一句话描述该类的功能)
 * @Author: x.t.
 */
public class OneArrayTest1 {
    public static void main(String[] args) {
        // 5. 数组元素的默认初始化值

        /*
        * 整型(byte \ shrt \ int \long)数组初始化默认值：0
        */
        int[] arr1 = new int[3];
        System.out.println(arr1[0]);

        short[] arr2 = new short[4];
        for(int i=0;i<arr2.length;i++) {
            System.out.println(arr2[i]);
        }
        /*
        * 浮点型数组元素的默认初始化值：
        */
        double[] arr3 = new double[3];
        System.out.println(arr3[0]);

        /* 字符型数组元素的默认初始化值： 0 或理解为 '\u0000' Ascll码的0 不是'0' 这个Ascll码的值是48
        *
        */
        char[] arr4 = new char[4];
        System.out.println(arr4[0]);
        if(arr4[0] == 0) {
            System.out.println("1111");
        }
        if(arr4[0] == '0'){
            System.out.println("2222");
        }

        if(arr4[0] == '\u0000'){
            System.out.println("3333");
        }
        System.out.println(arr4[0]+1); // 1转换为 int 型 直接用Ascll的数字进行操作
        /*
        * boolean型数组元素的默认初始化值：false
        */
        boolean[] arr5 = new boolean[4];
        System.out.println(arr5[0]);

        /*
        * 引用数据类型元素的默认初始化值：null
        * */
        String[] arr6 = new String[5];
        for(int i=0;i<arr6.length;i++) {
            System.out.println(arr6[i]);
        }

        if(arr6[0] == null) {
            System.out.println("aaaa");
        }
        if(arr6[0] == null) {
            System.out.println("bbbb");
        }
        // 6. 数组的内存解析



    }
}
