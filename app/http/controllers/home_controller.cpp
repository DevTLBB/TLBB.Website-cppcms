#include <cppcms/url_mapper.h>
#include <cppcms/url_dispatcher.h>
#include "home_controller.h"
#include "../../../resources/views/layouts/app.h"

namespace app
{
	namespace http
	{
		namespace controllers
		{
			HomeController::HomeController(cppcms::service &s) : Controller(s)
			{
				dispatcher().assign("/", &HomeController::index, 1, 1);
			}

			void HomeController::index()
			{
			
			}
		}
	}
}

