#include <jni.h>
#include <assert.h>
#include <cstdlib>
#include<android/log.h>

#define TAG "XLog"
#define LOG_E(...) __android_log_print(ANDROID_LOG_INFO,TAG,__VA_ARGS__)

//native 方法实现,需要添加 jobject obj
jint jni_getRegisterCode(JNIEnv *env, jobject obj, jint code) {
    LOG_E("########## code = %d", code);
    return code + 1;
}

//native 方法实现,需要添加 jobject obj
jobject jni_updateUser(JNIEnv *env, jobject obj, jobject userModel) {

//    jclass returnClazz = env->GetObjectClass(userModel);
//    jmethodID setUserNameId = env->GetMethodID(returnClazz, "setUserName", "(Ljava/lang/String;)V");
//    env->CallVoidMethod(userModel, setUserNameId, "alan");

    return userModel;
}

/*需要注册的函数列表，放在JNINativeMethod 类型的数组中，
以后如果需要增加函数，只需在这里添加就行了
参数：
1.java中用native关键字声明的函数名
2.签名（传进来参数类型和返回值类型的说明）
3.C/C++中对应函数的函数名（地址）
 传入的java参数有两个 分别是 int 和 long[] 函数返回值为 String 即函数的定义为：String getString(int a ,long[] b)
签名就应该是 :"(I[J)Ljava/lang/String;"(不要漏掉英文分号)
 凡是Object对象都要加 英文分号 (不论是参数还是返回值)
*/
static JNINativeMethod getMethods[] = {
        {"getRegisterCode", "(I)I",                                                           (void *) jni_getRegisterCode},
        {"updateUser",      "(Lcom/demo/jni/model/UserModel;)Lcom/demo/jni/model/UserModel;", (void *) jni_updateUser},
};

//此函数通过调用RegisterNatives方法来注册我们的函数
static int registerNativeMethods(JNIEnv *env, const char *className, JNINativeMethod *getMethods,
                                 int methodsNum) {
    jclass clazz;
    //找到声明native方法的类
    clazz = env->FindClass(className);
    if (clazz == NULL) {
        return JNI_FALSE;
    }
    //注册函数 参数：java类 所要注册的函数数组 注册函数的个数
    if (env->RegisterNatives(clazz, getMethods, methodsNum) < 0) {
        return JNI_FALSE;
    }
    return JNI_TRUE;
}

static int registerNatives(JNIEnv *env) {
    //指定类的路径，通过FindClass 方法来找到对应的类
    const char *className = "com/demo/jni/DynamicRegisterActivity";
    return registerNativeMethods(env, className, getMethods,
                                 sizeof(getMethods) / sizeof(getMethods[0]));
}


/**
 * 回调函数
 * 动态注册基本思想是在JNI_Onload()函数中通过JNI中提供的RegisterNatives()方法来将C/C++方法和java方法对应起来(注册)
 */
JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM *vm, void *reserved) {
    JNIEnv *env = NULL;
    //获取JNIEnv
    if (vm->GetEnv(reinterpret_cast<void **>(&env), JNI_VERSION_1_6) != JNI_OK) {
        return 0;
    }
    if (vm->GetEnv(reinterpret_cast<void **>(&env), JNI_VERSION_1_4) != JNI_OK) {
        return 0;
    }

    assert(env != NULL);

    //注册函数 registerNatives ->registerNativeMethods ->env->RegisterNatives
    if (!registerNatives(env)) {
        return -1;
    }
    //返回jni 的版本
    return JNI_VERSION_1_6;
}