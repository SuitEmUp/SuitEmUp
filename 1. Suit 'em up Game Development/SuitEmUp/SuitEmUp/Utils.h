#ifndef UTILS_H
#define UTILS_H

#include <random>
#include <chrono>
#include <string>

struct Circle {
	float x;
	float y;
	float radius;
};

struct RGB {
	int r;
	int g;
	int b;
	int a;
};

namespace Utils {

	/* Generates truly random numbers */
	namespace Random {
		int random(int min, int max);
		float frandom(float min, float max);
		void seed();
	};

	namespace File {
		void CreateFile(std::string filename);
	};

	/* Get current time in milliseconds */
	uint64_t GetTimeByMilliseconds();
	long long GetTimeBySeconds();

	/* Converts an integer to a string */
	std::string int_to_string(int v);

	/* Converts longlong to string  */
	std::string longlong_to_string(long long v);

	/* Converts a string to a float */
	float string_to_float(std::string s);

	/* Converts a float to a string */
	std::string float_to_string(float v);

	/* Splits a string by a delimiter and returns a vector with std::string */
	std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems);

	/* Explode */
	std::vector<std::string> explode(std::string str, char ch);

	/* Trims a string from start */
	std::string &ltrim(std::string &s);

	/* Trims a string from end */
	std::string &rtrim(std::string &s);

	/* Trims a string from both ends */
	std::string &trim(std::string &s);

	/* Convert string to int */
	int string_to_int(std::string v);
	long long string_to_longlong(std::string v);

	/* Converts a char into a int */
	int char_to_int(char v);

	/* Rounds a number the the nearest number n */
	float roundToNearestN(float x, float n);

	/* Rounds a number to num of decimals */
	float round(float v, float prec);

	/* Compare float numbers */
	bool AreSame(float a, float b);
	bool AreSame(double a, double b);

	/* Converts a hexadecimal color to a RGB struct */
	RGB HexToRGB(int hex);

	/* Converts all uppercase letters to lowercase */
	std::string toLower(std::string string);

	/* Converts a string to hex */
	int string_to_hex(std::string v);

	/* Simple escaping a string */
	std::string escape(const std::string &before);

}

#endif