package com.atguigu04._throw;

/**
 * @version v1.0
 * @Date:2023-10-02
 * @Description: TODO(一句话描述该类的功能)
 * @Author: x.t.
 */
public class BelowZeroException extends Exception{
    static final long serialVersionUID = -3387516933124229948L;
    public BelowZeroException() {

    }

    public BelowZeroException(String name) {
        super(name);
    }

    public BelowZeroException(String message, Throwable cause) {
        super(message, cause);
    }
}
