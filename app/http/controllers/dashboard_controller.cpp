#include "dashboard_controller.h"
#include <cppcms/url_mapper.h>
#include <cppcms/url_dispatcher.h>

#include "../../../resources/views/dashboard.h"

namespace app
{
  namespace http
  {
    namespace controllers
    {
    	DashboardController::DashboardController(cppcms::service &s) : Controller(s)
    	{
    	  dispatcher().assign(".*", &DashboardController::index, this);
    	}

    	void DashboardController::index()
    	{
    	  views::Dashboard view;
    	  view.text = ">>>Hello<<<";
          view.title = "Home Page";
    	  render("dashboard", view);
    	}
    }
  }
}
