#include "eurobate.h"
#include <string>
#include <iostream>
#include "curl/curl.h"

void Eurobate::setup(std::string username, std::string password)
{
  CURL *curl;
  curl = curl_easy_init();

  std::string post = "username=%s&passwd=%s&op=2login&lang=norwegian";
  char data[post.length() + username.length() + password.length()];
  sprintf(data, post.c_str(), username.c_str(), password.c_str());

  std::cout << "POST: " << data << std::endl;
  
  curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data);
  curl_easy_setopt(curl, CURLOPT_URL, 
                   "http://eurobate.com/index.php?option=com_profilemgr&task=login");
  curl_easy_setopt(curl, CURLOPT_COOKIEFILE, "cookies.txt");
  curl_easy_perform(curl);
}

bool Eurobate::send(std::string to, std::string from, std::string message)
{
  CURL *curl;
  curl = curl_easy_init();

  std::string post = "countrylist=47&gsm=%s&melding=%s&option=com_gratissms&task=send&usr_gsm=%s";
  char data[post.length() + to.length() + message.length()];
  sprintf(data, post.c_str(), from.c_str(), message.c_str(), to.c_str());

  std::cout << "POST: " << data << std::endl;

  curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data);
  curl_easy_setopt(curl, CURLOPT_URL, 
                   "http://eurobate.com/index.php");
  curl_easy_setopt(curl, CURLOPT_COOKIEFILE, "cookies.txt");
  curl_easy_perform(curl);

  return true;
}
