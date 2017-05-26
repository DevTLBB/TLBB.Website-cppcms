#ifndef RESOURCES_VIEWS_LAYOUTS_APP_H_
#define RESOURCES_VIEWS_LAYOUTS_APP_H_
#include <cppcms/view.h>
#include <string>

namespace views
{
  namespace layouts
  {
    struct App : public cppcms::base_content
    {
      std::string title;
      std::string text;
    };
  }
}

#endif
