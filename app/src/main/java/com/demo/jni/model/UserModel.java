package com.demo.jni.model;

public class UserModel {

    private String userName;
    private int sex;
    private int age;

    public UserModel() {
    }

    public UserModel(String userName, int sex, int age) {
        this.userName = userName;
        this.sex = sex;
        this.age = age;
    }

    public String getUserName() {
        return userName;
    }

    public void setUserName(String userName) {
        this.userName = userName;
    }

    public int getSex() {
        return sex;
    }

    public void setSex(int sex) {
        this.sex = sex;
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        this.age = age;
    }
}
