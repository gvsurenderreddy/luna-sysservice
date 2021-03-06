/**
 *  Copyright (c) 2010-2013 LG Electronics, Inc.
 * 
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */

#ifndef DEVICEINFORMATIONSERVICE_H
#define DEVICEINFORMATIONSERVICE_H

#include <string>
#include <map>

#include <nyx/nyx_client.h>
#include <luna-service2/lunaservice.h>

class DeviceInfoService
{
public:
	typedef std::map<std::string, nyx_device_info_type_t> command_map_t;

	static DeviceInfoService* instance();
	void setServiceHandle(LSPalmService* service);
	LSPalmService* serviceHandle() const;

	static bool cbGetDeviceInformation(LSHandle* lshandle, LSMessage *message, void *user_data);

private:
	DeviceInfoService();
	~DeviceInfoService();

	static void initCommandMap();

private:
	LSPalmService* m_service;
	static command_map_t s_commandMap;
};

#endif
