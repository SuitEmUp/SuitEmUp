#pragma once

#include <string>
#include <unordered_map>

class Config {
	Config();

public:
	static bool parseFile(std::string _config_file);
	static std::string get(std::string key);
	static int getInt(std::string key, int defaultVal);
	static int getHex(std::string key, int defaultVal);
	static bool getBool(std::string key, bool defaultVal);
	static float getFloat(std::string key, float defaultVal);
	
	static void set(std::string key, std::string value);
	static void renew();
private:
	static std::string config_file;
	static std::unordered_map<std::string, std::string> keys;
};