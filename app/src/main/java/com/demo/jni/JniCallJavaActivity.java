package com.demo.jni;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.util.Log;

import com.demo.jni.model.UserModel;

public class JniCallJavaActivity extends AppCompatActivity {

    static {
        System.loadLibrary("native-lib");
    }

    public native UserModel jniCallJava(UserModel userModel);

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_jni_call_java);


        UserModel userModel = new UserModel();
        userModel.setUserName("jaty");
        userModel.setAge(18);
        userModel.setSex(0);
        Log.e("XLog", "============== userModel:" + userModel.toString());

        UserModel jniCallUserModel = jniCallJava(userModel);

        Log.e("XLog", "============== jniCallUserModel:" + jniCallUserModel.toString());
        Log.e("XLog", "============== userName:" + jniCallUserModel.getUserName());
        Log.e("XLog", "============== age:" + jniCallUserModel.getAge());
        Log.e("XLog", "============== sex:" + jniCallUserModel.getSex());

    }
}
