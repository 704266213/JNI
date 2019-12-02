package com.demo.jni;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity implements View.OnClickListener {


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        TextView jniCallJava = findViewById(R.id.jniCallJava);
        jniCallJava.setOnClickListener(this);

        TextView jniDynamicRegistered = findViewById(R.id.jniDynamicRegistered);
        jniDynamicRegistered.setOnClickListener(this);


    }

    @Override
    public void onClick(View view) {
        Intent intent = null;
        switch (view.getId()) {
            case R.id.jniCallJava:
                intent = new Intent(this, JniCallJavaActivity.class);
                break;
            case R.id.jniDynamicRegistered:
                intent = new Intent(this, DynamicRegisterActivity.class);

                break;
        }
        startActivity(intent);
    }


}
