#ifndef __EUROBATE_H__
#define __EUROBATE_H__

#include "provider.h"
#include <string>

/*
Login:
POST /index.php?option=com_profilemgr&task=login HTTP/1.1
username=asd&passwd=asd&op2=login&lang=norwegian&return=http%3A%2F%2Feurobate.com%2Findex.php

Send:
index.php
countrylist=47&gsm=asdasd0&contacts=0&melding=test&option=com_gratissms&task=send&uid=1236&usr_gsm=asd0&retur=index.php
 */

class Eurobate : public Provider
{
 public:
  void setup(std::string username, std::string password);
  bool send(std::string to, std::string from, std::string message);
};

#endif //__EUROBATE_H__
