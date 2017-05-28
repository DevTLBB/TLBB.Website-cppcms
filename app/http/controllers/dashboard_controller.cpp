#include "dashboard_controller.h"
#include <cppcms/url_mapper.h>
#include <cppcms/url_dispatcher.h>
#include <cppdb/frontend.h>

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
        
        views::dashboard::Register::RegisterForm *c = &view.register_form;
        if (request().request_method() == "POST")
        {
          c->load(context());
          if (view.register_form.validate())
          {
            cppdb::session sql(this->model.web);
            //cppdb::transaction db(sql);
            sql << "INSERT INTO account(name,password)"
              "VALUES(?,MD5(?))"
              << c->name.value()
              << c->password.value()
              << cppdb::exec;
            //db.commit();
          }
        }
        c->password.clear();
        c->confirm_password.clear();

        // Render view at the end
        render("dashboard_register", view);
      }
    }
  }
}
