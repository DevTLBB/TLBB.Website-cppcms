#ifndef APP_HTTP_CONTROLLERS_HOME_CONTROLLER_H_
#define APP_HTTP_CONTROLLERS_HOME_CONTROLLER_H_
#include "controller.h"

namespace app
{
  namespace http
  {
    namespace controllers
    {
      class HomeController : public Controller 
      {
       public:
        HomeController(cppcms::service &s);

				void index();
      };
    }
  }
}


#endif
