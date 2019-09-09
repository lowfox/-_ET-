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

	using CommandCallback = void(*)(std::vector<String>&);
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

	static void update()
	{
		constexpr int32 RECEIVE_BUFFER = 256;
		uint8 data;

		EV3_LOG("BluetoothUpdate");

		// 受信データなし
		if (!m_bluetooth->read(data))
		{
			return;
		}

		// 受信文字列
		char receiveString[RECEIVE_BUFFER];
		::memset(receiveString, '\0', RECEIVE_BUFFER);
		bool argflg = false;

		// コマンド受信
		for (int32 i = 0; i < RECEIVE_BUFFER; i++)
		{
			while (!m_bluetooth->read(data))
			{
				tslp_tsk(10);
			}

			char c = static_cast<char>(data);

			if (c == ' ')
			{
				argflg = true;
				break;
			}
			else if (c == '\0')
			{
				break;
			}

			receiveString[i] = c;
		}
		EV3_LOG("Command %s", receiveString);

		//コマンド検索
		auto itr = m_commandMap.find(receiveString);

		if (itr == m_commandMap.end())
		{
			return;
		}

		// コマンド引数配列
		std::vector<String> arg;
		
		if (argflg)
		{
			// コマンド引数受信
			for (bool receiving = true; receiving;)
			{
				::memset(receiveString, '\0', RECEIVE_BUFFER);

				for (int32 i = 0; i < RECEIVE_BUFFER; i++)
				{
					while (!m_bluetooth->read(data))
					{
						tslp_tsk(10);
					}

					const char c = static_cast<char>(data);

					if (c == ' ')
					{
						break;
					}
					else if (c == '\0')
					{
						receiving = false;
						break;
					}

					receiveString[i] = c;
				}

				// コマンド引数を追加
				arg.push_back(receiveString);

				EV3_LOG("Command Arg = %s",receiveString);
			}
		}
		// コマンドコールバック実行
		itr->second(arg);
	}
};