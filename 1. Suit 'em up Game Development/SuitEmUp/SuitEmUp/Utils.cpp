#include <random>
#include <chrono>
#include <sstream>
#include <string>
#include <algorithm>
#include <cctype>
#include <functional>
#include <locale>
#include <cfloat>

#include "Utils.h"

namespace Utils {
	namespace Random {
		std::mt19937 engine;
	
		int Utils::Random::random(int min, int max) {
			std::uniform_int_distribution<int> distance(min, max);
			return distance(engine);
		}

		float Utils::Random::frandom(float min, float max) {
			std::uniform_real_distribution<float> distance(min, max);
			return distance(engine);
		}

		void Utils::Random::seed() {
			engine.seed(time(nullptr));
		}
	}

	namespace File {
		void Utils::File::CreateFile(std::string filename) {

		}
	}

	uint64_t Utils::GetTimeByMilliseconds() {
		return std::chrono::duration_cast<std::chrono::milliseconds>  (std::chrono::system_clock::now().time_since_epoch()).count();
	}

	long long GetTimeBySeconds() {
		return std::chrono::duration_cast<std::chrono::seconds>  (std::chrono::system_clock::now().time_since_epoch()).count();
	}

	std::string Utils::int_to_string(int v) {
		std::ostringstream ostr;
		ostr << v;
		return ostr.str();
	}

	std::string Utils::longlong_to_string(long long v) {
		std::ostringstream ostr;
		ostr << v;
		return ostr.str();
	}

	float string_to_float(std::string s) {
		return std::stof(s);
	}

	std::string float_to_string(float v) {
		std::ostringstream ss;
		ss << v;
		return std::string(ss.str());
	}

	std::vector<std::string> &Utils::split(const std::string &s, char delim, std::vector<std::string> &elems) {
		std::stringstream ss(s);
		std::string item;
		while (std::getline(ss, item, delim)) {
			elems.push_back(Utils::trim(item));
		}
		return elems;
	}

	float Utils::roundToNearestN(float x, float n)  {
		float fmod = fmodf(x, n);
		if(fmod < n*.5) { return ceil(x + fmod); }
		return ceil(x - fmod);
	}

	float Utils::round(float value, float prec) {
		return (floor((value * pow(10, prec) + 0.5)) / pow(10, prec)); 
	}

	std::string &Utils::ltrim(std::string &s) {
			s.erase(s.begin(), std::find_if(s.begin(), s.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
			return s;
	}

	std::string &Utils::rtrim(std::string &s) {
			s.erase(std::find_if(s.rbegin(), s.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
			return s;
	}

	std::string &Utils::trim(std::string &s) {
			return ltrim(rtrim(s));
	}

	int Utils::string_to_int(std::string v) {
		return std::stoi(v);
	}

	int char_to_int(char v) {
		return std::atoi(&v);
	}

	bool Utils::AreSame(float a, float b) {
		 return fabs(a - b) < FLT_EPSILON;
	}

	bool Utils::AreSame(double a, double b) {
		 return fabs(a - b) < FLT_EPSILON;
	}

	RGB Utils::HexToRGB(int hex) {
		RGB rgbColor;
		rgbColor.r = ((hex >> 16) & 0xFF) / 255.0;
		rgbColor.g = ((hex >> 8) & 0xFF) / 255.0;
		rgbColor.b = ((hex) & 0xFF) / 255.0;
		rgbColor.a = 255;

		return rgbColor; 
	}

	std::string toLower(std::string string) {
		std::transform(string.begin(), string.end(), string.begin(), ::tolower);
		return string;
	}

	int string_to_hex(std::string v) {
		std::stringstream str;
		std::string s1 = v;
		str << s1;
		int value;
		str >> std::hex >> value;
		return value;
	}

	std::string escape(const std::string &before) {
		std::string after;
		after.reserve(before.length() + 4);

		for (std::string::size_type i = 0; i < before.length(); ++i) {
			switch (before[i]) {
				case '"':
				case '\\':
					after += '\\';
					// Fall through.

				default:
					after += before[i];
			}
		}

		return after;
	}

	
	long long string_to_longlong(std::string v) {
		return std::stoll(v);
	}

	std::vector<std::string> explode(std::string str, char ch) {
		std::string next = "";
		std::vector<std::string> result;
		result.clear();

		for (auto it = str.begin(); it != str.end(); it++) {
			if (*it == ch) {
				if (!next.empty()) {
					result.push_back(next);
					next.clear();
				}
			} else {
				next += *it;
			}
		}
		if (!next.empty())
			 result.push_back(next);
		return result;
	}

}