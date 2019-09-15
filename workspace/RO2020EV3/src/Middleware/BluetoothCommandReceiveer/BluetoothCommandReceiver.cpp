#include <BluetoothCommandReceiver.h>

IBluetooth* BluetoothCommandReceiver::m_bluetooth = nullptr;
std::map<String, BluetoothCommandReceiver::CommandCallback>
    BluetoothCommandReceiver::m_commandMap;