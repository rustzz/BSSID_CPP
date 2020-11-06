#include <iostream>
#include <string>
#include <map>

#include <boost/filesystem.hpp>


class History {
public:
	History () {};
	~History () {};

	void Log (std::string text)
	{
		boost::filesystem::path path(getenv("HOME"));
		path += "/history";

		FILE * ptr_File = fopen(path.c_str(), "a");

		if (ptr_File != NULL)
		{
			fputs(text.c_str(), ptr_File);
			fclose(ptr_File);
		}
	}
private:
protected:
};
