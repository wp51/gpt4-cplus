// Device.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
//系统说明：
//实现对每台设备的IP、MAC、使用人，房间号、设备描述信息进行管理，其中IP地址不可重复。实现增删改查功能。
//现准备利用人工智能辅助编程实现它。
//计划分几个步骤：
//第一阶段：每台设备有IP、MAC、name，room、note四个属性，其中ip不可重复，实现设备的增删改查功能，同时为新增设备提供当前可用ip查询。
// 问题规划：
// 实现设备管理，每台设备有ip、mac、name，room、note四个属性，其中ip不可重复。
// 基于GTEST，添加CRUD单元测试
// 
//第二阶段：实现存储
//第三阶段：实现数据库存储。
//第三阶段：添加UI界面。

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Device {
    string ip;
    string mac;
    string name;
    string room;
    string note;
};

vector<Device> devices;

bool isIpExist(string ip) {
    for (auto device : devices) {
        if (device.ip == ip) {
            return true;
        }
    }
    return false;
}

bool isIpAvailable(string ip) {
    for (int i = 1; i <= 255; i++) {
        string testIp = ip.substr(0, ip.rfind(".") + 1) + to_string(i);
        if (!isIpExist(testIp)) {
            return true;
        }
    }
    return false;
}

void addDevice() {
    Device device;
    cout << "请输入设备IP地址：";
    cin >> device.ip;
    if (!isIpAvailable(device.ip)) {
        cout << "该IP地址已存在，请重新输入！" << endl;
        return;
    }
    cout << "请输入设备MAC地址：";
    cin >> device.mac;
    cout << "请输入设备名称：";
    cin >> device.name;
    cout << "请输入设备所在房间号：";
    cin >> device.room;
    cout << "请输入设备描述信息：";
    cin >> device.note;
    devices.push_back(device);
    cout << "设备添加成功！" << endl;
}

void deleteDevice() {
    string ip;
    cout << "请输入要删除的设备IP地址：";
    cin >> ip;
    for (auto it = devices.begin(); it != devices.end(); it++) {
        if (it->ip == ip) {
            devices.erase(it);
            cout << "设备删除成功！" << endl;
            return;
        }
    }
    cout << "未找到该设备！" << endl;
}

void updateDevice() {
    string ip;
    cout << "请输入要修改的设备IP地址：";
    cin >> ip;
    for (auto it = devices.begin(); it != devices.end(); it++) {
        if (it->ip == ip) {
            cout << "请输入设备MAC地址：";
            cin >> it->mac;
            cout << "请输入设备名称：";
            cin >> it->name;
            cout << "请输入设备所在房间号：";
            cin >> it->room;
            cout << "请输入设备描述信息：";
            cin >> it->note;
            cout << "设备修改成功！" << endl;
            return;
        }
    }
    cout << "未找到该设备！" << endl;
}

void listDevices() {
    if (devices.empty()) {
        cout << "当前无设备！" << endl;
        return;
    }
    cout << "设备列表：" << endl;
    for (auto device : devices) {
        cout << "IP地址：" << device.ip << endl;
        cout << "MAC地址：" << device.mac << endl;
        cout << "设备名称：" << device.name << endl;
        cout << "所在房间号：" << device.room << endl;
        cout << "设备描述信息：" << device.note << endl;
        cout << endl;
    }
}

void listAvailableIps() {
    cout << "当前可用IP地址：" << endl;
    for (int i = 1; i <= 255; i++) {
        string testIp = "192.168.1." + to_string(i);
        if (!isIpExist(testIp)) {
            cout << testIp << endl;
        }
    }
}

int main() {
    int choice;
    while (true) {
        cout << "请选择操作：" << endl;
        cout << "1. 添加设备" << endl;
        cout << "2. 删除设备" << endl;
        cout << "3. 修改设备" << endl;
        cout << "4. 查看设备列表" << endl;
        cout << "5. 查看当前可用IP地址" << endl;
        cout << "0. 退出" << endl;
        cin >> choice;
        switch (choice) {
        case 1:
            addDevice();
            break;
        case 2:
            deleteDevice();
            break;
        case 3:
            updateDevice();
            break;
        case 4:
            listDevices();
            break;
        case 5:
            listAvailableIps();
            break;
        case 0:
            return 0;
        default:
            cout << "输入有误，请重新输入！" << endl;
            break;
        }
    }
}