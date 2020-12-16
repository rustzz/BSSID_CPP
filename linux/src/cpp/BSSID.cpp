/*
    Author: rustzz
    Github: https://github.com/rustzz
*/

#include <map>
#include <string>

#include "../headers/BSSID.hpp"
#include "Requests.cpp"
#include "History.cpp"
#include "Parser.cpp"
#include "Shared.cpp"


class BSSID {
public:
    BSSID () {};
    ~BSSID () {};

    std::string Get (std::string bssid_code)
    {
        Checkers checkers;
        Requests requests;
        History history;
        Parser parser;
        std::string out;

        if (!checkers.ValidBSSID(bssid_code))
            return "Is not BSSID.\n";

        std::string URL = YANDEXURL0 + bssid_code + YANDEXURL1;
        std::string response;
        std::map<std::string, std::string> location;

        response = requests.GetResponse(URL);
        location = parser.GetLocation(response);

        if (!checkers.ValidLocation(location))
            return "Data empty.\n";
		out = PrepareOut(location, bssid_code);
        history.Log(out);
        return out;
    };
private:
	std::string PrepareOut (std::map<std::string, std::string> location, std::string bssid_code)
	{
		std::string out;
        out = "[ " + bssid_code + " ]\n";
		out += "Latitude: " + location["latitude"] + "\n";
        out += "Longitude: " + location["longitude"] + "\n";
        out += "Google.Maps link: https://google.com/maps/place/" + location["latitude"] + "%20" + location["longitude"] + "\n";
		return out;
	}
protected:
};
