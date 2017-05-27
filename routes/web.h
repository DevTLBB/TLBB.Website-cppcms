#ifndef ROUTES_WEB_H_
#define ROUTES_WEB_H_
#include <cppcms/application.h>
#include "../app/core/provider.h"

namespace routes
{
  class Web : public app::core::Provider
  {
   public:
    Web(cppcms::service &s);

    // virtual void main(std::string path);
  };
}

#endif
