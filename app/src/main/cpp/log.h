#include <jni.h>

#ifndef _Included_org_glog4android_MainActivity
#define _Included_org_glog4android_MainActivity
#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT jint JNICALL Java_org_glog4android_MainActivity_init
  (JNIEnv *, jobject);
JNIEXPORT jint JNICALL Java_org_glog4android_MainActivity_shutDown
        (JNIEnv *, jobject);

JNIEXPORT jint JNICALL Java_org_glog4android_MainActivity_startLog
        (JNIEnv *, jobject);
#ifdef __cplusplus
}
#endif
#endif