// HTTPrequests.cpp: определяет точку входа для приложения.
//

#include "cpr/api.h"
#include "cpr/payload.h"
#include "cpr/response.h"
#include "HTTPrequests.h"
#include <iostream>
#include <ostream>
#include <string>

using namespace std;

int main()
{
	cpr::Response g = cpr::Get(cpr::Url("http://httpbin.org/headers"),
							   cpr::Header({ {"user-agent", "Mozilla/5.0 (Windows NT 10.0; Win64; x64; rv:124.0) Gecko/20100101 Firefox/124.0"},
										        {"accept", "text/html"} }));
	
	string name = "Andrey", city = "Barnaul";
	//cin >> name >> city;
	cpr::Response p = cpr::Post(cpr::Url("http://httpbin.org/post"),
								cpr::Payload({ {"name", name}, {"city", city }}));

	cout << p.text << endl;

	p = cpr::Put(cpr::Url("http://httpbin.org/put"),
				 cpr::Payload({ {"name", "Anna"}, {"city", "Moskva"} }));

	cout << p.text << endl;

	p = cpr::Delete(cpr::Url("http://httpbin.org/delete"));

	cout << p.text << endl;
	return 0;
}
