#include "web.h"

//#include <cppcms/url_mapper.h>
//#include <cppcms/url_dispatcher.h>

#include "../app/http/controllers/controller.h"
#include "../app/http/controllers/home_controller.h"

namespace routes
{
  Web::Web(cppcms::service &s) : app::core::Provider(s)
  {
	//dispatcher().assign("/", &app::http::controllers::HomeController::index, this);
    //mapper().assign("number","/number/{1}");
    attach(new app::http::controllers::HomeController(s),
      "home",
      "/{1}",
      "/",
      1);
 }

 // void Web::main(std::string path)
 // {
 //   try
 //   {
 //     cppcms::application::main(path);
 //   }
 //   catch(std::exception &e)
 //   {

 //   }
 // }
}
