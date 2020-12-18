/*
    Author: rustzz
    Github: https://github.com/rustzz
*/

#include <map>

#include "../../../public/pugixml/pugixml.hpp"


class Parser {
public:
	Parser () {};
	~Parser () {};
	
	std::map<std::string, std::string> GetLocation (std::string raw_xml) {
        std::map<std::string, std::string> location;
        pugi::xml_document doc;
        pugi::xml_parse_result result = doc.load_string(raw_xml.c_str());
        if (!result)
            return location;

        pugi::xml_node coordinates = doc.child("location").child("coordinates");
        std::string latitude = coordinates.attribute("latitude").value();
        std::string longitude = coordinates.attribute("longitude").value();

        location = {{"latitude", latitude},
                    {"longitude", longitude}};
        return location;
    };
private:
protected:
};
