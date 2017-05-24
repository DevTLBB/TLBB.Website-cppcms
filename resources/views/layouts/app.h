#ifndef APP_CORE_VIEW_H_
#define APP_CORE_VIEW_H_
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
