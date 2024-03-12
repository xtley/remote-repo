package com.sangeng.domain;

import com.fasterxml.jackson.annotation.JsonInclude;
import com.sangeng.enums.AppHttpCodeEnum;
import java.io.Serializable;

/**
 * @version v1.0
 * @Date:2024-01-04
 * @Description: TODO
 * @Author: yuteng
 */
@JsonInclude(JsonInclude.Include.NON_NULL)
public class ResponseResult<T>  implements Serializable {
    private Integer code;
    private String msg;
    private T data;

    public ResponseResult() {
        this.code = AppHttpCodeEnum.SUCCESS.getCode();
        this.msg = AppHttpCodeEnum.SUCCESS.getMsg();
    }

    public ResponseResult(Integer code, T data) {
        this.code = code;
        this.data = data;
    }

    public ResponseResult(Integer code, String msg, T data) {
        this.code = code;
        this.msg = msg;
        this.data = data;
    }

    public static ResponseResult errorResult(int code, String msg) {
        ResponseResult result = new ResponseResult();
        return result.error(code,msg);
    }

    public static ResponseResult okResult() {
        ResponseResult result = new ResponseResult();
        return result;
    }

    public static ResponseResult okResult(int code,String msg) {
        ResponseResult result = new ResponseResult();
        return result.ok(code,null,msg);
    }

    public static ResponseResult okResult(Object data) {
        ResponseResult result = setAppHttpCodeEnum(AppHttpCodeEnum.SUCCESS,AppHttpCodeEnum.SUCCESS.getMsg());
        if(data!=null) {
            result.setData(data);
        }
        return result;
    }
    public static ResponseResult errorResult(AppHttpCodeEnum enums) {
        return setAppHttpCodeEnum(enums,enums.getMsg());
    }
    public static ResponseResult errorResult(AppHttpCodeEnum enums,String Msg) {
        return setAppHttpCodeEnum(enums,Msg);
    }
    public static ResponseResult setAppHttpCodeEnum(AppHttpCodeEnum enums) {
        return okResult(enums.getCode(),enums.getMsg());
    }

    public static ResponseResult setAppHttpCodeEnum(AppHttpCodeEnum enums,String msg) {
        return okResult(enums.getCode(),msg);
    }
    public ResponseResult<?> error(Integer code,String msg) {
        this.code=code;
        this.msg=msg;
        return this;
    }

    public ResponseResult<?> ok(Integer code,String msg) {
        this.code=code;
        this.msg=msg;
        return this;
    }

    public ResponseResult<?> ok(Integer code,T data,String msg) {
        this.code=code;
        this.data=data;
        this.msg=msg;
        return this;
    }

    public ResponseResult<?> ok(T data) {
        this.data=data;
        return this;
    }

    // Get Set
    public Integer getCode() {
        return code;
    }

    public String getMsg() {
        return msg;
    }

    public T getData() {
        return data;
    }

    public void setCode(Integer code) {
        this.code = code;
    }

    public void setMsg(String msg) {
        this.msg = msg;
    }

    public void setData(T data) {
        this.data = data;
    }
}

