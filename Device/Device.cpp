//系统说明：
//单位网络设备管理要求人机对应，每台电脑设备的IP、MAC、使用人，房间号、设备描述都要登记，添加新设备时会分配新的可用IP，以避免IP冲突。
//目前是用一个EXCEL表格管理，每次找新的可用IP时要人工查找。
//现准备利用人工智能辅助编程实现它。
//计划分几个步骤：
//第一阶段：实现设备的增删改查功能。
// 问题规划：
// 实现设备的IP地址，MAC地址、使用人、访问号、设备描述，其中IP地址不可重复。
// 基于GTEST，添加CRUD单元测试
// 
//第二阶段：实现存储
//第三阶段：实现数据库存储。
//第三阶段：添加UI界面。
#include <string>
#include <vector>
#include <iostream>

class Device {
public:
    std::string ip;
    std::string mac;
    std::string name;
    std::string room;
    std::string note;
};

class DeviceManager {
public:
    std::vector<Device> devices;

    bool addDevice(Device device) {
        for (auto& d : devices) {
            if (d.ip == device.ip) {
                return false;
            }
        }
        devices.push_back(device);
        return true;
    }

    bool removeDevice(std::string ip) {
        for (auto it = devices.begin(); it != devices.end(); ++it) {
            if (it->ip == ip) {
                devices.erase(it);
                return true;
            }
        }
        return false;
    }

    bool updateDevice(Device device) {
        for (auto& d : devices) {
            if (d.ip == device.ip) {
                d = device;
                return true;
            }
        }
        return false;
    }

    Device getDevice(std::string ip) {
        for (auto& d : devices) {
            if (d.ip == ip) {
                return d;
            }
        }
        return Device();
    }
};

int main() {
    DeviceManager manager;
    Device device1 = { "192.168.1.1", "00:11:22:33:44:55", "Device1", "Room1", "Note1" };
    Device device2 = { "192.168.1.2", "00:11:22:33:44:56", "Device2", "Room2", "Note2" };

    manager.addDevice(device1);
    manager.addDevice(device2);

    std::cout << "Device 1: " << manager.getDevice("192.168.1.1").name << std::endl;
    std::cout << "Device 2: " << manager.getDevice("192.168.1.2").name << std::endl;

    return 0;
}