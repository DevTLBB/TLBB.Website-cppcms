#ifndef APP_CORE_VIEW_H_
#define APP_CORE_VIEW_H_
#include <cppcms/application.h>
#include <cppcms/view.h>
#include <string>

namespace app
{
  namespace core
  {
	struct View : public cppcms::base_content
	{
	  std::string asset(std::string path)
	  {
	  	return this->media + path;
	  }
	  std::string media;

	};
  }
}
#endif
