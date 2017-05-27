#include "view.h"

namespace app
{
  namespace core
  {
	View::View()
	{
	  this->media = "/media";
	}
	std::string View::asset(std::string path)
	{
	  	return this->media + path;
	}
  }
}
