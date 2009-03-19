#include "eurobate.h"
#include <string>
#include <sstream>
#include <iostream>
#include "curl/curl.h"

void Eurobate::setup(std::string username, std::string password)
{
  // No need to login at eurobate
}

bool Eurobate::send(std::string to, std::string from, std::string message)
{
  CURL *curl;
  curl = curl_easy_init();

  std::stringstream dataStream;
  dataStream << "countrylist=47&gsm=" << to << "&melding=" << message;
  dataStream << "&option=com_gratissms&task=send&usr_gsm=" << from;

  std::string data = dataStream.str();

  std::cout << "POST: " << data << std::endl;

  curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data.c_str());
  curl_easy_setopt(curl, CURLOPT_URL,
                   "http://eurobate.com/index.php");
  curl_easy_setopt(curl, CURLOPT_COOKIEFILE, "cookies.txt");
  curl_easy_perform(curl);

  return true;
}
