#ifndef APP_HTTP_CONTROLLERS_DASHBOARD_CONTROLLER_H_
#define APP_HTTP_CONTROLLERS_DASHBOARD_CONTROLLER_H_
#include "controller.h"
#include "../../core/view.h"

namespace app
{
  namespace http
  {
    namespace controllers
    {
      class DashboardController : public Controller
      {
       public:
        DashboardController(cppcms::service &s);
        //virtual void ini(app::core::View &v);

       public:
        void index();
        void user_login();
        void user_register();
      };
    }
  }
}

#endif
