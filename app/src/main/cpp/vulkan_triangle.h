//
// Created by Piasy on 29/06/2017.
//

#ifndef VULKANTUTORIAL_ANDROID_VULKAN_TRIANGLE_H
#define VULKANTUTORIAL_ANDROID_VULKAN_TRIANGLE_H

#include <jni.h>
#include <android/log.h>
#include<android/native_window_jni.h>

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <stdexcept>
#include <cstring>
#include <functional>

#include "vulkan_wrapper/vulkan_wrapper.h"

#define APP_NAME "VK-TUTORIAL"
#define LOGI(...) ((void)__android_log_print(ANDROID_LOG_INFO, APP_NAME, __VA_ARGS__))
#define LOGE(...) ((void)__android_log_print(ANDROID_LOG_ERROR, APP_NAME, __VA_ARGS__))

struct QueueFamilyIndices {
    int graphicsFamily = -1;
    int presentFamily = -1;

    bool isComplete() {
        return graphicsFamily >= 0 && presentFamily >= 0;
    }
};

struct SwapchainSupportDetails {
    VkSurfaceCapabilitiesKHR capabilities;
    std::vector<VkSurfaceFormatKHR> formats;
    std::vector<VkPresentModeKHR> presentModes;
};

class HelloTriangleApplication {
public:
    void run(ANativeWindow *window);

private:
    inline void initWindow(ANativeWindow *window) {
        this->window = window;
    }

    void initVulkan();

    void createInstance();

    void setUpDebugCallback();

    void createSurface();

    void pickPhysicalDevice();

    void createLogicalDevice();

    void createSwapchain();

    void createImageViews();

    bool isDeviceSuitable(VkPhysicalDevice device);

    bool checkDeviceExtensionSupport(VkPhysicalDevice device);

    QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device);

    SwapchainSupportDetails querySwapchainSupport(VkPhysicalDevice device);

    void mainLoop();

    void cleanUp();

    VkInstance instance;
    VkDebugReportCallbackEXT callback;
    ANativeWindow *window;
    VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;
    VkDevice device;
    VkQueue graphicsQueue;
    VkQueue presentQueue;
    VkSurfaceKHR surface;
    VkSwapchainKHR swapchain;
    std::vector<VkImage> swapchainImages;
    std::vector<VkImageView> swapchainImageViews;
    VkFormat swapChainImageFormat;
    VkExtent2D swapChainExtent;
};

#endif //VULKANTUTORIAL_ANDROID_VULKAN_TRIANGLE_H
