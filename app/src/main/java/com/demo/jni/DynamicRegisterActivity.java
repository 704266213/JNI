package com.demo.jni;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.util.Log;

import com.demo.jni.model.UserModel;

public class DynamicRegisterActivity extends AppCompatActivity {

    static {
        System.loadLibrary("dynamic_register");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_dynamic_register);

        int registerCode = getRegisterCode(100);
        Log.e("XLog", "============== registerCode :" + registerCode);


        UserModel userModel = new UserModel();
        userModel.setUserName("jaty");
        userModel.setAge(18);
        userModel.setSex(0);
        Log.e("XLog", "============== userModel:" + userModel.toString());

        UserModel jniCallUserModel = updateUser(userModel);

        Log.e("XLog", "============== jniCallUserModel:" + jniCallUserModel.toString());
        Log.e("XLog", "============== userName:" + jniCallUserModel.getUserName());
        Log.e("XLog", "============== age:" + jniCallUserModel.getAge());
        Log.e("XLog", "============== sex:" + jniCallUserModel.getSex());
    }


    public native int getRegisterCode(int registerCode);


    public native UserModel updateUser(UserModel userModel);


}
