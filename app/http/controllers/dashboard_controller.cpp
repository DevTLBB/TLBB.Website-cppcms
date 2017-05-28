#include "dashboard_controller.h"
#include <cppcms/url_mapper.h>
#include <cppcms/url_dispatcher.h>

#include "../../../resources/views/dashboard.h"
#include "../../../resources/views/dashboard/register.h"
#include "../../models/account.h"

namespace app
{
  namespace http
  {
    namespace controllers
    {
      DashboardController::DashboardController(cppcms::service &s) : Controller(s)
      {
        dispatcher().assign("/login(/)?", &DashboardController::user_login, this);
        mapper().assign("login","/login");
        
        dispatcher().assign("/register(/)?", &DashboardController::user_register, this);
        mapper().assign("register","/register");
        
        dispatcher().assign("(/)?", &DashboardController::index, this);
        mapper().assign("dashboard", "");
      }

      void DashboardController::index()
      {
        views::Dashboard view;
        view.title = "Quản lí tài khoản cá nhân";

        // Render view at the end
        render("dashboard", view);
      }
      
      void DashboardController::user_login()
      {
      }

      void DashboardController::user_register()
      {
        views::dashboard::Register view;
        view.title = "Đăng kí tài khoản";
        
        if(request().request_method() == "POST")
        {
          view.register_form.load(context());
          std::cout << view.register_form.name.value();
        }

        // Render view at the end
        render("dashboard_register", view);
      }
    }
  }
}
