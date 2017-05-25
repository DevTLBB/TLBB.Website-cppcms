#include "home_controller.h"
#include <cppcms/url_mapper.h>
#include <cppcms/url_dispatcher.h>

#include "../../../resources/views/layouts/app.h"

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
		std::cout << "Index" << std::endl;
        response().make_error_response(cppcms::http::response::forbidden);
	  }
	}
  }
}

