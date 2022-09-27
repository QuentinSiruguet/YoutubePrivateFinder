#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>

#include <sstream>
#include <iostream>
#include <array>
#include <ctime>
#include <vector>
#include <thread>
#include <fstream>

#define API_KEY "THEKEYISAAA"

std::array<char, 64> base64 = { '0','1','2','3','4','5','6','7','8','9'
	,'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'
	,'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','-','_' };

std::string randomizeVIDEOID()
{
	std::stringstream video_id;
	for (int k = 0; k < 11; k++)
		video_id << base64[std::rand() / ((RAND_MAX + 1u) / 64)];
	return video_id.str();
}

void saveVideoID(std::string video_id)
{
	std::cout << std::endl << video_id << "    WORKED <-------" << std::endl;
	std::ofstream file("result.txt", std::ios_base::app);
	file << video_id << std::endl;
	file.close();
	//std::stringstream sendDatabase;
	//sendDatabase << "OLD" << video_id << "&api_key=" << API_KEY;
	//curlpp::Easy httpDatabase;
	//httpDatabase.setOpt<curlpp::options::Url>(sendDatabase.str());
	//sendDatabase << httpDatabase;
}

void tryVideoID(std::string video_id)
{
	curlpp::Easy htppRequest;
	std::stringstream link;
	link << "https://www.youtube.com/watch?v=" << video_id;
	htppRequest.setOpt<curlpp::options::Url>(link.str());

	std::stringstream result;
	result << htppRequest;

	if (result.str().find("\"status\":\"ERROR\"") != std::string::npos)
		std::cout << ".";
	else
		saveVideoID(video_id);
}

int main()
{
	std::srand(std::time(nullptr));
	std::cout << "Working ";
	while (true)
	{
		curlpp::Cleanup my_cleanup;
		std::string video_id = randomizeVIDEOID();

		std::thread htpp_request(tryVideoID, video_id);
		htpp_request.join();
	}
	return 0;
}
