#ifndef RESOURCES_VIEWS_LAYOUTS_APP_H_
#define RESOURCES_VIEWS_LAYOUTS_APP_H_
#include "../../../app/core/view.h"

namespace views
{
  namespace layouts
  {
    struct App : public app::core::View
    {
	  std::string title;
      std::string text;
    };
  }
}

#endif
