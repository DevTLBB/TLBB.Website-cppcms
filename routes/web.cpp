#include <cppcms/url_mapper.h>
#include <cppcms/url_dispatcher.h>
#include "web.h"

#include "../app/http/controllers/controller.h"
#include "../app/http/controllers/home_controller.h"

namespace routes
{
  Web::Web(cppcms::service &s) : cppcms::application(s)
  {
		attach(new app::http::controllers::HomeController(s),
      "home",
      "/{1}",
      "/",
      1);
 
		//dispatcher().assign("/", &app::http::controllers::HomeController::index);
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
