#ifndef APP_HTTP_CONTROLLERS_CONTROLLER_H_
#define APP_HTTP_CONTROLLERS_CONTROLLER_H_
#include <cppcms/application.h>

#include "../../core/provider.h"

namespace app
{
  namespace http
  {
    namespace controllers
    {
      class Controller : public app::core::Provider
      {
       public:
        Controller(cppcms::service &s);
      };
    }
  }
}

#endif
