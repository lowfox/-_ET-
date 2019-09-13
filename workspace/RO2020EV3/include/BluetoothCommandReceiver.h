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

	typedef void(*CommandCallback)(std::vector<const char*>& arg);

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

	static void analyze(char* commandString)
	{
		constexpr int32_t RECEIVE_BUFFER = 256;

		// 受信文字列
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

		//コマンド検索
		auto itr = m_commandMap.find(receiveString);

		if (itr == m_commandMap.end())
		{
			return;
		}

		// コマンド引数配列
		std::vector<const char*> arg;

		if (argflg)
		{
			pos++;

			// コマンド引数受信
			for (bool receiving = true; receiving;)
			{
				::memset(receiveString, '\0', RECEIVE_BUFFER);

				int32_t head = pos;

				for (;; pos++)
				{
					if (commandString[pos] == ' ')
					{
						commandString[pos] = '\0';
						break;
					}
					else if (commandString[pos] == '\0')
					{
						receiving = false;
						break;
					}
				}

				pos++;

				//::memcpy(receiveString, commandString + head, pos - head);
				EV3_LOG("Arg = %s", receiveString);

				//String a{ receiveString };
				// コマンド引数を追加
				arg.push_back(commandString + head);
			}
		}
		
		EV3_LOG("Command Run");
		itr->second(arg);
		EV3_LOG("Command Return");
	}
};