#ifndef RESOURCES_VIEWS_H_
#define RESOURCES_VIEWS_H_
#include <cppcms/view.h>
#include <string>

namespace views
{
  namespace layouts
  {
	struct app : public cppcms::base_content
	{
	  std::string text;
	};
  }
}

#endif
