#ifndef ROUTES_WEB_H_
#define ROUTES_WEB_H_
#include <cppcms/application.h>

namespace routes
{
  class Web : public cppcms::application
  {
   public:
    Web(cppcms::service &s);

	  virtual void main(std::string path);
  };
}

#endif
