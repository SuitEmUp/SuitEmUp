#include <fstream>
#include <ostream>
#include <iostream>
#include <map>
#include <vector>

#include "Utils.h"
#include "Config.h"

std::unordered_map<std::string, std::string> Config::keys;
std::string Config::config_file;

Config::Config() {

}

bool Config::parseFile(std::string _config_file) {
	config_file = _config_file;
	std::ifstream file(_config_file);
	std::string single_row;
	std::vector<std::string> configs;
	configs.clear();

	if(!file.is_open()) return false;

	while(!file.eof()) {
		std::getline(file, single_row, '\n');
		if(single_row.size() == 0) {
			// Empty line, we still need to store because we write back to the file
			keys.insert(std::pair<std::string, std::string>("", ""));
			continue;
		}
		Utils::split(single_row, '=', configs);
		auto it = keys.find(configs.front());
		if(it != keys.end()) 
			printf("Config::parseFile() Key already exists: %s\n", configs.front().c_str());
		else
			keys.insert(std::pair<std::string, std::string>(configs.front(), configs.back()));
		configs.clear();
	}
	file.close();

	return true;
}

std::string Config::get(std::string key) {
	auto it = keys.find(key);
	if(it == keys.end()) {
		printf("Config::get() Key %s was not found\n", key.c_str());
		return "";
	}
	return (*it).second;
}

int Config::getInt(std::string key, int defaultVal) {
    std::string value = Config::get(key);
    if (value.empty())
		return defaultVal;

	return Utils::string_to_int(value);
}

int Config::getHex(std::string key, int defaultVal) {
	std::string value = Config::get(key);
    if (value.empty())
		return defaultVal;

	return Utils::string_to_hex(value);
}

bool Config::getBool(std::string key, bool defaultVal) {
	if(key.empty()) return defaultVal;
	std::string val = Config::get(key);
	if(val.empty()) return defaultVal;
	if(val == "true" || val == "yes" || val == "1")
		return true;
	return false;
}

float Config::getFloat(std::string key, float defaultVal) {
	if(key.empty()) return defaultVal;
	std::string val = Config::get(key);
	if(val.empty()) return defaultVal;
	return Utils::string_to_float(val);
}

void Config::set(std::string key, std::string value) {
	auto it = keys.find(key);
	if(it == keys.end()) return;
	it->second = value;
}

void Config::renew() {
	std::ofstream ostream(config_file);
	if(!ostream) { 
		printf("Can't open file: %s", config_file.c_str());
		return;
	}
	for(auto it = keys.begin(); it != keys.end(); ++it) {
		if(it->first.empty() && it->second.empty()) {
			ostream << std::endl;
		} else {
			ostream << it->first << " = " << it->second << std::endl;
		}
	}
	ostream.close();
}