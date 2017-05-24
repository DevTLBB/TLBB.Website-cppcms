#include <cppcms/url_mapper.h>
#include <cppcms/url_dispatcher.h>
#include "web.h"

#include "../app/http/controllers/controller.h"
#include "../app/http/controllers/home_controller.h"

namespace routes
{
  Web::Web(cppcms::service &s) : cppcms::application(s)
  {
    /*attach(new HomeController(s),
      "home",
      "/{1}",
      "/",
      1);*/
		dispatcher().assign("^/page/(\\w+)$", &app::http::controllers::HomeController::index, 1);
		//dispatcher().assign("/number/(\\d+)", &app::http::controllers::HomeController::index, this, 1);  
    //mapper().assign("number","/number/{1}");
  }

  void Web::main(std::string path)
  {
    try
    {
      cppcms::application::main(path);
    }
    catch(std::exception &e)
    {

    }
  }
}
