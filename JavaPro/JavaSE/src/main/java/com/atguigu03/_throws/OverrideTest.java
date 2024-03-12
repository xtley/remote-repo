package com.atguigu03._throws;

import java.io.FileNotFoundException;
import java.io.IOException;

/**
 * @version v1.0
 * @Date:2023-10-01
 * @Description: TODO(一句话描述该类的功能)
 * @Author: x.t.
 */
public class OverrideTest {

}
class Father{
    public void method1() throws IOException {

    }
}

class Son extends Father{
    public void method1() throws FileNotFoundException {

    }
}