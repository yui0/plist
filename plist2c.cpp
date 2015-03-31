//g++ -o plist2c plist2c.cpp pugixml.cpp
//./plist2c > fontProportional.c
#include <map>
#include <string>
#include <iostream>
//#include <boost>
#include "Plist.hpp"

using namespace std;

int main()
{
	map<string, boost::any> dict;
	Plist::readPlist("fontProportional.plist", dict);

	// 要素を出力する
	map<string, boost::any>::iterator it = dict.begin();
	while( it != dict.end() )
	{
		//cout << (*it).first << ":" << (*it).second << endl;
		//cout << (*it).first << ":" << boost::any_cast<std::string>((*it).second) << endl;
		/*if (((*it).second).type() == typeid(std::string)) {
		if (((*it).second).type() == typeid(int)) {
			cout << "s";
		}*/

		cout << "\"" << (*it).first << "\", ";
		const vector<boost::any>& plistArray = boost::any_cast<const vector<boost::any>& >((*it).second);
		cout << boost::any_cast<const int64_t&>(plistArray[0]) << ", " << boost::any_cast<const int64_t&>(plistArray[1]) << ", " << boost::any_cast<const int64_t&>(plistArray[2]) << ", " << boost::any_cast<const int64_t&>(plistArray[3]) << "," << endl;

		++it;
	}
}
