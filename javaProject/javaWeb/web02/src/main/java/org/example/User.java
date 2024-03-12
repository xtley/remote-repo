package org.example;

/**
 * @version v1.0
 * @Date:2023-12-21
 * @Description: TODO
 * @Author: yuteng
 */
public class User {
    private String username;      // 用户姓名
    private String password;
    private String phone;                  // 用户手机号

    public String getUsername() {
        return username;
    }

    public String getPassword() {
        return password;
    }

    public String getPhone() {
        return phone;
    }

    public void setUsername(String username) {
        this.username = username;
    }

    public void setPassword(String password) {
        this.password = password;
    }

    public void setPhone(String phone) {
        this.phone = phone;
    }
}