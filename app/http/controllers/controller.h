#ifndef APP_HTTP_CONTROLLERS_CONTROLLER_H_
#define APP_HTTP_CONTROLLERS_CONTROLLER_H_
#include <cppcms/application.h>

namespace app
{
  namespace core
  {
    class Router;
  }
  namespace http
  {
    namespace controllers
    {
      class Controller : public cppcms::application
      {
       public:
        Controller(cppcms::service &s);
      };
    }
  }
}

#endif
