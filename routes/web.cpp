#include "web.h"
#include "../app/http/controllers/controller.h"

using namespace app::http::controllers;

routes::Web::Web(cppcms::service &s) : cppcms::application(s)
{
  // attach();
}

void routes::Web::main(std::string path)
{
	try
  {
    cppcms::application::main(path);
  }
	catch(std::exception &e)
	{
	
	}
}
