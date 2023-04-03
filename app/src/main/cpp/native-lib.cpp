#include <jni.h>
#include <string>
#include <memory>
#include <thread>
#include <iostream>
#include <android/sensor.h>
#include <android/log.h>
#include "opencv2/core.hpp"

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_sensorapp_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject thiz) {

        std::cout << "OpenCV Version " << cv::getVersionString() << std::endl;
        std::string message = "OpenCV Version: " + cv::getVersionString()
                + " " + cv::getCPUFeaturesLine() + "\n";
        unsigned int numberOfThreads = std::thread::hardware_concurrency();
        message.append("Number of threads: " + std::to_string(numberOfThreads) + "\n");
        std::cout << "Number of threads: " + std::to_string(numberOfThreads) << std::endl;
        const char* packageName = "com.example";
        ASensorManager *sensorManager = ASensorManager_getInstanceForPackage(packageName);

        ASensorList sensorList;
        int sensorCount = ASensorManager_getSensorList(sensorManager, &sensorList);
        message.append("Number of sensors: " + std::to_string(sensorCount) + "\n");
        std::cout << message << std::endl;

        for(int i = 0; i < sensorCount; i++ ) {
            message.append(ASensor_getName(sensorList[i])).append("\n");
            std::cout << i << " Sensor: " << ASensor_getName(sensorList[i]) << std::endl;
        }
        return env->NewStringUTF(message.c_str());
    }