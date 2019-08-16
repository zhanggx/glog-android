#include "log.h"

#include <android/log.h>
#include "glog/logging.h"

JNIEXPORT jint JNICALL Java_org_glog4android_MainActivity_init(JNIEnv *, jobject)
{
    google::InitGoogleLogging("Glog4Android");
    FLAGS_logtostderr = false; //设置日志消息是否转到标准输出而不是日志文件   
    FLAGS_alsologtostderr = true; //设置日志消息除了日志文件之外是否去标准输出
    FLAGS_log_prefix = true; //设置日志前缀是否应该添加到每行输出
    FLAGS_log_dir = "/sdcard/EducationSys/log"; //日志目录，需要预先创建好
    google::SetLogFilenameExtension("log");
    google::SetStderrLogging(google::GLOG_INFO);
    return 0;
}
JNIEXPORT jint JNICALL Java_org_glog4android_MainActivity_shutDown(JNIEnv *, jobject) {
    google::ShutdownGoogleLogging();
}


JNIEXPORT jint JNICALL Java_org_glog4android_MainActivity_startLog(JNIEnv *, jobject)
{
    __android_log_print(ANDROID_LOG_INFO, "Glog4Android", "%s", "Hello, Glog4Android");
    LOG(INFO) <<"Hello, Glog4Android INFO";
    LOG(ERROR) << "Hello Glog4Android ERROR! ";
    LOG(WARNING) << "Hello Glog4Android WARNING! ";
    //LOG(FATAL) << "Hello Glog4Android FATAL! ";//crash here.

	return 0;
}
