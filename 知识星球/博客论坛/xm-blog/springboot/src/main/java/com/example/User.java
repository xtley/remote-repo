package com.example;

/**
 * @version v1.0
 * @Date:2023-12-31
 * @Description: TODO
 * @Author: yuteng
 */
public class User {
    private Integer id;
    private String userName;
    private String passWord;
    private String sex;

    public void setId(Integer id) {
        this.id = id;
    }

    public void setUserName(String userName) {
        this.userName = userName;
    }

    public void setPassWord(String passWord) {
        this.passWord = passWord;
    }

    public void setSex(String sex) {
        this.sex = sex;
    }

    public Integer getId() {
        return id;
    }

    public String getUserName() {
        return userName;
    }

    public String getPassWord() {
        return passWord;
    }

    public String getSex() {
        return sex;
    }
}