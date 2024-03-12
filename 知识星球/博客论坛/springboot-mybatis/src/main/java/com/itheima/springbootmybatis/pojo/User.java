package com.itheima.springbootmybatis.pojo;

/**
 * @version v1.0
 * @Date:2024-01-01
 * @Description: TODO
 * @Author: yuteng
 */
public class User {
    private  Integer id;
    private String name;
    private Short age;
    private Short gender;
    private String phone;

    public User() {
    }

    public User(Integer id, String name, Short age, Short gender, String phone) {
        this.id = id;
        this.name = name;
        this.age = age;
        this.gender = gender;
        this.phone = phone;
    }

    public void setId(Integer id) {
        this.id = id;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setAge(Short age) {
        this.age = age;
    }

    public void setGender(Short gender) {
        this.gender = gender;
    }

    public void setPhone(String phone) {
        this.phone = phone;
    }

    public Integer getId() {
        return id;
    }

    public String getName() {
        return name;
    }

    public Short getAge() {
        return age;
    }

    public Short getGender() {
        return gender;
    }

    public String getPhone() {
        return phone;
    }
}
