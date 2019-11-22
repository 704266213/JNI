#include <jni.h>
#include <string>
#include <iostream>
#include<android/log.h>

#define TAG "XLog"
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG,TAG,__VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_INFO,TAG,__VA_ARGS__)


extern "C" JNIEXPORT jobject JNICALL
Java_com_demo_jni_JniCallJavaActivity_jniCallJava(JNIEnv *env, jobject obj, jobject userModel) {

    LOGD("===========开始执行JNI===============");
    //获取该对象的类
    jclass userModelClass = env->GetObjectClass(userModel);
    jfieldID userNameFieldId = env->GetFieldID(userModelClass, "userName", "Ljava/lang/String;");
    jfieldID sexFieldId = env->GetFieldID(userModelClass, "sex", "I");
    jfieldID ageFieldId = env->GetFieldID(userModelClass, "age", "I");


    jobject javaUserName = env->GetObjectField(userModel, userNameFieldId);
//    LOGE("########## javaUserName = %s", javaUserName);
    int sex = env->GetIntField(userModel, sexFieldId);
    LOGE("########## sex = %d", sex);
    int age = env->GetIntField(userModel, ageFieldId);
    LOGE("########## age = %d", age);

    //创建对象的本地变量
//    jobject object = (*env).NewGlobalRef(userModel);



    jclass returnClazz = env->FindClass("com/demo/jni/model/UserModel");
    jmethodID initMethodId = env->GetMethodID(returnClazz, "<init>", "()V");
    jobject user = env->NewObject(returnClazz, initMethodId);

    jmethodID setUserNameMethodId = env->GetMethodID(returnClazz, "setUserName",
                                                     "(Ljava/lang/String;)V");
    jstring userName = env->NewStringUTF("alan");
    env->CallVoidMethod(user, setUserNameMethodId, userName);

    jmethodID setSexMethodId = env->GetMethodID(returnClazz, "setSex", "(I)V");
    env->CallVoidMethod(user, setSexMethodId, 1);

    jmethodID setAgeMethodId = env->GetMethodID(returnClazz, "setAge", "(I)V");
    env->CallVoidMethod(user, setAgeMethodId, 20);

    return user;

}