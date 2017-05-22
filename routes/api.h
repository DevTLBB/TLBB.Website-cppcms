#ifndef ROUTES_API_H_
#define ROUTES_API_H_
#include <cppcms/application.h>

namespace routes
{
  class API : public cppcms::application
  {
   public:
    API(cppcms::service &s);

    virtual void main(std::string path);
  };
}

#endif
