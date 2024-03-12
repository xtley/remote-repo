package org.example;

/**
 * @version v1.0
 * @Date:2024-01-17
 * @Description: TODO
 * @Author: yuteng
 */
public class User {
    private Integer id;
    private String username;
    private String password;

    public void setId(Integer id) {
        this.id = id;
    }

    public Integer getId() {
        return id;
    }

    public String getUsername() {
        return username;
    }

    public String getPassword() {
        return password;
    }

    public void setUsername(String username) {
        this.username = username;
    }

    public void setPassword(String password) {
        this.password = password;
    }
}
