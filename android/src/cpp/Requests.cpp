/*
    Author: rustak
    Github: https://github.com/rustakss
*/

#include <curl/curl.h>
#include <string>


class Requests {
public:
	Requests () {};
	~Requests () {};
	std::string GetResponse (std::string URL)
	{
		std::string response;
		curl = curl_easy_init();
		if(curl) {
			curl_easy_setopt(curl, CURLOPT_URL, URL.c_str());
			curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
			curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
			curl_response = curl_easy_perform(curl);
			curl_easy_cleanup(curl);
		}
		return response;
	}
private:
	CURL * curl;
	CURLcode curl_response;

	static size_t WriteCallback(char * ptr, size_t size, size_t nmemb, std::string * userdata)
	{
		(userdata)->append(ptr, size * nmemb);
		return size * nmemb;
	}
protected:
};
