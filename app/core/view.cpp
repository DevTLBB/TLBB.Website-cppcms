#include "view.h"

namespace app
{
  namespace core
  {
	View::View()
	{
	}
	std::string View::asset(std::string path)
	{
	  	return "/media" + path;
	}
  }
}
