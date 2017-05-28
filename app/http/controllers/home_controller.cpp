#include "home_controller.h"
#include <cppcms/url_mapper.h>
#include <cppcms/url_dispatcher.h>
#include <cppcms/http_response.h>

#include "../../../resources/views/layouts/app/home.h"

namespace app
{
  namespace http
  {
    namespace controllers
    {
        HomeController::HomeController(cppcms::service &s) : Controller(s)
        {
          dispatcher().assign(".*", &HomeController::index, this);
        }

        void HomeController::index()
        {
          response().set_redirect_header("/dashboard", 301);
          // views::layouts::app::Home view;
          // view.text = ">>>Hello<<<";
          // view.title = "Home Page";
          // render("layouts_app_home", view);
        }
    }
  }
}
