#include <jni.h>
#include <iostream>
#include <functional>
#include "mapbox_java.h"
#include "../src/map.hpp"

using namespace std;

JNIEXPORT void JNICALL Java_MapboxJNI_render  (JNIEnv *env, jobject thisObject, jstring url, jobject callback) {
    StyledMap map;
    const char* urlChrp = env->GetStringUTFChars(url, NULL);

    jclass callbackClass=env->GetObjectClass(callback);
    jmethodID methodId=env->GetMethodID(callbackClass, "callback", "()V");

    map.render(urlChrp, [&](){
            env->CallObjectMethod(callback, methodId); 
        });
}
