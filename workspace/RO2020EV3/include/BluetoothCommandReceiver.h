#pragma once
#include "ZhanUString.h"
#include <map>
#include <RyujiEv3.h>
#include <vector>
#include <Logger.h>

using namespace ZhanU;

class BluetoothCommandReceiver
{
public:

	typedef void(*CommandCallback)(std::vector<String>& arg);

private:

	static std::map<String, CommandCallback> m_commandMap;

	static IBluetooth* m_bluetooth;

public:

	static void init()
	{
		m_bluetooth = RyujiEv3Engine::GetBluetooth();
	}

	static void add(const String& commandName, CommandCallback callback)
	{
		m_commandMap.emplace(commandName, callback);
	}

	static void erase(const String& commandName)
	{
		m_commandMap.erase(commandName);
	}

	static void analyze(const char* commandString)
	{
		constexpr int32_t RECEIVE_BUFFER = 256;

		// ��M������
		char receiveString[RECEIVE_BUFFER];
		::memset(receiveString, '\0', RECEIVE_BUFFER);

		bool argflg = false;

		int32_t pos = 0;

		for (; ; pos++)
		{
			if (commandString[pos] == ' ')
			{
				argflg = true;
				break;
			}
			else if (commandString[pos] == '\0')
			{
				break;
			}
		}

		::memcpy(receiveString, commandString, pos);

		EV3_LOG("Command %s", receiveString);

		//�R�}���h����
		auto itr = m_commandMap.find(receiveString);

		if (itr == m_commandMap.end())
		{
			return;
		}

		// �R�}���h�����z��
		std::vector<String> arg;

		if (argflg)
		{
			pos++;

			// �R�}���h������M
			for (bool receiving = true; receiving;)
			{
				::memset(receiveString, '\0', RECEIVE_BUFFER);

				int32_t head = pos;

				for (;; pos++)
				{
					if (commandString[pos] == ' ')
					{
						break;
					}
					else if (commandString[pos] == '\0')
					{
						receiving = false;
						break;
					}
				}

				pos++;

				::memcpy(receiveString, commandString + head, pos - head);
				EV3_LOG("Arg = %s", receiveString);

				// �R�}���h������ǉ�
				arg.push_back(receiveString);
			}
		}
		
		EV3_LOG("Command Run");
		itr->second(arg);
		EV3_LOG("Command Return");
	}
};